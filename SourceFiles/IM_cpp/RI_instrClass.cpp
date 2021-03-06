#include "../../Headers/IM_hpp/RI_instrClass.hpp"

RI_Instruction::RI_Instruction(){}

RI_Instruction::RI_Instruction(const std::string & op, const int & rs, const int & rt, const std::string & optionalLabel)
: Instructions(op, optionalLabel)
{
    RI_Instruction::setRs(rs);
    RI_Instruction::setRt(rt);
}


void RI_Instruction::setRs(const int & rs){
    if(rs < pow(2, 5))
        RI_Instruction::rs = std::bitset<5>(rs);
    else 
        throw std::invalid_argument("Ärgument provided as rs field is too large");
}

std::string RI_Instruction::getRs() const {
    return RI_Instruction::rs.to_string();
}


void RI_Instruction::setRt(const int & rt){
    if( rt < pow(2, 5) )
        RI_Instruction::rt = std::bitset<5>(rt);
    else 
        throw std::invalid_argument("Argument provided as rt field is too large'/Invalid");
}


std::string RI_Instruction::getRt() const {
    return RI_Instruction::rt.to_string();
}

std::string RI_Instruction::MachineCodeString(machineFormat some) const {
    if(some == machineFormat::S_tring)
        {
            std::string someString {Instructions::MachineCodeString(machineFormat::S_tring)};
            std::stringstream output;
            output << someString << std::dec << "$"<< std::bitset<5>(RI_Instruction::getRs()).to_ulong() << " "  << "$"<< std::bitset<5> (RI_Instruction::getRt()).to_ulong();
            return output.str();
        }
    else
        return Instructions::MachineCodeString(machineFormat::Binary) + RI_Instruction::getRs() + RI_Instruction::getRt();

}



