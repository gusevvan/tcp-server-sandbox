#include "connection_policy.hpp"

#include <chrono>
#include <iostream>
#include <thread>

#include <sys/socket.h>
#include <unistd.h>

ConnectionPolicy::ConnectionPolicy(const std::string& reply): reply{reply} {}

void ConnectionPolicy::handleConnection(int connection, bool sleep) {
    size_t size = read(connection, buffer, sizeof(buffer) - 1);
    if (size == -1) {
        std::cout << "Incorrect reading" << std::endl;
    }
    send(connection, reply.c_str(), reply.size(), 0);
    if (sleep) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(10ms);
    }
    close(connection);
}