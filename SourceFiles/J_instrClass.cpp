#include "../Headers/J_instrClass.hpp"

J_Instructions::J_Instructions(){}

J_Instructions::J_Instructions(const std::string & op, const int & address)
    : Instructions(op)
{
    J_Instructions::setAddress(address);
}



void J_Instructions::setAddress(const int & address){
    if(address < pow(2, 26))
        J_Instructions::address = std::bitset<26>(address);
     else
        throw std::invalid_argument("The argument passed as address is too large"); 
}

std::string J_Instructions::getAddress() const
{
    return J_Instructions::address.to_string();
}

 std::string J_Instructions::MachineCodeString(machineFormat some ) const  {
     return Instructions::MachineCodeString(machineFormat::Binary) + J_Instructions::address.to_string();
}