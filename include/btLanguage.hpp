#ifndef __BTLANGUAGE_HPP__
#define __BTLANGUAGE_HPP__

#include "common.hpp"

#include <string_view>
#include <unordered_map>


class   btLanguage{
    public:
        
    private:
        
        LanguageID Id{LanguageID::X};
    public:
        btLanguage() = default;
        explicit btLanguage(LanguageID id):Id{id}{};
        virtual ~btLanguage() = default;

        [[nodiscard]] LanguageID  getID() const noexcept {return this->Id;};
        void setID(LanguageID id) noexcept {this->Id = id;};       
        
        std::string_view    to_string() const noexcept {return ListLanguages.at(this->getID());};
        void    reset() noexcept {this->setID(LanguageID::X);};
       
};




#endif  /*  __BTLANGUAGE_HPP__  */