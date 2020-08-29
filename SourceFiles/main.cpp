#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include "./FileHelpers/FileHelper.hpp"
#include <array>
#include <algorithm>
#include <string>
std::vector<std::string>  InstructionQueue{
     "add $1 $2 $3",
     "add $4 $2 $3", 
     "beq $4 $1 jLabel",
     "sub $5 $3 $1", 
     "jLabel: addi $5, $3, $1",
     "mfc $3, $5",
     "add $12 $2 $1"
};

 

int main()
{
     // int i{0};
     //  std::array <std::string, 2> test{
     //      "mfc $5, $3", 
     //       "label: sw $5 0($3)"
     //  };

     // std::array <Instructions *, 2> res =  createPair(test);

     
     
    
     // Scheduler newSchd{res.at(0), res.at(1) };

     // for(auto item : newSchd.schedulePair())
     //      std::cout << item << std::endl;
     int i{0};

     // while ( i < InstructionQueue.size() ){
          
               std::array <Instructions *, 2> res =  createPair( 
                    {
                         InstructionQueue.at(0),
                         InstructionQueue.at(1)
                    }
               );
          
          Scheduler newSchd{res.at(0), res.at(1)};

          // if(newSchd.schedulePair().size() == 3)
          //      i += 1;
          // else 
          //      i+=2;
          //      int j{0};
               for(auto item : newSchd.schedulePair())
                    // { {}
                    //      if(j < 2)
                              std::cout << item << std::endl;
                        //. ++j;
                    //}
         

     //}
     
}


 

