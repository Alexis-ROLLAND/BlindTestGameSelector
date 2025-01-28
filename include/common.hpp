#ifndef __COMMON_HPP__
#define __COMMON_HPP__

#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <string_view>

using   FilterCriteria = std::pair<bool,bool>;        /** first = period, second = langauge */

enum class MainCategoryID{
    X = 0,
    TRAD_GAME = 1,
    EXTRA_GAME = 2,
    SPECIAL_GAME = 3,
    NA = 4
};

enum class SubCategoryID{
    X = 0,
    TRADITIONAL = 1,
    MOVIE = 2,
    TV_SHOW = 3,
    SBIG = 4,
    COVER = 5,
    DUET = 6,
    CHORUS = 7,
    RIFF = 8,
    NAMES = 9,
    CITIES = 10,
    PETIT_BAC = 11,
    BURGER_MORT = 12,
    TIROIRS = 13,
    MIME = 14,
    TABOO = 15,
    NA = 16
};

enum class PeriodID{    
    X = 0,          /**< Non initialisé         */ 
    OLDIES = 1,     /**< Avant 1970 (DATE < 1970) */
    SEVENTIES = 2,  /**< DATE entre 1970 et 1979 */
    EIGHTIES = 3,   /**< DATE entre 1980 et 1989*/
    NINETIES = 4,   /**< DATE entre 1990 et 1999 */
    Y2K0X = 5,      /**< DATE entre 2000 et 2009 */
    Y2K1X = 6,      /**< DATE entre 2010 et 2019 */
    Y2K2X = 7,      /**< DATE entre 2020 et 2029 */ 
    NA = 8          /**< Valeur Non Applicable (pas prise en compte par le jeu) */
};

enum class LanguageID{  
    X = 0,          /**< Non initialisé         */ 
    FRA = 1,        /**< FRAnçais */
    INT = 2,        /**< INTernational */
    NA = 3         /**< Valeur Non Applicable (pas prise en compte par le jeu) */
};

const   std::unordered_map<MainCategoryID,std::string_view> ListMainCategories{ 
    {MainCategoryID::X,"X"},
    {MainCategoryID::TRAD_GAME,"TRAD GAME"},
    {MainCategoryID::EXTRA_GAME,"EXTRA GAME"},
    {MainCategoryID::SPECIAL_GAME,"SPECIAL GAME"},
    {MainCategoryID::NA,"NOT APPLICABLE"}
};  

const   std::unordered_map<SubCategoryID,std::string_view> ListSubCategories{ 
    {SubCategoryID::X,"X"},
    {SubCategoryID::TRADITIONAL,"TRADITIONAL"},
    {SubCategoryID::MOVIE,"MOVIE"},
    {SubCategoryID::TV_SHOW,"TV SHOW"},
    {SubCategoryID::COVER,"COVER"},
    {SubCategoryID::DUET,"DUET"},
    {SubCategoryID::CHORUS,"CHORUS"},
    {SubCategoryID::RIFF,"RIFF"},
    {SubCategoryID::NAMES,"NAMES"},
    {SubCategoryID::CITIES,"CITIES"},
    {SubCategoryID::PETIT_BAC,"PETIT BAC"},
    {SubCategoryID::BURGER_MORT,"BURGER DE LA MORT"},
    {SubCategoryID::TIROIRS,"BLIND TEST A TIROIRS"},
    {SubCategoryID::MIME,"MIME"},
    {SubCategoryID::TABOO,"MOTS INTERDITS"},
    {SubCategoryID::NA,"NOT APPLICABLE"}
};   

const   std::unordered_map<SubCategoryID,FilterCriteria> ListFIlterCriteria{
    {SubCategoryID::X,{false,false}},
    {SubCategoryID::TRADITIONAL,{true,true}},
    {SubCategoryID::MOVIE,{true,false}},
    {SubCategoryID::TV_SHOW,{true,false}},
    {SubCategoryID::COVER,{false,true}},
    {SubCategoryID::DUET,{true,true}},
    {SubCategoryID::CHORUS,{false,false}},
    {SubCategoryID::RIFF,{false,false}},
    {SubCategoryID::NAMES,{false,true}},
    {SubCategoryID::CITIES,{false,true}}, 
    {SubCategoryID::PETIT_BAC,{false,true}},
    {SubCategoryID::BURGER_MORT,{false,true}},
    {SubCategoryID::TIROIRS,{false,false}},
    {SubCategoryID::MIME,{false,false}},
    {SubCategoryID::TABOO,{false,false}},  
    {SubCategoryID::NA,{false,false}}      
};

const   std::unordered_map<PeriodID,std::string_view> ListPeriods{
    {PeriodID::X,"X"},
    {PeriodID::OLDIES,"OLDIES"},
    {PeriodID::SEVENTIES,"SEVENTIES"},
    {PeriodID::EIGHTIES,"EIGHTIES"},
    {PeriodID::NINETIES,"NINETIES"},
    {PeriodID::Y2K0X,"ANNEES 2000"},
    {PeriodID::Y2K1X,"ANNEES 2010"},
    {PeriodID::Y2K2X,"ANNEES 2020"},    
    {PeriodID::NA,"NOT APPLICABLE"}
};

const   std::unordered_map<LanguageID,std::string_view> ListLanguages{
    {LanguageID::X,"X"},
    {LanguageID::FRA,"FRA"},
    {LanguageID::INT,"INT"},
    {LanguageID::NA,"NOT APPLICABLE"},
};

const   std::unordered_set<SubCategoryID>   allowed_sub_Main_X{SubCategoryID::X};
const   std::unordered_set<SubCategoryID>   allowed_sub_Main_Trad{SubCategoryID::TRADITIONAL};
const   std::unordered_set<SubCategoryID>   allowed_sub_Main_Extra{ SubCategoryID::MOVIE, 
                                                                    SubCategoryID::TV_SHOW,
                                                                    SubCategoryID::SBIG,
                                                                    SubCategoryID::COVER,
                                                                    SubCategoryID::DUET,
                                                                    SubCategoryID::CHORUS,
                                                                    SubCategoryID::RIFF,
                                                                    SubCategoryID::NAMES,
                                                                    SubCategoryID::CITIES};
const   std::unordered_set<SubCategoryID>   allowed_sub_Main_Special{   SubCategoryID::PETIT_BAC, 
                                                                        SubCategoryID::BURGER_MORT,
                                                                        SubCategoryID::TIROIRS,
                                                                        SubCategoryID::MIME,
                                                                        SubCategoryID::TABOO};
const   std::unordered_set<SubCategoryID>   allowed_sub_Main_NA{SubCategoryID::NA};   

const   std::unordered_map<MainCategoryID,std::unordered_set<SubCategoryID>> ListAllowedSubCategories{
                                                                                        {MainCategoryID::X, allowed_sub_Main_X},
                                                                                        {MainCategoryID::TRAD_GAME, allowed_sub_Main_Trad},
                                                                                        {MainCategoryID::EXTRA_GAME, allowed_sub_Main_Extra},
                                                                                        {MainCategoryID::SPECIAL_GAME, allowed_sub_Main_Special},
                                                                                        {MainCategoryID::NA, allowed_sub_Main_NA}

}; 

#endif  /*  __COMMON_HPP__  */