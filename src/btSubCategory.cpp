#include "btSubCategory.hpp"

void btSubCategory::setID(SubCategoryID id) noexcept{
    this->Id = id;
    this->setFilterCriteria(ListFilterCriteria.at(id));
}



