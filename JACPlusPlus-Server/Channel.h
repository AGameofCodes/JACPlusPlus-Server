/* 
 * File:   Channel.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 15:18
 */

#ifndef CHANNEL_H
#define	CHANNEL_H

#include <string>
#include <list>

using std::string;
using std::list;

class Client;

class Channel
{
public:
  Channel(string name);
  virtual ~Channel();

  //client management
  void addClient(Client *c);
  void removeClient(Client *c);
  bool isMember(Client *c);

  //getter
  list<Client*> getClients();
  string getName();
private:
  Channel(const Channel& orig) = delete;

  //vars
  string *name;
  list<Client*> clients;

  //iter
  typedef list<Client*>::iterator clientsIter;
};

#endif	/* CHANNEL_H */

