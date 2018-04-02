/*
Who - Sumit Pandey
When - 23-Mar-2018
For what - Singleton class
File - Singleton.h
Coding style - Google C++ coding standard
*/

#include <mutex>

class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton();
    static Singleton* m_sInastance;
    static std::mutex m_mMutex;
};