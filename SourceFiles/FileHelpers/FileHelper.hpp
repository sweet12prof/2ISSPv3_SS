#include "../../Headers/IM_hpp/all_Instr.hpp"
#include "../../Headers/Scheduler_hpp/Scheduler.hpp"
#include <array>
#include <vector>
#include <fstream>
#include <cstdlib>

   

   #ifndef HELPERS_H
   #define HELPERS_H
   
   //static variable that tells whether the currently parsed instruction consists of a label
   static bool hasLabel;

   // static vector to hold our Instruction Chunk(should be array really)
    // < std::string > InstructionQueue;
  

    class FileHelper{
        public :
            // Parse String MF reads a Line(possible instruction) and ensures it meets lexical requirements
            static std::stringstream parseString(std::string); 

            // This creates a pair of instruction(according to the blueprint defined for each class) corresponding to the string that passed Parsing
            // returns a base class reference to the pair
            static std::array <Instructions *, 2> createPair(std::array<std::string, 2>); 

            // This function reads a chunck of possible instruction strings ans stores them into the instruction queue
             std::vector <std::string> readFile();

            //Constructor for when a File Location is provided
            explicit FileHelper(const std::string &);

            //Constructor for when no File Location is provided
            FileHelper();
            
            //This Function returns the position to start reading the next chunk from
            std::streampos getnewLineCount() const;

            //This Function returns the position of the last character in the File
            std::streampos getEnd_OF_File() const;

            //Function to Determine Dependencies between Instrunctions in an Instruction Queue
            std::vector<std::string> schedulePairs( std::vector<std::string> );

            //Functionto Write Scheduled Pairs to File
            void   writeScheduleResults(const std::vector <std::string > &);

        private :
             // this represents the path of the File containing the instructions (text)
             std::string FilePath;

            // Variable representiing position to start reading the next chunk from
             std::streampos newLineCount;

             // Variable representiing the position of the last character in the File
             std::streampos End_OF_File;

             // File stream(input) to help read file
             std::ifstream input;

             //File stream(output) to write results
             std::ofstream output;
    };


   #endif
       
