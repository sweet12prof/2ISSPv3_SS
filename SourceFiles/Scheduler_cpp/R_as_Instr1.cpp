#include "../../Headers/Scheduler_hpp/Scheduler.hpp"


std::vector<std::string> Scheduler::R_asInstr_1(){
    R_Instruction * Instr1_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.first); 
    std::vector<std::string> result;
    switch(Scheduler::Instrpair.second->getInstrType()){
      
        case Instructions::InstrType::R_Type:
           {
                
                R_Instruction * Instr2_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.second);
                if( (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs()) && (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt()) && 
                        (Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRd()) )
                    result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                                Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                            };
                else 
                     result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
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
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                                        Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                                    };
                        else 
                            result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                                    };
                    break;


                    case I_Instruction::I_Type::Branch_Type :
                        if(Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRs() || Instr1_derivedPtr->getRd() == Instr2_derivedPtr->getRt())
                            result = std::vector<std::string>{
                                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                                };          
                        else 
                            result = std::vector<std::string>{
                                    Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),
                                    Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                                };
                    break;

                    default: 
                           result = std::vector<std::string>{
                                        Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                                        Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                        Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                                    };
                }
            }
        break;

        case Instructions::InstrType::J_Type : {
                J_Instructions * Instr2_derivedPtr = dynamic_cast<J_Instructions *>(Instrpair.second);
                    result = std::vector<std::string>{
                                Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                            };
        }
        break;

         default: 
                result = std::vector<std::string>{
                                Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                                Instructions::nopInstruction(Instructions::machineFormat::Decimal),  
                                Instructions::nopInstruction(Instructions::machineFormat::Decimal)
                            };
            break;
    }

  return result;
                  
}