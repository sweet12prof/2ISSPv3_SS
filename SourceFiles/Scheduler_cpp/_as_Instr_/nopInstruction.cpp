#include "../../../Headers/IM_hpp/nopInstruction.hpp"

NOP_Instruction::NOP_Instruction(){}

 NOP_Instruction::NOP_Instruction(const std::string & op, const std::string &opLabel)
    :Instructions(op, opLabel)
 {
     NOP_Instruction::OtherBits = std::bitset<26>(0);
 }


void NOP_Instruction::setOtherBits(){
    NOP_Instruction::OtherBits = std::bitset<26>(0);
}

std::string NOP_Instruction::getOtherBits() const {
    return NOP_Instruction::OtherBits.to_string();
}

std::string NOP_Instruction::MachineCodeString(Instructions::machineFormat some) const {
    std::string preResult{Instructions::MachineCodeString(Instructions::machineFormat::Binary)};
    std::string FinalResult;
    switch(some){
        case Instructions::machineFormat::Binary :
            FinalResult = preResult + NOP_Instruction::OtherBits.to_string();
        break;

        case Instructions::machineFormat::S_tring :
            FinalResult = NOP_Instruction::getopCodeString();
        break;

        case Instructions::machineFormat::Decimal :
            {
                std::stringstream Output;
                Output << std::hex << std::showbase << std::bitset<6>(NOP_Instruction::getOpcode()) <<  std::bitset<26>(NOP_Instruction::getOtherBits());
            }
        break;
    }
}
