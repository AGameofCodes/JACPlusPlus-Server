/* 
 * File:   ConnectionHandling.cpp
 * Author: jester
 * 
 * Created on February 18, 2015, 5:48 PM
 */

#include <thread>
#include "ConnectionHandler.h"
#include "packet/PacketFactory.h"

ConnectionHandler::ConnectionHandler(libsockcpp::Socket *socket)
: bufferreader(new SocketToBuffer(socket)), transmissionid(0)
{

}

ConnectionHandler::~ConnectionHandler()
{
  delete bufferreader;
}

//------------------------------------------------------------------------------

int ConnectionHandler::newTransMissionId()
{
  return transmissionid++;
}


//------------------------------------------------------------------------------

void ConnectionHandler::start()
{
  if (enabled)
  {
    return;
  }
  enabled = true;

  t = new std::thread(&ConnectionHandler::run, this);
}


//------------------------------------------------------------------------------

void ConnectionHandler::run()
{
  while (enabled)
  {
    readIo();
    writeIo();
  }

}


//------------------------------------------------------------------------------

void ConnectionHandler::readIo()
{
  readSocket();
  Buf *buf = bufferreader->getBuffer();

  while (true)
  {
    //check if packet length is readable
    if (buf->readableBytes() < sizeof (int))
      break;

    //mark position to reset it when packet is not fully readable
    buf->markReaderIndex();

    //read packet length and check if the packet has fully arrived
    int len = buf->readInt();
    if (buf->readableBytes() > len)
    {
      buf->resetReaderIndex();
      break;
    }

    //packet has fully arrieved ... now handle it
    char protocoltype = buf->readChar();
    handlePacket(protocoltype, buf);
  }

  //remove data we do not need anymore
  buf->discardReadBytes();
}


//------------------------------------------------------------------------------

void ConnectionHandler::readSocket()
{
  bufferreader->read();
}


//------------------------------------------------------------------------------

void ConnectionHandler::handlePacket(char protocoltype, Buf *b)
{
  //decide depending on protocol version
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
  int type = b->readInt();
  int transmissionid = b->readInt();

  //create the right packet object
  Packet *p = PacketFactory::getInstance()->create(type);
  if (p == nullptr)
  {
    //ignore
    return;
  }

  //read the packet
  p->read(b);

  //handle packet
  //todo: ...

  //delete the packet
  delete p;
}

void ConnectionHandler::writeIo()
{
  //  socket->write(); //todo write
  //make a queue and write it fully
}




//------------------------------------------------------------------------------

void ConnectionHandler::stop()
{
  if (!enabled)
  {
    return;
  }
  enabled = false;
}

//------------------------------------------------------------------------------

void ConnectionHandler::awaitTermination()
{
  if (t != nullptr)
  {
    t->join();
    t = nullptr;
  }
}