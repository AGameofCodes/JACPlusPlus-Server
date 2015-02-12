/* 
 * File:   AlreadyMemberOfChannelException.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 17:27
 */

#ifndef ALREADYMEMBEROFCHANNELEXCEPTION_H
#define	ALREADYMEMBEROFCHANNELEXCEPTION_H

#include "ChatException.h"

class AlreadyMemberOfChannelException : public ChatException
{
public:
  AlreadyMemberOfChannelException(Client *client, Channel* channel);
  AlreadyMemberOfChannelException(const AlreadyMemberOfChannelException& orig);
//  virtual ~AlreadyMemberOfChannelException();
  
  Client *getClient();
  Channel *getChannel();
private:
  Client *client;
  Channel *channel;

};

#endif	/* ALREADYMEMBEROFCHANNELEXCEPTION_H */

