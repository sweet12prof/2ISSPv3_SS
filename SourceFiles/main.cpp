#include <iostream>
#include <map>
#include <iterator>
#include "../Headers/I_instrClass.hpp"

int main(){
    // const std::map < std::string, std::pair <int, std::string > > varInstr 
    //     {
    //         {"add", {1, "add"}}, 
    //         {"sub", {2, "sub"}}, 

    // 	}; 

    // auto p = varInstr.find("add");

    // std::cout << (p->second).first;


    
    
    
        std::string op{"add"};
        int rs {20};
        int rt{5};
        int rd{31};
        int shamt{5};
        int Immediate(25089);
         I_Instruction someJ {op, rs, rt, Immediate};
         Instructions * J_Instrptr = & someJ;
         std::cout <<  (int)J_Instrptr->getInstrType() << std::endl;
         std::cout << J_Instrptr->MachineCodeString(I_Instruction::machineFormat::Binary);
    
}
