/* 
 * File:   NotMemberOfChannelException.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 17:16
 */

#include "NotMemberOfChannelException.h"

NotMemberOfChannelException::NotMemberOfChannelException(Client *client, Channel* channel) : ChatException(), client(client), channel(channel)
{
}

NotMemberOfChannelException::NotMemberOfChannelException(const NotMemberOfChannelException& orig)
{
}

NotMemberOfChannelException::~NotMemberOfChannelException()
{
}

Client *NotMemberOfChannelException::getClient()
{
  return client;
}
Channel *NotMemberOfChannelException::getChannel()
{
  return channel;
}
