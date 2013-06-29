#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lights.h"

Light::Light(void) throw ()
{

}

char* Light::c_str(void) throw ()
{
    char* ret = (char*)malloc(128 * sizeof(char));
    memset(ret, 0, 128 * sizeof(char));
    snprintf(ret, 128 * sizeof(char), "Light at %p", (void*)this);

    return ret;
}
