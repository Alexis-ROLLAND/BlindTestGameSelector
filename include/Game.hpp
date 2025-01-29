#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string_view>
#include <random>
#include <stdexcept>
#include <utility>
#include <unordered_map>
#include <print>
#include <iostream>

#include "common.hpp"
#include "btMainCategory.hpp"
#include "btSubCategory.hpp"
#include "btPeriod.hpp"
#include "btLanguage.hpp"



class Game{
    public:
        using   GameUID = uint32_t;
                
    private:
        std::random_device rd;  // Entropie pour initialiser le moteur
        std::mt19937 gen{rd()}; // Générateur Mersenne Twister
        [[nodiscard]] int  getRandomValue(int MaxValue) noexcept;

        btMainCategory  MainCategory{MainCategoryID::X};
        btSubCategory   SubCategory{SubCategoryID::X};
        btPeriod        Period{PeriodID::X};
        btLanguage      Language{LanguageID::X};
        
        MainCategoryID  getMainCategoryID(SubCategoryID id) const noexcept;

    public:
        Game() = default;
        virtual ~Game() = default;

        /**
         * @brief   Resets all the Game params (Main Catégory, Sub Category, Period and Language)
         */
        void    Reset() noexcept;

        /** 
         * @brief   Choose a Main Category
         * @param   id 
         * @return  true if OK
         *          false otherwise
         * @attention :     The main category cannot be set if another param is 
         *                  already set (subcategory, Period or Language)
         */
        bool    ChooseMainCategory(MainCategoryID id) noexcept;
        
        /**
         * @brief   chose a Sub Category
         * @param   id
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Subcategory needs (OR) :
         *                  - An empty (X) Main Category 
         *                  - The correct main category already set   
         *                  - The "forceMainCategory" param set to true (false by default) - In this case the Main Category is updated if needed.
         */
        bool    ChooseSubCategory(SubCategoryID id, bool forceMainCategory = false) noexcept;

        /**
         * @brief   chose a Period
         * @param   id              :   Period ID 
         * @param   bool forceFill  : Forces the Period setting if Sub Category is unset 
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Period needs : 
         *                  - A correct id (different from X)
         *                  - A correct matching with a set Sub Category (via the FilterCriteria value) - Regardless of the ForceFill value   
         *                  - An unset Subcategory AND the forceFill paramater set to true 
         */
        bool    ChoosePeriod(PeriodID id,bool forceFill = false) noexcept;

        /**
         * @brief   chose a Language
         * @param   id 
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Language needs : 
         *                  - A correct id (different from X)
         *                  - A correct matching with a set Sub Category (via the FilterCriteria value) - Regardless of the ForceFill value  
         *                  - An unset Subcategory AND the forceFill paramater set to true 
         */
        bool    ChooseLanguage(LanguageID id,bool forceFill = false) noexcept;

        /**
         * @brief   prints the game summary 
         *          
         * */
        void    printInfo() noexcept;
        

        

};










#endif  /* __GAME_HPP__  */

