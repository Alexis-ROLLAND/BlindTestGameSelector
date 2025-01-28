#ifndef __BTPERIOD_HPP__
#define __BTPERIOD_HPP__

#include "common.hpp"

#include <string_view>
#include <unordered_map>


class   btPeriod{
    public:
        
    private:
        
        
        PeriodID Id{PeriodID::X};
    public:
    btPeriod() = default;
        explicit btPeriod(PeriodID id):Id{id}{};
        virtual ~btPeriod() = default;

        [[nodiscard]] PeriodID  getID() const noexcept {return this->Id;};
        void setID(PeriodID id) noexcept {this->Id = id;};       
        
        std::string_view    to_string() const noexcept {return ListPeriods.at(this->getID());};
        void    reset() noexcept {this->setID(PeriodID::X);};
        
};


#endif  /*  __BTPERIOD_HPP__    */