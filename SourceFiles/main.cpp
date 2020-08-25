#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include <array>

int main(){
        std::string op{"mfc"};
        std::string Rop{"add"};
        std::string Iop{"beq"};
        std::string Iop2{"addi"};
        std::string jop{"J"};
        std::string nop{"nop"};
        int rs {20};
        int rt{5};
        int rd{31};
        int shamt{5};
        int Immediate(25089);
        int adr{24502};

        R_Instruction R_Instr{Rop, rs, rt, rd, shamt};
        //R_Instruction R_Instr2{Rop, rs, rd, rt, shamt};
        
        I_Instruction I_Instr{Iop, rs, rt, Immediate};
        
        J_Instructions J_Instr{jop, adr};
        
        Exp_Instructions Exp_Instr{op, rt, rd};
        

        Scheduler Schd{ &I_Instr, &R_Instr};

        

        for(auto item : Schd.schedulePair())
             std::cout << item << std::endl;


        //  std::array <Instructions *, 4> InstrPtr {&R_Instr, &Exp_Instr, &I_Instr, &J_Instr};
        //  std::cout << nopInstruction(Instructions::machineFormat::Decimal) << std::endl << std::endl;

        // std::cout << "Checking if nop is an Instruction " << getInstructionType(nop) << std::endl; 

        //  for(auto item : InstrPtr){
        //     std::cout << (int)item->getInstrType() << std::endl;
        //     std::cout << item->MachineCodeString(Instructions::machineFormat::Binary) << std::endl << std::endl;
        // } 

       // std::cout << I_Instr.MachineCodeString(Instructions::machineFormat::Binary);
    
}
