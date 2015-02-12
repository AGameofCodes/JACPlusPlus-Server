/* 
 * File:   NotMemberOfChannelException.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 17:16
 */

#ifndef NOTMEMBEROFCHANNELEXCEPTION_H
#define	NOTMEMBEROFCHANNELEXCEPTION_H

class NotMemberOfChannelException : public ChatException
{
public:
  NotMemberOfChannelException();
  NotMemberOfChannelException(const NotMemberOfChannelException& orig);
  virtual ~NotMemberOfChannelException();
private:

};

#endif	/* NOTMEMBEROFCHANNELEXCEPTION_H */

