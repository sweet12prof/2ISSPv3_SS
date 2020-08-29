#include "./R_instrClass.hpp"

#ifndef EXP_INSTR_H
#define EXP_INSTR_H

class Exp_Instructions : public Instructions{

private: 
//----------rt and rd Field in instruction Sequence
    std::bitset<5> rt;
    std::bitset<5> rd;

public: 
//---------accessors and mutators for rt and rd
    // accessors and mutators for rt
        std::string getRt() const;
        void setRt(const int &);
    
    // accessors and mutators for rs
        std::string getRd() const;
        void setRd(const int &);
//---------------Constructor and Destructor
    //----------Constructor
        Exp_Instructions();
        Exp_Instructions(const std::string &, const int &, const int&, const std::string &);
        virtual ~Exp_Instructions() = default;
//-----------ML representation of mfc Instruction
    virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction
//-------------------------
    void createExp_Instructions(const std::string &, const int &, const int&, const std::string &);
};

#endif