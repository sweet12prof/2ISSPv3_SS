#include "../../Headers/Scheduler_hpp/Scheduler.hpp"

Scheduler::Scheduler(Instructions *Instr_1, Instructions *Instr_2)
    : Instrpair{Instr_1, Instr_2}
{}
    

std::vector<std::string> Scheduler::schedulePair(){
    switch(Scheduler::Instrpair.first->getInstrType()){
        case Instructions::InstrType::R_Type:
          return Scheduler::R_asInstr_1(); // This can be found im ./_as_Insr_ directory
 
        break;

        case Instructions::InstrType::I_Type:
            return Scheduler::I_asInstr_1(); // This can be found im ./_as_Insr_ directory
        break;

        case Instructions::InstrType::J_Type :
            return Scheduler::J_asInstr_1(); // This can be found im ./_as_Insr_ directory
        break;

        case Instructions::InstrType::Exp :
            return Scheduler::Exp_asInstr_1(); // This can be found im ./_as_Insr_ directory
        break;

        default :
            return Scheduler::nop_Instr();      // This can be found im ./_as_Insr_ directory
   }
}

