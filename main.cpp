#include <iostream>
#include <string>
#include "headers/argsParser.h"
#include "./headers/fileUtils.h"
#include "./headers/logger.h"
#include "headers/yamlParser.h"

int main(const int argc, char *argv[]) {
    auto [path, templateType, templateName] = argsParser(argc, argv);
    if (!path.empty() && !isFilePath(path)) {
        std::cout<<"Path is not valid.";
        logger::log(logger::ERROR, "Path is invalid.");
        return 0;
    }

    if (templateName.empty()) {
        std::cout<<"Template name is required.\n";
        logger::log(logger::ERROR, "Path is invalid");
        return 0;
    }

    parseYaml(getCWD()/ "../../templates/yamlParsingTest.template");

    switch (getTemplateProtocol(templateType)) {
        case DEFAULT_PROTOCOL:
            if (isTemplate(templateType))
                logger::log(logger::TRACE, "Creating " + templateName + ".");
            else
                logger::log(logger::WARNING, "Template type '" + templateType + "' doesn't exist.");
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
