#include <iostream>
#include <map>
#include <iterator>
int main(){
    const std::map < std::string, std::pair <int, std::string > > varInstr 
        {
            {"add", {1, "add"}}, 
            {"sub", {2, "sub"}}, 

    	}; 

    auto p = varInstr.find("add");

    std::cout << (p->second).first;

        
    
}
