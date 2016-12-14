#include <iostream>
#include <GameWorld.h>

int main() {
    //TODO make gameworld a singleton
    GameWorld* world = new GameWorld();
    world->Setup();
    world->Run();
    world->Deinit();
    delete world;
    world = nullptr;
    return 0;
}