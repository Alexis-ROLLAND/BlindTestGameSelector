#include <cstdlib>
#include <print>

#include "lib_btGameSelector.hpp"

int main(){

    Game    myGame;

    /*
    std::println("Main Category = {0:}", Game::toString(myGame.getMainCategory()));
    std::println("Sub Category = {0:}", Game::toString(myGame.getSubCategory()));
    std::println("Periode = {0:}", Game::toString(myGame.getPeriod()));
    std::println("Langue = {0:}", Game::toString(myGame.getLangue()));
    */

    myGame.setMainCategory();
    std::println("Main Category = {0:}", Game::toString(myGame.getMainCategory()));

    myGame.setSubCategory();
    std::println("Sub Category = {0:}", Game::toString(myGame.getSubCategory()));

    myGame.setPeriodAndLanguage();
    std::println("Periode = {0:}", Game::toString(myGame.getPeriod()));
    std::println("Langue = {0:}", Game::toString(myGame.getLangue()));
    
    std::println("Uid = {0:08x}",myGame.getGameUID());

    myGame.CreateGame();
    std::println("Uid = {0:08x}",myGame.getGameUID());
    


    return EXIT_SUCCESS;
}



