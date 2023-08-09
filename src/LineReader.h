// LineReader.h 
// Created by Robin Rowe 2023-08-08
// MIT open source

#ifndef LineReader_h
#define LineReader_h

#include <iostream>
#include <fstream>
#include <string>

class LineReader
{	LineReader(const LineReader&) = delete;
	void operator=(const LineReader&) = delete;
	std::ofstream os;
public:
	unsigned lineNo;
	std::string filename;
	~LineReader()
	{	os << "</body></html>\n";
	}
	LineReader()
	:	lineNo(0)
	{}
	bool operator!() const
	{	return os.fail();
	}
	bool Open(const std::string& path)
	{	filename = path;
		filename.append("/grok_book.html");
		os.open(filename);
		os << "<html><body>\n";
		return !os.fail();
	}
	bool Filter(const std::string& path);
	std::ostream& Print(std::ostream& os) const;
	std::istream& Input(std::istream& is);
};

inline
std::ostream& operator<<(std::ostream& os,const LineReader& lineReader)
{	return lineReader.Print(os);
}


inline
std::istream& operator>>(std::istream& is,LineReader& lineReader)
{	return lineReader.Input(is);
}

#endif
