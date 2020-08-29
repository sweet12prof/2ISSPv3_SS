#include "./Instr_BaseClass.hpp"

#ifndef NOP_H
#define NOP_H
    class NOP_Instruction : public Instructions{
      private :
         std::bitset<26> OtherBits;
      public: 
        NOP_Instruction();
        NOP_Instruction(const std::string &, const std::string &);
        virtual std::string MachineCodeString(machineFormat ) const override;

        //---------------------
        void setOtherBits();
        std::string getOtherBits() const; 
    };
#endif