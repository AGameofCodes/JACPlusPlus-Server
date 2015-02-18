/* 
 * File:   SocketToBuffer.cpp
 * Author: jester
 * 
 * Created on February 18, 2015, 9:10 PM
 */

#include "SocketToBuffer.h"

SocketToBuffer::SocketToBuffer(libsockcpp::Socket *s) : s(s), b(new Buf())
{
  
}

SocketToBuffer::SocketToBuffer(const SocketToBuffer& orig) 
{
  
}

//------------------------------------------------------------------------------

SocketToBuffer::~SocketToBuffer() 
{
  delete b;
}

void SocketToBuffer::read() 
{
  char buffer[256];
  int len = s->read(buffer, 256);
  
  b->write(buffer, len);
}


//------------------------------------------------------------------------------

Buf *SocketToBuffer::getBuffer()
{
  return b;
}