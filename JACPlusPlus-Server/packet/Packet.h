/* 
 * File:   Packet.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 01:48
 */

#ifndef PACKET_H
#define	PACKET_H

#include "../../../libanoi/Buf.h"

class Packet
{
public:
  Packet();
  Packet(const Packet& orig) = delete;
  virtual ~Packet();
  static Packet* create();
  
  virtual void read(Buf *b) = 0;
  virtual void write(Buf *b) = 0;
private:

};

#endif	/* PACKET_H */

