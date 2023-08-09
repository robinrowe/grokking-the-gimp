// grok.cpp 
// Created by Robin Rowe 2023-08-08
// MIT open source

#include <string>
#include <iostream>
#include <filesystem>
#include <set>
#include "LineReader.h"
using namespace std;
namespace fs = std::filesystem;

void Usage()
{	cout << "Usage: grok " << endl;
}

enum
{	ok,
	invalid_args,
	invalid_path,
	invalid_file
};

#define STOP(x) std::cout << #x << std::endl; return x

int main(int argc,char* argv[])
{	cout << "grok starting..." << endl;
#if 0
	if(argc < 1)
	{	Usage();
		return invalid_args;
	}
#endif
    string path = "/code/github/grokking-the-gimp/original";
	LineReader lineReader;
	if(!lineReader.Open(path))
	{	cout << "Cannot open " << lineReader.filename << endl;
		STOP(invalid_path);
	}
	cout << "Output to " << lineReader.filename << endl;
	string filename;
	filename.reserve(255);
	for(unsigned i=1;i<=90;i++)
	{	filename = path;
		filename.append("/node");
		filename.append(to_string(i));
		filename.append(".html");
		if(lineReader.Filter(filename))
		{	cout << filename << ": " << lineReader.lineNo << endl;
		}
		else
		{	cout << "Cannot filter " << filename << endl;
			STOP(invalid_file);
	}	}
	cout << "grok done!" << endl;
	STOP(ok);
}

/*
 	set<fs::path> sorted_by_name;
	for (auto &entry : fs::directory_iterator(path))
    {	sorted_by_name.insert(entry.path());
	}

    std::string ext(".txt");
    for (auto& p : fs::recursive_directory_iterator(constructed_path_str_dbg))
    {
        if (p.path().extension() == ext)  

	for (auto &filename : sorted_by_name)
    {	cout << filename << endl;
	}

git clone https://github.com/jalbertbowden/grokking-the-gimp

Rename annoying image original/background.gif to anything else (to block it in html)

Write JS script to cat append from node1.html to node90.html to create one.html file that combines contents of all the nodeN.html files

Write JS script that reads one.html file line by line and outputs one-edit.html file that has removed any text between these lines:

<!--Navigation Panel-->
<!--End of Navigation Panel-->

Test by viewing one-edit.html
*/