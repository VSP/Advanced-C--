#ifndef __Exceptions_h__
#define __Exceptions_h__
/*
//#include "Exceptions.h"
#include <iostream>
#include <exception>
using namespace std;

class deadPlayerException: public exception
{
	virtual const char* what() const throw()
	{
		return "You have died painfully!";
	}

}deadpc;

class UnknownCmdException: public exception
{
	virtual const char* what() const throw()
	{
		return "DOSNOTCOMPT";
	}

}ucmd;
*/
#include <iostream>
#include <stdexcept>
//Lecture had these kind of structs
struct DeadPCError :public std::runtime_error{
DeadPCError(std::string msg) : std::runtime_error(msg.c_str()){}
};

struct UCMD : public std::runtime_error{
UCMD(std::string msg) : std::runtime_error(msg.c_str()){}
};
#endif