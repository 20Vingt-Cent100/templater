#include "../headers/yamlParser.h"
#include "../headers/logger.h"
#include <iostream>
#include <fstream>

void parseYaml(const std::filesystem::path& filePath) {
    std::ifstream file{filePath};

    if (!file.is_open()) {
        logger::log(logger::ERROR, "Could not open file: " + filePath.string());
    }

    std::string line{};

    while (std::getline(file, line)) {
        logger::log(logger::TRACE, line);
    }
}
