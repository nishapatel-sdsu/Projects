/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/31/2012                                      ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class inpmlement pass 1 of the assmebler.This 
class is used to generate and intermediate file from the program 
source code.********
********************************************************************/
#include<iostream>
#include<iomanip>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <string.h>
#include <cctype>
#include <algorithm>
#include "patelnst.h"
#include "patelnliteraltable.h"
#include "patelnliterals.h"
#include  "patelnerr.h"
#include  "pass1.h"
#include "patelnlinkedlistnode.h"
#include <math.h>
using namespace std;

int locctr = 0;
int LineCount = 1;
int literallocctr = 0;
int interimlocctr = 0;
OpcodeTable* Pass1Assembler :: getopcodetable()
    {
    return &opcodetable;
    }
  ExpressTable *Pass1Assembler :: getexpresstable()
    {
    return &expresstable;
    }
   Linklist<literals,string> *Pass1Assembler :: getliterallist()
       {
       return &literallist;
       }
   SymbolTable	*Pass1Assembler :: getsymboltable()
       {
          return  &symboltable;
       }
     int Pass1Assembler :: getprogramlength()
         {
       
         return programLength;
         }
/********************************************************************
*** FUNCTION isNumber                                             
*********************************************************************
*** DESCRIPTION :  Validates if the string is a number            ***
*** INPUT ARGS  :string value  The expr to be tested              ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns true if the expr is number or false 
                    otherwise                                     ***
********************************************************************/


bool isNumber(string value)
    {
    if(value.length() == 0) return false;	

    bool isValid = true;
 // Check if the other characters are 0-9
         for(int i=0; i<value.length();i++){
            if( !(value[i] >= '0' && value[i] <= '9')){
                isValid = false;
               
                break;
                }
            }
   return isValid;
    }

/********************************************************************
*** FUNCTION init()                                            
*********************************************************************
*** DESCRIPTION :This function is used to initialize the          ***
                 Pass1Assembler. It is used to create the opcode  ***
                 table.                                           ***
                 It then sets the references for the symbol table ***
                 and literal list for the expression table        ***
                 It is a default constructor                      ***

*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/

void Pass1Assembler :: init(){
   
    string filename = "ops.dat";
   opcodetable.createOpcodeTable(filename);
   expresstable.setSymboltable(&symboltable);
   expresstable.setliterallist(&literallist);
   addRegisters();
    }
void Pass1Assembler ::addRegisters()
    {
    string regName = "";
    int value = 0;
    regName = "A";
    value = 0;
      SymbolAttribute dataA(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataA);

          regName = "X";
          value = 1;
      SymbolAttribute dataX(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataX);

          regName = "L";
          value = 2;
      SymbolAttribute dataL(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataL);

          regName = "B";
          value = 3;
      SymbolAttribute dataB(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataB);

          regName = "S";
          value = 4;
      SymbolAttribute dataS(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataS);

          regName = "T";
          value = 5;
      SymbolAttribute dataT(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataT);

          regName = "F";
          value = 6;
      SymbolAttribute dataF(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataF);

          regName = "PC";
          value = 8;
      SymbolAttribute dataPC(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataPC);

          regName = "SW";
          value = 9;
      SymbolAttribute dataSW(0,0,0,value,regName); //to do 
         symboltable.insertSymbol(regName,dataSW);

    }
/********************************************************************
*** FUNCTION  Pass1Assembler                                   
*********************************************************************
*** DESCRIPTION :This is the default constructor of Pass1Assembler
class                                                             ***
*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/

Pass1Assembler ::Pass1Assembler()
{
 }
/********************************************************************
*** FUNCTION  getHexValueFromAscii()                                
*********************************************************************
*** DESCRIPTION :   It is used to get the hex value from ascii    ***
                    value                                         ***
*** INPUT ARGS  :string value The expr to be convertes            ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - string                                        ***
********************************************************************/
string getHexValueFromAscii(string value)
    {
 const char* cvalue = value.c_str();
 stringstream ss;
    const char* it = cvalue;
    const char* end = cvalue + strlen(cvalue);
     for (; it != end; ++it){
        if(*it == ' ')
            continue;
        ss << std::hex << unsigned(*it);
        }	
    unsigned result;
    ss >> result;
   string address = ss.str();
return address;
}

bool isNotCommentLine(string line);// forword declaration
bool processline(string progline, string &label,string &operand, string &opcode);// forword declaration
//bool processFirstline(string progline, string &operand);// forword declaration
 
 
/********************************************************************
*** FUNCTION  getLiteralLengthAndValue()                          ***
*********************************************************************
*** DESCRIPTION : *** Used to get the length and value of literal ***
*** INPUT ARGS  :string exp The expression to be calculated       ***
                 int &literallength Length of literal
                  string &literalhexvalue Hex value of literal    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void   getLiteralLengthAndValue(string exp,int &literallength,string &literalhexvalue)
    {
    bool error = false;
    // get the address
     if(exp[0] == '='){
        exp = exp.substr(1);
        }
  int explength = exp.length();

     //check if the literal needs to be converted to hex
    if(exp[0] == 'C' || exp[0] == 'c'){
        if( exp[1] == '\'' && exp[explength-1] == '\''){ //check to see if the literal conatins the single quotes
            string ascii = exp.substr(2,explength - 3); //Read the literal between the single quotes
            literalhexvalue = getHexValueFromAscii(ascii);
            literallength = ascii.length();
            }
        else {
            cout <<"The literal "+exp +"is not valid. The literal is missing the single quotes"<<endl;
            error = true;
            tocontinue();
            }
        }
    //check if the literal is already in hex
    else if(exp[0] == 'X' || exp[0] == 'x'){
        if( exp[1] == '\'' && exp[explength-1] == '\''){ //check to see if the literal conatins the single quotes
            literalhexvalue = exp.substr(2,explength-3); //Read the literal between the single quotes

            for(int i=0;i<literalhexvalue.length();i++){ 
                char hexval =literalhexvalue[i];
                //evaluate that the hex literal has valid hex characters
                if(!(hexval>='0'&&hexval<='9'||hexval>='A'&&hexval<='F'||hexval>='a'&&hexval<='f')){ 
                    cout<<"Error: The literal: "<<exp<<" contains ";
                    cout <<hexval;
                    cout <<" which is not a valid hex value"<<endl;
                    tocontinue();								
                    return;
                    }
                }
            int literalhexvaluelength = literalhexvalue.length();
            if((literalhexvaluelength % 2) == 0){
                literallength = literalhexvaluelength/2;
                }
            else {
                literalhexvalue = "0"+literalhexvalue;
                literallength = (literalhexvaluelength + 1)/2;
                }
            }
        else {
            cout <<"The literal "+exp +"is not valid. The literal is missing the single quotes"<<endl;
            error = true;
            tocontinue();
            }
        }
    else {
        cout <<"Literal "+exp +" is not valid. The char after = is "+exp[1] +". Only one of X,x,C or c is allowed after = "<<endl;
        error = true;
        tocontinue();
        }
    }

/********************************************************************
*** FUNCTION  readprogramFile                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to read the program source file
                 It processes the file for Pass1 assembler. 
                 Generates the intermediate .int file             ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void Pass1Assembler::readprogramFile(string filename)
    {
    ifstream inf;
    inf.open(filename.c_str(), ios::in);
    if (!inf) {
        cout << "can't open file";
        return;
        }
    else
        {
       string progline = "";
       string  label = "";
       string opcode = "";
        string operand = "";
        int rflag = 1;
        int iflag= 1;
        int mflag = 0;

        outf<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(24)<<"OPERAND"<<endl;
       // cout<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(24)<<"OPERAND"<<endl;
        tocontinue();
        getline(inf, progline);
      
         while(!isNotCommentLine(progline)) {
             // cout <<left<<progline<<endl;
              getline(inf, progline);
              }
         if(processline(progline, label,operand, opcode))
           {
             
            SymbolAttribute data(1,1,0,locctr,label); //to do 
            symboltable.insertSymbol(label,data);

           	locctr=atoi(operand.c_str());
             getline(inf, progline);
           processline(progline, label,operand, opcode);
            
            stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<locctr;
        string sloctr= ss.str();
         std::transform(sloctr.begin(), sloctr.end(), sloctr.begin(),(int (*)(int))std::toupper);
        outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	// cout<<left<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
   
	 LineCount++;
       tocontinue();
           }
       else
           {
           locctr = 0;
              stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<locctr;
        string sloctr= ss.str();
        std::transform(sloctr.begin(), sloctr.end(), sloctr.begin(),(int (*)(int))std::toupper);
    outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	// cout<<left<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	 LineCount++;
       tocontinue();
            
           }

        while ( (opcode != "END" || opcode != "end") && !inf.eof()) { // 
               
               if(isNotCommentLine(progline)){
                     
                   //Processing of label
                   if(label != ""){  // there is a symbol in label field
                         SymbolAttribute * symbolAttribute = symboltable.searchSymbol(label);
                         if(symbolAttribute != NULL){  // symbol already in symbol table
                           symbolAttribute->setMflag(1);
                               //cout <<"Error : Symbol Already in Symbol table";
                             }
                         else {    // insert the symbol in symbol table

                               if(opcode =="EQU"){ //Processing EQU directive
                                    //if operand is *
                                    if(operand == "*"){
                                        SymbolAttribute data(1,1,0,locctr,label); //to do 
                                       symboltable.insertSymbol(label,data);

                                         stringstream ss;
                                       ss  << hex << setw(5) <<setfill('0')<<locctr;
                                       string svalue= ss.str();
                                        std::transform(svalue.begin(), svalue.end(), svalue.begin(),(int (*)(int))std::toupper);
                                       
                                       outf<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                 // cout<<left<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                   LineCount++;
                                         tocontinue();
                                   }

                                    else if(isNumber(operand)){
                                          SymbolAttribute data(0,1,0,atoi(operand.c_str()),label); //to do 
                                       symboltable.insertSymbol(label,data);

                                         stringstream ss;
                                       ss  << hex << setw(5) <<setfill('0')<<atoi(operand.c_str());
                                       string svalue= ss.str();
                                        std::transform(svalue.begin(), svalue.end(), svalue.begin(),(int (*)(int))std::toupper);
                                       outf<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                //  cout<<left<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                   LineCount++;
                                         tocontinue();
                                     }
                                    else {
                                       Expression exp;
                                       expresstable.evaluatesingleExpression(operand,&exp);
                                       int value  = exp.value;
                                       int rflag1 = exp.relocatableFlag;
                                       SymbolAttribute data(rflag1,iflag,mflag,value,label); //to do 
                                       symboltable.insertSymbol(label,data);

                                        stringstream ss;
                                       ss  << hex << setw(5) <<setfill('0')<<value;
                                       string svalue= ss.str();
                                        std::transform(svalue.begin(), svalue.end(), svalue.begin(),(int (*)(int))std::toupper);
                                       
                                       outf<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                //  cout<<left<<setw(8)<<LineCount<<setw(8)<<svalue<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	                                   LineCount++;
                                         tocontinue();
                                   }
                              }

                               else {
                                      SymbolAttribute data(1,1,0,locctr,label); //to do 
                                       symboltable.insertSymbol(label,data);
                                  
                                   } 
                             }

                         }// if(label != "") 
                   //Processing opcode 
                OpcodeValue* data  =  opcodetable.searchOpcodeValue(opcode);
              
               if(data!= NULL)
                   {
                   //add 3 instrucation length to locctr
                  int format = data->getformat();
                  locctr = locctr + format;
                  }
                else if(opcode[0] == '+') { // processing format 4
                     string temp = opcode.substr(1);
             
                      OpcodeValue* data  =  opcodetable.searchOpcodeValue(temp);
                      if(data != NULL) {
                               int format = data->getformat();
                                 locctr = locctr + format + 1;
                          }
                   }
               else if(opcode=="WORD" ||opcode=="word") //the operation is a word
                   {
                  locctr = locctr + 3;
                   }

                else if(opcode=="RESW" ||opcode=="resw") //the operation is a resw
                   {
                        int value = atoi(operand.c_str());
                       int  ivalue = value* 3;
                        locctr =locctr +ivalue;
                         }
                 else if(opcode=="RESB" || opcode=="resb") //the operation is a resb
                   {
                    int value = atoi(operand.c_str());
                    locctr =locctr + value;
                   }
                   
                else if(opcode=="BYTE" || opcode=="byte") //the operation is a byte
                   {
                      int literallength = 0;
                      string literalhexvalue = "";
                      getLiteralLengthAndValue(operand,literallength,literalhexvalue);
                      locctr =locctr + literallength;
           
                   }  
                else
                    {
                   // cout<<"opcode is not in the opcode table"<<opcode<<endl;
                    }

                // evaluate literal
                expresstable.evaluateAllLiterals(operand);
                   }// if(isNotCommentLine(progline))
            
	      //reset the variables
          label = "";
          operand = "";
          opcode = "";
           getline(inf, progline);
          while(!isNotCommentLine(progline) &&  !inf.eof()) {
              cout <<left<<progline<<endl;
              getline(inf, progline);

              }
           processline(progline, label,operand, opcode);
              

       if(opcode != "EQU" && progline.length() > 0){
        
            stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<locctr;
        string sloctr= ss.str();
         std::transform(sloctr.begin(), sloctr.end(), sloctr.begin(),(int (*)(int))std::toupper);
    outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
         
   
	// cout<<left<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	 LineCount++;
       if(inf.eof()) break;
       tocontinue();
           }
}// end while
      interimlocctr = locctr;
// display literals
      appendliterals();
      //print symbol table
           //cout <<endl ;
           //cout <<"SYMBOL TABLE" <<endl<<endl;
           //symboltable.viewSymbolTable();
      
           //cout <<endl;
           //cout <<"LITERAL TABLE"<<endl<<endl;
           //literallist.display();
        } // end if (!inf)
        inf.close();
 }
 
/********************************************************************
*** FUNCTION  isNotCommentLine                                   
*********************************************************************
*** DESCRIPTION : Checks whether the program line is a            ***
                  comment line                                    ***
*** INPUT ARGS  : string line                                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
bool isNotCommentLine(string line){
    if(line.length() == 0) return false;
    char c = line[0];
    if(c == ';') return false;
    else return true;

    }

/********************************************************************
*** FUNCTION  processline                                   
*********************************************************************
*** DESCRIPTION : It is used to extract the label, operand        ***
                  and opcode from the line                        ***
*** INPUT ARGS  :string progline : The line to be evaluated       ***
                 string &label Reference to the the label field   ***
                 string &operand Reference to the operand field   *** 
                 string &opcode Reference to the opcode field     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns true if it is a start line else false ***
********************************************************************/
bool processline(string progline, string &label,string &operand, string &opcode)
    {
    if(progline.length() == 0) return false;
    char c =   progline[0];
    if (c == ' ')
        {
        size_t found = progline.find_first_not_of(" ");

        if(found !=string::npos)
            progline = progline.substr(found,(progline.length()-found));

        found=progline.find_last_not_of(" \n\r");
        if (found!=string::npos)
            progline.erase(found+1);

           string buffer = "";
        stringstream ss(progline);
        vector<string> tokens;

        while (ss>>buffer)
            {
            tokens.push_back(buffer);
            }
        if(tokens.size() > 0 ){
            opcode = tokens[0];
            if(tokens.size() > 1) {
               operand =  tokens[1];
                }
            }
        }
    else
        {
      size_t found=progline.find_last_not_of(" \n\r");
        if (found!=string::npos)
            progline.erase(found+1);
        string buffer = "";
        stringstream ss(progline);
        vector<string> tokens;

        while (ss>>buffer)
            {
            tokens.push_back(buffer);
            }
        label = tokens[0];
         opcode = tokens[1];
         if(tokens.size() >2 )
         operand =  tokens[2];
 }

    std::transform(opcode.begin(), opcode.end(), opcode.begin(),(int (*)(int))std::toupper);

    if(opcode =="START" || opcode =="start")
        {
        
           stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<locctr;
        string sloctr= ss.str();
   std::transform(sloctr.begin(), sloctr.end(), sloctr.begin(),(int (*)(int))std::toupper);

      outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	// cout<<left <<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
	LineCount++;
      tocontinue();
        return true; 
        }
    else
        return false;
    }

/********************************************************************
*** FUNCTION  appendliterals                                
*********************************************************************
*** DESCRIPTION :    Append the literals to the literal pool      ***
*** INPUT ARGS  : -                                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -   void                                        ***
********************************************************************/
 void Pass1Assembler :: appendliterals()
       {

   node<literals> *root ;
   root =   literallist.getrootNode();
    node<literals> *m;
   for(m=root;m!=NULL;m=m->link){
      string name =  m->data.name;
       int length = m->data.length;
       m->data.address = locctr;
     
            stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<locctr;
        string sloctr= ss.str();
       
     outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<'*'<<setw(12)<<name<<setw(24)<<endl;
	// cout<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<'*'<<setw(12)<<name<<setw(24)<<endl;
	 LineCount++;
       tocontinue();
      literallocctr = literallocctr + length;
      locctr = locctr + length;
       }
   programLength =  locctr;
  //  cout << endl <<endl;
  //  cout <<"Program Length = " << hex <<interimlocctr << "- 0 + " << hex << literallocctr << " = " << hex <<locctr <<endl;
        
       }
        

    
