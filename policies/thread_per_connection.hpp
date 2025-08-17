#ifndef __THREAD_PER_CONNECTION_HPP__
#define __THREAD_PER_CONNECTION_HPP__
#include "connection_policy.hpp"

#include <thread>
#include <vector>

class ThreadPerConnection final : public ConnectionPolicy {
public:
    ThreadPerConnection(const std::string& reply): ConnectionPolicy(reply) {}
    void run(int socket) override;
private:
    std::vector<std::jthread> connectionThreads; 
};

#endif