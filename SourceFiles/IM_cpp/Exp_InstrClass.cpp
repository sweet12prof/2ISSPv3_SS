#include "../../Headers/IM_hpp/Exp_InstrClass.hpp"

Exp_Instructions::Exp_Instructions(){}

Exp_Instructions::Exp_Instructions(const std::string & op, const int& rd, const int& rt, const std::string & optionalLabel)
    : Instructions(op, optionalLabel)
{
    Exp_Instructions::setRd(rd);
    Exp_Instructions::setRt(rt);
} 

void Exp_Instructions::setRt(const int & rt){
    if(rt < pow(2, 5))
        this->rt = std::bitset<5>(rt);
    else 
        throw std::invalid_argument("Provided value for rt is too large");
}


std::string Exp_Instructions::getRt() const {
    return this->rt.to_string();
}


void Exp_Instructions::setRd(const int & rd){
    if(rd < pow(2, 5))
        this->rd = std::bitset<5>(rd);
    else 
        throw std::invalid_argument("Provided value for rd is too large");
}


std::string Exp_Instructions::getRd() const{
    return this->rd.to_string();
}


std::string Exp_Instructions::MachineCodeString(machineFormat some) const {
    std::bitset<5> zero_5(0);
    std::bitset<6> zero_6(0);
    std::string returnString {
                                Instructions::MachineCodeString(machineFormat::Binary) + 
                                zero_5.to_string() + Exp_Instructions::getRt() + 
                                Exp_Instructions::getRd() + zero_5.to_string() + 
                                zero_6.to_string()
                            };
        if(some == Instructions::machineFormat::Binary)
            return returnString;
        else if(some == Instructions::machineFormat::S_tring)
        {
             std::string someString { Instructions::MachineCodeString(machineFormat::S_tring)};
            std::stringstream output;
            output  << someString 
                    << "$"
                    << std::dec << std::bitset<5>(Exp_Instructions::getRd()).to_ulong()
                    << " $" 
                    << std::dec << std::bitset<5>(Exp_Instructions::getRt()).to_ulong();
            return output.str();
        }
        else{
            auto p =std::bitset<32>(returnString).to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
            return output.str();   
        } 

}