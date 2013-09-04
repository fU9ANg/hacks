
#ifndef _CCGS_CONVERSION_H_
#define _CCGS_CONVERSION_H_

#include <string>

using std::string;


extern bool  strToBool(const string &s);
extern int   strToInt(const string &s);
extern float strToFloat(const string &s); 

extern bool strToBool(const string &s, bool *b);
extern bool strToInt(const string &s, int *i);
extern bool strToFloat(const string &s, float *f);

extern string boolToStr(bool b);
extern string intToStr(int i);
extern string intToHex(int i);
extern string floatToStr(float f);
extern string doubleToStr(double f);


#endif  // _CCGS_CONVERSION_H
