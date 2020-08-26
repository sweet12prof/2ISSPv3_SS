#include "../../Headers/IM_hpp/I_instrClass.hpp"
I_Instruction::I_Instruction(){}

I_Instruction::I_Instruction(const std::string & op, const int & rs, const int & rt, const int & Imm, const std::string &optionalLabel, const std::string &optionalimmediateLabel)
    : RI_Instruction(op, rs, rt, optionalLabel), ImmediateLabel{optionalimmediateLabel}
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
    std::string returnString {RI_Instruction::MachineCodeString(machineFormat::Binary) + I_Instruction::getImmediate()};
        if(some == Instructions::machineFormat::Binary)
            return returnString;
        else if(some == Instructions::machineFormat::S_tring)
        {
            std::string someString { RI_Instruction::MachineCodeString(machineFormat::S_tring)};
            std::stringstream output;
            if(I_Instruction::ImmediateLabel != "")
                output << someString 
                       << " " 
                       <<I_Instruction::getImmediateLabel();
            else 
                output << someString 
                        << "(" 
                        << std::dec
                        <<  I_Instruction::Immediate.to_ulong()
                        <<  ")";


            return output.str();
        }
        else{
            auto p =std::bitset<32>(returnString).to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
            return output.str();   
        } 
            
    
}

void I_Instruction::setItype_Type(const std::string & op){
    auto p = I_Type_Types.find(op);

    if(p == I_Type_Types.end())
        throw std::invalid_argument("Undefined Opcode specified");
    else {
            this->iType_Type = static_cast<I_Instruction::I_Type>(p->second);
    }
        
}


I_Instruction::I_Type I_Instruction::getIType_Type() const {
    return this->iType_Type;
}

std::string I_Instruction::getImmediateLabel() const{
    return I_Instruction::ImmediateLabel;
}

void I_Instruction::setImmediateLabel(const std::string & labelInput){
    this->ImmediateLabel = labelInput;
}