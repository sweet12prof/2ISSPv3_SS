#include "./RI_instrClass.hpp"
#include <unordered_map>

#ifndef I_INSTR_H
#define I_INSTR_H

class I_Instruction : public RI_Instruction{
    
    public:
    //-------------Enum class that consists of the various kinds of I Instructions
        enum class I_Type {Mem_Sw_Type = 1, Mem_LwType, Imm_Type, Branch_Type};

    //-------------Enum 
    //-----------Accessors and Mutators
        
        std::string getImmediate() const;
        void setImmediate(const int &);

        I_Type getIType_Type() const; // Used by derived class to determine the type of I-type instruction object ie; Mem-tyPE Or Immediate Type or Branch Type

    //-----------Constructor and Destructor
        I_Instruction();
        I_Instruction(const std::string &, const int &, const int &, const int &, const std::string &, const std::string &);
        virtual ~I_Instruction() = default;

    //-------------MF to return Machine Code representation
        virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction

    //-----------0-MF to access and mutate Immediate Label(private)
        std::string getImmediateLabel() const;
        void setImmediateLabel(const std::string &);


    private:
        const std::unordered_map<std::string, int> I_Type_Types 
        {
            {"addi", 3}, 
            {"bne", 4}, 
            {"subi", 3}, 
            {"andi", 3}, 
            {"ori", 3}, 
            {"xori", 3}, 
            {"addiu", 3}, 
            {"beq", 4},
            {"sw", 1},
            {"lw", 1}
        };

        std::bitset<16>Immediate; // Immediate Portion of Instruction
        I_Type iType_Type; // This describes the kind of I-Type instruction an object is;
        std::string ImmediateLabel;
        void setItype_Type(const std::string & ); // sets the Type of Itype Instructions



};

#endif
