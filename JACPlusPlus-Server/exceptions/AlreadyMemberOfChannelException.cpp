/* 
 * File:   AlreadyMemberOfChannelException.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 17:27
 */

#include "AlreadyMemberOfChannelException.h"

AlreadyMemberOfChannelException::AlreadyMemberOfChannelException(Client *client, Channel* channel) : ChatException(), client(client), channel(channel)
{
}

AlreadyMemberOfChannelException::AlreadyMemberOfChannelException(const AlreadyMemberOfChannelException& orig)
{
}

//AlreadyMemberOfChannelException::~AlreadyMemberOfChannelException()
//{
//}

Client *AlreadyMemberOfChannelException::getClient()
{
  return client;
}
Channel *AlreadyMemberOfChannelException::getChannel()
{
  return channel;
}