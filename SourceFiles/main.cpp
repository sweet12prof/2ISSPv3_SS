#include <iostream>
#include "../Headers/all_Instr.hpp"
#include <array>

int main(){
    // const std::map < std::string, std::pair <int, std::string > > varInstr 
    //     {
    //         {"add", {1, "add"}}, 
    //         {"sub", {2, "sub"}}, 

    // 	}; 

    // auto p = varInstr.find("add");

    // std::cout << (p->second).first;

    
        std::string op{"mfc"};
        std::string Rop{"add"};
        std::string Iop{"addi"};
        std::string jop{"J"};
        int rs {20};
        int rt{5};
        int rd{31};
        int shamt{5};
        int Immediate(25089);
        int adr{24502};

        R_Instruction R_Instr{Rop, rs, rt, rd, shamt};
        I_Instruction I_Instr{Iop, rs, rt, Immediate};
        J_Instructions J_Instr{jop, adr};
        Exp_Instructions Exp_Instr{op, rt, rd};


         std::array <Instructions *, 4> InstrPtr {&R_Instr, &Exp_Instr, &I_Instr, &J_Instr};
         std::cout << nopInstruction(Instructions::machineFormat::Decimal) << std::endl << std::endl;
         for(auto item : InstrPtr){
            std::cout << (int)item->getInstrType() << std::endl;
            std::cout << item->MachineCodeString(Instructions::machineFormat::Binary) << std::endl << std::endl;
        } 

       // std::cout << I_Instr.MachineCodeString(Instructions::machineFormat::Binary);
    
}
