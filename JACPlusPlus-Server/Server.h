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
  virtual ~Server();
  void run();
public:
  Server(const Server& orig) = delete;
  
  static Server *getInstance();
  void start();
  void stop();
  void awaitTermination();

};

#endif	/* SERVER_H */

