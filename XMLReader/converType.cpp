
// written by fU9ANg
// date: 2013

#include "converType.h"

#include <stdexcept>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int strSize = 256;

bool strToBool (const string &s)
{
	if (s=="0" || s=="false"){
		return false;
	}
	if (s=="1" || s=="true"){
		return true;
	}
	throw runtime_error ("Error converting string to bool, expected 0 or 1, found: " + s);
}

int strToInt (const string &s)
{
	char *endChar;
	int intValue= strtol (s.c_str(), &endChar, 10);
	
	if (*endChar!='\0') {
		throw runtime_error ("Error converting from string to int, found: " + s);
	}

	return (intValue);
}


float strToFloat (const string &s)
{
	char *endChar;
	float floatValue = static_cast<float> (strtod (s.c_str(), &endChar));
	
	if (*endChar!='\0') {
		throw runtime_error ("Error converting from string to float, found: " + s);
	}

	return (floatValue);
}

bool strToBool (const string &s, bool *b)
{
	if (s=="0" || s=="false") {
		*b= false;
		return (true);
	}
	if (s=="1" || s=="true") {
		*b= true;
		return (true);
	}
     
	return (false);
}

bool strToInt (const string &s, int *i)
{
	char *endChar;
	*i= strtol (s.c_str(), &endChar, 10);
	
	if (*endChar!='\0')
    {
		return (false);
	}
	return true;
}

bool strToFloat (const string &s, float *f)
{
	char *endChar;
	*f= static_cast<float> (strtod (s.c_str(), &endChar));
	
	if (*endChar!='\0') {
		return (false);
	}
	return (true);
}

string boolToStr (bool b)
{
	if (b) {
		return ("1");
	}
	else {
		return ("0");
	}
}

string intToStr (int i)
{
	char str[strSize];
	sprintf (str, "%d", i);
	return (str); 
}

string intToHex (int i)
{
	char str[strSize];
	sprintf (str, "%x", i);
	return (str);
}

string floatToStr (float f)
{
	char str[strSize];
	sprintf (str, "%.2f", f);
	return (str); 
}

string doubleToStr (double d)
{
	char str[strSize];
	sprintf (str, "%.2f", d);
	return (str); 
}
