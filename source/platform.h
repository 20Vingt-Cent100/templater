#pragma once

#ifdef __linux__
    #define PLATFORM_LINUX
#elif defined( __APPLE__)
    #define PLATFORM_APPLE
#elif defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS
#else
    #error "Unknown platform"
#endif