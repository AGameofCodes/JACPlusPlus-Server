/* 
 * File:   PacketFactory.cpp
 * Author: alex
 * 
 * Created on 19. Februar 2015, 02:38
 */

#include "PacketFactory.h"

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
  //init map<char, Packetclass or so>
}

Packet *PacketFactory::create(char type)
{
  return nullptr;
}

