#ifndef __BTSUBCATEGOTY_HPP__
#define __BTSUBCATEGOTY_HPP__


#include <unordered_map>
#include <string_view>

#include "common.hpp"
#include "btMainCategory.hpp"


class   btSubCategory{
    public:
        
        
    private:
        
        SubCategoryID   Id{SubCategoryID::X};
        FilterCriteria  Filter{};

        MainCategoryID getMainCategoryID(SubCategoryID id);

        void    setFilterCriteria(const FilterCriteria &filter) noexcept {this->Filter = filter;};
    public:
        btSubCategory() = default;
        explicit btSubCategory(SubCategoryID id):Id{id}{};
        virtual ~btSubCategory() = default;

        [[nodiscard]] SubCategoryID  getID() const noexcept {return this->Id;};
        void setID(SubCategoryID id) noexcept; 
        
        std::string_view    to_string() const noexcept {return ListSubCategories.at(this->getID());};
        void    reset() noexcept {this->setID(SubCategoryID::X);};

        FilterCriteria getFilterCriteria() const noexcept {return this->Filter;};

        bool    isSet() const noexcept {return (this->getID() == SubCategoryID::X)?false:true;};
        
    };




#endif  /*  __BTSUBCATEGOTY_HPP__   */