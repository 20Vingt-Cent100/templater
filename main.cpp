#include <iostream>
#include <string>
#include "./source/argsParser.h"

int main(const int argc, char *argv[]) {
    Arguments args = argsParser(argc, argv);
    std::cout << args.path << "\n" << args.templateType << "\n" << args.templateName << std::endl;
}
