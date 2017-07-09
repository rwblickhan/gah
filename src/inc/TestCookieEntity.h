//
// Created by Russell Blickhan on 12/17/16.
//

#pragma once

//gah
#include <GameEntity.h>
#include <EntityCache.h>

class TestCookieEntity : public GameEntity {
public:
    TestCookieEntity(std::shared_ptr<EntityCache> cache);

    virtual ~TestCookieEntity();

    virtual void Update(WorldStateUpdateCallback* worldState) override;

    virtual void Render(WorldStateRenderCallback* worldState, SDL_Renderer* renderer) override;

};