#include <chrono>
#include <iostream>

#define TIME_FUNC(func) {Timer __timer__(#func); func;}
#define TIME_FUNC_N(func,name) {Timer __timer__(name); func;}

struct Timer
{
    Timer(const char* name_)
    {
        name = name_;
        start_time = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        auto stop_time = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_time);
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(stop_time);
        std::cout << name << " took: " << (float)((end-start).count())/1000.0f << "ms" << std::endl;
    
    }
private:
    const char* name;
    std::chrono::high_resolution_clock::time_point start_time;
};
