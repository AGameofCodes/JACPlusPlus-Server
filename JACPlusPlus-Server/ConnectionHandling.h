/* 
 * File:   ConnectionHandling.h
 * Author: jester
 *
 * Created on February 18, 2015, 5:47 PM
 */

#ifndef CONNECTIONHANDLING_H
#define	CONNECTIONHANDLING_H

#include <sys/socket.h>
#include "../../libsockcpp/Socket.h"
#include "../../libsockcpp/IllegalStateException.h"

class ConnectionHandling {
private:
    bool enabled;
    std::thread *t;
    libsockcpp::Socket *socket;
public:
    ConnectionHandling(libsockcpp::Socket *socket);
    ConnectionHandling(const ConnectionHandling& orig);
    virtual ~ConnectionHandling();
    void run();
    void start();
    void stop();
    void awaitTermination();
};

#endif	/* CONNECTIONHANDLING_H */

