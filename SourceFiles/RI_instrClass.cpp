#include "../Headers/RI_instrClass.hpp"

RI_Instruction::RI_Instruction(){}

RI_Instruction::RI_Instruction(const std::string op, const int & rs, const int & rt){

}

void RI_Instruction::setRs(const int & rs){
    if(rs < pow(2, 5))
        this->rs = std::bitset<5>(rs);
    else 
        throw std::invalid_argument("Ärgument provided as rs field is too large");
}

std::string RI_Instruction::getRs() const {
    return this->rs.to_string();
}


void RI_Instruction::setRt(const int & rt){
    if( rt < pow(2, 5) )
        this->rt = rt;
    else 
        throw std::invalid_argument("Argument provided as rt field is too large'/Invalid");
}


std::string RI_Instruction::getRt() const {
    return this->rt.to_string();
}

std::string MachineCodeString(Instructions::machineFormat  some) {

    }// Overide to produce Machine representation of Instruction



