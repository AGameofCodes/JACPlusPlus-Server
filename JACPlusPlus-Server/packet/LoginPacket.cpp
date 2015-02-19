/* 
 * File:   LoginPacket.cpp
 * Author: alex
 * 
 * Created on 19. Februar 2015, 16:43
 */

#include "LoginPacket.h"

using std::string;

LoginPacket::LoginPacket() : Packet()
{
}

LoginPacket::~LoginPacket()
{
  delete vname;
  delete vrealname;
  delete vnick;
  delete vnick2;
  delete vnick3;
}

void LoginPacket::read(Buf* b)
{
  vname = b->readString();
  vrealname = b->readString();
  vnick = b->readString();
  vnick2 = b->readString();
  vnick3 = b->readString();
}

void LoginPacket::write(Buf *b)
{
  b->write(vname);
  b->write(vrealname);
  b->write(vnick);
  b->write(vnick2);
  b->write(vnick3);
}

//getter & setter
string *LoginPacket::name()
{
  return vname;
}

void LoginPacket::name(string *name)
{
  vname = name;
}

string *LoginPacket::realname()
{
  return vrealname;
}

void LoginPacket::realname(string *realname)
{
  vrealname = realname;
}

string *LoginPacket::nick()
{
  return vnick;
}

void LoginPacket::nick(string *nick)
{
  vnick = nick;
}

string *LoginPacket::nick2()
{
  return vnick2;
}

void LoginPacket::nick2(string *nick2)
{
  vnick2 = nick2;
}

string *LoginPacket::nick3()
{
  return vnick3;
}

void LoginPacket::nick3(string *nick3)
{
  vnick3 = nick3;
}