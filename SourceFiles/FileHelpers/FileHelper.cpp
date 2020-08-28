#include "./FileHelper.hpp"
#include <iostream>

std::array <R_Instruction, 2> schd_R_Instr;
std::array <I_Instruction, 2> schd_I_Instr;
std::array <J_Instructions, 2> schd_J_Instr;



std::stringstream parseString(std::string someString){
      std::string token ="";
     
      std::stringstream result;
      int i{0};
      hasLabel = false;
     for(auto item : someString)
          {
               switch(item){
                    case ':' :
                         hasLabel = true;
                         if(token != "")
                              result << (token + " ");
                         token = "";
                   break; 

                    case ' ' :
                         if(token != "")
                              result << (token + " ");
                          token = "";
                    break;

                    case '(' :
                         result << (token + " ");
                         token = "";
                    break;

                    case ')' :
                          result << (token + " ");
                          token = "";
                    break;

                    case '$' :
                    break;

                    
                    default: 
                    {
                               token += item;
                               if(i == someString.size() - 1 )
                                   result << token;    
                    }                        
               }

             ++i;               
          }
     return result;
 }



std::array <Instructions *, 2> createPair(std::array<std::string, 2> InstrPairString){
     int i{0};
     std::array <Instructions *, 2> result;

     std::string op, label, immLabel;
     int rs, rt, rd,  shamt,  Imm,  Address; 

     for(auto item : InstrPairString){
          std::string InstrString = parseString(item).str() ;
          std::stringstream output{InstrString};
          
          if(hasLabel)
               output >> label >>op;
          else 
               output >> op;
               
               output.str("");
               output.str(InstrString);

               switch(Instructions::getInstrType2(op))
               {
                    case Instructions::InstrType::R_Type :
                         {
                              if(hasLabel){
                                   output >> label >>  op >> rs >> rt >> rd; 
                                   schd_R_Instr.at(i).createR_Instruction(op, rs, rt, rd, 0, label);
                                   result.at(i) = &schd_R_Instr.at(i);
                              }
                              else {
                                   output >> op >> rs >> rt >> rd; 
                                   schd_R_Instr.at(i).createR_Instruction(op, rs, rt, rd, 0, "");
                                   result.at(i) = &schd_R_Instr.at(i);
                              }
                         }
                    break;

                    case Instructions::InstrType::I_Type :
                         {
                             switch(I_Instruction::getIType_Type_static(op)){
                                  case I_Instruction::I_Type::Imm_Type :
                                  case I_Instruction::I_Type::Mem_LwType :
                                  case I_Instruction::I_Type::Mem_Sw_Type :
                                        {
                                             if(hasLabel){
                                                  output >> label >> op >> rs >> rt >>  Imm;
                                                  schd_I_Instr.at(i).createI_Instruction(op, rs, rt, Imm, label, "");
                                                  result.at(i) =  &schd_I_Instr.at(i);
                                                 //std::cout << schd_I_Instr.at(i).MachineCodeString(Instructions::machineFormat::S_tring) << std::endl;
                                                  result.at(i)->MachineCodeString(Instructions::machineFormat::S_tring);
                                                 // std::cout  << "op is " << schd_I_Instr.at(i).getOpcode()  <<  "Instruction type is " << (int)schd_I_Instr.at(i).getIType_Type() << " rs is " << schd_I_Instr.at(i).getRs() << " rt is " << schd_I_Instr.at(i).getRt() ;
                                             }
                                             else {
                                                  output >> op >> rs >> rt >> Imm;
                                                  schd_I_Instr.at(i).createI_Instruction(op, rs, rt, Imm, "", "");
                                                  result.at(i) =  &schd_I_Instr.at(i);
                                             }
                                             
                                        }
                                  break;

                                  case I_Instruction::I_Type::Branch_Type : 
                                        {
                                             if(hasLabel){
                                                                 output >> label >> op >> rs >> rt >>  immLabel;
                                                                 schd_I_Instr.at(i).createI_Instruction(op, rs, rt, 0 , label, immLabel);
                                                                 result.at(i) =  &schd_I_Instr.at(i);
                                             }
                                             else {
                                                                 output >>  op >> rs >> rt >>  immLabel;
                                                                 schd_I_Instr.at(i).createI_Instruction(op, rs, rt, 0 , "", immLabel);
                                                                 result.at(i) =  &schd_I_Instr.at(i);
                                             }
                                        }
                                   break;
                             }
                         }

                    case  Instructions::InstrType::J_Type : {
                         if(hasLabel){
                                        output >> label >> op >> immLabel;
                                        schd_J_Instr.at(i).createJ_Instructions(op, 0 , label, immLabel );
                                        result.at(i) = &schd_J_Instr.at(i);
                         } 
                         else {
                                         output >> op >> immLabel;
                                        schd_J_Instr.at(i).createJ_Instructions(op, 0 , "", immLabel );
                                        result.at(i) = &schd_J_Instr.at(i);
                         }
                    }
                    break;
               }
               ++i;
     }

   return result;
}


