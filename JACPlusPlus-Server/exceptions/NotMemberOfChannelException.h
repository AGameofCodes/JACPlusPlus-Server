/* 
 * File:   NotMemberOfChannelException.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 17:16
 */

#ifndef NOTMEMBEROFCHANNELEXCEPTION_H
#define	NOTMEMBEROFCHANNELEXCEPTION_H

class ChatException;

class NotMemberOfChannelException : public ChatException
{
public:
  NotMemberOfChannelException(Client *client, Channel* channel);
  NotMemberOfChannelException(const NotMemberOfChannelException& orig);
  virtual ~NotMemberOfChannelException();
  
  Client *getClient();
  Channel *getChannel();
private:
  Client *client;
  Channel *channel;
};

#endif	/* NOTMEMBEROFCHANNELEXCEPTION_H */

