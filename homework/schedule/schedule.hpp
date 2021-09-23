#pragma once

#include <chrono>
#include <functional>
#include <thread>
#include <string>

/* generic function */
template<typename FUNCTION, typename DURATION, typename... ARGS>
void schedule(FUNCTION function, DURATION time, ARGS&&... args) {
    std::this_thread::sleep_for(time);
    std::invoke(function, std::forward<ARGS>(args)...);             // function(std::forward<ARGS>(args)...);
}

/* overloaded functions */
void schedule(std::function<void()> func,
              std::chrono::seconds secs)
{
    std::this_thread::sleep_for(secs);
    func();
}

void schedule(std::function<void(int)> func,
              const std::chrono::seconds& secs,
              int value)
{
    std::this_thread::sleep_for(secs);
    func(value);
}

void schedule(std::function<void(std::string, double)> func,
              const std::chrono::seconds& secs,
              const std::string& str,
              double value)
{
    std::this_thread::sleep_for(secs);
    func(str, value);
}
