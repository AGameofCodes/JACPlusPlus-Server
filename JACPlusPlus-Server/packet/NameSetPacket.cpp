/* 
 * File:   NameSetPacket.cpp
 * Author: alex
 * 
 * Created on 19. Februar 2015, 16:43
 */

#include "NameSetPacket.h"

using std::string;

NameSetPacket::NameSetPacket() : Packet()
{
}

NameSetPacket::~NameSetPacket()
{
  delete vname;
  delete vrealname;
  delete vnick;
  delete vnick2;
  delete vnick3;
}

void NameSetPacket::read(Buf* b)
{
  vname = b->readString();
  vrealname = b->readString();
  vnick = b->readString();
  vnick2 = b->readString();
  vnick3 = b->readString();
}

void NameSetPacket::write(Buf *b)
{
  b->write(vname);
  b->write(vrealname);
  b->write(vnick);
  b->write(vnick2);
  b->write(vnick3);
}

//getter & setter
string *NameSetPacket::name()
{
  return vname;
}

void NameSetPacket::name(string *name)
{
  vname = name;
}

string *NameSetPacket::realname()
{
  return vrealname;
}

void NameSetPacket::realname(string *realname)
{
  vrealname = realname;
}

string *NameSetPacket::nick()
{
  return vnick;
}

void NameSetPacket::nick(string *nick)
{
  vnick = nick;
}

string *NameSetPacket::nick2()
{
  return vnick2;
}

void NameSetPacket::nick2(string *nick2)
{
  vnick2 = nick2;
}

string *NameSetPacket::nick3()
{
  return vnick3;
}

void NameSetPacket::nick3(string *nick3)
{
  vnick3 = nick3;
}