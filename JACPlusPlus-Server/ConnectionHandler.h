/* 
 * File:   ConnectionHandling.h
 * Author: jester
 *
 * Created on February 18, 2015, 5:47 PM
 */

#ifndef CONNECTIONHANDLER_H
#define	CONNECTIONHANDLER_H

#include "../../libsockcpp/Socket.h"
#include "../../libsockcpp/IllegalStateException.h"
#include "iostream"
#include <string>
#include "../../libanoi/Buf.h"

class ConnectionHandler {
private:
    bool enabled;
    std::thread *t;
    libsockcpp::Socket *socket;
    
    int transmissionid;
    int protokoltyp;
    
    int newTransMissionId();
    void run();
    void readIo();
    void writeIo();
    void readSocket();
    void handlePacket(char protocoltype, Buf *b);
    void handlePacket1(Buf *b);
    
public:
    ConnectionHandler(libsockcpp::Socket *socket);
    ConnectionHandler(const ConnectionHandler& orig);
    virtual ~ConnectionHandler();
    void start();
    void stop();
    void awaitTermination();
    
    
};

#endif	/* CONNECTIONHANDLER_H */
