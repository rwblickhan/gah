//
// Created by Russell Blickhan on 1/10/17.
//

//std
#include <iostream>

//gah
#include <AssetLoader.h>

AssetLoader::AssetLoader() {

}

AssetLoader::~AssetLoader() {

}

void AssetLoader::LoadAssets(SDL_Renderer *mainWinRen, std::shared_ptr<EntityCache> cache) {
    //load upper left icon
    std::string path = std::string(SDL_GetBasePath()) + "assets/gah-ul.png";
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        cache->m_pIconUL = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (cache->m_pIconUL == nullptr) {
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
        cache->m_pIconUR = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (cache->m_pIconUR == nullptr) {
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
        cache->m_pIconDL = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (cache->m_pIconDL == nullptr) {
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
        cache->m_pIconDR = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (cache->m_pIconDR == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }

    //load cookie icon
    path = std::string(SDL_GetBasePath()) + "assets/cookie.png";
    loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cout << "Error: Couldn't load given path: " << path << ": error: " << SDL_GetError() << std::endl;
    } else {
        cache->m_pIconCookie = SDL_CreateTextureFromSurface(mainWinRen, loadedSurface);
        if (cache->m_pIconCookie == nullptr) {
            std::cout << "Error: Couldn't create texture, error: " << SDL_GetError() << std::endl;
        }
        delete loadedSurface;
        loadedSurface = nullptr;
    }

}