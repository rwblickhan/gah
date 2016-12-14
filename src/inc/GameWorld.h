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

    virtual Quadrant GetCursorQuadrant() override;

private:

    void HandleInput();

    void Update();

    void Render();

    void SetCursorQuadrant(int32_t x, int32_t y);

    std::vector<std::shared_ptr<GameEntity>> m_entityList;
    bool m_running;
    Quadrant m_curQuad = Quadrant::DownLeft;
    SDL_Window* m_pMainWindow;
    SDL_Renderer* m_pRen;
};