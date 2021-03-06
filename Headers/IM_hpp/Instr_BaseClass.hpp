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
        {"lw", {2, 13}},
        {"sw", {2, 5}},
        {"jr", {1, 13}}
    };
    
    
    
    public:
    enum class InstrType{R_Type = 1, I_Type, J_Type, Exp, Undefined, nop};
    enum class machineFormat { Binary=1, Decimal, S_tring };
     
        //Constructor and Destructor
            //Instructions();
                explicit Instructions(const std::string &, const  std::string &);
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
            static Instructions::InstrType getInstrType2(const std::string &);

        //Function To set and get Instruction Label(Optional)
            std::string getLabel() const;
            void setLabel(const std::string &);
       
       //Function to set and get opCode String 
            std::string getopCodeString() const;
            void setOpcodeString(const std::string &);

        //
        static  std::map < std::string, std::pair <int, int > > varInstr2;
        void setInstrType(const std::string &);
    private: 
         std::bitset<6> Opcode; // Opcode is common to all instructions, thus in base class
         std::string opCodeString; // String representation of Opcode String
         std::string label; //Optional Label For each instruction 
         InstrType instrType;
         // This is defined private because its handled within the object itself ...Mutator for Instruction Type

            //Friend Function to generate nop instruction whenever needed
};

#endif