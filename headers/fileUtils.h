#pragma once
#include <filesystem>
#include <string>


std::filesystem::path getCWD();
std::filesystem::path getConfigDir();
bool isTemplate(const std::string& templateType);
bool isFilePath(const std::string& str);