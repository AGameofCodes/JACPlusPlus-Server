/* 
 * File:   ConnectionHandling.cpp
 * Author: jester
 * 
 * Created on February 18, 2015, 5:48 PM
 */

#include <thread>
#include "ConnectionHandler.h"


ConnectionHandler::ConnectionHandler(libsockcpp::Socket *socket) 
{
  
}

ConnectionHandler::ConnectionHandler(const ConnectionHandler& orig) 
{
}

ConnectionHandler::~ConnectionHandler() 
{
}

//------------------------------------------------------------------------------

int ConnectionHandler::newTransMissionId() 
{
  return transmissionid++;
}


//------------------------------------------------------------------------------

void ConnectionHandler::start() 
{
  if(enabled)
  {
    return;
  }
  enabled = true;
  
  t = new std::thread(&ConnectionHandler::run, this);
  
}


//------------------------------------------------------------------------------

void ConnectionHandler::run() 
{
  while(enabled)
  {
    readIo();
    writeIo();
  }
  
}


//------------------------------------------------------------------------------

void ConnectionHandler::readIo() {
  socket->read(); //todo read
  Buf *buf;
  if(buf->readableBytes() < sizeof(int))
    return;
  
  buf->markReaderIndex();
  int len = buf->readInt();
  if(buf->readableBytes() > len)
  {
    buf->resetReaderIndex();
    return;
  }
  
  
  
  char protocoltype = buf->readChar();
  handlePacket(protocoltype, buf);
}


//------------------------------------------------------------------------------

void ConnectionHandler::readSocket()
{
  //socket->
}


//------------------------------------------------------------------------------

void ConnectionHandler::handlePacket(char protocoltype, Buf *b)
{
  switch (protocoltype)
  {
    case 1: 
      handlePacket1(b);
      break;
      
    default:
      break;
  }
}


//------------------------------------------------------------------------------

void ConnectionHandler::handlePacket1(Buf *b)
{
  int typ = b->readInt();
  int transmissionid = b->readInt();
}

void ConnectionHandler::writeIo()
{
  socket->write(); //todo write
}




//------------------------------------------------------------------------------

void ConnectionHandler::stop() 
{
  if(!enabled)
  {
    return;
  }
  enabled = false;
}

//------------------------------------------------------------------------------

void ConnectionHandler::awaitTermination()
{
  if(t != NULL)
  {
    t->join();
    t = NULL;
  }
}