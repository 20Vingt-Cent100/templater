#include <iostream>
#include <string>
#include "headers/argsParser.h"
#include "./headers/fileUtils.h"
#include "./headers/logger.h"

int main(const int argc, char *argv[]) {
    auto [path, templateType, templateName] = argsParser(argc, argv);
    if (templateName.empty()) {
        std::cout<<"Template name is required.\n";
        return 0;
    }

    switch (getTemplateProtocol(templateType)) {
        case DEFAULT_PROTOCOL:
            if (isTemplate(templateType))
                logger::log(logger::TRACE, "Template type: " + templateType + " found.");
            else
                logger::log(logger::WARNING, "Template type: " + templateType + " doesn't exist.");
            break;
        case REMOTE_PROTOCOL: std::cout<< "Remote Protocol";
            break;
        case PATH_PROTOCOL: std::cout<< "PATH_PROTOCOL";
            break;
        case UNSUPPORTED_PROTOCOL: std::cout << "Protocol provided is not supported.";
            break;
    }



    return 0;
}
