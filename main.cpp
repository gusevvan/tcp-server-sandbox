#include "tcp_server.hpp"
#include "policies/synchronous.hpp"
#include "policies/thread_per_connection.hpp"

#define SAMPLE_HTTP_REPLY "HTTP/1.1 200 OK\r\nContent-Length: 0\r\nConnection: close\r\n\r\n"

void testSyncronous() {
    TcpServer<Syncronous> httpServer(1234, SAMPLE_HTTP_REPLY);
    httpServer.run();
}

void testThreadPerConnection() {
    TcpServer<ThreadPerConnection> httpServer(1234, SAMPLE_HTTP_REPLY);
    httpServer.run();
}

int main() {
    testThreadPerConnection();
}
