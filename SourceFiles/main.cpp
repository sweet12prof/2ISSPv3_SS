#include "../Headers/Assembler_hpp/Assembler.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main(int argc, char * argv[])
{
        std::string asmPath{argv[1]};
        std::string mode{argv[2]};
        Instructions::machineFormat type_arg;

        std::transform(mode.begin(), mode.end(), mode.begin(), [](auto &item){
            return std::tolower(item);
        });

        if(mode == "--binary")
            type_arg = Instructions::machineFormat::Binary;
        
        else if(mode == "--decimal") 
            type_arg = Instructions::machineFormat::Decimal;
        
        else if(mode == "--string")
            type_arg = Instructions::machineFormat::S_tring;

        else 
            {
                std::cerr << "Invalid machine representation argument, Program will now quit" << std::endl;
                exit(EXIT_FAILURE);
            }
            

          Assembler::processSegments(asmPath);
          std::string path{"/home/sweet12prof/Desktop/Final/2ISSPv3_SS/SourceFiles/Output/textSection.txt"};
          Assembler assembler{path};
          assembler.Assemble(type_arg);

          std::cout << std::endl << std::endl << "Completed Translation successfully, Find results in Output Folder" << std::endl;  

          assembler.processDataSegment();
}


