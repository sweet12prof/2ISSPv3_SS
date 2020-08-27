#include "./FileHelper.hpp"
#include <iostream>

R_Instruction R_Instr2;

std::string parseString(std::string someString){
    
     std::string stringWithoutWhiteSpace;

     for(auto item : someString){
          if(item != ' ')
          stringWithoutWhiteSpace += item;
     }

     //std::cout << stringWithoutWhiteSpace; 
     return stringWithoutWhiteSpace;
    
}


std::stringstream genstream(std::string someString){
    std::string result;
    CurrentinstrHasLabel2 = false;
    for(auto item : someString){
     switch(item){
          case ':' :
               result += ": ";
               CurrentinstrHasLabel2 = true;
          break;

          case '$' :
               result += " ";
          break;

          case ',' :
          break;


          default :
               result += item;
     }
    }

    //std::cout << result;
    std::stringstream output{result};
    return output;
}


Instructions * createPair(std::string InstrPairString){
   
    std::string op, label;
    int rs, rt, rd,  shamt,  Imm,  Address; 
    std::string InstrString = genstream( parseString(InstrPairString) ).str() ;
    std::stringstream output{InstrString};
   
    //shamt = 0;
   if(CurrentinstrHasLabel2)
     output >> label >>op;
   else 
     output >> op;

     output.str("");
     output.str(InstrString);

    // std::cout << "op is " << op <<" " << op.size() <<std::endl;
     Instructions * InstrPtr;
     switch (Instructions::getInstrType2(op)){
          case Instructions::InstrType::R_Type : 
               {    
                    if(CurrentinstrHasLabel2){
                         
                         output >> label >> op >> rs >> rt >> rd; 

                         // std::cout << "rt is " << rs <<" " << op.size() <<std::endl;
                         // std::cout << "rs is " << rt <<" " << op.size() <<std::endl;
                         // std::cout << "rd is " << rd <<" " << op.size() <<std::endl;
                         // std::cout << "Here1" << std::endl; 

                         //R_Instruction R_Instr{op, rs, rt, rd, 0, label};
                         R_Instr2.createR_Instruction(op, rs, rt, rd, 0, label);
                        // std::cout << R_Instr.MachineCodeString(Instructions::machineFormat::S_tring);
                        // R_Instr2 = R_Instr;
                         InstrPtr = &R_Instr2;
                    }
                         
                    else {
                              std::cout << "Here 2";
                               output >> op >> rs >> rt >> rd; 
                               R_Instruction R_Instr{op, rs, rt, rd, 0, ""};
                               InstrPtr = &R_Instr;
                    }
                        
                
               }
               break;
          
          default : {    
                         std::cout << "Here 3";
                         R_Instruction R_Instr{op, rs, rt, rd, 0, "Didntwork"};
                         InstrPtr = &R_Instr;
          }    
                

     }
     
          return InstrPtr;
}


// void setInstrLabel(bool some){
//      Helpers::CurrentinstrHasLabel = some;
// }

 //static std::array <std::string, 2> createPair(std::array <std::string, 2> )

