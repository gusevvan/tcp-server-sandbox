#ifndef __EVENT_LOOP_HPP__
#define __EVENT_LOOP_HPP__
#include "connection_policy.hpp"

#include <sys/epoll.h>

#define MAX_EVENTS 10

class EventLoop final : public ConnectionPolicy {
public:
    EventLoop(const std::string& reply);
    void run(int socket) override;
private:
    int epoll;
    epoll_event events[MAX_EVENTS];
    struct epoll_event event;
    void addServerSocket(int socket);
    void addConnection(int connection);
    void setNonBlocking(int connection);
};

#endif