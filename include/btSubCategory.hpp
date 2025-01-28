#ifndef __BTSUBCATEGOTY_HPP__
#define __BTSUBCATEGOTY_HPP__


#include <unordered_map>
#include <string_view>

#include "common.hpp"
#include "btMainCategory.hpp"


class   btSubCategory{
    public:
        
        
    private:
    
    
        MainCategoryID MainCatID{MainCategoryID::X};
        SubCategoryID  Id{SubCategoryID::X};
        FilterCriteria  Filter{};

        MainCategoryID getMainCategoryID(SubCategoryID id);

        void    setMainCategoryID(MainCategoryID id) noexcept {this->MainCatID = id;};
        void    setFilterCriteria(const FilterCriteria &filter) noexcept {this->Filter = filter;};
    public:
        btSubCategory() = default;
        explicit btSubCategory(SubCategoryID id):Id{id}{};
        virtual ~btSubCategory() = default;

        [[nodiscard]] SubCategoryID  getID() const noexcept {return this->Id;};
        void setID(SubCategoryID id) noexcept; 
        
        std::string_view    to_string() const noexcept {return ListSubCategories.at(this->getID());};
        void    reset() noexcept {this->setID(SubCategoryID::X);};

        MainCategoryID getMainCatID() const noexcept {return this->MainCatID;}; 
        FilterCriteria getFilterCriteria() const noexcept {return this->Filter;};
        
    };




#endif  /*  __BTSUBCATEGOTY_HPP__   */