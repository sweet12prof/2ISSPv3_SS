#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "../FileHelper_hpp/FileHelper.hpp"


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
        void RemoveWhiteSpace();
        static std::stringstream parseString(std::string &);

       
    private:
        std::string filepath;
        
};

#endif