// test_LineReader.cpp 
// Created by Robin Rowe 2023-08-08
// MIT open source

#include <iostream>
#include "../LineReader.h"
using namespace std;

int main(int argc,char* argv[])
{	cout << "Testing LineReader" << endl;
	LineReader lineReader;
	if(!lineReader)
	{	cout << "LineReader failed on operator!" << endl;
		return 1;
	}
	cout << lineReader << endl;
	cout << "LineReader Passed!" << endl;
	return 0;
}
