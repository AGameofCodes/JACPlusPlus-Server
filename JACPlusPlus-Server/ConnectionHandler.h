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
#include "SocketToBuffer.h"
#include <queue>
#include "packet/Packet.h"
#include <mutex>

class ConnectionHandler
{
private:
  ConnectionHandler(const ConnectionHandler& orig) = delete;

  bool enabled;
  std::thread *t;
  libsockcpp::Socket *socket;
  SocketToBuffer *bufferreader;
  //                    protocoltype, packettype, transmissionid, packet
  std::queue<std::tuple<char, char, int, Packet*>*> writequeue;
  std::mutex writeqmutex;
  
  int transmissionid;

  int newTransMissionId();
  void run();
  void readIo();
  void writeIo();
  void readSocket();
  void handlePacket(char protocoltype, Buf *b);
  void handlePacket1(Buf *b);
  void writerFct(char protocoltype, char packettype, int transmissionid, Packet *packet);
public:
  ConnectionHandler(libsockcpp::Socket *socket);
  virtual ~ConnectionHandler();
  void start();
  void stop();
  void awaitTermination();


};

#endif	/* CONNECTIONHANDLER_H */

