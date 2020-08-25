#include "../../Headers/Scheduler_hpp/Scheduler.hpp"

Scheduler::Scheduler(Instructions *Instr_1, Instructions *Instr_2)
    : Instrpair{Instr_1, Instr_2}
{}
    

std::vector<std::string> Scheduler::schedulePair(){
    std::vector<std::string> result;
    switch(Scheduler::Instrpair.first->getInstrType()){
        case Instructions::InstrType::R_Type:
         result = Scheduler::R_asInstr_1(); // This can be found im ./_as_Insr_ directory
 
        break;

        case Instructions::InstrType::I_Type:
            result = Scheduler::I_asInstr_1();// This can be found im ./_as_Insr_ directory
        break;

        case Instructions::InstrType::J_Type :
            result =  Scheduler::J_asInstr_1(); // This can be found im ./_as_Insr_ directory
        break;

        case Instructions::InstrType::Exp :
            result =  Scheduler::Exp_asInstr_1(); // This can be found im ./_as_Insr_ directory
        break;

        default :
            result =  Scheduler::nop_Instr();      // This can be found im ./_as_Insr_ directory
   }

   return result;
}

   // This can be found im ./_as_Insr_ directory
std::vector<std::string> Scheduler::Exp_asInstr_1(){ return 
            std::vector<std::string>{"1243"};} // This can be found im ./_as_Insr_ directory
std::vector<std::string> Scheduler::nop_Instr(){ return 
            std::vector<std::string>{"1243"};}      // This can be found im ./_as_Insr_ directory
            