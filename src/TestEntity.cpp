//
// Created by Russell Blickhan on 12/13/16.
//

//std
#include <iostream>

//gah
#include <TestEntity.h>

TestEntity::TestEntity(std::shared_ptr<EntityCache> cache)
    : GameEntity(cache)
{

}

TestEntity::~TestEntity() {

}

void TestEntity::Update(WorldStateUpdateCallback* worldState) {
    std::cout << "Updating TestEntity!" << std::endl;
}

void TestEntity::Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) {
    switch (worldState->GetCursorQuadrant())
    {
        case Quadrant::UpLeft:
            std::cout << "Cursor in upper left" << std::endl;
            break;
        case Quadrant::UpRight:
            std::cout << "Cursor in upper right" << std::endl;
            break;
        case Quadrant::DownLeft:
            std::cout << "Cursor in bottom left" << std::endl;
            break;
        case Quadrant::DownRight:
            std::cout << "Cursor in bottom right" << std::endl;
            break;
        case Quadrant::Invalid:
        default:
            std::cout << "Uh, something went really wrong..." << std::endl;
    }
}