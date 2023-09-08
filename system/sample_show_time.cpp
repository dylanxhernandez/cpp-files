#include <iostream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>

int main() {
    // Get the current time in the system's timezone
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert the time to a string in your desired format
    std::tm* localTime = std::localtime(&currentTime);
    std::stringstream ss;
    ss << "Current Date & Time: ";
    ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S %Z");

    // Print the result to the console
    std::cout << ss.str() << std::endl;

    return 0;
}

