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
    //NOTE: entity does NOT own main window renderer
    if (m_pIconUL) {
        SDL_DestroyTexture(m_pIconUL);
    }
    if (m_pIconUR) {
        SDL_DestroyTexture(m_pIconUR);
    }
    if (m_pIconDL) {
        SDL_DestroyTexture(m_pIconDL);
    }
    if (m_pIconDR) {
        SDL_DestroyTexture(m_pIconDR);
    }
}

void TestMoustachioEntity::Init(SDL_Renderer* mainWinRen) {

    m_pMainWinRen = mainWinRen;

    //TODO put all asset loading in a shared cache
    //TODO give this nicer error handling

    //load upper left icon
    std::string path = std::string(SDL_GetBasePath()) + "assets/gah-ul.png";
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconUL = SDL_CreateTextureFromSurface(m_pMainWinRen, loadedSurface);
        if (m_pIconUL == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }

    //load upper right icon
    path = std::string(SDL_GetBasePath()) + "assets/gah-ur.png";
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconUR = SDL_CreateTextureFromSurface(m_pMainWinRen, loadedSurface);
        if (m_pIconUR == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }

    //load down left icon
    path = std::string(SDL_GetBasePath()) + "assets/gah-dl.png";
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconDL = SDL_CreateTextureFromSurface(m_pMainWinRen, loadedSurface);
        if (m_pIconDL == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }

    //load down right icon
    path = std::string(SDL_GetBasePath()) + "assets/gah-dr.png";
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconDR = SDL_CreateTextureFromSurface(m_pMainWinRen, loadedSurface);
        if (m_pIconDR == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }
}

void TestMoustachioEntity::Update(WorldStateUpdateCallback* worldState) {
    (void) worldState;
}

void TestMoustachioEntity::Render(WorldStateRenderCallback* worldState) {
    Quadrant quad = worldState->GetCursorQuadrant();

    switch (quad) {
        case Quadrant::UpLeft:
            SDL_RenderCopy(m_pMainWinRen, m_pIconUL, 0, 0);
            break;
        case Quadrant::UpRight:
            SDL_RenderCopy(m_pMainWinRen, m_pIconUR, 0, 0);
            break;
        case Quadrant::DownLeft:
            SDL_RenderCopy(m_pMainWinRen, m_pIconDL, 0, 0);
            break;
        case Quadrant::DownRight:
            SDL_RenderCopy(m_pMainWinRen, m_pIconDR, 0, 0);
            break;
        default:
            std::cout << "Problem occurred rendering TestMoustachioEntity" << std::endl;
            return;
    }
}