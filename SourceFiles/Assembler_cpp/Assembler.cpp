#include "../../Headers/Assembler_hpp/Assembler.hpp"
#include <string>
#include <iomanip>

Assembler::Assembler(){}

Assembler::Assembler(const std::string & path)
    :filepath{path}
{
    Assembler::inputFile.open(Assembler::filepath, std::ios::in);
    if(!Assembler::inputFile)
        {
            std::cerr << "\nThe file could not be opened";
            exit(EXIT_FAILURE);
        }
    else {
            Assembler::inputFile.close();
            Assembler::inputFile.seekg(0, std::ios::end);
            endLocation = Assembler::inputFile.tellg();
            Assembler::inputFile.close();
    }
    currentPoint = 0;
        
}


std::vector < std::string> Assembler::readFile(){
    Assembler::inputFile.open(Assembler::filepath, std::ios::in);
    Assembler::inputFile.seekg(currentPoint);
    int lineCount{0};
    std::string lineString;
    std::vector<std::string> result;

    while(std::getline(Assembler::inputFile, lineString) && lineCount < 5 )
        {
           if(lineString != "\0") {
               result.push_back(lineString);
               ++lineCount;
               currentPoint = Assembler::inputFile.tellg();
               ++globalLineCount;
           }
                
        }
   inputFile.close();
   return result;
}

void Assembler::RemoveWhiteSpace(){
    std::ofstream output;
    std::string filepath = "POSTwhitespace";
    std::vector <std::string> postWhiteSpace;
    std::vector <std::string> postRead = Assembler::readFile();

        for(auto item : postRead)
            {
                std::stringstream postParseString = Assembler::parseString(item) ;
                std::string Label;
                std::string restofString;
                std::string fullString;
                
                if( hasLabel2){
                    restofString = postParseString.str();
                    int location = (int)restofString.find(" ");
                    restofString = restofString.substr(location + 1, restofString.npos);
                    postParseString >> Label;
                    postParseString.str("");
                    std::pair <std::string, int> textEntry {Label, globalLineCount};
                    textSegmentTable.insert( textEntry);
                    
                }
                else {
                    restofString = postParseString.str();
                }
                    

                     postWhiteSpace.push_back(restofString);    
            }
        
        
        output.open(filepath, std::ios::out );

        if(!output)
            {
                std::cerr << "File could not be opened or created";
                exit(EXIT_FAILURE);
            }
        else 
            for(auto item : postWhiteSpace)
                output << item << std::endl;
        
        
}


std::stringstream Assembler::parseString(std::string & someString ){
     // Variable to hold current Token in a string being parsed
      std::string token =""; 
     
     //  Stream to hold parsed Instruction
      std::stringstream result;

     // Iterator to help in iterating string to parse
      int i{0};

      // set has label vto false before starting parse
      hasLabel2 = false;

      // iterate through every character in string  to parse
     for(auto item : someString)
          {
               switch(item){
                    case ':' :
                         hasLabel2 = true;
                         if(token != "")
                              result << (token + ": ");
                         token = "";
                   break; 

                    case ' ' :
                         if(token != "")
                              result << (token + " ");
                          token = "";
                    break;

                    case '(' :
                         result << (token + " ");
                         token = "";
                    break;

                    case ')' :
                          result << (token + " ");
                          token = "";
                    break;

                    case '$' :
                    break;

                    case ',' :
                    break;


                    
                    default: 
                    {
                               token += item;
                               if(i == someString.size() - 1 )
                                   result << token;    
                    }                        
               }

             ++i;               
          }
     return result;
 }