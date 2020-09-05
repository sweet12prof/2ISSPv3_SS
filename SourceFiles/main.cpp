
#include "../Headers/FileHelper_hpp/FileHelper.hpp"
#include "../Headers/Assembler_hpp/Assembler.hpp"
#include <iostream>
#include <array>
#include <algorithm>
#include <string>
#include <iterator>
#include <stdexcept>
// std::vector<std::string>  InstructionQueues;{
//      //"anotherlabel : J label",
//      "mfc $2 $3",
//      "someotherlabel : addi $4 $2 2890", 
//      "beq $4 $1 jLabel",Assembler_hpp
//      "sub $5 $3 $1", 
//      "jLabel : addi $5 $4 1",
//      "mfc $3 $5",
//      "someLabel     :       add $12 $2 $1",
//      "lw $3 180($30)", 
//      "someLabel: sw $3 180($30)", 
//      "addi $3, $2, 890"

// };

 

int main()
{
          std::ostream_iterator <std::string> output {std::cout, "\n"};
          std::vector <std::string> result;
          std::vector<std::string>  InstructionQueues;
          std::string path{"mips1.asm"};
          FileHelper fileproc{path};

          try{
              result = fileproc.fileProcess(path);
          }
          catch(std::exception &ex){
              std::cout << ex.what();
          }
              
          
          std::copy(result.cbegin(), result.cend(), output);
          fileproc.writeScheduleResults(result);

        // Assembler assembler{path};

        //assembler.RemoveWhiteSpace();    \

        std::string someNum = "12837a47440a";

        std::cout  << std::endl << std::boolalpha << FileHelper::is_A_Number(someNum) << std::endl;
          
          
}


 
