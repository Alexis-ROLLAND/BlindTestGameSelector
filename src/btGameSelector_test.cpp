#include <cstdlib>
#include <print>

#include "Game.hpp"

int main(){
    bool res;
    Game myGame{};

    myGame.printInfo();

    myGame.ChooseMainCategory(MainCategoryID::SPECIAL_GAME);

    myGame.printInfo();

    res = myGame.ChooseSubCategory(SubCategoryID::BURGER_MORT);
    std::println("res = {0:}", res);

    myGame.printInfo();


    return EXIT_SUCCESS;
}



