#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tints.h"

Tint::Tint(void) throw ()
{

}

char* Tint::c_str(void) throw ()
{
    char* ret = (char*)malloc(128 * sizeof(char));
    memset(ret, 0, 128 * sizeof(char));
    snprintf(ret, 128 * sizeof(char), "Tint at %p", (void*)this);

    return ret;
}
