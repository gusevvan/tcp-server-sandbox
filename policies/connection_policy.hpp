#ifndef __EXECUTION_POLICY__
#define __EXECUTION_POLICY__

#define MAX_BUFFER 8096

#include <string>

class ConnectionPolicy {
public:
    ConnectionPolicy(const std::string& reply): reply{reply} {}
    virtual void run(int socket) = 0;
    virtual ~ConnectionPolicy() {};
protected:
    char buffer[MAX_BUFFER + 1];
    const std::string reply; 
};

#endif