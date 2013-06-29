#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tile.h"

Tile::Tile(void) throw ()
{
    this->light_stack.clear();
}


// Handling tints

bool Tile::HasTintFrom(Light* src) throw ()
{
    lights_t::size_type found = light_stack.count(src);

    return found != 0;
}

void Tile::AddTint(Light* src, Tint color, bool forced) throw (TileTintError)
{
    if (this->HasTintFrom(src))
    {
        if (forced) { this->DelTint(src); }
        else
        {
            char* reason = (char*)malloc(128 * sizeof(char));
            memset(reason, 0, 128 * sizeof(char));
            snprintf(reason, 128 * sizeof(char), "light from %p already has light in tile %p", (void*)src, (void*)this);

            throw TileTintError(reason);
        }
    }

    light_stack[src] = color;
}


void Tile::DelTint(Light* src) throw ()
{
    lights_t::iterator found = light_stack.find(src);
    light_stack.erase(found);
}

void Tile::PrintTints(void) throw ()
{
    lights_t::iterator tints;
    char *name1, *name2;
    
    name1 = this->c_str();
    printf("\nTints for %s:\n", name1);
    free(name1);

    for (tints = light_stack.begin(); tints != light_stack.end(); ++tints)
    {
        name1 = tints->first->c_str();
        name2 = tints->second.c_str();
        printf("  (%s) -> (%s)\n", name1, name2);

        free(name1);
        free(name2);
    }
}

char* Tile::c_str(void) throw ()
{
    char* ret = (char*)malloc(128 * sizeof(char));
    memset(ret, 0, 128 * sizeof(char));
    snprintf(ret, 128 * sizeof(char), "Tile at %p", (void*)this);
    
    return ret;
}
