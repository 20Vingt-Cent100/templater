#include "../headers/logger.h"
#include <iostream>
#include "../headers/platform.h"

void logger::log(const level lv, const std::string& message) {
    switch (lv) {
        case ERROR:
            std::cout<<COLOR_RED + message + "\n";
            break;
        case WARNING:
            std::cout<<COLOR_YELLOW + message + "\n";
            break;
        case DEBUG:
            std::cout<<COLOR_CYAN + message + "\n";
            break;
        case INFO:
        case TRACE:
            std::cout<<message + "\n";
            break;
    }
}
