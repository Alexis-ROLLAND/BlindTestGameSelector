#include <cstdlib>
#include <print>

#include "Game.hpp"

int main(){
    bool res;
    Game myGame{};

    myGame.printInfo();

    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);

    
    res = myGame.setRandomMainCategory();

    if (res) myGame.printInfo();
    else std::println("Error while setting random main category");

    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);

    res = myGame.setRandomSubCategory();
    if (res) myGame.printInfo();
    else std::println("Error while setting random sub category");

    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);

    res = myGame.setRandomPeriod();
    if (res) myGame.printInfo();
    else std::println("Error while setting random Period");

    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);

    res = myGame.setRandomLanguage();
    if (res) myGame.printInfo();
    else std::println("Error while setting random Language");

    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);

    res = myGame.makeFullRandomGame();
    if (res) myGame.printInfo();
    else std::println("Error while making full random game");
    
    res = myGame.isGameOK();
    std::println("  Game.isGameOK = {0:}",res);
    
    std::println("-----------------------------------------------------");
    myGame.Reset();

    res = myGame.ChooseMainCategory(MainCategoryID::SPECIAL_GAME);
    if (res) myGame.printInfo();
    else std::println("Error while setting main category");

    res = myGame.fillWithRandom();
    if (res) myGame.printInfo();
    else std::println("Error while filling randomly");

    return EXIT_SUCCESS;
}



