#include "./Instr_BaseClass.hpp"

#ifndef J_INSTR_H
#define J_INSTR_H

class J_Instructions : public Instructions {
    private:
        std::bitset<26> address; //26 bit address field from instruction
        std::string jumpLabel;
    public:
        J_Instructions(); /// Default Contsructo0r 
        J_Instructions(const std::string &,  const int &, const std::string &, const std::string &); // Constructor for j instruction
        
        virtual ~J_Instructions() = default; // destructor defined virtual to avoid errors when using delete on pointer objects of the class
        
        std::string getAddress() const; // getAddress in string format
        void setAddress(const int &); // sets the bit value of the address
        
        virtual std::string MachineCodeString(machineFormat ) const override; // returns the binary representataion of the J_Instruction

        void createJ_Instructions(const std::string &,  const int &, const std::string &, const std::string &);

    //----------accessor and mutator for jumpLabel String
        void setjumpLabel(const std::string &);
        std::string getJumpLabel() const;
};

#endif