//
// Created by Russell Blickhan on 12/12/16.
//

#pragma once

//std
#include <memory>

//sdl
#include <SDL2/SDL.h>

//gah
#include <EntityCache.h>
#include <WorldStateRenderCallback.h>
#include <WorldStateUpdateCallback.h>

class GameEntity {

public:

    virtual void Update(WorldStateUpdateCallback* worldState) = 0;

    virtual void Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) = 0;

protected:

    GameEntity(std::shared_ptr<EntityCache> cache)
            : m_cache(cache) {};

    std::shared_ptr<SDL_Renderer> m_renderer;
    std::shared_ptr<EntityCache> m_cache;

};
