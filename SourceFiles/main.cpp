#include "../Headers/Assembler_hpp/Assembler.hpp"
#include <iostream>
#include <string>

int main()
{
          
          std::string path{"mips1.asm"};
          std::string path2 {"scheduleRes.asm"};
          Assembler assembler{path2};
          assembler.Assemble(path);        
}


 
