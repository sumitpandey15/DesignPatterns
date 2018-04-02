/*
Who - Sumit Pandey
When - 23-Mar-2018
For what - Singleton class
File - Singleton.cpp
Coding style - Google C++ coding standard
*/

#include "Singleton.h"

Singleton* Singleton::m_sInastance;
std::mutex Singleton::m_mMutex;

Singleton::Singleton()
{
}

Singleton* Singleton::getInstance()
{
    m_mMutex.lock();
    if (m_sInastance == nullptr)
    {
        m_sInastance = new Singleton();
    }
    m_mMutex.unlock();

    return m_sInastance;
}
