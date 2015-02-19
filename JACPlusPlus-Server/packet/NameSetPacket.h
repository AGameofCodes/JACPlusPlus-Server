/* 
 * File:   LoginPacket.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 16:43
 */

#ifndef NAMESETPACKET_H
#define	NAMESETPACKET_H

#include "Packet.h"
#include <string>

class NameSetPacket : public Packet
{
public:
  NameSetPacket();
  virtual ~NameSetPacket();
  
  //getter & setter
  std::string *name();
  void name(std::string *name);
  std::string *realname();
  void realname(std::string *realname);
  std::string *nick();
  void nick(std::string *nick);
  std::string *nick2();
  void nick2(std::string *nick2);
  std::string *nick3();
  void nick3(std::string *nick3);
private:
  NameSetPacket(const NameSetPacket& orig) = delete;
  void read(Buf *b);
  void write(Buf *b);

  //vars
  std::string *vname;
  std::string *vrealname;
  std::string *vnick;
  std::string *vnick2;
  std::string *vnick3;
};

#endif	/* NAMESETPACKET_H */

