#include "../Headers/R_instrClass.hpp"

void R_Instruction::setFunct(const std::string & op){
    auto p = R_op_To_Funct.find(op);
    if(p == R_op_To_Funct.end())
        throw std::invalid_argument("The provided Opcode is not available");
    else 
        this->funct = std::bitset<6>((p->second));
}

std::string R_Instruction::getFunct() const {
    return this->funct.to_string();
}


void R_Instruction::setShamt(const int & shamt){
    if(shamt < pow(2, 5))
        this->shamt = std::bitset<5>(shamt);
    else 
        throw std::invalid_argument("The provides value for shamt is too large");
}

std::string R_Instruction::getShamt() const {
    return this->shamt.to_string();
}


std::string R_Instruction::getRd() const {
    return this->rd.to_string();
}


void R_Instruction::setRd(const int & rd){
    if(rd < pow(2, 5))
        this->rd = std::bitset<5>(rd);
    else 
        throw std::invalid_argument("The provides value for Rd is too large");
}


R_Instruction::R_Instruction() {};

R_Instruction::R_Instruction(const std::string & op, const int & rs, const int & rt, const int & rd, const int & shamt)
    :RI_Instruction(op, rs, rt)   
{
    R_Instruction::setFunct(op);
    R_Instruction::setShamt(shamt);
    R_Instruction::setRd(rd);
}


std::string R_Instruction::MachineCodeString(Instructions::machineFormat some) const {
    std::string returnString = RI_Instruction::MachineCodeString(machineFormat::Binary) + R_Instruction::getRd() +  R_Instruction::getShamt() + R_Instruction::getFunct(); 
    if(some == machineFormat::Binary)
        return returnString;
    else {
           
            auto p = std::bitset<32>(returnString).to_ulong();
             std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
            return output.str();   
    }
};

