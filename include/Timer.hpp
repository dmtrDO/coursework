#ifndef TIMER_HPP
#define TIMER_HPP
#include <chrono>


class Timer
{
private:
    std::chrono::time_point<std::chrono::system_clock> start_point;
    std::chrono::time_point<std::chrono::system_clock> stop_point;
public:
    void start();
    void stop();
    double getElapsedTime();
};
#endif