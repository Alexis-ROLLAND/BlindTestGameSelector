#include <cstdlib>
#include <print>

#include "Game.hpp"

int main(){
    bool res;
    Game myGame{};

    myGame.printInfo();

    myGame.ChoosePeriod(PeriodID::SEVENTIES,true);
    myGame.ChooseLanguage(LanguageID::INT,true);
    myGame.printInfo();

    myGame.Reset();

    myGame.ChooseMainCategory(MainCategoryID::SPECIAL_GAME);

    myGame.printInfo();

    res = myGame.ChooseSubCategory(SubCategoryID::BURGER_MORT);
    std::println("res = {0:}", res);

    myGame.printInfo();

    myGame.ChooseSubCategory(SubCategoryID::COVER,true);
    myGame.printInfo();

    res = myGame.ChoosePeriod(PeriodID::NA);
    //std::println(" # res = {0:}",res);
    myGame.printInfo();

    res = myGame.ChooseLanguage(LanguageID::FRA);
    //std::println(" # res = {0:}",res);
    myGame.printInfo();

    return EXIT_SUCCESS;
}



