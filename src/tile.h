#ifndef _HELLOSDL_TILE__
#define _HELLOSDL_TILE__

#include <map>

#include "exceptions.h"
#include "lights.h"
#include "tints.h"

using namespace std;

typedef map<Light*, Tint> lights_t;

class Tile
{
    protected:
        lights_t light_stack;

    public:
        Tile(void) throw ();
        void AddTint(Light* source, Tint color, bool forced = false) throw (TileTintError);
        void DelTint(Light* source) throw ();
        bool HasTintFrom(Light* source) throw ();
        void PrintTints(void) throw ();
        char* c_str(void) throw ();
};

#endif

