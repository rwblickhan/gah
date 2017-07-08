//
// Created by Russell Blickhan on 1/10/17.
//

#pragma once

//std
#include <memory>

//sdl
#include <SDL_image.h>

//gah
#include <EntityCache.h>

class AssetLoader {
public:
    AssetLoader();
    ~AssetLoader();

    void LoadAssets(SDL_Renderer* mainWinRen, std::shared_ptr<EntityCache> cache);
};
