//===============================================
#ifndef _GFFT_
#define _GFFT_
//===============================================
#include <iostream>
#include <string>
//===============================================
using namespace std;
//===============================================
class GFFT {
private:
    GFFT();
    
public:
    ~GFFT();
    static GFFT* Instance();
    
public:
    void setData(const string& data);
    void showData() const;
    
private:
    static GFFT* m_instance;
    string m_data;
};
//===============================================
#endif
//===============================================
