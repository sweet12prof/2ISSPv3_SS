#include "../../Headers/IM_hpp/R_instrClass.hpp"

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

R_Instruction::R_Instruction(const std::string & op, const int & rs, const int & rt, const int & rd, const int & shamt, const std::string & optionalLabel)
    :RI_Instruction(op, rs, rt, optionalLabel)   
{
    R_Instruction::setFunct(op);
    R_Instruction::setShamt(shamt);
    R_Instruction::setRd(rd);
    R_Instruction::setRType(op);
}


std::string R_Instruction::MachineCodeString(Instructions::machineFormat some) const {
    std::string returnString = RI_Instruction::MachineCodeString(machineFormat::Binary) + R_Instruction::getRd() +  R_Instruction::getShamt() + R_Instruction::getFunct(); 
    if(some == machineFormat::Binary)
        return returnString;
    else if (some == machineFormat::S_tring){
            std::stringstream output;
            if(R_Instruction::rType_Type == R_Instruction::R_Type::def_R_Type) {
                 output << std::dec
                        << (R_Instruction::getLabel() != "" ?   (R_Instruction::getLabel() + ": " ) : "") 
                        << (R_Instruction::getopCodeString() )
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRd()).to_ulong()
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRs()).to_ulong()
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRt()).to_ulong();
            }
                   
            else if(R_Instruction::rType_Type == R_Instruction::R_Type::Jr_Type){
                output << std::dec
                        << (R_Instruction::getLabel() != "" ?   (R_Instruction::getLabel() + ": " ) : "") 
                        << (R_Instruction::getopCodeString() )
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRs()).to_ulong();
            }
                     
            else {
                    output << std::dec
                        << (R_Instruction::getLabel() != "" ?   (R_Instruction::getLabel() + ": " ) : "") 
                        << (R_Instruction::getopCodeString() )
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRd()).to_ulong()
                        << " $"  
                        << std::bitset<5>(R_Instruction::getRt()).to_ulong()
                        << " $"  
                        << std::bitset<5>(R_Instruction::getShamt()).to_ulong();
            }
                    
                 return output.str();
             }
    else {
           
            auto p = std::bitset<32>(returnString).to_ulong();
             std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
            return output.str();   
    }
};



void  R_Instruction::createR_Instruction(const std::string & op, const int & rs, const int & rt, const int & rd, const int & shmt, const std::string & opLabel){
    R_Instruction::setOpcode(op);
    R_Instruction::setRs(rs);
    R_Instruction::setRd(rd);
    R_Instruction::setLabel(opLabel);
    R_Instruction::setOpcodeString(op);
    R_Instruction::setFunct(op);
    R_Instruction::setShamt(shmt);
    R_Instruction::setRt(rt);
    R_Instruction::setInstrType(op);
    R_Instruction::setRType(op);
}


std::map <std::string, int> R_Instruction::R_Types_map_struc = {
        {"add", 3},
        {"and", 3},
        {"or", 3},
        {"sub", 3},
        {"slt", 3},
        {"jr", 1},
        {"sll", 2}, 
        {"srl", 2}
};


R_Instruction::R_Type R_Instruction::getRType() const {
    return R_Instruction::rType_Type;
}

void R_Instruction::setRType(const std::string & op){
    auto p = R_Instruction::R_Types_map_struc.find(op);

    if(p == R_Instruction::R_Types_map_struc.end())
        throw std::invalid_argument("Undefined R-Type Type Operation");
    else 
        R_Instruction::rType_Type = (R_Instruction::R_Type) (p->second);

}


R_Instruction::R_Type R_Instruction::getRType_Type(const std::string & op) {
      auto p = R_Instruction::R_Types_map_struc.find(op);

    if(p == R_Instruction::R_Types_map_struc.end())
        throw std::invalid_argument("Undefined R-Type Type Operation");
    else
        return static_cast< R_Instruction::R_Type > (p->second);
}