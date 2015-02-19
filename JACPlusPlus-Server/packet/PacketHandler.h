/* 
 * File:   PacketHandler.h
 * Author: alex
 *
 * Created on 19. Februar 2015, 13:59
 */

#ifndef PACKETHANDLER_H
#define	PACKETHANDLER_H

class PacketHandler
{
public:
  PacketHandler();
  virtual ~PacketHandler();
  
  //void handle<Packetname>(<packetname> *p);
private:
  PacketHandler(const PacketHandler& orig) = delete;
};

#endif	/* PACKETHANDLER_H */

