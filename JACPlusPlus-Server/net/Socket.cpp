/* 
 * File:   Socket.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 16:38
 */

#include "Socket.h"
#include <sys/socket.h>
#include <netdb.h>

Socket::Socket() : Socket(AF_INET, SOCK_STREAM, 0)
{

}

Socket::Socket(int domain, int type, int protocol) : domain(domain), type(type), protocol(protocol)
{

}

Socket::Socket(int sockfd, int domain, int type, int protocol, Status status, sockaddr_in *localEndPoint, sockaddr_in *remoteEndPoint)
: Socket(domain, type, protocol), status(status), localEndPoint(localEndPoint), remoteEndPoint(remoteEndPoint)
{

}

Socket::Socket(const Socket& orig)
{
}

Socket::~Socket()
{
  if (localEndPoint != NULL)
  {
    delete localEndPoint;
    localEndPoint = NULL;
  }
  if (remoteEndPoint != NULL)
  {
    delete remoteEndPoint;
    remoteEndPoint = NULL;
  }
}

void Socket::bind(short port)
{
  bind(INADDR_ANY, port);
}

void Socket::bind(int ip, short port)
{
  initSocket();
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &1, sizeof (int));

  localEndPoint = calloc(1, sizeof(sockaddr_in));
  //  bzero((void *) localEndPoint, sizeof (sockaddr_in));
  localEndPoint->sin_family = AF_INET;
  localEndPoint->sin_addr.s_addr = ip;
  localEndPoint->sin_port = htons(port);

  bind(sockfd, (struct sockaddr *) localEndPoint, sizeof (sockaddr_in));

  status = Status.BOUND;
}

void Socket::listen()
{
  listen(50);
}

void Socket::listen(int backlog)
{
  if (status != Status.BOUND)
  {
    //todo throw illegal state exception
    return;
  }
  listen(sockfd, backlog);
  
  status = Status.LISTENING;
}

Socket *Socket::accept()
{
  if (status != Status.BOUND)
  {
    //todo throw illegal state exception
    return NULL;
  }
  
  struct sockaddr_in *cli_addr = calloc(1, sizeof(sockaddr_in));
  int clilen = sizeof (cli_addr);
  int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

  Socket *s = new Socket(newsockfd, domain, type, status, localEndPoint, cli_addr);
  
  return s;
}

void Socket::initSocket()
{
  if (status != Status.UNINITIZIALIZED)
  {
    //todo throw illegal state exception
    return;
  }

  //set state
  status = Status.INITIZIALIZED;

  //init socket
  sockfd = socket(domain, type, protocol);
  if (sockfd == -1)
  {
    //todo throw socket exception
  }
}
