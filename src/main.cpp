#include "tile.h"
#include "lights.h"
#include "tints.h"

int main(int argc, char* argv[])
{
    Tile herp;
    Light derp;
    Light lerp;
    Tint nerp;
    Tint berp;

    herp.AddTint(&derp, nerp);
    herp.AddTint(&lerp, berp);

    herp.PrintTints();
    return 0;
}
