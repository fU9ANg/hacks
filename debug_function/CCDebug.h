
#ifndef __CCDEBUG_H_
#define __CCDEBUG_H_

#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

#ifdef _DEBUG_FUNCTION_
    #define DEBUG_FUNCION \
    CCDebug dumpobj(__FILE__, typeid(this).name(), __func__, __LINE__)
#else
    #define DEBUG_FUNCION
#endif

class CCDebug {
public:
    CCDebug (std::string _file, std::string _class, std::string _func, int _line) 
        : filename_ (_file),
          classname_ (_class),
          funcname_ (_func),
          line_ (_line)
    {
        std::string tmpstr;
        tmpstr = ((_class.size()>=3 && _class.size() <=11) ? \
                 _class.substr (2) : \
                 ((_class.size()>=13 && _class.size() <=102) ? \
                  _class.substr (3) : \
                  ((_class.size()>=104 && _class.size() <=1003) ? \
                   _class.substr (4) : \
                   "unknown")));
        classname_ = tmpstr;
#ifdef __COCOS2DX__
        
#else
        std::cout << filename_ << ":" 
                  << line_<< " - " 
                  << classname_ << "::" 
                  << funcname_ << "()" 
                  << std::endl;
#endif
    }

    ~CCDebug () 
    {
#ifdef __COCOS2DX__
#else
        std::cout << filename_ << ":" 
                  << line_<< " - " 
                  << classname_ << "::~" 
                  << funcname_ << "()" 
                  << std::endl;
#endif
    }

private:
    CCDebug (const CCDebug& t);
    const CCDebug& operator= (const CCDebug&);


private:
    std::string  filename_;
    std::string  classname_;
    std::string  funcname_;
    int          line_;
};

#endif  // __CCDEBUG_H_
