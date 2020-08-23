#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <stdexcept>
#include <cmath>
 
#ifndef BASECLASS_H
#define BAECLASS_H


    

class Instructions {
   

    const std::map < std::string, std::pair <int, int > > varInstr 
    {
        {"add", {1, 12}}, 
        {"sub", {1, 29}},
        {"addi", {1, 25}}

    }; 
  
    
    public:
    enum class InstrType{R_Type = 1, I_Type, J_Type, Exp, Undefined };
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
        
        // static machine Code Format to specify MC format 
        static machineFormat mcFormat;
                // static InstrType Type;
        
        //virtual Function To generate MachineCode
        virtual std::string MachineCodeString(machineFormat ) const;
    
    private: 
         std::bitset<6> Opcode; // Opcode is common to all instructions, thus in base class
         InstrType instrType;
         void setInstrType(const std::string &); // This is defined private because its handled within the object itself ...Mutator for Instruction Type
};

#endif