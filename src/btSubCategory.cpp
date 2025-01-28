#include "btSubCategory.hpp"

void btSubCategory::setID(SubCategoryID id) noexcept{
    this->Id = id;
    this->setMainCategoryID(this->getMainCategoryID(this->getID()));
    this->setFilterCriteria(ListFIlterCriteria.at(id));
}


MainCategoryID btSubCategory::getMainCategoryID(SubCategoryID id){
    MainCategoryID mainCatId{MainCategoryID::X};

    switch(id){
        case SubCategoryID::TRADITIONAL : 
            mainCatId = MainCategoryID::TRAD_GAME;
            break;

        case SubCategoryID::MOVIE:
        case SubCategoryID::TV_SHOW:
        case SubCategoryID::SBIG:
        case SubCategoryID::COVER:
        case SubCategoryID::CHORUS:
        case SubCategoryID::RIFF:
        case SubCategoryID::NAMES:
        case SubCategoryID::CITIES:
            mainCatId = MainCategoryID::EXTRA_GAME;
            break;
        
        case SubCategoryID::PETIT_BAC:
        case SubCategoryID::BURGER_MORT:
        case SubCategoryID::TIROIRS:
        case SubCategoryID::MIME:
        case SubCategoryID::TABOO:
            mainCatId = MainCategoryID::SPECIAL_GAME;
            break;

        default : break;
    }

    return mainCatId;
}

