#include "./RI_instrClass.hpp"

#ifndef R_INSTR_H
#define R_INSTR_H

class R_Instruction : public RI_Instruction{

   
    
    public: 
        //Constructors and Destructors
        R_Instruction();
        R_Instruction(const std::string &, const int &, const int &, const int &, const int &, const std::string &);
        virtual ~R_Instruction() = default;

    ///
        enum class R_Type { Jr_Type=1, Imm_R_Type, def_R_Type};
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

        // accessor and mutator for R-Type Enum
            R_Type getRType() const;
            void setRType(const std::string &);
        
    
    // Static Function to help determine Rtype of an op without creating an Object
        static R_Type getRType_Type(const std::string &);
        static std::map <std::string, int> R_Types_map_struc;

    //-------------------------------------
        virtual std::string MachineCodeString(machineFormat ) const override; // Overide to produce Machine representation of Instruction

        void createR_Instruction(const std::string &, const int &, const int &, const int &, const int &, const std::string &);

     private:
        std::bitset<5> rd;
        std::bitset<5> shamt;
        std::bitset<6> funct;
        const std::map< std::string, int> R_op_To_Funct = 
        {
            {"add", 56},
            {"sub", 20},
            {"jr", 4}
        }; 

        R_Type rType_Type;
        
    };

#endif