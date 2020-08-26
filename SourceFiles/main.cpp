#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include <array>

int main(){
        std::string op{"mfc"};
        std::string Rop{"add"};
        std::string Iop{"beq"};
        std::string Iop2{"lw"};
        std::string jop{"J"};
        std::string nop{"nop"};
        int rs {20};
        int rt{5};
        int rd{31};
        int shamt{5};
        int Immediate(25089);
        int adr{24502};

         R_Instruction R_Instr{Rop, rs, rd, rd, shamt, ""};

         //std::cout << R_Instr.MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;
         R_Instruction R_Instr2{Rop, rs, rd, rt, shamt, ""};

         //std::cout << R_Instr2.MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;


        
         I_Instruction I_Instr{Iop2, rs, rt, -9999999, "JumpLabel",  "someLabel"};
         //std::cout << I_Instr.MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;

         J_Instructions J_Instr{jop, adr, "", "JumpLabel"};
        
         Exp_Instructions Exp_Instr{op, 1, 3, ""};
          //std::cout << J_Instr.MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;

          //std::cout << Exp_Instr.MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;
         Scheduler Schd{ &I_Instr,  &J_Instr};

        

         for(auto item : Schd.schedulePair())
              std::cout << item << std::endl;


        //  std::array <Instructions *, 4> InstrPtr {&R_Instr, &Exp_Instr, &I_Instr, &J_IJ_Instrnstr};
        //  std::cout << nopInstruction(Instructions::machineFormat::Decimal) << std::endl << std::endl;

        // std::cout << "Checking if nop is an Instruction " << getInstructionType(nop) << std::endl; 

        //  for(auto item : InstrPtr){
        //     std::cout << (int)item->getInstrType() << std::endl;
        //     std::cout << item->MachineCodeString(Instructions::machineFormat::Binary) << std::endl << std::endl;
        // } 

       // std::cout << I_Instr.MachineCodeString(Instructions::machineFormat::Binary);
    
     // std::string someStr {"Chris    is     a            fool"};
     // std::stringstream stream{someStr};

     // std::string s1;
     // std::string s2;
     // std::string s3;

     // stream >> s1 >> s2 >> s3;
     // std::cout <<"s1 is : " << s1 << std::endl << "s2 is " << s2 << std::endl << "s3 is " << s3;

}
