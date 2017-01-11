#include <iostream>
#include <GameWorld.h>
#include <Vec2.h>

void RunVec2Tests();

int main() {
    //TODO make gameworld a singleton
    GameWorld* world = new GameWorld();
    world->Setup();
    world->Run();
    world->Deinit();
    delete world;
    world = nullptr;
    return 0;
    //RunVec2Tests();
}

//TODO make these tests nicer and move them out of main
//void RunVec2Tests() {
//    Vec2 x = std::make_tuple(2, 2);
//    Vec2 y = std::make_tuple(-1.5, -1.5);
//    std::cout << "Result of add: " << std::get<0>(x + y) << ", " << std::get<1>(x + y) << std::endl;
//    std::cout << "Result of subtract: " << std::get<0>(x - y) << ", " << std::get<1>(x - y) << std::endl;
//    std::cout << "Result of multiply: " << std::get<0>(3 * y) << ", " << std::get<1>(3 * y) << std::endl;
//    std::cout << "Result of dot: " << x * y << std::endl;
//    std::cout << "Result of rotate 90: " << std::get<0>(rotate(90, x)) << ", " << std::get<1>(rotate(90, x)) << std::endl;
//    std::cout << "Result of rotate 180: " << std::get<0>(rotate(180, x)) << ", " << std::get<1>(rotate(180, x)) << std::endl;
//}