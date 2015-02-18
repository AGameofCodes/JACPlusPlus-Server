/* 
 * File:   ConnectionHandling.cpp
 * Author: jester
 * 
 * Created on February 18, 2015, 5:48 PM
 */

#include <thread>
#include "ConnectionHandling.h"


ConnectionHandling::ConnectionHandling(libsockcpp::Socket *socket) 
{
  
}

ConnectionHandling::ConnectionHandling(const ConnectionHandling& orig) 
{
}

ConnectionHandling::~ConnectionHandling() 
{
}



void ConnectionHandling::start() 
{
  if(enabled)
  {
    return;
  }
  enabled = true;
  
  t = new std::thread(&ConnectionHandling::run, this);
  
}

void ConnectionHandling::run() 
{
  
}

void ConnectionHandling::stop() 
{
  if(!enabled)
  {
    return;
  }
  enabled = false;
}

void ConnectionHandling::awaitTermination()
{
  if(t != NULL)
  {
    t->join();
    t = NULL;
  }
}