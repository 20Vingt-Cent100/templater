#pragma once
#include <string>

struct Arguments {
    std::string path{"./"};
    std::string templateType;
    std::string templateName;
};

Arguments argsParser(int argc, char* argv[]);

// inline int DEFAULT_PROTOCOL = 0;
// inline int PATH_PROTOCOL = 1;
// inline int REMOTE_PROTOCOL = 2;
// inline int UNSUPORTED_PROTOCOL = -1;

enum TemplateProtocol {
    DEFAULT_PROTOCOL,
    PATH_PROTOCOL,
    REMOTE_PROTOCOL,
    UNSUPPORTED_PROTOCOL
};

TemplateProtocol getTemplateProtocol(const std::string& templateType);
