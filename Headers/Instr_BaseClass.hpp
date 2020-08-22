#include <string>
#include <map>
 
 static enum class InstrType{R_Type = 1, I_Type, J_Type, Exp, Undefined };
 static enum class machineCodeFormat {Binary, Decimal};
  const std::map < std::string, std::pair <int, std::string > > varInstr 
        {
            {"add", {1, "add"}}, 
            {"sub", {2, "sub"}}, 

    	}; 

class Instructions {
    
    private:
        int Opcode; // Opcode is common to all instructions, thus in base class
        
        
         InstrType instrType;
         void setInstrType(); // This is defined private because its handled within the object itself ...Mutator for Instruction Type
    
    public:
        //accessor and mutator functions
        int getOpcode() const; 
        void setOpcode() const;
        
        //accessor and mutator for Instruction type
        InstrType getInstrType() const; // Returns instruction type of object
        
        //virtual Function To generate MachineCode
        virtual std::string MachineCodeString(machineCodeFormat &) const;



};