#include "lib_btGameSelector.hpp"

std::string_view Game::toString(btPeriod period){
    switch (period){
        case btPeriod::X : return "X";break;
        case btPeriod::OLDIES : return "OLDIES";break;
        case btPeriod::SEVENTIES : return "SEVENTIES";break;
        case btPeriod::EIGHTIES : return "EIGHTIES";break;
        case btPeriod::NINETIES : return "NINETIES";break;
        case btPeriod::Y2K0X : return "ANNEES 2000";break;
        case btPeriod::Y2K1X : return "ANNEES 2010";break;
        case btPeriod::Y2K2X : return "ANNEES 2020";break;
        case btPeriod::NA : return "NA";break;    
        default:    return "ERROR"; break;
    }

}

std::string_view Game::toString(btLanguage langue){
    switch (langue){
        case btLanguage::X : return "X"; break;
        case btLanguage::FRA : return "FRA"; break;
        case btLanguage::INT : return "INT"; break;
        case btLanguage::NA : return "NA"; break;
        default: return "ERROR";break;
    }
}

std::string_view Game::toString(btMainCategory category){
    switch (category){
        case btMainCategory::X : return "X"; break;
        case btMainCategory::TRAD_GAME : return "TRAD GAME"; break;
        case btMainCategory::EXTRA_GAME : return "EXTRA GAME"; break;
        case btMainCategory::SPECIAL_GAME : return "SPECIAL GAME"; break;
        default: return "ERROR";break;
    }
}

std::string_view Game::toString(btSubCategory category){
    switch (category){
        case btSubCategory::X : return "X"; break;
        
        case btSubCategory::TRADITIONAL : return "TRADITIONAL"; break;
        
        case btSubCategory::MOVIE : return "MOVIE"; break;
        case btSubCategory::TV_SHOW : return "TV SHOW"; break;
        case btSubCategory::SBIG : return "BOUSES DECENNIE"; break;
        case btSubCategory::COVER : return "COVER"; break;
        case btSubCategory::DUET : return "DUET"; break;
        case btSubCategory::CHORUS : return "CHORUS"; break;
        case btSubCategory::RIFF : return "RIFF"; break;
        case btSubCategory::NAMES : return "NAMES"; break;
        case btSubCategory::CITIES : return "CITIES"; break;
        
        case btSubCategory::PETIT_BAC : return "PETIT BAC"; break;
        case btSubCategory::BURGER_MORT : return "BURGER DE LA MORT"; break;
        case btSubCategory::TIROIRS : return "BLIND TEST TIROIRS"; break;
        case btSubCategory::MIME : return "MIME"; break;
        case btSubCategory::TABOO : return "MOTS INTERDITS"; break;

        default: return "ERROR";break;
    }

}

int  Game::getRandomValue(int MaxValue) noexcept {
    std::uniform_int_distribution<> distrib(0, MaxValue); // Distribution entière entre 0 et MaxValue inclus
    return  distrib(gen); // Génération d'une valeur aléatoire
}

void    Game::setMainCategory(bool update){
    
    if ((update == false) && (this->getMainCategory() != btMainCategory::X)) throw std::logic_error("Main category already set.");

    this->resetSubCategory();
    this->resetPeriod();
    this->resetLangue();

    int rdMainCat = this->getRandomValue(2);

    switch(rdMainCat){
        case 0 : this->iSetMainCategory(btMainCategory::TRAD_GAME);break;
        case 1 : this->iSetMainCategory(btMainCategory::EXTRA_GAME);break;
        case 2 : this->iSetMainCategory(btMainCategory::SPECIAL_GAME);break;
        default : throw std::out_of_range("Error while setting Main category.");break;
    }
}

void    Game::SetSubCategoryForExtraGame(int index){
    switch(index){
        case 0 : this->iSetSubCategory(btSubCategory::MOVIE);break;
        case 1 : this->iSetSubCategory(btSubCategory::TV_SHOW);break;
        case 2 : this->iSetSubCategory(btSubCategory::SBIG);break;
        case 3 : this->iSetSubCategory(btSubCategory::COVER);break;
        case 4 : this->iSetSubCategory(btSubCategory::DUET);break;
        case 5 : this->iSetSubCategory(btSubCategory::CHORUS);break;
        case 6 : this->iSetSubCategory(btSubCategory::RIFF);break;
        case 7 : this->iSetSubCategory(btSubCategory::NAMES);break;
        case 8 : this->iSetSubCategory(btSubCategory::CITIES);break;
        default : throw std::out_of_range("Error while setting Sub category.");break;
    }
}

void    Game::SetSubCategoryForSpecialGame(int index){
    switch(index){
        case 0 : this->iSetSubCategory(btSubCategory::PETIT_BAC);break;
        case 1 : this->iSetSubCategory(btSubCategory::BURGER_MORT);break;
        case 2 : this->iSetSubCategory(btSubCategory::TIROIRS);break;
        case 3 : this->iSetSubCategory(btSubCategory::MIME);break;
        case 4 : this->iSetSubCategory(btSubCategory::TABOO);break;
        default : throw std::out_of_range("Error while setting Sub category.");break;
    }   
}

void    Game::setSubCategory(bool update){
    
    if (this->getMainCategory() == btMainCategory::X) throw std::logic_error("Main category needs to be set before sub category");
    if ((update == false) && (this->getSubCategory() != btSubCategory::X)) throw std::logic_error("Sub category already set.");

    this->resetPeriod();
    this->resetLangue();

    switch (this->getMainCategory()){
        case btMainCategory::TRAD_GAME : 
            this->iSetSubCategory(btSubCategory::TRADITIONAL);
            break;
        
        case btMainCategory::EXTRA_GAME : 
            this->SetSubCategoryForExtraGame(this->getRandomValue(8));
            break;
        case btMainCategory::SPECIAL_GAME :
            this->SetSubCategoryForSpecialGame(this->getRandomValue(4));
            break;
            
        default : throw std::out_of_range("Error while setting Sub Category"); break;
        
    }

}

Game::btLanguage  Game::getRandomLanguage() {
    int rdlang = this->getRandomValue(1);
    switch (rdlang){
        case 0 : return btLanguage::FRA;break;
        case 1 : return btLanguage::INT;break;
        default : throw std::out_of_range("Error while setting Language"); break;
    }
}

Game::btPeriod    Game::getRandomPeriod(){
    int rdper = this->getRandomValue(6);
    switch(rdper){
        case 0 : return btPeriod::OLDIES;break;
        case 1 : return btPeriod::SEVENTIES;break;
        case 2 : return btPeriod::EIGHTIES;break;
        case 3 : return btPeriod::NINETIES;break;
        case 4 : return btPeriod::Y2K0X;break;
        case 5 : return btPeriod::Y2K1X;break;
        case 6 : return btPeriod::Y2K2X;break;

        default : throw std::out_of_range("Error while setting Period"); break;
    }
}

void    Game::setPeriodAndLanguage(bool update){
    if (this->getMainCategory() == btMainCategory::X) throw std::logic_error("Main category needs to be set before Language or Period");
    if (this->getSubCategory() == btSubCategory::X) throw std::logic_error("Sub category needs to be set before Language or Period");
    if ((update == false) && (this->getPeriod() != btPeriod::X)) throw std::logic_error("Period is already set.");
    if ((update == false) && (this->getLangue() != btLanguage::X)) throw std::logic_error("Language is already set.");

    this->resetPeriod();
    this->resetLangue();

    switch(this->getSubCategory()){
        /** YES / YES Subcategories */
        case btSubCategory::TRADITIONAL:
        case btSubCategory::SBIG:
        case btSubCategory::DUET:
            this->iSetPeriod(this->getRandomPeriod());
            this->iSetLanguage(this->getRandomLanguage());
            break;
        
        /** YES / NO Subcategories */    
        case btSubCategory::MOVIE:
        case btSubCategory::TV_SHOW:
            this->iSetPeriod(this->getRandomPeriod());
            this->iSetLanguage(btLanguage::NA);
            break;
        
        /** NO / YES Subcategories */    
        case btSubCategory::COVER:
        case btSubCategory::NAMES:
        case btSubCategory::CITIES:
        case btSubCategory::PETIT_BAC:
        case btSubCategory::BURGER_MORT:
            this->iSetPeriod(btPeriod::NA); 
            this->iSetLanguage(this->getRandomLanguage());
            break;

        /** NO / NO Subcategories */    
        case btSubCategory::CHORUS:
        case btSubCategory::RIFF:
        case btSubCategory::TIROIRS:
        case btSubCategory::MIME:
        case btSubCategory::TABOO:
            this->iSetPeriod(btPeriod::NA); 
            this->iSetLanguage(btLanguage::NA);
            break;

        default : throw std::out_of_range("Error while setting Period or Language"); break;
    }

}

Game::GameUID Game::getGameUID(){
    GameUID Uid{0};
    uint32_t tmp;

    if (this->isGameValid() == false) throw std::logic_error("Game is not valid.");

    tmp = std::to_underlying(this->getMainCategory());
    tmp <<=24;
    Uid += tmp;

    tmp = std::to_underlying(this->getSubCategory());
    tmp <<=16;
    Uid += tmp;

    tmp = std::to_underlying(this->getPeriod());
    tmp <<=8;
    Uid += tmp;

    tmp = std::to_underlying(this->getLangue());
    Uid += tmp;

    return Uid;
}

Game::btMainCategory Game::getMainCategoryFromSubCategory(btSubCategory subcat) noexcept{
    switch(subcat){
        case btSubCategory::TRADITIONAL : return btMainCategory::TRAD_GAME;break;

        case btSubCategory::MOVIE:
        case btSubCategory::TV_SHOW:
        case btSubCategory::SBIG:
        case btSubCategory::COVER:
        case btSubCategory::DUET:
        case btSubCategory::CHORUS:
        case btSubCategory::RIFF:
        case btSubCategory::NAMES:
        case btSubCategory::CITIES:
            return btMainCategory::EXTRA_GAME;
            break;

        case btSubCategory::PETIT_BAC:
        case btSubCategory::BURGER_MORT:
        case btSubCategory::TIROIRS:
        case btSubCategory::MIME:
        case btSubCategory::TABOO:
            return btMainCategory::SPECIAL_GAME;
            break;
        
        default : return btMainCategory::X;break;
    }
}



