/* 
 * File:   Client.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 15:19
 */

#include "Client.h"
#include "exceptions/NotMemberOfChannelException.h"

Client::Client(string name, string nick) : name(new string(name)), nick(new string(nick))
{
}

Client::~Client()
{
  delete name;
  delete nick;
}

void Client::join(Channel *c)
{
  //notify join
}

void Client::leave(Channel *c)
{
  
  
  //notify leave
}

void Client::say(Channel *c, string *msg)
{
  if(!isMemberOfChannel(c))
  {
    throw NotMemberOfChannelException(this, c);
  }
  
  //todo write
}

bool Client::isMemberOfChannel(Channel *c)
{
  for(chanIter it = channels.begin(); it != channels.end(); it++)
  {
    if(*it == c)
    {
      return true;
    }
  }
  return false;
}

//getter

string Client::getName()
{
  return string(*name);
}

string Client::getNick()
{
  return string(*nick);
}

list<Channel*> Client::getChannels()
{
  //todo return copy of list
  return channels;
}