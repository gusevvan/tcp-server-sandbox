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
            connectionThreads.emplace_back(&ThreadPerConnection::handleConnection, this, connection, true);
        }
    }
}
