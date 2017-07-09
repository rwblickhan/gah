//
// Created by Russell Blickhan on 12/17/16.
//

//std
#include <iostream>

//sdl
#include <SDL_image.h>

//gah
#include <TestMoustachioEntity.h>

TestMoustachioEntity::TestMoustachioEntity(std::shared_ptr<EntityCache> cache)
    : GameEntity(cache)
{

}

TestMoustachioEntity::~TestMoustachioEntity() {

}

void TestMoustachioEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestMoustachioEntity::Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) {
    Quadrant quad = worldState->GetCursorQuadrant();

    switch (quad) {
        case Quadrant::UpLeft:
            SDL_RenderCopy(renderer, m_cache->m_pIconUL, 0, 0);
            break;
        case Quadrant::UpRight:
            SDL_RenderCopy(renderer, m_cache->m_pIconUR, 0, 0);
            break;
        case Quadrant::DownLeft:
            SDL_RenderCopy(renderer, m_cache->m_pIconDL, 0, 0);
            break;
        case Quadrant::DownRight:
            SDL_RenderCopy(renderer, m_cache->m_pIconDR, 0, 0);
            break;
        default:
            std::cout << "Problem occurred rendering TestMoustachioEntity" << std::endl;
            return;
    }
}