#include <iostream>
#include <string>
#include "headers/argsParser.h"
#include "./headers/fileUtils.h"

int main(const int argc, char *argv[]) {
    auto [path, templateType, templateName] = argsParser(argc, argv);
    if (templateName.empty()) {
        std::cout<<"Template name is required.\n";
        return 0;
    }

    if (isTemplate(templateType))
        std::cout<<"Template " << templateType << " found.\n";
    else
        std::cout<<"Template type " << templateType<<" doesn't exists.";

    return 0;
}
