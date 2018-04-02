/*
Who - Sumit Pandey
When - 23-Mar-2018
For what - Singleton class
File - Singleton.cpp
Coding style - Google C++ coding standard
*/

#include "SingletonDCLP.h"

std::atomic<SingletonDCLP*> SingletonDCLP::m_sInastance;
std::mutex SingletonDCLP::m_mMutex;

SingletonDCLP::SingletonDCLP()
{
}

SingletonDCLP* SingletonDCLP::getInstance()
{
    SingletonDCLP* tmp = m_sInastance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);
    if (nullptr == tmp)
    {
        std::lock_guard<std::mutex> lock(m_mMutex);
        if (nullptr == tmp)
        {
            tmp = new SingletonDCLP();
            std::_Atomic_thread_fence(std::memory_order_release);
            m_sInastance.store(tmp, std::memory_order_relaxed);
        }
    }
    return m_sInastance;
}
