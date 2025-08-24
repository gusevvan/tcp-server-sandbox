#ifndef __TCP_SERVER_HPP__
#define __TCP_SERVER_HPP__
#include <concepts>
#include <iostream>
#include <stdexcept>
#include <string>

#include <arpa/inet.h>
#include <unistd.h>

#include "policies/connection_policy.hpp"

template <std::derived_from<ConnectionPolicy> CP>
class TcpServer {
public:
    TcpServer(const int port, const std::string& reply): connectionPolicy{reply} {
        _socket = socket(AF_INET, SOCK_STREAM, 0);
        if (_socket < 0) {
            throw std::runtime_error("failed to open socket");
        }
        sockaddr_in serverAddr{.sin_family{AF_INET}, .sin_port{htons(port)}, .sin_addr{htonl(INADDR_ANY)}};
        if (bind(_socket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
            throw std::runtime_error("Failed to bind socket");
        }
        std::cout << "Server created" << std::endl;
    }

    void run() {
        int listenStatus = listen(_socket, SOMAXCONN);
        if (listenStatus < 0) {
            throw std::runtime_error("Failed to start server");
        }
        std::cout << "Server started" << std::endl;
        connectionPolicy.run(_socket);
    }

    ~TcpServer() {
        close(_socket);
    }

    TcpServer(const TcpServer&) = delete;
    TcpServer(TcpServer&&) = delete;
    TcpServer& operator=(const TcpServer&) = delete;
    TcpServer& operator=(TcpServer&&) = delete;

private:
    CP connectionPolicy;
    int _socket;
};


#endif
