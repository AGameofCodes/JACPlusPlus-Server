/* 
 * File:   Server.h
 * Author: jester
 *
 * Created on February 12, 2015, 3:04 PM
 */

#ifndef SERVER_H
#define	SERVER_H

//using std::string;

#include <thread>

using std::thread;

class Server
{
private:
  static Server *instance;
  thread *t;
  bool enabled;

  Server();
  Server(const Server& orig);
  virtual ~Server();
  void run();
public:
  static Server *getInstance();
  void start();
  void stop();
  void awaitTermination();

};

#endif	/* SERVER_H */

