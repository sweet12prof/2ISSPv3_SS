#include "../../../Headers/Scheduler_hpp/Scheduler.hpp"
std::vector<std::string> Scheduler::Exp_asInstr_1(){ 
    Exp_Instructions * i1 = dynamic_cast<Exp_Instructions *>(Scheduler::Instrpair.first);
    std::vector<std::string> result;
    switch(Scheduler::Instrpair.second->getInstrType()){

        case Instructions::InstrType::R_Type : {
            R_Instruction * i2 = dynamic_cast< R_Instruction *>(Scheduler::Instrpair.second);
            if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt() || i1->getRt() == i2->getRd()){
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                };
            }
            else 
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                };
        }
        break;

        case Instructions::InstrType::I_Type : {
            I_Instruction * i2 = dynamic_cast< I_Instruction *>(Scheduler::Instrpair.second);
            
            switch(i2->getIType_Type())
            {
                case I_Instruction::I_Type::Imm_Type :
                case I_Instruction::I_Type::Mem_LwType :
                case I_Instruction::I_Type::Mem_Sw_Type : {
                    if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                         result = {
                                    i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                    i2->MachineCodeString(Instructions::machineFormat::Decimal)
                                 };
                    else 
                        result = {
                                    i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    i2->MachineCodeString(Instructions::machineFormat::Decimal)
                                 };
                }
                break;

                case I_Instruction::I_Type::Branch_Type :
                    {
                        if(i1->getRt() == i2->getRs() || i1->getRt() == i2->getRt())
                             result = {
                                    i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                                    i2->MachineCodeString(Instructions::machineFormat::Decimal)
                                 };
                        else 
                            result = {
                                    i2->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    i1->MachineCodeString(Instructions::machineFormat::Decimal)
                                 };
                    }
                break;
                
            }
        }
        break;
        
        case Instructions::InstrType::J_Type :
        {
             J_Instructions * i2 = dynamic_cast< J_Instructions *>(Scheduler::Instrpair.second);

             result = {
                        i2->MachineCodeString(Instructions::machineFormat::Decimal), 
                        i1->MachineCodeString(Instructions::machineFormat::Decimal)
                        };
        }
        break;

        case Instructions::InstrType::Exp :{
            Exp_Instructions * i2 = dynamic_cast< Exp_Instructions *>(Scheduler::Instrpair.second);

            if(i1->getRt() == i2->getRd() || i1->getRt() == i2->getRd())
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                            Instructions::nopInstruction(Instructions::machineFormat::Decimal), 
                            i2->MachineCodeString(Instructions::machineFormat::Decimal)
                            };
            else 
                result = {
                                    i1->MachineCodeString(Instructions::machineFormat::Decimal), 
                                    i2->MachineCodeString(Instructions::machineFormat::Decimal)
                                 };


        }
    }
        return result;
} 