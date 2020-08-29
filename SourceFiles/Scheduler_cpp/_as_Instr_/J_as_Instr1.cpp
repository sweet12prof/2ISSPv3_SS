#include "../../../Headers/Scheduler_hpp/Scheduler.hpp"

  std::vector<std::string> Scheduler::J_asInstr_1(){
    J_Instructions * Instr1_derivedPtr = dynamic_cast <J_Instructions *> (Scheduler::Instrpair.first);
    
    std::vector<std::string> result;
        
        switch(Scheduler::Instrpair.second->getInstrType()){
            case Instructions::InstrType::R_Type:{
                R_Instruction * Instr2_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.second); 
                result = std::vector<std::string>{
                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                    Instructions::nopInstruction(Instructions::machineFormat::S_tring),
                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                }; }
            break;

            case Instructions::InstrType::J_Type:
            {
                J_Instructions * Instr2_derivedPtr = dynamic_cast<J_Instructions *>(Instrpair.second); 
                result = std::vector<std::string>{
                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                    Instructions::nopInstruction(Instructions::machineFormat::S_tring),
                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                };
            }
            break;

            case Instructions::InstrType::I_Type:{
                I_Instruction * Instr2_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.second);

                result = std::vector<std::string>{
                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                    Instructions::nopInstruction(Instructions::machineFormat::S_tring),
                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                };}
            break;

            case Instructions::InstrType::Exp: {
                I_Instruction * Instr2_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.second); 
                    result = std::vector<std::string>{
                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                        Instructions::nopInstruction(Instructions::machineFormat::S_tring),
                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                    };
            }
            break;

            case Instructions::InstrType::nop : {
                NOP_Instruction *i2 = dynamic_cast< NOP_Instruction *> (Scheduler::Instrpair.second);
                    result = {
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                        i2->MachineCodeString(Instructions::machineFormat::S_tring)
                            };
                }
            break;
        }

        return result;
  }