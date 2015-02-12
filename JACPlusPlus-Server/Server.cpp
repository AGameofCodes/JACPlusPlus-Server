/* 
 * File:   Server.cpp
 * Author: jester
 * 
 * Created on February 12, 2015, 3:04 PM
 */

#include "Server.h"
#include <string>
#include <iostream>
#include <sys/socket.h>


Server::Server() 
{
    
}


unsigned int Server::start() 
{
   
}

//------------------------------------------------------------------------------
unsigned int Server::stopp() 
{
    
}


//------------------------------------------------------------------------------
unsigned int Server::run() 
{
    int socketfd;
    int portnumber;
    char buffer[256];
    struct sockadd serv_addr;
    int status;
    
    cout << "Waiting for incoming connection..." << endl;
    
    //    int socket(int domain, int type, int protocol);
    //    domain : The domain argument specifies a communication domain. In our case this value is AF_INET or AF_INET6 (the internet using ip4 or ip6) 
    //    type : The type of socket. In our case it is SOCK_STREAM (tcp) 
    //    protocol : The protocol to be used with the socket-type. In our case the right protocol is automatically choosen. 
    //    return value : The socket system call returns a socket descriptor. If the socket call fails, it returns -1. 
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        cout << "Error: Opening Socket!" << endl;
        return -1;
    }
    
    
    
    //int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen); 
    //sockfd : The socket descriptor the socket() call returns. 
    //addr : The address we want to listen on (localhost). 
    //addrlen : The lenght of this address. 
    //Return value : Like all the other calls it also returns an integer. If it's '0' the call succeeded, if it's -1, we got an error that will be stored in errno as usual. 
    //status = bind(socketfd, ai_a)
    
    
    
    
    while(1)
    {
        // let the socket listen to incoming connections
        
    }
}



//Server::Server(const Server& orig) 
//{
//    
//}

Server::~Server() 
{
}



