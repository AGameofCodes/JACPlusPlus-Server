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
        static Server *Server1;
        Server();
        Server(const Server& orig);
        virtual ~Server();
    public:
        unsigned int start();
        unsigned int stopp();
        unsigned int run();
     
};

#endif	/* SERVER_H */

