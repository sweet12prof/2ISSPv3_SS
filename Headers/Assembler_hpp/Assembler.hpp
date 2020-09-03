#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "../FileHelper_hpp/FileHelper.hpp"
#include "../IM_hpp/all_Instr.hpp"


#ifndef ASSEMBLER_H
#define ASSEMBLER_H

static std::streampos endLocation;
static std::streampos currentPoint;
static int globalLineCount{0};
static std::unordered_map <std::string, int> textSegmentTable;
static std::unordered_map <std::string, int> DataSegmentTable;
static bool hasLabel2;


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
       
    private:
        std::string filepath;
        
};

#endif