#pragma once
#include <filesystem>
#include <string>

std::filesystem::path getConfigDir();
bool isTemplate(const std::string& templateType);

inline int DEFAULT_PROTOCOL = 0;
inline int PATH_PROTOCOL = 1;
inline int REMOTE_PROTOCOL = 2;
inline int UNSUPORTED_PROTOCOL = -1;

int getTemplateProtocol(const std::string& templateType);