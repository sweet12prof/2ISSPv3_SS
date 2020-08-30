#include "../../Headers/IM_hpp/all_Instr.hpp"
#include <array>
#include <vector>
#include <fstream>
#include <cstdlib>

   

   #ifndef HELPERS_H
   #define HELPERS_H
   
   //static variable that tells whether the currently parsed instruction consists of a label
   static bool hasLabel;

   // static vector to hold our Instruction Chunk(should be array really)
   static std::vector < std::string > InstructionQueue;
  

    class FileHelper{
        public :
            // Parse String MF reads a Line(possible instruction) and ensures it meets lexical requirements
            static std::stringstream parseString(std::string); 

            // This creates a pair of instruction(according to the blueprint defined for each class) corresponding to the string that passed Parsing
            static std::array <Instructions *, 2> createPair(std::array<std::string, 2>); 

            // This function reads a chunck of possible instruction strings ans stores them into the instruction queue
            void  readFile();

            //Constructor for when a File Location is provided
            explicit FileHelper(const std::string &);

            //Constructor for when no File Location is provided
            FileHelper();
            
            //This Function returns the position to start reading the next chunk from
            std::streampos getnewLineCount() const;

            //This Function returns the position of the last character in the File
            std::streampos getEnd_OF_File() const;

        private :
             // this represents the path of the File containing the instructions (text)
             std::string FilePath;

            // Variable representiing position to start reading the next chunk from
             std::streampos newLineCount;

             // Variable representiing the position of the last character in the File
             std::streampos End_OF_File;

             // File stream(input) to help read file
             std::ifstream input;
    };


   #endif
       
