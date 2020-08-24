#include "./Exp_InstrClass.hpp"
#include "./I_instrClass.hpp"
#include "./J_instrClass.hpp"
#include "./R_instrClass.hpp"
#include <iostream>
std::string nopInstruction(Instructions::machineFormat some){
    std::bitset<32>returnVal(0);
    if(some == Instructions::machineFormat::Binary){
      
        return returnVal.to_string();
    }
        
    else  
        {
            auto p = returnVal.to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
             
            return "0x" + output.str();  
        }


       // output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
}
