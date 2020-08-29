#include "../../Headers/IM_hpp/Instr_BaseClass.hpp"
 
 Instructions::Instructions(){}

 Instructions::Instructions(const std::string & opCode, const std::string & someLabel)
    :label{someLabel}, opCodeString{opCode}
{
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
    
        
      if (some == Instructions::machineFormat::S_tring)
        {
            std::stringstream stream;
            stream << Instructions::getLabel();  //<< (Instructions::getLabel() == "" ? "" : ": ");
            stream << (Instructions::getopCodeString() + " ");
            return stream.str();  
        } 

      else 
            return getOpcode();
}


std::string Instructions::nopInstruction(Instructions::machineFormat some){
    std::bitset<32>returnVal(0);
    if(some == Instructions::machineFormat::Binary){
      
        return returnVal.to_string();
    }

    else if(some == Instructions::machineFormat::S_tring)
        return "nop";
    
    else  
        {
            auto p = returnVal.to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
             
            return "0x" + output.str();  
        }


       // output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
}

std::string Instructions::getLabel() const{
    return Instructions::label;
}

void Instructions::setLabel(const std::string & somelabel){
    Instructions::label = somelabel;
}
    

std::string Instructions::getopCodeString() const {
    return this->opCodeString;
}

void Instructions::setOpcodeString(const std::string & OpcodeString) {
    Instructions::opCodeString = OpcodeString;
}

Instructions::InstrType Instructions::getInstrType2(const std::string &someOp){
     auto p {Instructions::varInstr2.find(someOp)};
     if(p == Instructions::varInstr2.end())
        throw std::invalid_argument ("Undefined Operation");
    else {
            return (Instructions::InstrType)(p->second).first;
           
        }   
}


std::map < std::string, std::pair <int, int > > Instructions::varInstr2 = {
        {"add", {1, 12}}, 
        {"sub", {1, 29}},
        {"addi", {2, 25}},
        {"mfc", {4, 31}},
        {"J", {3, 21}}, 
        {"nop", {6, 0}}, 
        {"beq", {2, 15}} ,
        {"lw", {2, 13}}, 
        {"sw", {2, 5}}
    };