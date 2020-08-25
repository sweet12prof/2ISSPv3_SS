#include "../../Headers/IM_hpp/Instr_BaseClass.hpp"
 
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


std::string Instructions::nopInstruction(Instructions::machineFormat some){
    std::bitset<32>returnVal(0);
    if(some == Instructions::machineFormat::Binary){
      
        return returnVal.to_string();
    }
        
    else  
        {
            auto p = returnVal.to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
             
            return "0x" + output.str();  
        }


       // output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
}

    
    


