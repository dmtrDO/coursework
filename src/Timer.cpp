#include "Timer.hpp"


void Timer::start()
{
    start_point = std::chrono::system_clock::now();
}
void Timer::stop()
{
    stop_point = std::chrono::system_clock::now();
}
double Timer::getElapsedTime()
{
    std::chrono::duration<double> elapsed_seconds = stop_point - start_point;
    return elapsed_seconds.count();
}