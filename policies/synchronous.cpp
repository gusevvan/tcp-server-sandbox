#include "synchronous.hpp"

#include <iostream>

#include <sys/socket.h>
#include <unistd.h>

void Syncronous::run(int socket) {
    int connection;
    while (true) {
        if ((connection = accept(socket, NULL, NULL)) < 0) {
            std::cout << "Failed to establish connection" << std::endl;
        } else {
            size_t size = read(connection, buffer, sizeof(buffer) - 1);
            if (size == -1) {
                std::cout << "Incorrect reading" << std::endl;
            }
            send(connection, reply.c_str(), reply.size(), 0);
            close(connection);
        }
    }
}
