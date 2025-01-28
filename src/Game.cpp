#include "Game.hpp"

int  Game::getRandomValue(int MaxValue) noexcept {
    std::uniform_int_distribution<> distrib(0, MaxValue); // Distribution entière entre 0 et MaxValue inclus
    return  distrib(gen); // Génération d'une valeur aléatoire
}

void    Game::Reset() noexcept{
    this->MainCategory.reset();
    this->SubCategory.reset();
    this->Period.reset();
    this->Language.reset();

    this->setStatus(gameStatus_t::RESET_STATE);
}

bool    Game::ChooseMainCategory(MainCategoryID id) noexcept{
    if (this->SubCategory.getID() != SubCategoryID::X) return false;
    if (this->Period.getID() != PeriodID::X) return false;
    if (this->Language.getID() != LanguageID::X) return false;

    this->MainCategory.setID(id);
    return true;
}

bool    Game::ChooseSubCategory(SubCategoryID id) noexcept{
    if (this->MainCategory.getID() == MainCategoryID::X){
        this->SubCategory.setID(id);
        return true;
    }
    else{
        if (!this->MainCategory.getListAllowedSubCategories().contains(id)) return false;
        this->SubCategory.setID(id);
        return true;
    }

    
}

void    Game::printInfo() noexcept{
    std::println("Main Category : {0:}", this->MainCategory.to_string());
    std::println("Sub Category : {0:}", this->SubCategory.to_string());
    std::println("Period : {0:}", this->Period.to_string());
    std::println("Language : {0:}", this->Language.to_string());

    std::unordered_set<SubCategoryID>  allowedSC = this->MainCategory.getListAllowedSubCategories();
    std::println("   Number of allowed Sub Categories = {0:d} ",allowedSC.size());




}
