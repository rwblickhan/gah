//
// Created by Russell Blickhan on 12/12/16.
//

#pragma once

//sdl
#include <SDL2/SDL.h>

//gah
#include <WorldStateRenderCallback.h>
#include <WorldStateUpdateCallback.h>

class GameEntity {

public:

    virtual void Init(SDL_Renderer* mainWinRen) = 0;

    virtual void Update(WorldStateUpdateCallback* worldState) = 0;

    virtual void Render(WorldStateRenderCallback* worldState) = 0;

};
