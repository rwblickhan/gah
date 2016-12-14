//
// Created by Russell Blickhan on 12/12/16.
//

#pragma once

#include <WorldStateRenderCallback.h>
#include <WorldStateUpdateCallback.h>

class GameEntity {

public:

    virtual void Update(WorldStateUpdateCallback* worldState) = 0;

    virtual void Render(WorldStateRenderCallback* worldState) = 0;

};
