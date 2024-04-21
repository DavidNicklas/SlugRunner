#pragma once


#include <mutex>

template<class T>
class Singleton
{
public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;

    static T* GetInstance();

protected:
    Singleton() {}
    virtual ~Singleton() {}

private:
    static T* instance;
    static std::mutex mutex;

};

template<class T>
T* Singleton<T>::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr)
    {
        instance = new T();
    }

    return instance;
}
