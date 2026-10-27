#include "../headers/fileUtils.h"
#include <iostream>
#include "../headers/platform.h"
#include <cstdlib>
#include <variant>

//TODO: Support custom paths, and other protocols.
bool isTemplate(const std::string& templateType) {
    const std::filesystem::path configDirPath = getConfigDir();
    std::cout << configDirPath << "\n";
    return std::filesystem::exists(configDirPath / templateType);
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

//TODO: Find reliable rules to determine the protocol in use
int getTemplateProtocol(const std::string &templateType) {
    if (templateType.starts_with("https://")) {
        return REMOTE_PROTOCOL;
    }

    if (templateType.find('/') == std::variant_npos && templateType.find(':') == std::variant_npos)
        return DEFAULT_PROTOCOL;

    return UNSUPORTED_PROTOCOL;
}
