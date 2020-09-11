#include "../../Headers/Assembler_hpp/Assembler.hpp"
#include <string>
#include <iomanip>

R_Instruction R_Instr1;
I_Instruction I_Instr1;
J_Instructions J_Instr1;
Exp_Instructions E_Instr1;
NOP_Instruction NOP_Instr;

bool hasLabel2;

  std::map <std::string, int> textSegmentTable;
  std::map <std::string, int> DataSegmentTable;
  int globalLineCount{0};

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
                              result << (token + " ");
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

                    case '.':
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


Assembler::Assembler(){}

Assembler::Assembler(const std::string & path)
    :filepath{path}
{
    currentPoint = 0;
        
}


std::vector < std::string> Assembler::readFile(){
    Assembler::inputFile.open("/home/sweet12prof/Desktop/Final/2ISSPv3_SS/SourceFiles/scheduleRes.asm", std::ios::in);
    Assembler::inputFile.seekg(currentPoint);
    int lineCount{0};
    std::string lineString;
    std::vector<std::string> result;

    while(std::getline(Assembler::inputFile, lineString) && lineCount < 5 )
        {
           if(lineString != "\0") {
               result.push_back(lineString);
               ++lineCount;
               Assembler::currentPoint = Assembler::inputFile.tellg();
           }
                
        }
   inputFile.close();
   return result;
}

std::string Assembler::PostParseProcess(std::string item){
                std::ofstream output;
                std::stringstream postParseString {item} ;
                std::string Label;
                std::string restofString;
                std::string fullString;
                
                if( hasLabel2){
                    restofString = postParseString.str();
                    int location = restofString.find(" ");
                    restofString = restofString.substr(location + 1, restofString.npos);
                    postParseString >> Label;
                    postParseString.str("");
                    std::pair <std::string, int> textEntry {Label, globalLineCount};
                    textSegmentTable.insert( textEntry);                   
                }
                else {
                    restofString = postParseString.str();
                }

           // for(auto item : textSegmentTable)
               // std::cout << item.first << "\t\t" << item.second;
            //std::cout << std::endl << std::endl <<std::endl;
                globalLineCount++;
             
              return restofString;
}


int Assembler::getTextLabelAddress(const std::string & label){
    auto p = textSegmentTable.find(label);

    if(p == textSegmentTable.end())
        throw std::invalid_argument("Lexical error at line " + globalLineCount);
    else 
        return p->second;
} 



Instructions * Assembler::CreateInstructionObject(const std::string & instrString){   
    std::stringstream instrStream{instrString};
    std::string op;
    instrStream >> op;
    instrStream.str("");
    instrStream.str(instrString);

    std::string immLabel;
    int rs, rt, rd, Imm;

    Instructions *result{nullptr};

    switch(Instructions::getInstrType2(op))
        {
            case Instructions::InstrType::R_Type : 
                {
                    instrStream >> op >> rd >> rs >> rt; 
                                   switch(R_Instruction::getRType_Type(op) )
                                        {
                                             case R_Instruction::R_Type::def_R_Type : 
                                                  R_Instr1.createR_Instruction(op,  rs, rt, rd,  0, "");
                                             break; 

                                             case R_Instruction::R_Type::Jr_Type :
                                                  R_Instr1.createR_Instruction(op,  rd, 0, 0,  0, "");                                                
                                             break; 

                                             case R_Instruction::R_Type::Imm_R_Type :
                                                  R_Instr1.createR_Instruction(op,  0, rt, rd,  rs, "");
                                             break;
                                             
                                             default :
                                             throw std::invalid_argument("Rtype Type Op does not exist");
                                        }
                result = &R_Instr1;
                   
                }
            break;
             
            case Instructions::InstrType::I_Type :
                {
                    switch( I_Instruction::getIType_Type_static(op) )
                        {
                            case I_Instruction::I_Type::Mem_LwType:
                            case I_Instruction::I_Type::Mem_Sw_Type:
                                instrStream >> op >> rt >> Imm >> rs;
                                I_Instr1.createI_Instruction(op, rs, rt, Imm, "", "");
                            break; 

                            case I_Instruction::I_Type::Imm_Type :
                                instrStream >> op >> rt>> rs >> Imm;
                                I_Instr1.createI_Instruction(op, rs, rt, Imm, "", "");
                            break;

                            case I_Instruction::I_Type::Branch_Type:{
                                     instrStream >>  op >> rt >> rs >>  immLabel;
                                
                                auto p = textSegmentTable.find(immLabel);
                               // std::cout << "label is " << immLabel;
                                if(p == textSegmentTable.end())
                                    throw std::invalid_argument("Lexical Error at line ");
                                else 
                                    Imm = p->second;

                                    I_Instr1.createI_Instruction(op, rs, rt, Imm , "", immLabel);
                            }                           
                            break;


                        }
                    result = &I_Instr1;
                }
            break;

            case Instructions::InstrType::J_Type : 
            {
                instrStream >> op >> immLabel;

                auto p = textSegmentTable.find(immLabel);
                
                    if(std::string errMessage{"Lexical Error"}; p == textSegmentTable.end()  )
                        throw std::invalid_argument(errMessage);
                    else 
                        Imm = p->second;
                
                
                J_Instr1.createJ_Instructions(op, Imm, "", immLabel);
                result = & J_Instr1;
            }
            break;

            case Instructions::InstrType::Exp :
            {
                instrStream >> op >> rd >> rt;
                E_Instr1.createExp_Instructions(op, rd, rt, "");
                result = & E_Instr1;
            }
            break;

            case Instructions::InstrType::nop :
                {
                    instrStream >> op;
                    NOP_Instr.createNOP_Instruction(op, "");
                    result = & NOP_Instr;
                }
            break;

            default:
                {
                    throw std::invalid_argument("Could not create Instruction Object for Translation, Invalid op most probable");
                }
        }
    return result;

}

std::streampos Assembler::getCurrentpoint() const{
    return Assembler::currentPoint;
}


std::string Assembler::Translate(Instructions * instr ,Instructions::machineFormat format){
    std::stringstream output;
        output  << std::left  
                << std::setw(20) 
                << instr->MachineCodeString(Instructions::machineFormat::S_tring)
                <<  ("\t" +  instr->MachineCodeString(format)) 
                << "\t" << instr->MachineCodeString(Instructions::machineFormat::Binary);
    return  output.str();
}

std::string Assembler::Translate_To_MachineRepresentation(Instructions * instr ,Instructions::machineFormat format){
    std::stringstream output;
        output  << std::setw(8) 
                << std::left
                << instr->MachineCodeString(format); 
    return  output.str();
}


void Assembler::Assemble( Instructions::machineFormat format){
    std::ofstream OutputFile {"Output/log.txt", std::ios::out};
    std::ofstream machineOutput{"Output/Binaries.txt", std::ios::out};
    std::vector <std::string> machineFormatResult;

    std::cout << std::endl;
    std::cout   << std::left  
                << std::setw(20) 
                << "Scheduling Output"
                <<  "\t" << std::setw(10) 
                << std::left << "hexOutput"  
                <<  "\t" << std::setw(32) 
                << std::left << "Binary Output" 
                << std::endl;

    std::vector <std::string> result;
    std::vector<std::string>  InstructionQueues;
    FileHelper fileproc{Assembler::filepath};
      try{
              result = fileproc.fileProcess(Assembler::filepath);
          }
          catch(std::exception &ex){
              std::cout << ex.what();
          }
    fileproc.writeScheduleResults(result);

        while( Assembler::getCurrentpoint() != -1 ){
            std::vector <std::string> result = Assembler::readFile();
            for(auto item : result)
                try{
                    std::string output = Assembler::Translate (Assembler::CreateInstructionObject ( Assembler::PostParseProcess( Assembler::parseString(item).str() ) ), Instructions::machineFormat::Decimal );
                    std::cout << output << std::endl;
                    OutputFile << output << std::endl;
                    std::string machineFormatOutput = Assembler::Translate_To_MachineRepresentation(Assembler::CreateInstructionObject(Assembler::PostParseProcess( Assembler::parseString(item).str() ) ), format);
                    machineFormatResult.push_back(machineFormatOutput);
                }
                catch(std::invalid_argument ex)
                    {
                        std::cout << ex.what() << std::endl;
                    }               
                }
        std::cout << std::endl;
        //std::cout << std::endl << "Output written to file: " << OutputFile.;
        OutputFile.close();

        for(auto item : machineFormatResult){
            machineOutput << item << std::endl;
        }
            machineOutput.close();
}



  void Assembler::processSegments(const std::string & path){
    std::ifstream inputFile;
    std::ofstream outputFile;
    std::string line;
    std::vector <std::string > dataSection;
    std::vector <std::string> textSection;
    
    bool isDataSection;
    bool set = false;

        inputFile.open(path, std::ios::in);
        if(!inputFile)
            std::cerr << "File Could not be opened Here2";
        else 
            {
                while(std::getline(inputFile, line)){
                    if(line == ".data"){
                        isDataSection = true;
                        set = true;
                    }
                        
                    else if(line == ".text")
                        {
                            isDataSection = false;
                            set = true;
                        }
                    else 
                    {
                        if (set == true && line != "\0")
                        {
                            if(isDataSection == true)
                                dataSection.push_back(line);
                            else 
                                textSection.push_back(line);
                        }

                    }
                }
                inputFile.close();
            }

        outputFile.open("Output/textSection.txt", std::ios::out);
        if(int i{0}; !outputFile)
            std::cerr << "Could not create File";
        else {
            for (auto item : textSection){
                if(i != textSection.size() - 1)
                    outputFile << item << std::endl;
                else 
                    outputFile << item;
                ++i;
            }
                
        }
        outputFile.close();

        outputFile.open("Output/dataSection.txt", std::ios::out);
        if(!outputFile)
            std::cerr << "Could not create File";
        else {
            for (auto item : dataSection)
                outputFile << item << std::endl;
        }
        outputFile.close();


  }

  void Assembler::processDataSegment(){
     
      std::vector <std::string> data;
      std::string line;
      std::ifstream inputFile{"/home/sweet12prof/Desktop/Final/2ISSPv3_SS/SourceFiles/Output/dataSection.txt", std::ios::in}; 
      if(!inputFile){
            std::cerr << "File could not be opened";
            exit(EXIT_FAILURE);
      }
      else {
                while(std::getline(inputFile, line) && line != "\0")
                {
                    data.push_back(Assembler::parseString(line).str());
                }
      }
       
  }

//   void parseString2(const std::string someString){
//       int tokencount{0};
//       for(int i{0}; i < someString.size(); ++i){
//           if(i = ' ')
//           {
//               if(tokencount == 0)
//               ++tokencount;
//           }
//       }
//   }