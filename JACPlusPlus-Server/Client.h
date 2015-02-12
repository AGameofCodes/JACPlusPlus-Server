/* 
 * File:   Client.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 15:19
 */

#ifndef CLIENT_H
#define	CLIENT_H

#include <string>
#include <list>

using std::string;
using std::list;

class Channel;

class Client
{
public:
  Client(string name, string nick);
  virtual ~Client();
  
  //channel management
  void join(Channel *c);
  void leave(Channel *c);
  void say(Channel *c, string *msg);
  bool isMemberOfChannel(Channel *c);
  
  //getter
  string getName();
  string getNick();
  list<Channel*> getChannels();
  
private:
  Client(const Client& orig);
  
  //var
  string *name;
  string *nick;
  list<Channel*> channels;
  
  //iterator
  typedef list<Channel*>::iterator chanIter;
};

#endif	/* CLIENT_H */

