#include "Game.hpp"
/*---------------------------------------------------------------------------*/
int  Game::getRandomValue(int MaxValue) noexcept {
    std::uniform_int_distribution<> distrib(0, MaxValue); // Distribution entière entre 0 et MaxValue inclus
    return  distrib(gen); // Génération d'une valeur aléatoire
}
/*---------------------------------------------------------------------------*/
void    Game::Reset() noexcept{
    this->MainCategory.reset();
    this->SubCategory.reset();
    this->Period.reset();
    this->Language.reset();

}
/*---------------------------------------------------------------------------*/
bool    Game::ChooseMainCategory(MainCategoryID id) noexcept{
    if (this->SubCategory.getID() != SubCategoryID::X) return false;
    if (this->Period.getID() != PeriodID::X) return false;
    if (this->Language.getID() != LanguageID::X) return false;

    this->MainCategory.setID(id);
    return true;
}
/*---------------------------------------------------------------------------*/
bool    Game::ChooseSubCategory(SubCategoryID id, bool forceMainCategory) noexcept{
    if (this->MainCategory.getID() == MainCategoryID::X){
        this->SubCategory.setID(id);
        return true;
    }
    else{
        if (this->MainCategory.getListAllowedSubCategories().contains(id)){
            this->SubCategory.setID(id);
            return true;
        }
        else {
            if (forceMainCategory == true){
                this->MainCategory.setID(this->getMainCategoryID(id));
                this->SubCategory.setID(id);        
                return true;
            }
        }
    }

    return false;
}
/*---------------------------------------------------------------------------*/
bool    Game::ChoosePeriod(PeriodID id, bool forceFill) noexcept{
    if (id == PeriodID::X) return false;    /* Check if Period is not "X" */

    if (this->SubCategory.isSet() == true){         /** Subcategory is set, check consistency     */
        FilterCriteria filter = this->SubCategory.getFilterCriteria();
        
        if (filter.first == false) {
            if (id != PeriodID::NA) return false;   /** If period is not a criteria, value MUST be NA */
            else{
                this->Period.setID(id);             /** Everything seems ok, let's set the Period   */
                return true;                        /** and return OK (true)    */
            }
        }
        else{                                       /** Period is a criteria  */
            if (id == PeriodID::NA) return false;   /** If period is  a criteria, value MUSTN'T be NA */
            this->Period.setID(id);                 /** Everything seems ok, let's set the Period   */
            return true;                            /** and return OK (true)    */
        }
    }
    else{                                           /** Subcategory is unset, let's check the forceFIll value */
        if (forceFill == true){
            this->Period.setID(id);
            return true;
        }
    }
    return false;
}
/*---------------------------------------------------------------------------*/
bool    Game::ChooseLanguage(LanguageID id, bool forceFill) noexcept{
    if (id == LanguageID::X) return false;          /* Check if Language is not "X" */

    if (this->SubCategory.isSet() == true){
        FilterCriteria filter = this->SubCategory.getFilterCriteria();
        
        if (filter.second == false) {
            if (id != LanguageID::NA) return false;     /** If language is not a criteria, value MUST be NA */
            else{
                this->Language.setID(id);               /** Everything seems ok, let's set the Language    */
                return true;                            /** and return OK (true)    */
            }
        }
        else{                                           /** Language is a criteria  */
            if (id == LanguageID::NA) return false;     /** If language is  a criteria, value MUSTN'T be NA */
            this->Language.setID(id);                   /** Everything seems ok, let's set the Language   */
            return true;                                /** and return OK (true)    */
        }
    }
    else{                                               /** Subcategory is unset, let's check the forceFill value */
        if (forceFill == true){
            this->Language.setID(id);
            return true;
        }
    }

    return false;
}
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
void    Game::printInfo() noexcept{
    std::println("Main Category : {0:} - isSet = {1:}", this->MainCategory.to_string(),this->MainCategory.isSet());
    std::println("Sub Category : {0:} - isSet = {1:}", this->SubCategory.to_string(),this->SubCategory.isSet());
    std::println("Period : {0:} - isSet = {1:}", this->Period.to_string(), this->Period.isSet());
    std::println("Language : {0:} - isSet = {1:}", this->Language.to_string(), this->Language.isSet());
}
/*---------------------------------------------------------------------------*/
MainCategoryID Game::getMainCategoryID(SubCategoryID id) const noexcept {
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
/*---------------------------------------------------------------------------*/


