//
// Created by Russell Blickhan on 12/17/16.
//

//std
#include <iostream>

//sdl
#include <SDL_image.h>

//gah
#include <TestCookieEntity.h>

TestCookieEntity::TestCookieEntity() {

}

TestCookieEntity::~TestCookieEntity() {

}

void TestCookieEntity::Init(SDL_Renderer* mainWinRen, std::shared_ptr<EntityCache> cache) {

    m_pMainWinRen = mainWinRen;
    m_pCache = cache;

}

void TestCookieEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestCookieEntity::Render(WorldStateRenderCallback* worldState) {
    WindowPos pos = worldState->GetCursorPos();
    SDL_Rect dstRect = {pos.x, pos.y, 16, 16};

    SDL_RenderCopy(m_pMainWinRen, m_pCache->m_pIconCookie, 0, &dstRect);
}