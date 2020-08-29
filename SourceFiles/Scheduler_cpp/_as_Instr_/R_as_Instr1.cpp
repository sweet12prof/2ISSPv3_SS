#include "../../../Headers/Scheduler_hpp/Scheduler.hpp"


std::vector<std::string> Scheduler::R_asInstr_1(){
    R_Instruction * Instr1_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.first); 
    std::vector<std::string> result;
    switch(Scheduler::Instrpair.second->getInstrType()){
      
        case Instructions::InstrType::R_Type:
           {
                
                R_Instruction * Instr2_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.second);
                if( (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs()) || (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt()) || 
                        (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRd()) )
                    result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                            };
                else 
                     result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),  
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                            };
           }
        break;

        case Instructions::InstrType::I_Type :
            {
                I_Instruction * Instr2_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.second);
                switch(Instr2_derivedPtr->getIType_Type()){

                    case I_Instruction::I_Type::Mem_Sw_Type :
                    case I_Instruction::I_Type::Mem_LwType : 
                    case I_Instruction::I_Type::Imm_Type : 
                        if(Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs() || Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt())
                            
                           result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                        Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                                    };
                        else 
                            result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),  
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                                    };
                    break;


                    case I_Instruction::I_Type::Branch_Type :
                        if(Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs() || Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt())
                            result = std::vector<std::string>{
                                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                                };          
                        else 
                            result = std::vector<std::string>{
                                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),  
                                };
                    break;

                    default: 
                           result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                        Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                                    };
                }
            }
        break;

        case Instructions::InstrType::J_Type : {
                J_Instructions * Instr2_derivedPtr = dynamic_cast<J_Instructions *>(Instrpair.second);
                    result = std::vector<std::string>{
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),  
                            };
        }
        break;


        case Instructions::InstrType::Exp : {
                Exp_Instructions * Instr2_derivedPtr = dynamic_cast<Exp_Instructions *>(Instrpair.second);
                if(Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt() || Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRd())
                     result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                        Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring)
                                    };
                else 
                     result = std::vector<std::string>{
                                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),
                                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring),  
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


         default: 
                result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::S_tring), 
                                Instructions::nopInstruction(Instructions::machineFormat::S_tring),  
                                Instructions::nopInstruction(Instructions::machineFormat::S_tring)
                            };
            break;
    }

  return result;
                  
}