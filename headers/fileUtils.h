#pragma once
#include <filesystem>
#include <string>

std::filesystem::path getConfigDir();
bool isTemplate(const std::string& templateType);