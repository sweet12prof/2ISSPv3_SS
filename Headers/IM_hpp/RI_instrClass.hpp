#include "./Instr_BaseClass.hpp"

#ifndef RI_INSTR_H
#define RI_INSTR_H

class RI_Instruction : public Instructions{

    private:
        std::bitset<5> rs;
        std::bitset<5> rt;
    
    public: 
        //Constructors and Destructors
        RI_Instruction();
        RI_Instruction(const std::string op, const int &, const int &);
        virtual ~RI_Instruction() = default;
    //-----------------------------------
        // accessors and mutators for rs
        std::string getRs() const;
        void setRs(const int &);

         // accessors and mutators for rs
        std::string getRt() const;
        void setRt(const int &);
    
    //-------------------------------------
        virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction
};

#endif