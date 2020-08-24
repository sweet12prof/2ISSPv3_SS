#include "../../Headers/Scheduler_hpp/Scheduler.hpp"

Scheduler::Scheduler(Instructions *Instr_1, Instructions *Instr_2)
    : Instrpair{Instr_1, Instr_2}
{}
    

std::vector<std::string> Scheduler::schedulePair(){
    switch(Scheduler::Instrpair.first->getInstrType()){
        case Instructions::InstrType::R_Type:
           return Scheduler::R_asInstr_1();
 
        break;

        case Instructions::InstrType::I_Type:
            return Scheduler::I_asInstr_1();
        break;

        case Instructions::InstrType::J_Type :
            return Scheduler::J_asInstr_1();
        break;

        case Instructions::InstrType::Exp :
            return Scheduler::Exp_asInstr_1();
        break;

        default :
            return Scheduler::nop_Instr();
   }
}

std::vector<std::string> Scheduler::R_asInstr_1(){
    R_Instruction * Instr1_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.first); 
    switch(Scheduler::Instrpair.second->getInstrType()){
      
        case Instructions::InstrType::R_Type:
           {
                
                R_Instruction * Instr2_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.second);
                if( (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs()) || (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt()))
                    return std::vector<std::string>{Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                            nopInstruction(Instructions::machineFormat::Decimal), Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)};
                else 
                     return std::vector<std::string>{Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                            Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)};
           }
        break;

        case Instructions::InstrType::I_Type :
            {
                I_Instruction * Instr2_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.second);
            }
        break;
            
    }
                  
}