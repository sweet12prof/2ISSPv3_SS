 #include "../../Headers/Scheduler_hpp/Scheduler.hpp"
    std::vector<std::string> Imm_as_I_Type_Type(I_Instruction *, I_Instruction *);
    std::vector<std::string> Beq_as_I_Type_Type(I_Instruction *, I_Instruction *);
    std::vector<std::string> Lw_as_I_type_Type(I_Instruction *, I_Instruction *);
    std::vector<std::string> sw_as_I_type_Type(I_Instruction *, I_Instruction *);


 std::vector<std::string> Scheduler::I_asInstr_1(){
     I_Instruction * Instr1_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.first); 
     std::vector<std::string> result;

    switch(Scheduler::Instrpair.second->getInstrType()){
        case Instructions::InstrType::R_Type :
            R_Instruction * Instr2_derivedPtr = dynamic_cast<R_Instruction *>(Instrpair.second);
            if(Instr1_derivedPtr->getRt() == Instr2_derivedPtr->getRs() || Instr1_derivedPtr->getRt() == Instr2_derivedPtr->getRt())
                result =  std::vector<std::string>{
                            Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                            nopInstruction(Instructions::machineFormat::Decimal), 
                            Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
            else 
                result = std::vector<std::string>{
                            Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal),  
                            Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
        break;

        case Instructions::InstrType::J_Type :
            J_Instructions * Instr2_derivedPtr = dynamic_cast<J_Instructions *>(Instrpair.second);
                result = std::vector<std::string>{ 
                            Instr2_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal), 
                            Instr1_derivedPtr->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
        break;

        case Instructions::InstrType::I_Type:
            {
                I_Instruction * Instr2_derivedPtr = dynamic_cast<I_Instruction *>(Instrpair.second);
                switch(Instr1_derivedPtr->getIType_Type()){
                    case I_Instruction::I_Type::Imm_Type :
                        result = Imm_as_I_Type_Type(Instr1_derivedPtr, Instr2_derivedPtr);
                    break;

                    case I_Instruction::I_Type::Branch_Type : 
                        result = Beq_as_I_Type_Type(Instr1_derivedPtr, Instr2_derivedPtr);
                    break;

                    case I_Instruction::I_Type::Mem_LwType :
                        result =  Lw_as_I_type_Type(Instr1_derivedPtr, Instr2_derivedPtr);
                    break;

                    case I_Instruction::I_Type::Mem_Sw_Type :
                        result = sw_as_I_type_Type(Instr1_derivedPtr, Instr2_derivedPtr);
                    break;
                }
            }
        break;

        
    }
     return result;
}
 

 std::vector<std::string> Lw_as_I_type_Type(I_Instruction * i1, I_Instruction *i2){
     if(i2->getIType_Type() == I_Instruction::I_Type::Mem_LwType || i2->getIType_Type() == I_Instruction::I_Type::Mem_Sw_Type)
        return  std::vector<std::string>{
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            nopInstruction(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
    else if(i2->getIType_Type() == I_Instruction::I_Type::Branch_Type)
            {
                if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                        return  std::vector<std::string>{ 
                                i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                nopInstruction(Instructions::machineFormat::Decimal), 
                                i2->MachineCodeString(Instructions::machineFormat::Decimal) 
                            };
                else
                         return std::vector<std::string>
                         {
                             i2->MachineCodeString(Instructions::machineFormat::Decimal), 
                             i1->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
        

            }
    else {
            if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                return 
                    std::vector<std::string>
                                    { 
                                        i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                        nopInstruction(Instructions::machineFormat::Decimal), 
                                        i2->MachineCodeString(Instructions::machineFormat::Decimal)
                                    };
        else 
                 return std::vector<std::string>
                         {
                             i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                             i2->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
    }
 }


std::vector<std::string> Beq_as_I_Type_Type(I_Instruction * i1, I_Instruction *i2){
    return std::vector<std::string>{ 
                                i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                nopInstruction(Instructions::machineFormat::Decimal), 
                                i2->MachineCodeString(Instructions::machineFormat::Decimal) 
                            };   
}


std::vector<std::string> sw_as_I_type_Type(I_Instruction *i1, I_Instruction *i2){
     if(i2->getIType_Type() == I_Instruction::I_Type::Mem_LwType || i2->getIType_Type() == I_Instruction::I_Type::Mem_Sw_Type)
        return  std::vector<std::string>{
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            nopInstruction(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
     
     else if(i2->getIType_Type() == I_Instruction::I_Type::Branch_Type) 
        return std::vector<std::string>
                         {
                             i2->MachineCodeString(Instructions::machineFormat::Decimal), 
                             i1->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
    
     else 
         return std::vector<std::string>
                         {
                             i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                             i2->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
}


std::vector<std::string> Imm_as_I_Type_Type(I_Instruction *i1, I_Instruction *i2){
    std::vector<std::string> result; 
    switch(i2->getIType_Type()){
        case I_Instruction::I_Type::Mem_LwType:
        case I_Instruction::I_Type::Mem_Sw_Type:
        case I_Instruction::I_Type::Imm_Type :
            if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                result = std::vector<std::string>{
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            nopInstruction(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
            else 
                result = std::vector<std::string>{
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                        };

        case I_Instruction::I_Type::Branch_Type :
                 if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                        return  std::vector<std::string>{ 
                                i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                nopInstruction(Instructions::machineFormat::Decimal), 
                                i2->MachineCodeString(Instructions::machineFormat::Decimal) 
                            };
                else
                         return std::vector<std::string>
                         {
                             i2->MachineCodeString(Instructions::machineFormat::Decimal), 
                             i1->MachineCodeString(Instructions::machineFormat::Decimal)  
                        };
        break;
                
    }

    return result;
}