#include "../IM_hpp/Exp_InstrClass.hpp"
#include "../IM_hpp/I_instrClass.hpp"
#include "../IM_hpp/J_instrClass.hpp"
#include "../IM_hpp/R_instrClass.hpp"
#include <vector>
class Scheduler{
    
    private:
        std::pair < Instructions *, Instructions *> Instrpair;
    
    public:
        Scheduler(Instructions *, Instructions *);
        std::vector<std::string> schedulePair();

        std::vector<std::string> R_asInstr_1();
        std::vector<std::string> I_asInstr_1();
        std::vector<std::string> J_asInstr_1();
        std::vector<std::string> Exp_asInstr_1();
        std::vector<std::string> nop_Instr();


};