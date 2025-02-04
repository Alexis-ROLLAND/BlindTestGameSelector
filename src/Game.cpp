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
bool    Game::setRandomMainCategory(bool forceReset) noexcept{
    if (forceReset == true) this->Reset();

    if (this->SubCategory.getID() != SubCategoryID::X) return false;
    if (this->Period.getID() != PeriodID::X) return false;
    if (this->Language.getID() != LanguageID::X) return false;

    int idxMainCat = this->getRandomValue(MAX_ID_MAIN_CATEGORY);

    switch(idxMainCat){
        case 0 : this->MainCategory.setID(MainCategoryID::TRAD_GAME);break;
        case 1 : this->MainCategory.setID(MainCategoryID::EXTRA_GAME);break;
        case 2 : this->MainCategory.setID(MainCategoryID::SPECIAL_GAME);break;
        default : return false;
    }
    return true;
}
/*---------------------------------------------------------------------------*/
bool    Game::ChooseSubCategory(SubCategoryID id, bool forceMainCategory) noexcept{
    if (this->MainCategory.getID() == MainCategoryID::X){
        this->MainCategory.setID(this->getMainCategoryID(id));
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
bool    Game::setRandomSubCategory(bool forceMainCategory) noexcept{
    SubCategoryID scid{};

    do{
        int idxSubCat = this->getRandomValue(MAX_ID_SUB_CATEGORY);
        switch(idxSubCat){
            case 0 : scid = SubCategoryID::TRADITIONAL;break;
            case 1 : scid = SubCategoryID::MOVIE;break;
            case 2 : scid = SubCategoryID::TV_SHOW;break;
            case 3 : scid = SubCategoryID::SBIG;break;
            case 4 : scid = SubCategoryID::COVER;break;
            case 5 : scid = SubCategoryID::DUET;break;
            case 6 : scid = SubCategoryID::CHORUS;break;
            case 7 : scid = SubCategoryID::RIFF;break;
            case 8 : scid = SubCategoryID::NAMES;break;
            case 9 : scid = SubCategoryID::CITIES;break;
            case 10 : scid = SubCategoryID::PETIT_BAC;break;
            case 11 : scid = SubCategoryID::BURGER_MORT;break;
            case 12 : scid = SubCategoryID::TIROIRS;break;
            case 13 : scid = SubCategoryID::MIME;break;
            case 14 : scid = SubCategoryID::TABOO;break;
            default : return false;
            }
        }
    while (this->ChooseSubCategory(scid,forceMainCategory) != true);
    return true;
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
bool    Game::setRandomPeriod(bool forceFill) noexcept{
    PeriodID perid{};

    do{
        int idxPeriod = this->getRandomValue(MAX_ID_PERIOD);
        switch(idxPeriod){
            case 0 : perid = PeriodID::OLDIES;break;
            case 1 : perid = PeriodID::SEVENTIES;break;
            case 2 : perid = PeriodID::EIGHTIES;break;
            case 3 : perid = PeriodID::NINETIES;break;
            case 4 : perid = PeriodID::Y2K0X;break;
            case 5 : perid = PeriodID::Y2K1X;break;
            case 6 : perid = PeriodID::Y2K2X;break;
            case 7 : perid = PeriodID::NA;break;
            default : return false;
        }

    }while(this->ChoosePeriod(perid,forceFill) != true);
    return true;
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
bool    Game::setRandomLanguage(bool forceFill) noexcept{
    LanguageID langid{};

    do{
        int idxlang = this->getRandomValue(MAX_ID_LANGUAGE);
        switch(idxlang){
            case 0 : langid = LanguageID::FRA;break;
            case 1 : langid = LanguageID::INT;break;
            case 2 : langid = LanguageID::NA;break;
            default : return false;
        }

    }while(this->ChooseLanguage(langid,forceFill) != true);
    return true;
}
/*---------------------------------------------------------------------------*/
bool    Game::makeFullRandomGame(){
    this->Reset();
    if (this->setRandomSubCategory(true) == false) return false;
    if (this->setRandomPeriod() == false) return false;
    return this->setRandomLanguage();
}
/*---------------------------------------------------------------------------*/
bool    Game::isGameOK(){
    if (this->MainCategory.getID() == MainCategoryID::X) return false;
    if (this->MainCategory.getID() == MainCategoryID::NA) return false;
    
    if (this->SubCategory.getID() == SubCategoryID::X) return false;
    if (this->SubCategory.getID() == SubCategoryID::NA) return false;
    
    if (this->MainCategory.getID() != this->getMainCategoryID(this->SubCategory.getID())) return false;
    
    if (this->Period.getID() == PeriodID::X) return false;
    if (this->Language.getID() == LanguageID::X) return false;
    
    FilterCriteria filter = this->SubCategory.getFilterCriteria();
    if ( (filter.first == true) && (this->Period.getID() == PeriodID::NA) ) return false;
    if ( (filter.first == false) && (this->Period.getID() != PeriodID::NA) ) return false;
    if ( (filter.second == true) && (this->Language.getID() == LanguageID::NA) ) return false;
    if ( (filter.second == false) && (this->Language.getID() != LanguageID::NA) ) return false;

    return true;
}
/*---------------------------------------------------------------------------*/
bool    Game::fillWithRandom(){
    if (this->isGameOK() == true) return true;
    if (this->MainCategory.getID() == MainCategoryID::NA) return false;
    if (this->SubCategory.getID() == SubCategoryID::NA) return false;

    if (this->SubCategory.isSet() == false){                            /** Subcategory is unset */
        this->setRandomSubCategory(!this->MainCategory.isSet());         /** Random SubCategory, according to main category status */


    }
    else{                                                               /** Subcategory is already set */
        if (this->MainCategory.isSet() == false)    this->ChooseMainCategory(this->getMainCategoryID(this->SubCategory.getID()) ); /** Fill Main Category according to sub category */
        
    }

    if (this->Period.isSet() == false) this->setRandomPeriod();
    if (this->Language.isSet() == false) this->setRandomLanguage();

    return this->isGameOK();
}
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


