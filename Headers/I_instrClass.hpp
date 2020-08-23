#include "../Headers/RI_instrClass.hpp"

#ifndef I_INSTR_H
#define I_INSTR_H

class I_Instruction : public RI_Instruction{
    private:
        std::bitset<16>Immediate; // Immediate Portion of Instruction

    public:
    //-----------Accessors and Mutators
        std::string getImmediate() const;
        void setImmediate(const int &);

    //-----------Constructor and Destructor
        I_Instruction();
        I_Instruction(const std::string &, const int &, const int &, const int &);
        virtual ~I_Instruction() = default;

    //-------------MF to return Machine Code representation
        virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction
};

#endif
