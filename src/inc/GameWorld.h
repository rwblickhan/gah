//
// Created by Russell Blickhan on 12/12/16.
//

#pragma once

//std
#include <vector>

//SDL
#include <SDL_video.h>
#include <SDL_render.h>

//gah
#include <GameEntity.h>

class GameWorld {

    GameWorld();

    ~GameWorld();

    void Setup();

    void Deinit();

    void Run();

    void HandleInput();

    void Update();

    void Render();

private:
    std::vector<std::shared_ptr<GameEntity>> m_entityList;
    bool m_running;
    SDL_Window* m_pMainWindow;
    SDL_Renderer* m_pRen;
};