#include <iostream>
#include <chrono>

int main() {
    // Get the current time_point using system_clock
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

    // Get the time_point 1 hour from now
    std::chrono::system_clock::time_point one_hour_from_now = now + std::chrono::hours(1);
    return 0;
}