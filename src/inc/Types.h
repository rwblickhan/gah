//
// Created by Russell Blickhan on 12/13/16.
//

#pragma once

enum struct Quadrant {
    UpLeft = 0,
    UpRight,
    DownLeft,
    DownRight,
    Invalid
};

//Represents an (x,y) position relative to the main window
struct WindowPos {
    int x;
    int y;
};