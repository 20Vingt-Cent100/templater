#pragma once
#include <string>

struct Arguments {
    std::string path{"./"};
    std::string templateType;
    std::string templateName;
};

Arguments argsParser(int argc, char* argv[]);
Arguments argsParserV2(int argc, char* argv[]);

enum TemplateProtocol {
    DEFAULT_PROTOCOL,
    PATH_PROTOCOL,
    REMOTE_PROTOCOL,
    UNSUPPORTED_PROTOCOL
};

TemplateProtocol getTemplateProtocol(const std::string& templateType);
