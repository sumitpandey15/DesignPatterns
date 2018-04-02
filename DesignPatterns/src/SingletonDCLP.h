/*
Who - Sumit Pandey
When - 23-Mar-2018
For what - Singleton class
File - Singleton.h
Coding style - Google C++ coding standard
*/

#include <atomic>
#include <mutex>

class SingletonDCLP
{
public:
    static SingletonDCLP* getInstance();
private:
    SingletonDCLP();
    static std::atomic<SingletonDCLP*> m_sInastance;
    static std::mutex m_mMutex;
};