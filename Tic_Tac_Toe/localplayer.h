#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "player.h"

class LocalPlayer : public Player
{
    public:
        LocalPlayer();
        void placeSymbol(void);
        ~LocalPlayer();
};

#endif // LOCALPLAYER_H
