#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string_view>
#include <random>
#include <stdexcept>
#include <utility>
#include <unordered_map>
#include <print>

#include "common.hpp"
#include "btMainCategory.hpp"
#include "btSubCategory.hpp"
#include "btPeriod.hpp"
#include "btLanguage.hpp"



class Game{
    public:
        using   GameUID = uint32_t;
        enum class gameStatus_t{RESET_STATE, IN_PROGRESS, COMPLETE};
        
    private:
        std::random_device rd;  // Entropie pour initialiser le moteur
        std::mt19937 gen{rd()}; // Générateur Mersenne Twister
        [[nodiscard]] int  getRandomValue(int MaxValue) noexcept;

        gameStatus_t    Status{gameStatus_t::RESET_STATE};
        gameStatus_t    getStatus() noexcept {return this->Status;};
        void            setStatus(gameStatus_t status) noexcept {this->Status = Status;};

        btMainCategory  MainCategory{MainCategoryID::X};
        btSubCategory   SubCategory{SubCategoryID::X};
        btPeriod        Period{PeriodID::X};
        btLanguage      Language{LanguageID::X};
        

    public:
        Game() = default;
        virtual ~Game() = default;

        /**
         * @brief   Resest all the Game params (Main Catégory, Sub Category, Period and Language)
         */
        void    Reset() noexcept;

        /** 
         * @brief   Choose a Main Category
         * @param   id 
         * @return  true if OK
         *          false if another param is already st (subcategory, Period or Language)
         * 
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
         */
        bool    ChooseSubCategory(SubCategoryID id) noexcept;

        /**
         * @brief   prints the game summary 
         *          
         * */
        void    printInfo() noexcept;
        

        

};










#endif  /* __GAME_HPP__  */

