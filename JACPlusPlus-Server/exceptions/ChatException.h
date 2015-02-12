/* 
 * File:   ChatException.h
 * Author: alex
 *
 * Created on 12. Februar 2015, 17:15
 */

#ifndef CHATEXCEPTION_H
#define	CHATEXCEPTION_H

using std::exception;

class ChatException : public exception
{
public:
  ChatException();
  ChatException(const ChatException& orig);
//  virtual ~ChatException();
private:

};

#endif	/* CHATEXCEPTION_H */

