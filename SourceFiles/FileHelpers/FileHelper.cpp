#include "../../Headers/FileHelper_hpp/FileHelper.hpp"
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
      //hasLabel = false;

      // iterate through every character in string  to parse
     for(auto item : someString)
          {
               switch(item){
                    case ':' :
                         hasLabel = true;
                         if(token != "")
                              result << (token + ": ");
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
     : FilePath{filepath}, newLineCount{0}, outstandingFlag{false}, outstandingInstruction{""} {
          FileHelper::input.open(FileHelper::FilePath);
          if(!FileHelper::input)
               {
                    std::cerr << "File could not be opened";
                    exit(EXIT_FAILURE);
               }
          FileHelper::input.seekg(0,  std::ios::end );
          FileHelper::End_OF_File = FileHelper::input.tellg();
          FileHelper::input.seekg(0);
          FileHelper::input.close();

     }


//Reading Lines from File (to be used in parsing) 
 std::vector < std::string > FileHelper::readFile()  {
     std::vector < std::string > InstructionQueue; //Vector to hold our Chunk of Lines
     std::string someString; // Variable to hold current read Line
     FileHelper::input.open(FileHelper::FilePath);
     FileHelper::input.seekg(newLineCount); // Seek our next location to read from
     int LineCount{0};   // Variable to keep count of the lines read
     if(FileHelper::outstandingFlag == true) // Check if previous chunk has an outstanding instruction      
          {
               InstructionQueue.push_back(FileHelper::outstandingInstruction); // push outstanding instruction First into the qeue for parsing
               ++LineCount;
          }
     FileHelper::outstandingFlag = false;
     while(std::getline(FileHelper::input, someString) && LineCount < 6){ 
          if(someString != "\n" && someString != "\0")
          {
               InstructionQueue.push_back(someString); // Store read string 
               ++LineCount; // Increment count
               FileHelper::newLineCount =  std::streampos( FileHelper::input.tellg() ); // Save next position
          }
               
        //  std::cout << std::endl << newLineCount << std::endl; // Clear this out soon
     }
     input.close();
     return InstructionQueue;
 }


// Return position where the next chunk of Lines will be read from 
 std::streampos FileHelper::getnewLineCount() const {
      return FileHelper::newLineCount;
 }


// Returns Location of Last character in File
 std::streampos FileHelper::getEnd_OF_File() const{
      return FileHelper::End_OF_File;
 }

  //Function to Determine Dependencies between Instrunctions in an Instruction Queue
std::vector <std::string> FileHelper::schedulePairs( std::vector<std::string>  InstructionQueue) {
     
     int i{0};
     std::string nopInstr{"nop"};
     std::string Instr2;
     std::vector <std::string> result; // Contains results from scheduler
     //FileHelper::outstandingFlag = false;

     while( i < InstructionQueue.size()){
              if (i == InstructionQueue.size() - 1) { // Check if we are at the end of queue with only one instrruction left, if so make second of pair nop
                   FileHelper::outstandingFlag = true;
                   FileHelper::outstandingInstruction = InstructionQueue.at(i);
                    break;
              } 
              
               Instr2 =  InstructionQueue.at(i + 1); 

               std::array <Instructions *, 2> res  = FileHelper::createPair ({  //Create pair i.e Instruction representing corresponding parsed string
                              InstructionQueue.at(i),  // First instruction in the pair(from qeue)
                              Instr2                   // Second in qeuee...will be nop when there's no second instruction in the pair
               });

               Scheduler Schd{res.at(0), res.at(1)}; //Scheduler Object instantiation; to be used to schedule the references to instruction objects specified in the argument list
               
              // result = Schd.schedulePair();

               if(Schd.schedulePair().size() == 3 ) // check if the scheduler suggests a dependency between the references
                  {
                        ++i; // If true our next pair starts from(has as first instruction) last of the current pair 
                  } 
               else 
                    i+=2; // Next pair in normal order

               int k{0};

               for(auto item : Schd.schedulePair()){
                    if( k < 2){
                        result.push_back(item);
                    }              
                    ++k;
                    
              }

              
          }
           return result;

}

void FileHelper::writeScheduleResults(const std::vector <std::string > & results){
      FileHelper::output.open("scheduleRes.asm", std::ios::out);
     int i{0};
      while( i < results.size()){
           output << results.at(i) << std::endl;
           ++i;
      }

      FileHelper::output.close();
 }


 std::vector <std::string> FileHelper::fileProcess(const std::string & filePath){
       std::vector <std::string> result;
       std::vector<std::string>  InstructionQueues;
       std::vector<std::string>  preResult;

          while( FileHelper::getnewLineCount() >= 0) {
                InstructionQueues = FileHelper::readFile();
                preResult = FileHelper::schedulePairs(InstructionQueues);  

                result.insert(result.end(), preResult.begin(), preResult.end());
          }

          return result;
 }