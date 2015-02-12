/* 
 * File:   Server.h
 * Author: jester
 *
 * Created on February 12, 2015, 3:04 PM
 */

#ifndef SERVER_H
#define	SERVER_H

//using std::string;

using namespace std;

class Server
{
private:
  static Server *instance;
  Server();
  Server(const Server& orig);
  virtual ~Server();
public:

  static Server *getInstance();
  unsigned int start();
  unsigned int stop();
  unsigned int run();

};

#endif	/* SERVER_H */

