#include "../Headers/I_instrClass.hpp"
#include <iostream>
I_Instruction::I_Instruction(){}

I_Instruction::I_Instruction(const std::string & op, const int & rs, const int & rt, const int & Imm)
    : RI_Instruction(op, rs, rt)
{
    I_Instruction::setImmediate(Imm);
    I_Instruction::setItype_Type(op);
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

void I_Instruction::setItype_Type(const std::string & op){
    auto p = I_Type_Types.find(op);

    if(p == I_Type_Types.end())
        throw std::invalid_argument("Undefined Opcode specified");
    else {
            std::cout << "ne dis " << p->second << " op is " << op;
            this->iType_Type = static_cast<I_Instruction::I_Type>(p->second);
    }
        
}


I_Instruction::I_Type I_Instruction::getIType_Type() const {
    return this->iType_Type;
}