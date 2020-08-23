#include "../Headers/Instr_BaseClass.hpp"
 
 Instructions::Instructions(){}

 Instructions::Instructions(const std::string & opCode){
    Instructions::setOpcode(opCode);
    Instructions::setInstrType(opCode);
}

Instructions::InstrType Instructions::getInstrType() const{
    return instrType;
}


 void Instructions::setInstrType(const std::string & opCode){
     auto p {Instructions::varInstr.find(opCode)};
    if(p == Instructions::varInstr.end())
        throw std::invalid_argument ("Undefined Operation");
    else {
            Instructions::instrType = (InstrType)(p->second).first;
        }
 }

void Instructions::setOpcode(const std::string & opCode){
    std::ostringstream output;
    auto p {Instructions::varInstr.find(opCode)};
    if(p == Instructions::varInstr.end())
        throw std::invalid_argument ("Undefined Operation");
    else {
            Opcode = std::bitset<6>((p->second).second);
        }
}

std::string Instructions::getOpcode() const {
    return Opcode.to_string();
}

std::string Instructions::MachineCodeString(machineFormat some) const {
    return getOpcode();
}


