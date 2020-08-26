#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include <array>
#include <algorithm>

std::vector<std::string>  InstructionQueue{
     "add $1 $2 $3",
     "add $4 $2 $3", 
     "beq $4 $1 jLabel",
     "sub $5 $3 $1", 
     "jLabel: addi $5, $3, $1",
     "mfc $3, $5"
};


std::string parseString(std::string );
std::stringstream genstream(std::string);
bool CurrentinstrHasLabel;

int main()
{
    std::string parseResult {parseString("jLabel: addi $5, $3, $1")};
    std::stringstream genStreamResult{genstream(parseResult)};
    
     std::string Label;
     std::string op;

    if(CurrentinstrHasLabel)
     {
          genStreamResult >> Label >> op;
          std::cout << std::endl << (int) Instructions::getInstrType2(op);
     }

}


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
    for(auto item : someString){
     switch(item){
          case ':' :
               result += ": ";
               CurrentinstrHasLabel = true;
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

    std::cout << result;
     std::stringstream output{result};
    return output;
}