#pragma once
#include <string>

struct Arguments {
    std::string path{"./"};
    std::string templateType;
    std::string templateName;
};

Arguments argsParser(int argc, char* argv[]);
