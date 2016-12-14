//
// Created by Russell Blickhan on 12/13/16.
//

#pragma once

//std
#include <memory>

//gah
#include <WorldStateUpdateCallback.h>
#include <WorldStateRenderCallback.h>
#include <GameEntity.h>

class TestEntity : public GameEntity {
public:
    TestEntity();
    ~TestEntity();

    virtual void Update(WorldStateUpdateCallback* worldState) override;
    virtual void Render(WorldStateRenderCallback* worldState) override;
};

