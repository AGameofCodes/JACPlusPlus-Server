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
  static std::string *getMagicNO();
  
  LoginPacket();
  virtual ~LoginPacket();
  
  //getter & setter
  std::string *hello();
  void hello(std::string *hello);
private:
  LoginPacket(const LoginPacket& orig) = delete;
  void read(Buf *b);
  void write(Buf *b);

  //vars
  std::string *vhello;
};

#endif	/* LOGINPACKET_H */

