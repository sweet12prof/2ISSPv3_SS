#include "../Headers/I_instrClass.hpp"

I_Instruction::I_Instruction(){}

I_Instruction::I_Instruction(const std::string & op, const int & rs, const int & rt, const int & Imm)
    : RI_Instruction(op, rs, rt)
{
    I_Instruction::setImmediate(Imm);
}

void I_Instruction::setImmediate(const int & Imm){
    if(Imm < pow(2, Imm))
        this->Immediate = std::bitset<16>(Imm);
    else 
        throw std::invalid_argument("The value provided for the immediate is too large");
}

std::string I_Instruction::getImmediate() const {
    return this->Immediate.to_string();
}


std::string I_Instruction::MachineCodeString(machineFormat some) const {
    return RI_Instruction::MachineCodeString(machineFormat::Binary) + I_Instruction::getImmediate();
}