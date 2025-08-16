#include "thread_per_connection.hpp"

#include <chrono>
#include <iostream>

#include <sys/socket.h>
#include <unistd.h>

void ThreadPerConnection::run(int socket) {
    int connection;
    while (true) {
        if ((connection = accept(socket, NULL, NULL)) < 0) {
            std::cout << "Failed to establish connection" << std::endl;
        } else {
            connectionThreads.emplace_back(&ThreadPerConnection::handleConnection, this, connection);
        }
    }
}

void ThreadPerConnection::handleConnection(int connection) {
    using namespace std::chrono_literals;
    size_t size = read(connection, buffer, sizeof(buffer) - 1);
    if (size == -1) {
        std::cout << "Incorrect reading" << std::endl;
    }
    send(connection, reply.c_str(), reply.size(), 0);
    std::this_thread::sleep_for(10ms);
    close(connection);
}
