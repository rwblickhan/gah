//
// Created by Russell Blickhan on 12/17/16.
//

//std
#include <iostream>

//sdl
#include <SDL_image.h>

//gah
#include <TestCookieEntity.h>

TestCookieEntity::TestCookieEntity(std::shared_ptr<EntityCache> cache)
    : GameEntity(cache)
{

}

TestCookieEntity::~TestCookieEntity() {

}

void TestCookieEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestCookieEntity::Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) {
    WindowPos pos = worldState->GetCursorPos();
    SDL_Rect dstRect = {pos.x, pos.y, 16, 16};

    SDL_RenderCopy(renderer, m_cache->m_pIconCookie, 0, &dstRect);
}