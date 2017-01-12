//
// Created by Russell Blickhan on 12/17/16.
//

//std
#include <iostream>

//sdl
#include <SDL_image.h>

//gah
#include <TestMoustachioEntity.h>

TestMoustachioEntity::TestMoustachioEntity() {

}

TestMoustachioEntity::~TestMoustachioEntity() {

}

void TestMoustachioEntity::Init(SDL_Renderer* mainWinRen, std::shared_ptr<EntityCache> cache) {

    m_pMainWinRen = mainWinRen;
    m_pCache = cache;

}

void TestMoustachioEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestMoustachioEntity::Render(WorldStateRenderCallback* worldState) {
    Quadrant quad = worldState->GetCursorQuadrant();

    switch (quad) {
        case Quadrant::UpLeft:
            SDL_RenderCopy(m_pMainWinRen, m_pCache->m_pIconUL, 0, 0);
            break;
        case Quadrant::UpRight:
            SDL_RenderCopy(m_pMainWinRen, m_pCache->m_pIconUR, 0, 0);
            break;
        case Quadrant::DownLeft:
            SDL_RenderCopy(m_pMainWinRen, m_pCache->m_pIconDL, 0, 0);
            break;
        case Quadrant::DownRight:
            SDL_RenderCopy(m_pMainWinRen, m_pCache->m_pIconDR, 0, 0);
            break;
        default:
            std::cout << "Problem occurred rendering TestMoustachioEntity" << std::endl;
            return;
    }
}