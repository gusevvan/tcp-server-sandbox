#include "event_loop.hpp"

#include <fcntl.h>
#include <sys/socket.h>

#include <iostream>
#include <stdexcept>
#include <unistd.h>

EventLoop::EventLoop(const std::string& reply): ConnectionPolicy(reply) {
    epoll = epoll_create1(0);
    if (epoll == -1) {
        throw std::runtime_error("failed to create epoll");
    }
}

void EventLoop::run(int socket) {
    addServerSocket(socket);
    int connection;
    while (true) {
        int nfds = epoll_wait(epoll, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            throw std::runtime_error("failed to handle epoll events");
        }
        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == socket) {
                if ((connection = accept(socket, NULL, NULL)) < 0) {
                    std::cout << "Failed to establish connection" << std::endl;
                } else {
                    addConnection(connection);
                }
            } else {
                handleConnection(events[n].data.fd);
            }
        }
    }
}

void EventLoop::addServerSocket(int socket) {
    event.events = EPOLLIN;
    event.data.fd = socket;
    if (epoll_ctl(epoll, EPOLL_CTL_ADD, socket, &event) == -1) {
        throw std::runtime_error("failed to add server socket to epoll");
    }
}

void EventLoop::addConnection(int connection) {
    setNonBlocking(connection);
    event.events = EPOLLIN | EPOLLET;
    event.data.fd = connection;
    if (epoll_ctl(epoll, EPOLL_CTL_ADD, connection, &event) == -1) {
        close(connection);
    }
}

void EventLoop::setNonBlocking(int connection) {
    int flags = fcntl(connection, F_GETFL, 0);
    fcntl(connection, F_SETFL, flags | O_NONBLOCK);
}
