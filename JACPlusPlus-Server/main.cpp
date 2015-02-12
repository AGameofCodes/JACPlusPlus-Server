/* 
 * File:   main.cpp
 * Author: alex
 * 
 * Created on 12. Februar 2015, 14:16
 */

#include <iostream>

#include "Server.h"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
  Server::getInstance()->start();
}
