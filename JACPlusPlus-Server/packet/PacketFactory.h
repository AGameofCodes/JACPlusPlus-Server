/* 
 * File:   PacketFactory.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 02:38
 */

#ifndef PACKETFACTORY_H
#define	PACKETFACTORY_H

#include "Packet.h"
#include <map>

#define PACKET_CTOR_TYPE Packet*(*)()  //returntype(*function point)(paramtypes)

class PacketFactory
{
public:
  static PacketFactory *getInstance();
  
  virtual ~PacketFactory() = delete;
  
  Packet *create(char type);
private:
  static PacketFactory *instance;
  std::map<char, PACKET_CTOR_TYPE> packetctormap; //Packet*(*)() lol
  typedef std::map<char, PACKET_CTOR_TYPE>::iterator mapiter; //netbeans can't find the iterator but it compiles  // love it
  
  PacketFactory();
  PacketFactory(const PacketFactory& orig) = delete;
};

#endif	/* PACKETFACTORY_H */

