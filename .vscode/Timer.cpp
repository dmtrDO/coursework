#include <iostream>
#include <chrono>
#include <thread>

class Timer {
private:
    std::chrono::time_point<std::chrono::system_clock> start_point;
    std::chrono::time_point<std::chrono::system_clock> stop_point;

public:
    void start() {
        start_point = std::chrono::system_clock::now();
    }

    void stop() {
        stop_point = std::chrono::system_clock::now();
    }

    double getElapsedTime() {
        std::chrono::duration<double> elapsed_seconds = stop_point - start_point;
        return elapsed_seconds.count();
    }
};

int main() {
    Timer timer;

    std::cout << "Starting timer..." << std::endl;
    timer.start();

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::seconds(3));

    timer.stop();
    double elapsedTime = timer.getElapsedTime();

    std::cout << "Elapsed time: " << elapsedTime << " seconds" << std::endl;

    return 0;
}