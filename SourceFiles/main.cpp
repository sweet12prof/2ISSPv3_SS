#include "../Headers/Assembler_hpp/Assembler.hpp"
#include <iostream>
#include <string>

int main()
{

          Assembler::processSegments("mips1.asm");
          std::string path{"/home/sweet12prof/Desktop/Final/2ISSPv3_SS/SourceFiles/Output/textSection.txt"};
          Assembler assembler{path};
          assembler.Assemble(Instructions::machineFormat::Decimal);  

        
          assembler.processDataSegment();
}


