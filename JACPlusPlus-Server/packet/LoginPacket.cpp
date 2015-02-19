/* 
 * File:   LoginPacket.cpp
 * Author: alex
 * 
 * Created on 19. Februar 2015, 16:43
 */

#include "LoginPacket.h"

using std::string;

std::string *LoginPacket::getMagicNO()
{
  return new std::string("\x00\x01\x02JAC++");
}

LoginPacket::LoginPacket() : Packet()
{
}

LoginPacket::~LoginPacket()
{
  delete vhello;
}

void LoginPacket::read(Buf* b)
{
  vhello = b->readString();
}

void LoginPacket::write(Buf *b)
{
  b->write(vhello);
}

//getter & setter
string *LoginPacket::hello()
{
  return vhello;
}

void LoginPacket::hello(string *hello)
{
  vhello = hello;
}
