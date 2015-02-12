/* 
 * File:   Socket.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 16:38
 */

#ifndef SOCKET_H
#define	SOCKET_H

class Socket
{
public:
  Socket();
  Socket(const Socket& orig);
  virtual ~Socket();
  
  bind();
  listen();
  accept();
  
  connect();
  close();
  
private:

};

#endif	/* SOCKET_H */

