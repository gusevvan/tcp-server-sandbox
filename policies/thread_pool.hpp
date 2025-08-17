#ifndef __THREAD_POOL_HPP__
#define __THREAD_POOL_HPP__
#include "connection_policy.hpp"

#include <condition_variable>
#include <queue>
#include <mutex>
#include <thread>
#include <vector>

template <int N>
class ThreadPool final : public ConnectionPolicy {
public:
    ThreadPool(const std::string& reply): ConnectionPolicy(reply) {
        threads.reserve(N);
    }
    void run(int socket) override {
        for (int i = 0; i < N; ++i) {
            threads.emplace_back(&ThreadPool::work, this);
        }
        int connection;
        while (true) {
            if ((connection = accept(socket, NULL, NULL)) < 0) {
                std::cout << "Failed to establish connection" << std::endl;
            } else {
                std::lock_guard locker(queueMutex);
                connections.push(connection);
                queueReady.notify_one();
            }
        }
    }
private:
    void work() {
        using namespace std::chrono_literals;
        int connection;
        while (true) {
            {
                std::unique_lock locker(queueMutex);
                queueReady.wait(locker, [this]() {return !connections.empty();});
                connection = connections.front();
                connections.pop();
            }
            handleConnection(connection, true);
        }
    }

    std::condition_variable queueReady;
    std::mutex queueMutex;
    std::queue<int> connections;
    std::vector<std::jthread> threads; 
};

#endif