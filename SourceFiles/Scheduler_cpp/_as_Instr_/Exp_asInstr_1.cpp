#include "../../../Headers/Scheduler_hpp/Scheduler.hpp"
#include <iostream>
std::vector<std::string> Scheduler::Exp_asInstr_1(){ 
    Exp_Instructions * i1 = dynamic_cast<Exp_Instructions *>(Scheduler::Instrpair.first);
    std::vector<std::string> result;
    switch(Scheduler::Instrpair.second->getInstrType()){

        case Instructions::InstrType::R_Type : {
            R_Instruction * i2 = dynamic_cast< R_Instruction *>(Scheduler::Instrpair.second);
            if( (i1->getRd() == i2->getRs()) || (i1->getRd() == i2->getRt()) || (i1->getRd() == i2->getRd()) ){
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                            Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                            i2->MachineCodeString(Instructions::machineFormat::S_tring)
                };
            }
            else 
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                            i2->MachineCodeString(Instructions::machineFormat::S_tring)
                };
               // std::cout << "Here";
        }
        break;

        case Instructions::InstrType::I_Type : {
            I_Instruction * i2 = dynamic_cast< I_Instruction *>(Scheduler::Instrpair.second);
            
            switch(i2->getIType_Type())
            {
                case I_Instruction::I_Type::Imm_Type :
                case I_Instruction::I_Type::Mem_LwType :
                case I_Instruction::I_Type::Mem_Sw_Type : {
                    if(i1->getRd() == i2->getRs() || i1->getRd() == i2->getRt())
                         result = {
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring)
                                 };
                    else 
                        result = {
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring)
                                 };
                }
                break;

                case I_Instruction::I_Type::Branch_Type :
                    {
                        if(i1->getRd() == i2->getRs() || i1->getRd() == i2->getRt())
                             result = {
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring)
                                 };
                        else 
                            result = {
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring)
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
                        i2->MachineCodeString(Instructions::machineFormat::S_tring), 
                        i1->MachineCodeString(Instructions::machineFormat::S_tring)
                        };
        }
        break;

        case Instructions::InstrType::Exp :{
            Exp_Instructions * i2 = dynamic_cast< Exp_Instructions *>(Scheduler::Instrpair.second);

            if(i1->getRd() == i2->getRd() || i1->getRd() == i2->getRd())
                result = {
                            i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                            Instructions::nopInstruction(Instructions::machineFormat::S_tring), 
                            i2->MachineCodeString(Instructions::machineFormat::S_tring)
                            };
            else 
                result = {
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring)
                                 };


        }
        break;


        case Instructions::InstrType::nop : {
            NOP_Instruction *i2 = dynamic_cast< NOP_Instruction *> (Scheduler::Instrpair.second);
                result = {
                                    i1->MachineCodeString(Instructions::machineFormat::S_tring), 
                                    i2->MachineCodeString(Instructions::machineFormat::S_tring)
                         };
        }
        break;
    }
        return result;
} 