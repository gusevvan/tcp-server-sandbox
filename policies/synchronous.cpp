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
            handleConnection(connection);
        }
    }
}
