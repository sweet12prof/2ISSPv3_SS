#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include "./FileHelpers/FileHelper.hpp"
#include <array>
#include <algorithm>
#include <string>
std::vector<std::string>  InstructionQueue{
     "add $1 $2 $3",
     "add $4 $2 $3", 
     "beq $4 $1 jLabel",
     "sub $5 $3 $1", 
     "jLabel: addi $5, $3, $1",
     "mfc $3, $5"
};

 


 std::stringstream parseString(std::string);

int main()
{
     int i{0};
      std::array <std::string, 2> test{
          "sub $3 $2 $1",
          "add $4 $2 $3" 
      };

     std::array <Instructions *, 2> res =  createPair(test);

     R_Instruction * r1 = dynamic_cast<R_Instruction *> (res.at(1));
     
     R_Instruction * r2 = dynamic_cast<R_Instruction *> (res.at(0));
     
     std::cout << "string is " << r2->MachineCodeString(Instructions::machineFormat::S_tring);
      std::cout << r1->MachineCodeString(Instructions::machineFormat::S_tring);
     // std::cout << r2->MachineCodeString(Instructions::machineFormat::S_tring);
     // std::cout << r1->MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;
     // std::cout << r2->MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;

     Scheduler newSchd{res.at(0), res.at(1) };

     for(auto item : newSchd.schedulePair())
          std::cout << item << std::endl;


     
}


 

