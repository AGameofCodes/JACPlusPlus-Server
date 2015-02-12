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
#include <sys/types.h>
#include <netdb.h>
#include <cstring>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

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
    int socketfd, newsocketfd;
    int portnumber;
    int response;
    char buffer[256];
    struct sockaddr_in server_addr, client_addr;
    unsigned int clientaddrlen;
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
    
    //memset((char *) &serv_addr, sizeof(serv_addr));
    portnumber = 5001;
    
  
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portnumber);
    
    status = bind(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if(status < 0)
    {
        cout << "ERROR: Binding not possible!" << endl;
        return -1;
    }
    
    
    //    int listen(int sockfd, int backlog); 
    //    sockfd : The socket descriptor the socket() call returns. 
    //    backlog : Our server can only handle 1 client at a time. What if more clients want to connect to your server at the same time? With backlog you can specify how many connections will be put in que. For example, if you set it to 5, and 7 connections to your server are made, 1 will fail, 1 will connect and the other 5 will be put "on hold". 
    cout << "Listen()ing for connections..." << endl;
    status  = listen(socketfd,5);
    if(status < 0)
    {
        cout << "Error: Listener!" << endl;
    }
    
    clientaddrlen = sizeof(client_addr);
    
    newsocketfd = accept(socketfd, (struct sockaddr *) &client_addr, &clientaddrlen);
    if(newsocketfd < 0)
    {
        cout << "Error: Accept!" << endl;
        return -1;       
    }
    
    status = read(newsocketfd, buffer, 255);
    if(status < 0)
    {
        cout << "Error: Reading from Socket!" << endl;
        return -1;
    }
    
    status = write(newsocketfd, "I got your message", 18);
    if(status < 0)
    {
        cout << "Error: Writing to Socket!" << endl;
        return -1;
    }
    
    
//    while(1)
//    {
//        newsocketfd = accept(socketfd, (struct sockaddr *) &client_addr, &clientaddrlen);
//        if(newsocketfd < 0)
//        {
//            cout << "Error: Accept!" << endl;
//            return -1;
//        }
//
//        pid_t pid = fork();
//        if(pid < 0)
//        {
//            cout << "What the fork?" << endl;
//            return -1;
//        }
//        
//        // Client Process started
//        if(pid == 0)
//        {
//            close(socketfd);
//            return -1;
//        }
//        else
//        {
//            close(newsocketfd);
//        }
//            
//    }
}



//Server::Server(const Server& orig) 
//{
//    
//}

Server::~Server() 
{
}



