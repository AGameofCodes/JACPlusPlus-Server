/* 
 * File:   PacketFactory.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 02:38
 */

#ifndef PACKETFACTORY_H
#define	PACKETFACTORY_H

#include "Packet.h"

class PacketFactory
{
public:
  static PacketFactory *getInstance();
  
  PacketFactory(const PacketFactory& orig) = delete;
  virtual ~PacketFactory() = delete;
  
  Packet *create(char type);
private:
  static PacketFactory *instance;
  
  PacketFactory();
};

#endif	/* PACKETFACTORY_H */

