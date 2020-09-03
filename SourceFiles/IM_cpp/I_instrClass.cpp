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

    std::stringstream streamrt;
    streamrt<< std::dec << std::bitset<16>( I_Instruction::getImmediate() ).to_ulong();

     std::stringstream streamrt2;
    streamrt2 << std::dec << std::bitset<16>( I_Instruction::getRt() ).to_ulong();

    std::string returnString {RI_Instruction::MachineCodeString(machineFormat::Binary) + I_Instruction::getImmediate()};
        if(some == Instructions::machineFormat::Binary)
            return returnString;
        else if(some == Instructions::machineFormat::S_tring)
        {
            std::string someString { RI_Instruction::MachineCodeString(machineFormat::S_tring)};
            std::stringstream output;
            if( (I_Instruction::getIType_Type() == I_Instruction::I_Type::Branch_Type)  )
                    output  << std::dec
                            << (I_Instruction::getLabel() != "" ?   (I_Instruction::getLabel() + ": ") : "") 
                            << (I_Instruction::getopCodeString() )
                            << " $"  
                            << std::bitset<5>(I_Instruction::getRt()).to_ulong()
                            << " $"  
                            << std::bitset<5>(I_Instruction::getRs()).to_ulong()
                            << ( " " + I_Instruction::getImmediateLabel() );

            else if( (I_Instruction::getIType_Type() == I_Instruction::I_Type::Imm_Type) )

                       output << std::dec
                                << (I_Instruction::getLabel() != "" ?   (I_Instruction::getLabel() + ": ") : "") 
                                << (I_Instruction::getopCodeString() )
                                << " $"  
                                << std::bitset<5>(I_Instruction::getRt()).to_ulong()
                                << " $"  
                                << std::bitset<5>(I_Instruction::getRs()).to_ulong()
                                << (" " + streamrt.str() );

            else 
                output  << std::dec
                        << (I_Instruction::getLabel() != "" ?   (I_Instruction::getLabel() + ": ") : "")
                        << (I_Instruction::getopCodeString() + " ")
                        << "$" 
                        <<  ( streamrt2.str() + " ")
                        <<   I_Instruction::Immediate.to_ulong() 
                        << "($" 
                        <<  std::bitset<5>(I_Instruction::getRs()).to_ulong()
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


void  I_Instruction::createI_Instruction(const std::string & op, const int & rs, const int & rt, const int & Imm, const std::string & opLabel, const std::string & opImmediateLabel){
     I_Instruction::setImmediate(Imm);
     I_Instruction::setItype_Type(op);

     I_Instruction::ImmediateLabel = opImmediateLabel;

     I_Instruction::setOpcode(op);
     I_Instruction::setOpcodeString(op);
     I_Instruction::setRs(rs);
     I_Instruction::setRt(rt);
     I_Instruction::setLabel(opLabel);
     I_Instruction::setInstrType(op);
    
}


std::map<std::string, int> I_Instruction::I_Type_Types_static = {
            {"addi", 3}, 
            {"bne", 4}, 
            {"subi", 3}, 
            {"andi", 3}, 
            {"ori", 3}, 
            {"xori", 3}, 
            {"addiu", 3}, 
            {"beq", 4},
            {"sw", 1},
            {"lw", 2}
};

I_Instruction::I_Type I_Instruction::getIType_Type_static(const std::string & op){
    auto p = I_Instruction::I_Type_Types_static.find(op);

    if(p == I_Instruction::I_Type_Types_static.end())
        throw std::invalid_argument("Undefined Opcode specified");
    else {
          return static_cast<I_Instruction::I_Type>(p->second);
    }
}