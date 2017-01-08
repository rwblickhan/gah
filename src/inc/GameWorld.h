//
// Created by Russell Blickhan on 12/12/16.
//

#pragma once

//std
#include <vector>

//SDL
#include <SDL2/SDL.h>

//gah
#include <GameEntity.h>
#include <EntityCache.h>
#include <WorldStateRenderCallback.h>
#include <WorldStateUpdateCallback.h>

class GameWorld : public WorldStateRenderCallback, WorldStateUpdateCallback {

public:

    GameWorld();

    virtual ~GameWorld();

    void Setup();

    void Deinit();

    void Run();

    //WorldStateRenderCallback methods

    virtual WindowPos GetCursorPos() override;

    virtual Quadrant GetCursorQuadrant() override;

private:

    void HandleInput();

    void Update();

    void Render();

    void SetCursorPos(int x, int y);

    std::vector<std::shared_ptr<GameEntity>> m_entityList;
    std::shared_ptr<EntityCache> m_pCache;
    bool m_running;
    WindowPos cursorPos;
    SDL_Window* m_pMainWindow;
    SDL_Renderer* m_pRen;
};