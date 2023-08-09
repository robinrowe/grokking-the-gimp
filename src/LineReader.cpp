// LineReader.cpp
// Created by Robin Rowe 2023-08-08
// MIT open source

#include <string.h>
#include "LineReader.h"
using namespace std;

ostream& LineReader::Print(ostream& os) const
{	// to-do
	return os << "LineReader";
} 

istream& LineReader::Input(std::istream& is) 
{	// to-do
	return is;
}

const char* endNav = "<!--End of Navigation Panel-->";
const char* startNav = "<!--Navigation Panel-->";

bool LineReader::Filter(const std::string& path)
{	ifstream is;
	is.open(path);
	if(is.fail())
	{	return false;
	}
	bool isNav = true;
	string line;
	line.reserve(255);
	lineNo = 0;
	while(getline(is,line).good())
	{	lineNo++;
		if(strstr(line.c_str(),endNav))
		{	isNav = false;
			continue;
		}
		if(!isNav)
		{	if(strstr(line.c_str(),startNav))
			{	break;
			}
			os << line;
	}	}
	return !is.fail();
}	
