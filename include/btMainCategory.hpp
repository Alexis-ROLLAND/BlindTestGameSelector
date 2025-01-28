#ifndef     __BTMAINCATEGORY_HPP__
#define     __BTMAINCATEGORY_HPP__

#include "common.hpp"

#include <unordered_map>
#include <unordered_set>
#include <string_view>


class   btMainCategory{
    public:
        
    private:
        

        
        MainCategoryID  Id{MainCategoryID::X};
    public:
        btMainCategory() = default;
        explicit btMainCategory(MainCategoryID id):Id{id}{};
        virtual ~btMainCategory() = default;

        [[nodiscard]] MainCategoryID  getID() const noexcept {return this->Id;};
        void setID(MainCategoryID id) noexcept {this->Id = id;};       
        
        std::string_view    to_string() const noexcept {return ListMainCategories.at(this->getID());};
        void    reset() noexcept {this->setID(MainCategoryID::X);};

        std::unordered_set<SubCategoryID>   getListAllowedSubCategories() noexcept {return ListAllowedSubCategories.at(this->getID());};

};



#endif  /*  __BTMAINCATEGORY_HPP__  */