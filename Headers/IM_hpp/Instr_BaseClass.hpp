#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <cmath>
 
#ifndef BASECLASS_H
#define BASECLASS_H

class Instructions {
   
   
    const  std::map < std::string, std::pair <int, int > > varInstr {
       
        {"add", {1, 12}}, 
        {"sub", {1, 29}},
        {"addi", {2, 25}},
        {"mfc", {4, 31}},
        {"J", {3, 21}}, 
        {"nop", {6, 0}}, 
        {"beq", {2, 15}} ,
        {"lw", {2, 13}}
    };
  
    
    public:
    enum class InstrType{R_Type = 1, I_Type, J_Type, Exp, Undefined, nop};
    enum class machineFormat { Binary=1, Decimal };
     
        //Constructor and Destructor
            //Instructions();
                explicit Instructions(const std::string &);
                Instructions();
                virtual  ~Instructions() = default;
        
        //accessor and mutator functions
            std::string getOpcode() const; 
            void setOpcode(const std::string &);
        
        //accessor and mutator for Instruction type
            InstrType getInstrType() const; // Returns instruction type of object   
                      
        //virtual Function To generate MachineCode
            virtual std::string MachineCodeString(machineFormat ) const;
            static std::string nopInstruction(machineFormat );
        
       
        
    
    private: 
         std::bitset<6> Opcode; // Opcode is common to all instructions, thus in base class
         InstrType instrType;
         void setInstrType(const std::string &); // This is defined private because its handled within the object itself ...Mutator for Instruction Type

            //Friend Function to generate nop instruction whenever needed
};

#endif