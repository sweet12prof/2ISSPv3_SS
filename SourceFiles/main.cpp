#include <iostream>
#include "../Headers/IM_hpp/all_Instr.hpp"
#include "../Headers/Scheduler_hpp/Scheduler.hpp"
#include "./FileHelpers/FileHelper.hpp"
#include <array>
#include <algorithm>
#include <string>
std::vector<std::string>  InstructionQueue{
     //"anotherlabel : J label",
     "mfc $2 $3",
     "someotherlabel : addi $4 $2 2890", 
     "beq $4 $1 jLabel",
     "sub $5 $3 $1", 
     "jLabel : addi $5 $4 1",
     "mfc $3 $5",
     "someLabel     :       add $12 $2 $1",
     "lw $3 180($30)", 
     "someLabel: sw $3 180($30)", 

};

 

int main()
{
     int i{0};

     std::string nop {"nop"};
     std::string Instr2;
          while(i < InstructionQueue.size()){

                Instr2 = ( InstructionQueue.size() -  (i + 1) > 1 ? InstructionQueue.at(i+1) :  nop) ;
                        

                    std::array <Instructions *, 2> res =  createPair( 
                         {
                              InstructionQueue.at(i),
                              Instr2
                         }
                    );
     
                    Scheduler newSchd{res.at(0), res.at(1)};

                    if(newSchd.schedulePair().size() == 3)
                         ++i;
                    else 
                         i+=2;

                         int k{0};
                         for( auto item : newSchd.schedulePair()){
                              if(k < 2){
                                   std::cout << item << std::endl;
                                   ++k;
                              }
                         }
               
          }
}


 

