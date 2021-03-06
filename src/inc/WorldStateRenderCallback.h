//
// Created by Russell Blickhan on 12/13/16.
//

#pragma once

#include <Types.h>

class WorldStateRenderCallback {
public:

    virtual WindowPos GetCursorPos() = 0;

    virtual Quadrant GetCursorQuadrant() = 0;

};