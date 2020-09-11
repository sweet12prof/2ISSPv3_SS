#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "../FileHelper_hpp/FileHelper.hpp"
#include "../IM_hpp/all_Instr.hpp"


#ifndef ASSEMBLER_H
#define ASSEMBLER_H

class Assembler{
    public:
        Assembler();
        explicit Assembler(const std::string &);

        std::vector < std::string> readFile();
        std::ifstream inputFile;

        // It registers any instruction Labels and removes them from the instruction string 
        std::string PostParseProcess(std::string ); 
        
        //Formats instruction strings read from File into convinient form.
        static std::stringstream parseString(std::string &);


        //Create an Instruction object depending on the op in the string received from the postParseProcess
        Instructions * CreateInstructionObject(const std::string &);
        
        //Instruction Finds the address of supplied string
        static int getTextLabelAddress(const std::string &); 

        //Accessor for current point 
        std::streampos getCurrentpoint() const;

        // Translate Instruction Object to machineCode
        std::string Translate(Instructions * , Instructions::machineFormat );

    
        //This translates to the user specified base, output is used in storing to file
        std::string Translate_To_MachineRepresentation(Instructions *  ,Instructions::machineFormat );

        // Store Results 
         void Assemble(Instructions::machineFormat);
        
        // Function to process Segments 
        static void processSegments(const std::string &);

        //Function to process Data Segment
        void processDataSegment();
       
    private:
        std::string filepath;
         std::streampos endLocation;
         std::streampos currentPoint = 0;
         
         
};

#endif