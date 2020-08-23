#include <iostream>
#include <map>
#include <iterator>
#include "../Headers/J_instrClass.hpp"
int main(){
    // const std::map < std::string, std::pair <int, std::string > > varInstr 
    //     {
    //         {"add", {1, "add"}}, 
    //         {"sub", {2, "sub"}}, 

    // 	}; 

    // auto p = varInstr.find("add");

    // std::cout << (p->second).first;


    
    
    
        std::string op{"add"};
        int adr {20};
       J_Instructions someJ {op, adr};
         Instructions * J_Instrptr = & someJ;
         std::cout <<  (int)J_Instrptr->getInstrType() << std::endl;
         std::cout << J_Instrptr->MachineCodeString(J_Instructions::machineFormat::Binary);
    
}
