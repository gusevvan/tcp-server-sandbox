#ifndef __SYNCRONOUS_HPP__
#define __SYNCRONOUS_HPP__
#include "connection_policy.hpp"

class Syncronous final : public ConnectionPolicy {
public:
    Syncronous(const std::string& reply): ConnectionPolicy(reply) {}
    void run(int socket) override;
};

#endif