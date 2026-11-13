#include "../headers/fileUtils.h"
#include <iostream>
#include "../headers/platform.h"
#include <cstdlib>

//TODO: Support custom paths, and other protocols.
bool isTemplate(const std::string& templateType) {
    const std::filesystem::path configDirPath = getConfigDir();
    const std::filesystem::path templateTypePath = configDirPath / templateType;

    //TODO: Rework this checking function.
    return std::filesystem::exists(templateTypePath) && std::filesystem::exists(templateTypePath / (templateType +".template"));
}

bool isFilePath(const std::string& str) {
#if defined(PLATFORM_LINUX) || defined(PLATFORM_APPLE)
    if (str.starts_with("./") || str.starts_with('/') || str.starts_with("~/") || str.starts_with("../"))
        return true;
#elif defined(PLATFORM_WINDOWS)
#endif
    return false;
}

std::filesystem::path getCWD() {
    return std::filesystem::current_path();
}

std::filesystem::path getConfigDir() {
    const char* envPath = nullptr;
#if defined(PLATFORM_LINUX)
    if (envPath = std::getenv("XDG_CONFIG_HOME"); !envPath) {
        envPath = std::getenv("HOME");
    }
#elif defined(PLATFORM_APPLE)
        auto envPath = std::getenv("HOME");
#elif defined(PLATFORM_WINDOWS)
        auto envPath = std::getenv("APPDATA")
#endif

    std::filesystem::path p{envPath};

#if defined(PLATFORM_LINUX)
    p /= ".config";
#elif defined(PLATFORM_APPLE)
    p /= "Library/Application Support"
#endif

    return p / "templater";
}
