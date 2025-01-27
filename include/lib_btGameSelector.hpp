#ifndef __LIB_BTGAMESELECTOR_HPP__
#define __LIB_BTGAMESELECTOR_HPP__

#include <string_view>
#include <random>
#include <stdexcept>
#include <utility>

class Game{
    public:
        using   GameUID = uint32_t;
        enum class btMainCategory{
                                X = 0,
                                TRAD_GAME = 1,
                                EXTRA_GAME = 2,
                                SPECIAL_GAME = 3
        };

        static std::string_view toString(btMainCategory category);

        enum class btSubCategory{
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
            TABOO = 15
        };

        static std::string_view toString(btSubCategory category);

        enum class btPeriod{    X = 0,          /**< Non initialisé         */ 
                                OLDIES = 1,     /**< Avant 1970 (DATE < 1970) */
                                SEVENTIES = 2,  /**< DATE entre 1970 et 1979 */
                                EIGHTIES = 3,   /**< DATE entre 1980 et 1989*/
                                NINETIES = 4,   /**< DATE entre 1990 et 1999 */
                                Y2K0X = 5,      /**< DATE entre 2000 et 2009 */
                                Y2K1X = 6,      /**< DATE entre 2010 et 2019 */
                                Y2K2X = 7,      /**< DATE entre 2020 et 2029 */ 
                                NA = 8          /**< Valeur Non Applicable (pas prise en compte par le jeu) */
        };
        
        static std::string_view toString(btPeriod period);

        enum class btLanguage{  X = 0,          /**< Non initialisé         */ 
                                FRA = 1,        /**< FRAnçais */
                                INT = 2,        /**< INTernational */
                                NA = 3         /**< Valeur Non Applicable (pas prise en compte par le jeu) */
        };

        static std::string_view toString(btLanguage langue);

    private:
        btPeriod        Periode{btPeriod::X};
        btLanguage      Langue{btLanguage::X};
        btMainCategory  MainCategory{btMainCategory::X};
        btSubCategory   SubCategory{btSubCategory::X};
        
        
        constexpr void    resetPeriod() noexcept {this->Periode = btPeriod::X;};
        constexpr void    resetLangue() noexcept {this->Langue = btLanguage::X;};
        constexpr void    resetMainCategory() noexcept {this->MainCategory = btMainCategory::X;};
        constexpr void    resetSubCategory() noexcept {this->SubCategory = btSubCategory::X;};

        void    iSetMainCategory(btMainCategory mc) noexcept {this->MainCategory = mc;};
        void    iSetSubCategory(btSubCategory sc) noexcept {this->SubCategory = sc;};
        void    iSetPeriod(btPeriod period) noexcept {this->Periode = period;};
        void    iSetLanguage(btLanguage lang) noexcept {this->Langue = lang;};

        void    SetSubCategoryForSpecialGame(int index);
        void    SetSubCategoryForExtraGame(int index);

        std::random_device rd;  // Entropie pour initialiser le moteur
        std::mt19937 gen{rd()}; // Générateur Mersenne Twister

        [[nodiscard]] int  getRandomValue(int MaxValue) noexcept;
        [[nodiscard]] btLanguage  getRandomLanguage();
        [[nodiscard]] btPeriod    getRandomPeriod();

        [[nodiscard]] bool    isGameValid() noexcept {if (  (this->getMainCategory() == btMainCategory::X) | 
                                                            (this->getSubCategory() == btSubCategory::X) |
                                                            (this->getLangue() == btLanguage::X) |
                                                            (this->getPeriod() == btPeriod::X) ) return false;
                                                    else return true;};
        btMainCategory getMainCategoryFromSubCategory(btSubCategory subcat) noexcept;  
    public:
        Game() = default;
        virtual ~Game() = default;

        [[nodiscard]] btPeriod          getPeriod() noexcept {return this->Periode;};
        [[nodiscard]] btLanguage        getLangue() noexcept {return this->Langue;};
        [[nodiscard]] btMainCategory    getMainCategory() noexcept {return this->MainCategory;};
        [[nodiscard]] btSubCategory     getSubCategory() noexcept {return this->SubCategory;};

        void    reset() noexcept {this->resetMainCategory(); this->resetSubCategory(); this->resetPeriod(); this->resetLangue();};

        void    setMainCategory(bool update = false);
        void    setSubCategory(bool update = false);
        void    setPeriodAndLanguage(bool update = false);

        void    CreateGame() {this->setMainCategory(true); this->setSubCategory(true); this->setPeriodAndLanguage(true);};

        GameUID getGameUID();

        

        

};







#endif  /*  __LIB_BTGAMESELECTOR_HPP__  */

