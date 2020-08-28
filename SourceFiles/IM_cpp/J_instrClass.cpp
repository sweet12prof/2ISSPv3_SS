#include "../../Headers/IM_hpp/J_instrClass.hpp"

J_Instructions::J_Instructions(){}

J_Instructions::J_Instructions(const std::string & op, const int & address, const std::string &optionalLabel, const std::string & jLabelInput)
    : Instructions(op, optionalLabel), jumpLabel{jLabelInput}
{
    J_Instructions::setAddress(address);
}



void J_Instructions::setAddress(const int & address){
    if(address < pow(2, 26))
        J_Instructions::address = std::bitset<26>(address);
     else
        throw std::invalid_argument("The argument passed as address is too large"); 
}

std::string J_Instructions::getAddress() const
{
    return J_Instructions::address.to_string();
}

 std::string J_Instructions::MachineCodeString(machineFormat some ) const  {
     std::string returnString {Instructions::MachineCodeString(machineFormat::Binary) + J_Instructions::address.to_string()};


      if(some == Instructions::machineFormat::Binary)
            return returnString;
      else if(some == Instructions::machineFormat::S_tring)
        {
             std::string someString { Instructions::MachineCodeString(machineFormat::S_tring)};
            std::stringstream output;
            if(J_Instructions::getJumpLabel() == "")
                output << someString << std::dec << std::bitset<26>(J_Instructions::getAddress()).to_ulong();
            else 
                 output << someString << std::dec << " " << J_Instructions::getJumpLabel();
            return output.str();
        }
        else{
            auto p =std::bitset<32>(returnString).to_ulong();
            std::ostringstream output;
            output << std::setw(8) << std::hex << std::showbase << std::setfill('0') << p;
            return output.str();   
        } 
}

    std::string J_Instructions::getJumpLabel() const {
        return this->jumpLabel;
    }

    void J_Instructions::setjumpLabel(const std::string & jLabelInput){
        J_Instructions::jumpLabel = jLabelInput;
    }


    void J_Instructions::createJ_Instructions(const std::string & op,  const int & Address, const std::string & opLabel, const std::string & jumpLabel){
            J_Instructions::setOpcode(op);
            J_Instructions::setOpcodeString(op);
            J_Instructions::setLabel(opLabel);
            J_Instructions::setjumpLabel(jumpLabel);
            J_Instructions::setAddress(Address);

    }