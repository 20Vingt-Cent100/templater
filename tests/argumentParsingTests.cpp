#include "../headers/fileUtils.h"
#include <cassert>

//TODO: Add cmake config for unit testing
int testGetTemplateProtocol() {
    assert(getTemplateProtocol("templateGenerator") == DEFAULT_PROTOCOL);
    assert(getTemplateProtocol("noNeedForTheTemplateToExistToReturnDefaultProtocol") == DEFAULT_PROTOCOL);
    assert(getTemplateProtocol("./ThisIsAPath") == PATH_PROTOCOL);
    assert(getTemplateProtocol("https://github.com/20Vingt-Cent100/templater") == REMOTE_PROTOCOL);
    assert(getTemplateProtocol("asdf::thisIsNotARealProtocol") == UNSUPORTED_PROTOCOL);

    return 1;
}
