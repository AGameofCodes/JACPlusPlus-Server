/* 
 * File:   Server.cpp
 * Author: jester
 * 
 * Created on February 12, 2015, 3:04 PM
 */

#include "Server.h"
#include "../../libsockcpp/Socket.h"
#include "../../libsockcpp/IllegalStateException.h"
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace libsockcpp;
using std::string;

Server *Server::instance;

Server::Server() : t(NULL), enabled(false)
{

}

Server::Server(const Server& orig)
{

}

Server::~Server()
{
    
}

Server *Server::getInstance()
{
  if (Server::instance == NULL)
  {
    Server::instance = new Server();
  }
  return Server::instance;
}

void Server::start()
{
  if (enabled)
  {
    return;
  }
  enabled = true;

  t = new thread(&Server::run, this);
}

//------------------------------------------------------------------------------

void Server::stop()
{
  if (!enabled)
  {
    return;
  }
  enabled = false;
}

void Server::awaitTermination()
{
  if (t != NULL)
  {
    t->join();
    t == NULL;
  }
}


//------------------------------------------------------------------------------

void Server::run()
{
  std::cout << "Creating socket." << std::endl;
  Socket *socket = new Socket();
  std::cout << "Binding to port." << std::endl;
  socket->bind(5001);
  std::cout << "Start listening." << std::endl;
  socket->listen();

  char buffer[256];
  while (enabled)
  {
    try
    {
      std::cout << "Listening for connections ..." << std::endl;
      Socket *s = socket->accept();
      std::cout << "Reading." << std::endl;
      int read = s->read(buffer, 255);
      buffer[read] = '\0';
      std::cout << string(buffer) << std::endl;
      std::cout << "Responding" << std::endl;
      s->write("I got your message");
      s->close();
      delete s;
    }
    catch (IllegalStateException &e)
    {
      std::cerr << e.what() << std::endl;
      break;
    }
  }
  socket->close();
}