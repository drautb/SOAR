#include <cstdlib>
#include <cstring>

#include "StringUtils.h"

using namespace SOAR;
using namespace Util;

StringUtils::StringUtils()
{

}

char* StringUtils::RemoveConst(const char* str)
{
    char* copy = nullptr;
    int length = strlen(str);

    copy = (char*)malloc(length + 1);
    strcpy(copy, str);
    copy[length] = '\0';

    return copy;
}
