/* 
 * File:   Channel.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 15:18
 */

#include "Channel.h"

Channel::Channel(string name) : name(new string(name))
{
}

Channel::~Channel()
{
  delete name;
}

//client management

void Channel::addClient(Client *c)
{
  if (isMember(c))
  {
    return;
  }

  clients.push_back(c);
}

void Channel::removeClient(Client *c)
{
  for (clientsIter it = clients.begin(); it != clients.end(); it++)
  {
    if (*it == c)
    {
      //todo remove it;

      return;
    }
  }
}

bool Channel::isMember(Client *c)
{
  for (clientsIter it = clients.begin(); it != clients.end(); it++)
  {
    if (*it == c)
    {
      return true;
    }
  }
  return false;
}

//getter

list<Client*> Channel::getClients()
{
  //todo return a copy of this
  return clients;
}

string Channel::getName()
{
  return string(*name);
}

