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
    //NOTE: entity does NOT own main window renderer
    if (m_pIconCookie) {
        SDL_DestroyTexture(m_pIconCookie);
    }
}

void TestCookieEntity::Init(SDL_Renderer* mainWinRen) {

    m_pMainWinRen = mainWinRen;

    //TODO put all asset loading in a shared cache
    //TODO give this nicer error handling

    //load cookie icon
    std::string path = std::string(SDL_GetBasePath()) + "assets/cookie.png";
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconCookie = SDL_CreateTextureFromSurface(m_pMainWinRen, loadedSurface);
        if (m_pIconCookie == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }
}

void TestCookieEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestCookieEntity::Render(WorldStateRenderCallback* worldState) {
    WindowPos pos = worldState->GetCursorPos();
    SDL_Rect dstRect = {pos.x, pos.y, 16, 16};

    SDL_RenderCopy(m_pMainWinRen, m_pIconCookie, 0, &dstRect);
}