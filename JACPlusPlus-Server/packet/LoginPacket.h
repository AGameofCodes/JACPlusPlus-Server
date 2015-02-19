/* 
 * File:   LoginPacket.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 16:43
 */

#ifndef LOGINPACKET_H
#define	LOGINPACKET_H

#include "Packet.h"
#include <string>

class LoginPacket : public Packet
{
public:
  LoginPacket();
  virtual ~LoginPacket();
  
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
  LoginPacket(const LoginPacket& orig) = delete;
  void read(Buf *b);
  void write(Buf *b);

  //vars
  std::string *vname;
  std::string *vrealname;
  std::string *vnick;
  std::string *vnick2;
  std::string *vnick3;
};

#endif	/* LOGINPACKET_H */

