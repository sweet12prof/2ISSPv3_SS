#include "../Headers/RI_instrClass.hpp"

class R_Instruction : public RI_Instruction{

    private:
        std::bitset<5> rd;
        std::bitset<5> shamt;
        std::bitset<6> funct;
        const std::map< std::string, int> R_op_To_Funct = 
        {
            {"add", 56},
            {"sub", 20}
        }; 
    
    public: 
        //Constructors and Destructors
        R_Instruction();
        R_Instruction(const std::string &, const int &, const int &, const int &, const int &);
        virtual ~R_Instruction() = default;
    //-----------------------------------
         // accessors and mutators for rs
        std::string getRd() const;
        void setRd(const int &);

         // accessors and mutators for rs
        std::string getShamt() const;
        void setShamt(const int &);

         // accessors and mutators for rs
        std::string getFunct() const;
        void setFunct(const std::string &);
    
    //-------------------------------------
        virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction
};