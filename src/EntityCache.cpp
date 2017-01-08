//
// Created by Russell Blickhan on 1/8/17.
//

//std
#include <iostream>

//sdl
#include <SDL_image.h>

//gah
#include <EntityCache.h>

EntityCache::EntityCache() {

}

EntityCache::~EntityCache() {

}


void EntityCache::LoadAssets(SDL_Renderer* mainWinRen) {
//load upper left icon
    std::string path = std::string(SDL_GetBasePath()) + "assets/gah-ul.png";
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        m_pIconUL = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
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
        m_pIconUR = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
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
        m_pIconDL = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
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
        m_pIconDR = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (m_pIconDR == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }
}