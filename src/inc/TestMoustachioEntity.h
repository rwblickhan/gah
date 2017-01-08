//
// Created by Russell Blickhan on 12/17/16.
//

#pragma once

//gah
#include <GameEntity.h>

class TestMoustachioEntity : public GameEntity {
public:
    TestMoustachioEntity();
    virtual ~TestMoustachioEntity();

    virtual void Init(SDL_Renderer* mainWinRen, std::shared_ptr<EntityCache> cache) override;

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState) override;

private:

    SDL_Renderer* m_pMainWinRen = nullptr;
    std::shared_ptr<EntityCache> m_pCache = nullptr;
};