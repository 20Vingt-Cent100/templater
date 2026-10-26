#include "argsParser.h"
#include <iostream>
#include <variant>

Arguments argsParser(const int argc, char* argv[]) {
    std::string path{};
    std::string templateType{};
    std::string templateName{};

    for (int i = 1; i < argc; i++) {
        if (std::string arg{argv[i]}; arg == "--path" || arg == "-p") {
            if (i + 1 >= argc) {
                std::cout << "No arguments provided for: --path.\n";
                break;
            }
            path = argv[i + 1];
            i++;
            continue;
        }

        if (argv[i][0] != '-') {
            std::string templateTypeName{argv[i]};
            const size_t separatorPos = templateTypeName.find('@');

            if (separatorPos == std::variant_npos) {
                std::cout << "Invalid argument : " << templateTypeName << "\n";
                break;
            }

            templateType = templateTypeName.substr(0, separatorPos);
            templateName = templateTypeName.substr(separatorPos + 1);
        }
    }

    return Arguments{.path = path, .templateType = templateType, .templateName = templateName};
}
