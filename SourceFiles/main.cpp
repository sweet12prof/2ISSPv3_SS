#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include "./FileHelpers/FileHelper.hpp"
#include <array>
#include <algorithm>

std::vector<std::string>  InstructionQueue{
     "add $1 $2 $3",
     "add $4 $2 $3", 
     "beq $4 $1 jLabel",
     "sub $5 $3 $1", 
     "jLabel: addi $5, $3, $1",
     "mfc $3, $5"
};





int main()
{
     Instructions *someInstr =  createPair("       jLabel: add $5, $3, $1");
     R_Instruction * R_Instr = dynamic_cast< R_Instruction *>(someInstr);
    // std::cout << R_Instr->MachineCodeString(Instructions::machineFormat::S_tring);
          
}


