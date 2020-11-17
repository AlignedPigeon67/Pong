#include "FrameTimer.h"

using namespace std::chrono;

FrameTimer::FrameTimer()
{
    lastFrameTime = steady_clock::now();
}

float FrameTimer::Mark()
{
    const auto old = lastFrameTime;
    lastFrameTime = steady_clock::now();
    const duration<float> frameTime = lastFrameTime - old;
    return frameTime.count();
}
