#include "./FileHelper.hpp"
#include <iostream>

std::array <R_Instruction, 2> schd_R_Instr;
std::array <I_Instruction, 2> schd_I_Instr;
std::array <J_Instructions, 2> schd_J_Instr;
std::array <Exp_Instructions, 2> schd_Exp_Instr;
std::array <NOP_Instruction, 2> schd_NOP_Instr;



std::stringstream FileHelper::parseString(std::string someString){
     // Variable to hold current Token in a string being parsed
      std::string token =""; 
     
     //  Stream to hold parsed Instruction
      std::stringstream result;

     // Iterator to help in iterating string to parse
      int i{0};

      // set has label vto false before starting parse
      hasLabel = false;

      // iterate through every character in string  to parse
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

                    case ',' :
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


//  Create pair returns reference to the pair of Instructions Objects created after succefful parsing
std::array <Instructions *, 2> FileHelper::createPair(std::array<std::string, 2> InstrPairString){
     int i{0};
     std::array <Instructions *, 2> result;

     std::string op, label, immLabel;
     int rs, rt, rd,  shamt,  Imm,  Address; 

     for(auto item : InstrPairString){
          std::string InstrString = FileHelper::parseString(item).str() ;
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
                                   output >> label >>  op >> rd >> rs >> rt; 
                                   schd_R_Instr.at(i).createR_Instruction(op,  rs, rt, rd,  0, label);
                                   result.at(i) = &schd_R_Instr.at(i);
                              }
                              else {
                                   output >> op >> rd >> rs >> rt; 
                                   schd_R_Instr.at(i).createR_Instruction(op, rs, rt, rd, 0, "");
                                   result.at(i) = &schd_R_Instr.at(i);
                              }
                         }
                    break;

                    case Instructions::InstrType::I_Type :
                         {
                             switch(I_Instruction::getIType_Type_static(op)){
                                  
                                  case I_Instruction::I_Type::Mem_LwType :
                                  case I_Instruction::I_Type::Mem_Sw_Type :
                                        {
                                             if(hasLabel){
                                                  output >> label >> op >> rt >> Imm >>  rs;
                                                  schd_I_Instr.at(i).createI_Instruction(op, rs, rt, Imm, label, "");
                                                  result.at(i) = &schd_I_Instr.at(i) ;
                                             }
                                             else {
                                                  output >> op >> rt >> Imm >> rs;
                                                  schd_I_Instr.at(i).createI_Instruction(op, rs, rt, Imm, "", "");
                                                  result.at(i) =  &schd_I_Instr.at(i);
                                             }
                                             
                                        }
                                  break;



                                  case I_Instruction::I_Type::Imm_Type :
                                        {
                                             if(hasLabel){
                                                  output >> label >> op >> rt >> rs >>  Imm;
                                                  schd_I_Instr.at(i).createI_Instruction(op, rs, rt, Imm, label, "");
                                                  result.at(i) = &schd_I_Instr.at(i) ;
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
                                                                 output >>  op >> rt >> rs >>  immLabel;
                                                                 schd_I_Instr.at(i).createI_Instruction(op, rs, rt, 0 , "", immLabel);
                                                                 result.at(i) =  &schd_I_Instr.at(i);
                                             }
                                        }
                                   break;
                             }
                         }
                         break;

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

                    case Instructions::InstrType::Exp : {
                         if(hasLabel){
                              output >> label >> op >> rd >> rt;
                              schd_Exp_Instr.at(i).createExp_Instructions(op, rd, rt, label);
                              result.at(i) = &schd_Exp_Instr.at(i);
                         }
                         else {
                                   output >> op >> rd >> rt;
                                   schd_Exp_Instr.at(i).createExp_Instructions(op, rd, rt, "");
                                   result.at(i) = &schd_Exp_Instr.at(i);

                         }
                    }
                    break;


                    case Instructions::InstrType::nop : {
                         if(hasLabel) {
                              output >> label >> op;
                              schd_NOP_Instr.at(i).createNOP_Instruction(op, label);
                              result.at(i) = & schd_NOP_Instr.at(i);
                         }
                         else{
                              output >> label >> op;
                              schd_NOP_Instr.at(i).createNOP_Instruction(op, "");
                              result.at(i) = & schd_NOP_Instr.at(i);
                         }
                    }
                    break;
               }
               ++i;
     }
          
   return result;
}

// empty File Constructor For situation where no file is provided
FileHelper::FileHelper()
     :FilePath{""}
{
}


// Constructor For situation where File location ahs been specified
FileHelper::FileHelper(const std::string & filepath)
     : FilePath{filepath}, newLineCount{0} {
          FileHelper::input.open(FileHelper::FilePath);
          if(!FileHelper::input)
               {
                    std::cerr << "File could not be opened";
                    exit(EXIT_FAILURE);
               }
          FileHelper::input.seekg(0,  std::ios::end );
          FileHelper::End_OF_File = FileHelper::input.tellg();
          FileHelper::input.seekg(0);
     }

 
 void FileHelper::readFile()  {
     
     std::string someString;
     FileHelper::input.seekg(newLineCount);
     int LineCount{0};
     while(std::getline(FileHelper::input, someString) && LineCount < 5){
          
          InstructionQueue.push_back(someString);
          ++LineCount;
               FileHelper::newLineCount =  std::streampos( FileHelper::input.tellg() );
          std::cout << someString << std::endl;
     }
     std::cout << std::endl  << std::endl << std::endl << "Read 5 Lines" << std::endl << std::endl << std::endl; 
 }

 
 std::streampos FileHelper::getnewLineCount() const {
      return FileHelper::newLineCount;
 }

 std::streampos FileHelper::getEnd_OF_File() const{
      return FileHelper::End_OF_File;
 }