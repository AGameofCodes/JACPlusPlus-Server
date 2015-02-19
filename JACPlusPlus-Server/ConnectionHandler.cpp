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
  //make a queue and write it fully
  while(!writequeue.empty())
  {
    std::tuple<char, char, int, Packet*> *tq = writequeue.front();
  
    // get info
    char protocoltype = std::get<0>(*tq);
    char packettype = std::get<1>(*tq);
    int transmissionid = std::get<2>(*tq);
    Packet *packet = std::get<3>(*tq);
    
    // write packet buffer
    Buf *b = new Buf();
    packet->write(b);
    
    // get sizeof network packet
    int len = sizeof(protocoltype) + sizeof(packettype) + sizeof(transmissionid) + b->writerIndex();
    
    // encode network packet
    Buf *writebuf = new Buf();
    writebuf->write(len);
    writebuf->write(protocoltype);
    writebuf->write(packettype);
    writebuf->write(transmissionid);
    writebuf->write(b);
    
    // write to socket
    socket->write(writebuf->data(), writebuf->writerIndex());
    
    // remove element and delete it
    writequeue.pop();
    delete tq;
  }
}


//------------------------------------------------------------------------------

void ConnectionHandler::writerFct(char protocoltype, char packettype, int transmissionid, Packet *packet)
{
  std::tuple<char, char, int, Packet*> *tq = new std::tuple<char, char, int, Packet*>(protocoltype, packettype, transmissionid, packet);
  writeqmutex.lock();
  // add elment to queue
  writequeue.push(tq);
  writeqmutex.unlock();
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