/* 
 * File:   PacketFactory.cpp
 * Author: alex
 * 
 * Created on 19. Februar 2015, 02:38
 */

#include "PacketFactory.h"

#define MAPPAIR(x, y) pair<char, PACKET_CTOR_TYPE>(x, y)

using std::pair;

PacketFactory *PacketFactory::instance;

PacketFactory *PacketFactory::getInstance()
{
  if (PacketFactory::instance == nullptr)
  {
    instance = new PacketFactory();
  }
  return PacketFactory::instance;
}

PacketFactory::PacketFactory()
{
  //list a packets here
//  packetctormap.insert(MAPPAIR(0, &Packet::create));
}

Packet *PacketFactory::create(char type)
{
  mapiter it = packetctormap.find(type);
  return it != packetctormap.end() ? (*it->second)() : nullptr;
}

