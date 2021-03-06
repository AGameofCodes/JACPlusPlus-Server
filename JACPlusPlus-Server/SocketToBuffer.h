/* 
 * File:   SocketToBuffer.h
 * Author: jester
 *
 * Created on February 18, 2015, 9:10 PM
 */

#ifndef SOCKETTOBUFFER_H
#define	SOCKETTOBUFFER_H


#include "../../libsockcpp/Socket.h"
#include "../../libsockcpp/IllegalStateException.h"
#include "../../libanoi/Buf.h"
#include <string>

class SocketToBuffer
{
public:
  SocketToBuffer(libsockcpp::Socket *s);
  virtual ~SocketToBuffer();

  void read();
  Buf *getBuffer();
private:
  SocketToBuffer(const SocketToBuffer& orig) = delete;

  Buf *b;
  libsockcpp::Socket *s;


};

#endif	/* SOCKETTOBUFFER_H */

