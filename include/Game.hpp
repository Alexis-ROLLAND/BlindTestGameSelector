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


constexpr   int     MAX_ID_MAIN_CATEGORY{2};
constexpr   int     MAX_ID_SUB_CATEGORY{14};
constexpr   int     MAX_ID_PERIOD{7};
constexpr   int     MAX_ID_LANGUAGE{2};

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
         * @brief   fills the main category with a random value
         * 
         * @return  true if OK
         *          false otherwise
         * @attention :     The main category cannot be set if another param is 
         *                  already set (subcategory, Period or Language)
         */
        bool    setRandomMainCategory(bool forceReset = false) noexcept;

        /**
         * @brief   chose a Sub Category
         * @param   id
         * @param   bool forceMainCategory
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Subcategory needs (OR) :
         *                  - An empty (X) Main Category - Main Category will be updated, regardless of forceMainCategory value
         *                  - The correct main category already set   
         *                  - The "forceMainCategory" param set to true (false by default) - In this case the Main Category is updated if needed.
         */
        bool    ChooseSubCategory(SubCategoryID id, bool forceMainCategory = false) noexcept;

        /**
         * @brief   randomly sets a Sub Category
         * @param   bool forceMainCategory (false)
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Subcategory needs (OR) :
         *                  - An empty (X) Main Category 
         *                  - The correct main category already set   
         *                  - The "forceMainCategory" param set to true (false by default) - In this case the Main Category is updated if needed.
         */
        bool    setRandomSubCategory(bool forceMainCategory = false) noexcept;

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
         * @brief   randomly chose a Period
         * 
         * @param   bool forceFill  : Forces the Period setting if Sub Category is unset 
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Period needs : 
         *                  - A correct id (different from X)
         *                  - A correct matching with a set Sub Category (via the FilterCriteria value) - Regardless of the ForceFill value   
         *                  - An unset Subcategory AND the forceFill paramater set to true 
         */
        bool    setRandomPeriod(bool forceFill = false) noexcept;

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
         * @brief   chose a Language
         * @param   forcefill
         * @return  true if OK
         *          false otherwise
         * @attention   To be set the Language needs : 
         *                  - A correct id (different from X)
         *                  - A correct matching with a set Sub Category (via the FilterCriteria value) - Regardless of the ForceFill value  
         *                  - An unset Subcategory AND the forceFill paramater set to true 
         */
        bool    setRandomLanguage(bool forceFill = false) noexcept;

        /**
         * @brief   Creates a full random game.operator delete[]
         * 
         * @return  true if OK
         *          false otherwise
         * 
         * @attention : A game resets is performed before creating the ransom game. 
         *              The return value should never be false.
         */
        bool    makeFullRandomGame();

        /**
         * @brief   Tries to fill unset Game values with random values
         * 
         * @return  true if success
         *          false otherwise
         * 
         * @attention if all values are already set and Game is consistent, return is true.
         */
        bool    fillWithRandom();


        /**
         * @brief   Check Game consistency
         * 
         * @return  true if Game is consistent
         *          false if not
         */
        bool    isGameOK();


        /**
         * @brief   prints the game summary 
         *          
         * */
        void    printInfo() noexcept;
        

        

};










#endif  /* __GAME_HPP__  */

