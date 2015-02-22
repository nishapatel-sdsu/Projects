/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 11/25/2012                                      ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class inpmlement pass 2 of the assmebler. ****
This class is used to generate and list file and the object code ****
file from the intermediate file from pass1                       ****
********************************************************************/

#include <stdio.h>
#include<iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <string.h>
#include<vector>
#include<math.h>
#include  "pass2.h"
#include "pass1.h"
#include <cctype>
#include  "patelnerr.h"

using namespace std;
/********************************************************************
*** FUNCTION  isNotCommentLine2                                   
*********************************************************************
*** DESCRIPTION : Checks whether the program line is a            ***
                  comment line                                    ***
*** INPUT ARGS  : string line                                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
bool isNotCommentLine2(string line);
/********************************************************************
*** FUNCTION  isLiteral                                   
*********************************************************************
*** DESCRIPTION : Checks whether the string is a literal          ***
                                                                  ***
*** INPUT ARGS  : string exp                                      ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is a literal         ***
                  line or returns false                           ***
********************************************************************/
bool isLiteral(string exp);
/********************************************************************
*** FUNCTION isNumber2                                             
*********************************************************************
*** DESCRIPTION :  Validates if the string is a number            ***
*** INPUT ARGS  :string value  The expr to be tested              ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns true if the expr is number or false 
                    otherwise                                     ***
********************************************************************/
bool isNumber2(string value);
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
void getLiteralLengthAndValue(string exp,int &literallength,string &literalhexvalue);

string assembleExpressionObjectCode(int format4Flag,int operandaddress,Expression * exp,OpcodeValue* data, string locttr,int baseVal);
/********************************************************************
*** FUNCTION  convertToFirst2BitBinary                                   
*********************************************************************
*** DESCRIPTION : Calculates the First2 Bit binary                ***
                  comment line                                    ***
*** INPUT ARGS  : char opcode The data to be converted             ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
string convertToFirst2BitBinary(char opcode);
/********************************************************************
*** FUNCTION  convertFirst4ToHex                                   
*********************************************************************
*** DESCRIPTION : Calculates the First 4 Bit to Hex               ***
                                                                  ***
*** INPUT ARGS  : string binary 
                  int indirectFlag 
                  int immediateFlag                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
string convertFirst4ToHex(string binary , int indirectFlag, int immediateFlag);

/********************************************************************
*** FUNCTION  assembleLittralObjectCode                           ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the Litteral 
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
string assembleLittralObjectCode(int format4Flag,int operandaddress,OpcodeValue* data, literals *searchliteral ,string locttr,int baseVal);
/********************************************************************
*** FUNCTION  convertToThirdHexBit                                   
*********************************************************************
*** DESCRIPTION : Calculates the Third bit of the object code     ***
                                                                  ***
*** INPUT ARGS  : string binary 
                  int indirectFlag 
                  int immediateFlag                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
string convertToThirdHexBit(int index,int bFlag ,int pFlag,int eFlag);

/********************************************************************
*** FUNCTION  trim()                                              ***
*********************************************************************
*** DESCRIPTION : *** Used to trim the string                     ***
*** INPUT ARGS  :string &str The string to be terminated          ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void trim( string &str);
/********************************************************************
*** FUNCTION  binToDec                                   
*********************************************************************
*** DESCRIPTION : Converts bin to Dec                             ***
                  comment line                                    ***
*** INPUT ARGS  : string binaryData The data to be converted      ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/

int binToDec(string binaryData);
/********************************************************************
*** FUNCTION  convertIntToString                                  ***
*********************************************************************
*** DESCRIPTION : *** Used to trim the string                     ***
*** INPUT ARGS  :int num The number to be converted to string     ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The string of the number                        ***
********************************************************************/
string convertIntToString(int num);// convert int to string
/********************************************************************
*** FUNCTION  convertIntToHex                                     ***
*********************************************************************
*** DESCRIPTION : *** Used to convert int to Hex                  ***
*** INPUT ARGS  :int num The number to be converted to hex        ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                        ***
********************************************************************/
string convertIntToHex(int number);
/********************************************************************
*** FUNCTION  calc2scomplement                                    ***
*********************************************************************
*** DESCRIPTION : *** Used to get the 2s complement of number     ***
*** INPUT ARGS  :int num The number                               ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The 2s complement of a no.                      ***
********************************************************************/
int  calc2scomplement(int value);
/********************************************************************
*** FUNCTION  containsOnlySpaces                                  ***
*********************************************************************
*** DESCRIPTION : *** Used to determine if the string only contains
                  spaces                                          ***
*** INPUT ARGS  :int num The number                               ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : True if the string only contains spaces         ***
********************************************************************/
bool containsOnlySpaces(string str);
string paddZeros(string operand);
/********************************************************************
*** FUNCTION  assembleNoOperandObjectCode                         ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the object code for 
                 no opernad instructions   
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
string assembleNoOperandObjectCode(OpcodeValue* data);
/********************************************************************
*** FUNCTION  calmRecord                                          ***
*********************************************************************
*** DESCRIPTION :The function is used to calculate m record    
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void  calmRecord(string operand,vector<string> *exdtokens,string progName,string locttr,string *modRecords);

/********************************************************************
*** FUNCTION  getExpressionValue                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to add modification 
                 record
                 It processes the line to determine if a modification 
                 record needs to be added                         ***
*** INPUT ARGS  :string operand : The operand to get the value    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass2Assembler :: getExpressionValue( string operand ,Expression * expression ){
    ExpressTable *expresstable =  pass1Assembler->getexpresstable(); 
    expresstable->evaluatesingleExpression(operand,expression);
}

void Pass2Assembler :: setPass1Assembler(Pass1Assembler * pass1){
    pass1Assembler = pass1;
    }

/********************************************************************
*** FUNCTION  readexpfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the intermediate
                 file
                 It processes the file for Pass2 assembler. 
                 Generates the list file                          ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass2Assembler :: readprogramFile(string filename)
    {
    ifstream inf;
    inf.open(filename.c_str(), ios::in);// read from the file
    //cout << "open file";
    if (!inf) {
        cout << "can't open file";
        return;
        }
    string line = "";
    // read first line from the file
    getline(inf, line);//header line
    getline(inf, line);

    string  locttr;
    string  label;
    string   opcode;
    string  operand;
    string linenum;
    int baseVal = 0;

    //   outf<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(24)<<"OPERAND"<<endl;
  //  cout <<endl;    
    cout<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(20)<<"OPERAND"<<setw(8)<<"OBJCODE"<<endl;
    outflst<<left<<setw(8)<<"LINE#"<<setw(8)<<"LOCCTR"<<setw(12)<<"LABEL"<<setw(12)<<"OPERATION"<<setw(20)<<"OPERAND"<<setw(8)<<"OBJCODE";
     tocontinue();
    processintline(line,linenum,locttr,label,opcode,operand);
    //cout<<"line#"<<linenum<<"locttr"<<locttr<<"label"<<label<<"opcode"<<opcode<<"operand"<<operand<<endl;
    // cout<<line<<endl;
    if(opcode == "START")
        {
        // outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
        cout<<left<<setw(8)<<linenum<<setw(8)<<locttr<<setw(12)<<label<<setw(12)<<opcode<<setw(20)<<operand<<endl;
        outflst<<endl<<left<<setw(8)<<linenum<<setw(8)<<locttr<<setw(12)<<label<<setw(12)<<opcode<<setw(20)<<operand;
        tocontinue();
        
        getline(inf, line);
        processintline(line,linenum,locttr,label,opcode,operand);
        }

    string objectcode = "";
    // while(opcode != "END"){
    while(!inf.eof()){
        
        if(isNotCommentLine2(line))
            {
            OpcodeValue* data = NULL;
            string objectcode ;
            int format4Flag = 0;
            // string chopcode = opcode;
            if(opcode[0] == '+') {
                // opcode = opcode.substr(1);
                format4Flag = 1;
                }

            if(opcode == "BASE") {
                Expression exp;
                getExpressionValue(operand,&exp);
                baseVal   = exp.value;
                //cout<<"The Base iS"<<baseRegVal;
                }
            else if(searchoptab(opcode, &data)){
                int operandaddress = 0;
                if(operand.length() > 0)
                    {

                    if (isLiteral(operand)) {
                        literals searchliteral;
                        if(getLiteral(operand,searchliteral)){
                            operandaddress = searchliteral.address;
                            objectcode = assembleLittralObjectCode(format4Flag,operandaddress,data,&searchliteral,locttr,baseVal);//call the assembleLittralObjectCode funcation

                            }
                        else {
                            cout<<"The literal not in the littral table"<<endl;
                            }
                        } // IF LITERAL
                    else if(data->getformat() == 2)// assemble formate 2 object code
                        {
                        objectcode = assembleformat2Objectcode(data,operand);
                        }

                    else {
                        Expression exp;
                        getExpressionValue(operand,&exp);
                        operandaddress = exp.value;
                        objectcode = assembleExpressionObjectCode(format4Flag,operandaddress,&exp,data,locttr, baseVal);
                        }
                    } // symbol in operand
                else{

                    objectcode = assembleNoOperandObjectCode(data);
                    //to calculate object code
                    }
                //   objectcode =  assembleObjectCode(opcode,operandaddress,data );// call the assembleobjectcode
                } // if opcode found
            else if(opcode == "BYTE")
                {
                if(isNumber2(operand)){
                    //convert int to hex
                    int num = atoi(operand.c_str());
                    stringstream ss;
                    ss  << hex << setw(6) <<setfill('0')<<num;
                    string svalue= ss.str();
                    objectcode = svalue;
                    }
                else {
                    int literallength;
                    string literalhexvalue;
                    getLiteralLengthAndValue(operand, literallength,literalhexvalue);
                    objectcode = paddZeros(literalhexvalue);
                    }
                }
            else if(opcode == "WORD")
                {
                if(isNumber2(operand)){
                    //convert int to hex
                    int num = atoi(operand.c_str());
                    stringstream ss;
                    ss  << hex << setw(6) <<setfill('0')<<num;
                    string svalue= ss.str();
                    objectcode = svalue;
                    }
                else {
                    Expression exp;
                    getExpressionValue(operand,&exp);
                    int value = exp.value;
                    string svalue = "";
                    if(value < 0) {
                        int value2scomp = calc2scomplement(value);
                        stringstream ss;
                        ss  << hex << setw(6) <<setfill('F')<<value2scomp;
                        svalue = ss.str();
                        }
                    else {
                        stringstream ss;
                        ss  << hex << setw(6) <<setfill('0')<<value;
                        svalue= ss.str();
                        }

                    objectcode = svalue;

                    }
                }
            else if(opcode == "EXTREF") {
                std::stringstream ss(operand);
                string extSymbol;
                while(std::getline(ss, extSymbol, ',')) {
                    SymbolAttribute data(0,0,0,0,extSymbol); //to do 
                    pass1Assembler->getsymboltable()->insertSymbol(extSymbol,data);

                    }
                }

            else if (isLiteral(opcode)) {
                literals searchliteral;
                if(getLiteral(opcode,searchliteral)){
                    objectcode = searchliteral.value;
                    }
                }



            // outf<<setw(8)<<LineCount<<setw(8)<<sloctr<<setw(12)<<label<<setw(12)<<opcode<<setw(24)<<operand<<endl;
            std::transform(objectcode.begin(), objectcode.end(), objectcode.begin(),(int (*)(int))std::toupper);
            cout<<left<<setw(8)<<linenum<<setw(8)<<locttr<<setw(12)<<label<<setw(12)<<opcode<<setw(20)<<operand<<setw(8)<<objectcode<<endl;
            outflst<<endl<<left<<setw(8)<<linenum<<setw(8)<<locttr<<setw(12)<<label<<setw(12)<<opcode<<setw(20)<<operand<<setw(8)<<objectcode;
       //       tocontinue();
   
            }//not a comment line
        getline(inf, line);
        // if(inf.eof()) break;
         if(containsOnlySpaces(line)) break;
        while(!isNotCommentLine2(line) && !inf.eof()) {
       //       cout <<left<<progline<<endl;
              getline(inf, line);
              }
           //if(inf.eof()) break;
          if(containsOnlySpaces(line)) break;
        processintline(line,linenum,locttr,label,opcode,operand);
        }// while 
        cout << endl <<endl;

            stringstream sslen;
        sslen  << hex <<pass1Assembler->getprogramlength();
        string sproLen= sslen.str();
         std::transform(sproLen.begin(), sproLen.end(), sproLen.begin(),(int (*)(int))std::toupper);
      
        cout <<"Program Length ="<< sproLen<<endl;


    outflst<<endl<<endl<<"Program Length = "<< sproLen;
    outflst <<endl<<endl ;
    cout <<endl<<endl ;
    cout <<"SYMBOL TABLE" <<endl<<endl;
    outflst <<"SYMBOL TABLE" <<endl<<endl;
           
           pass1Assembler->getsymboltable()->viewSymbolTable();
           cout <<endl;
           tocontinue();
           cout <<"LITERAL TABLE"<<endl<<endl;
          
           outflst <<endl;
           outflst <<"LITERAL TABLE"<<endl<<endl;
          pass1Assembler->getliterallist()->display();
           tocontinue();
          
    inf.close();
    }
/********************************************************************
*** FUNCTION  convertIntToHex                                     ***
*********************************************************************
*** DESCRIPTION : *** Used to convert int to Hex                  ***
*** INPUT ARGS  :int num The number to be converted to hex        ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string convertIntToHex(int number)// convert int to hex
    {
    stringstream ss;
    ss  << hex <<number;
    return ss.str();

    }
/********************************************************************
*** FUNCTION  readlstfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the list
                 file
                 It processes the file to generate the object code 
                 Generates the objcode file                       ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass2Assembler :: readlstFile(string lstfileename)
    {
    ifstream inflst;
    string line = "";
    string  locttr = "";
    string  label = "";
    string   opcode = "";
    string  operand = "";
    string linenum  = "";
    string objectcode = "";
    string progName = "";
    inflst.open(lstfileename.c_str(), ios::in);// read from the file
    bool external = false;
    //cout << "open file"<<endl;
    if (!inflst) {
        cout << "can't open file"<<endl;
        return;
        }
    getline(inflst, line);//header line
    getline(inflst, line);
    processlstline(line,linenum ,locttr,label,opcode,operand,objectcode);
    stringstream ss;
    ss  << hex << setw(6) <<setfill('0')<<pass1Assembler->getprogramlength();
    string  prolen =  ss.str();
    cout<<endl <<"Object Program File"<<endl<<endl;
    //outfobj<<"ObjectProgram:"<<endl<<endl;
    locttr = "0" + locttr;
    progName = label;
    cout<<"H^"<<setw(8)<<label<<"^"<<setw(6)<<locttr<<"^"<<setw(6)<<prolen;
     outfobj<<"H^"<<setw(8)<<label<<"^"<<setw(6)<<locttr<<"^"<<setw(6)<<prolen;
     tocontinue();
   
     
    int textcount  = 0;
    bool newtextline =  true;
    string textrecodeline = "";
    string textrlength = "";
    string txtstartaddr = "";
    vector<string> tokens;
    vector<string> exdtokens;
    string modRecords = "";
    while(!inflst.eof()){
        getline(inflst, line);
        if(containsOnlySpaces(line)) break;
        processlstline(line,linenum ,locttr,label,opcode,operand,objectcode);
        if(opcode == "EQU") continue;
        if(opcode == "EXTDEF")
            {
            std::stringstream ss(operand);
            string extSymbol;
           
            cout<<endl<<"D";
            outfobj<<endl<<"D";
            tocontinue();
            while(std::getline(ss, extSymbol, ',')) {
                  exdtokens.push_back( extSymbol);
                SymbolAttribute data(0,0,0,0,extSymbol); //to do 
                SymbolAttribute * symbolAttribute = pass1Assembler->getsymboltable()->searchSymbol(extSymbol);
                string hexValue = "";
                if(symbolAttribute != NULL){  // symbol already in symbol table
                    int value = symbolAttribute->getValue();
                    stringstream ss;
                    ss  << hex << setw(6) <<setfill('0')<<value;
                    hexValue =  ss.str();

                    }

                 std::transform(hexValue.begin(), hexValue.end(), hexValue.begin(),(int (*)(int))std::toupper);
      
                cout<<"^"<<setw(8)<<extSymbol<<"^"<<setw(6)<<hexValue;
                 outfobj<<"^"<<setw(8)<<extSymbol<<"^"<<setw(6)<<hexValue;
                 tocontinue();
                }
            }
        else if(opcode == "EXTREF")
            {
             external = true;
            std::stringstream ss(operand);
            string extrSymbol;
            cout<<endl<<"R";
             outfobj<<endl<<"R";
             tocontinue();
            while(std::getline(ss, extrSymbol, ',')) {
                tokens.push_back(extrSymbol);
                cout<<"^"<<setw(8)<<extrSymbol;
                 outfobj<<"^"<<setw(8)<<extrSymbol;
                 tocontinue();
                }

            }
        else if(objectcode.length() == 0 || textcount == 10)
            {
            newtextline= true;
            textcount = 0;

            if(textrecodeline.length() > 0) {
                string endaddr = locttr;
                int iendaddr = 0;// convert hex to intrger
                std::stringstream ss;
                ss << std::hex <<endaddr;
                ss >>iendaddr;

                int  itxtstartaddr = 0; 
                std::stringstream strss;
                strss << std::hex << txtstartaddr;
                strss >>itxtstartaddr;


                int length = iendaddr -itxtstartaddr;
                stringstream iss;
                iss  << hex << setw(2) <<setfill('0') <<length; // convert hex to integer
                string  strlen =  iss.str();
                std::transform(strlen.begin(), strlen.end(), strlen.begin(),(int (*)(int))std::toupper);// convert to upper case

                cout<<endl<<"T^"<<setw(6)<<txtstartaddr<<"^"<<strlen<<textrecodeline;
                 outfobj<<endl<<"T^"<<setw(6)<<txtstartaddr<<"^"<<strlen<<textrecodeline;
                 tocontinue();
                }


            if(objectcode.length() > 0){
                textcount++;
                textrecodeline = "^"+ objectcode;
                txtstartaddr = "0" + locttr;
                newtextline = false;
                }
            else {
                textrecodeline = "";
                }
            }
        else if(objectcode.length()> 0)
            {
            textcount++;
            if(newtextline)
                {
                txtstartaddr = "0"+locttr;
                newtextline = false;

                }
            textrecodeline = textrecodeline + "^" + objectcode;
 }

        //check for M record
        if(external && opcode != "EXTREF")
        modificationRecord(&tokens,opcode,operand,&modRecords,locttr,progName,&exdtokens);


        //   cout<<setw(5)<<linenum<<locttr<<label<<opcode<<operand<<objectcode<<endl;
        //cout<<left<<setw(8)<<linenum<<setw(8)<<locttr<<setw(12)<<label<<setw(12)<<opcode<<setw(20)<<operand<<setw(8)<<objectcode<<endl;

        }
        //print the pending text record line
        if(textrecodeline.length() > 0) {
              //  string endaddr = locttr;
                int iendaddr = pass1Assembler->getprogramlength();// convert hex to intrger
               // std::stringstream ss;
                //ss << std::hex <<endaddr;
                //ss >>iendaddr;

                int  itxtstartaddr = 0; 
                std::stringstream strss;
                strss << std::hex << txtstartaddr;
                strss >>itxtstartaddr;


                int length = iendaddr -itxtstartaddr;
                stringstream iss;
                iss  << hex << setw(2) <<setfill('0') <<length; // convert hex to integer
                string  strlen =  iss.str();
                std::transform(strlen.begin(), strlen.end(), strlen.begin(),(int (*)(int))std::toupper);// convert to upper case

                cout<<endl<<"T^"<<setw(6)<<txtstartaddr<<"^"<<strlen<<textrecodeline;
                 outfobj<<endl<<"T^"<<setw(6)<<txtstartaddr<<"^"<<strlen<<textrecodeline;
                 tocontinue();
                }


    cout<<modRecords;
    outfobj<<modRecords;
    cout<<endl<<"E^"<<"000000";
    outfobj<<endl<<"E^"<<"000000";
    inflst.close();
    }

/********************************************************************
*** FUNCTION  modificationRecord                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to add modification 
                 record
                 It processes the line to determine if a modification 
                 record needs to be added                         ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass2Assembler :: modificationRecord(vector<string> *tokens, string opcode, string operand,string *modRecords,string locttr,string progName,vector<string> *exdtokens){
    size_t found;
    bool isExtRef = false;
    bool format4 = false;
    if(opcode[0] == '+')
        {
        format4 = true;
       
        }
  
                int ilocttr = 0;// convert hex to int 
                std::stringstream ss2;
                ss2 << std::hex <<locttr;
                ss2 >>ilocttr;
                ilocttr = ilocttr +1;

                 stringstream iss1;
                iss1  << hex << setw(6) <<setfill('0') <<ilocttr; // convert hex to integer
                string  mlocctr=  iss1.str();
                std::transform(mlocctr.begin(), mlocctr.end(), mlocctr.begin(),(int (*)(int))std::toupper);// convert to upper case


    for(int i = 0; i< tokens->size(); i++)
        {
        found=operand.find((*tokens)[i]);
        if (found!=string::npos)
            {
            isExtRef = true;
            string modSign = "+";
            string halflen = "05";
            string mcounter = mlocctr;
            int pos = int(found);
            if(pos > 0)
                {
                char c = operand[pos-1];
                if(c == '-'){
                modSign = "-";
                    }
                }
            if(opcode =="WORD")
                {
                halflen = "06";
                mcounter = "0"+ locttr;
                }
             string mrecord = "\nM^" +  mcounter + "^" + halflen + "^" + modSign + (*tokens)[i];
             (*modRecords) = (*modRecords) + mrecord;
           }//if found
        }
   if(opcode == "WORD")
 {
 if(!isNumber2(operand))
     {
      calmRecord(operand, exdtokens,progName,locttr, modRecords);
     }
       }
    if(format4 && !isExtRef ) {
         string modSign = "+";
            string halflen = "05";
            string mcounter = mlocctr;
            string mrecord = "\nM^" +  mcounter + "^" + halflen + "^" + modSign + progName;
            (*modRecords) = (*modRecords )+ mrecord;
        }
    }
string paddZeros(string operand){
    string objectcode = operand;
    int length = operand.length();
    for(int i = length; i<6; i++){
        objectcode = "0"+ objectcode;
        }
    return objectcode;
    }
/********************************************************************
*** FUNCTION  calmRecord                                          ***
*********************************************************************
*** DESCRIPTION :The function is used to calculate m record    
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void  calmRecord(string operand,vector<string> *exdtokens,string progName,string locttr,string *modRecords)
    {
     size_t found;
     int count = 0;
     string modSign = "+";
     string halflen = "06";
    string mcounter = "0" +locttr;
        int pos = 0;
     for(int i = 0; i< exdtokens->size(); i++)
        {
        found=operand.find((*exdtokens)[i]);
        if (found!=string::npos)
            {
             pos = int(found);
            count++;
            }
        }
    if(count>0)
        {
        if(pos > 0)
                {
                char c = operand[pos-1];
                if(c == '-'){
                modSign = "-";
                    }
                }
         if(!(modSign == "-" && count%2 ==0)){
         string mrecord = "\nM^" +  mcounter + "^" + halflen + "^" + modSign + progName;
          (*modRecords) = (*modRecords) +mrecord ; 
             }
        }
    

    }
//
/********************************************************************
*** FUNCTION  assembleLittralObjectCode                           ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the Litteral 
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

string assembleLittralObjectCode(int format4Flag,int operandaddress,OpcodeValue* data, literals *searchliteral ,string locttr,int baseVal){ 

    int eFlag = 0;
    int bFlag = 0;
    int pFlag = 0;
    int indirectFlag = 0;
    int immediateFlag = 0;
    int  indexFlag = 0;
    int ilocttr = 0;
    std::stringstream stream;// convert location counter from hex to decimal
    stream << locttr;
    stream >> std::hex >> ilocttr;


    string opcode =  data->getopcode();
    int format = data->getformat();
    int displacement = 0;
    string sdisplacement = "";

    string firsthexbit =  opcode.substr(0,1); //first Hex Bit
    char opcode2 = opcode[1];
    string binary = convertToFirst2BitBinary(opcode2);
    if(format4Flag == 1){

        displacement =operandaddress;
        bFlag = 0;
        pFlag =0;
        indirectFlag = 1;
        immediateFlag = 1;
        eFlag = 1;
        stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<displacement;
        sdisplacement = ss.str();
        }//end format 4
    else
        {
        ilocttr = ilocttr + format;
        indirectFlag = 1;
        immediateFlag = 1;
        displacement = operandaddress - ilocttr;

        if(displacement >= 2048) { // value more than 7FF
            bFlag = 1;
            pFlag =0;
            displacement = operandaddress - baseVal; 
            }
        else {
            bFlag = 0;
            pFlag =1;
            }

        if(displacement < 0)
            {
            displacement = calc2scomplement(displacement);
            stringstream ss;
            ss  << hex << setw(3) <<setfill('F')<<displacement;
            sdisplacement = ss.str();

            }
        else {
            stringstream ss;
            ss  << hex << setw(3) <<setfill('0')<<displacement;
            sdisplacement = ss.str();
            }



        }// end format3
    string secondHexBit = convertFirst4ToHex(binary ,indirectFlag,immediateFlag);

    string thirdHexBit = convertToThirdHexBit(indexFlag,bFlag , pFlag, eFlag);

    string objectcode = firsthexbit +secondHexBit+thirdHexBit+sdisplacement;
    //cout<<"objectcode"<<objectcode<<endl;
    return objectcode;
    }

/********************************************************************
*** FUNCTION  assembleformat2Objectcode                           ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the object code for 
                 format 2 instruction 
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
string Pass2Assembler :: assembleformat2Objectcode(OpcodeValue* data, string operand)
    {
    string objcode = "";
    string opcode =  data->getopcode();
    if(operand.find(",") != string::npos)
        {
        string reg1 = "";
        string reg2 = "";
        int value1 = 0;
        int value2 =0;
        int length = operand.length(); //  
        int i = operand.find(",");    // Find the loction of the , sign
        reg1 = operand.substr(0,i);   // Extract the first operand
        reg2 = operand.substr(i+1,length-(i+1));  // Extract the second operand
        SymbolAttribute * symbolAttribute = pass1Assembler->getsymboltable()->searchSymbol(reg1);
        if(symbolAttribute != NULL)
            {
            value1 =  symbolAttribute->getValue();
            }

        symbolAttribute = pass1Assembler->getsymboltable()->searchSymbol(reg2);
        if(symbolAttribute != NULL)
            {
            value2 =  symbolAttribute->getValue();
            }

        objcode = opcode + convertIntToString(value1) + convertIntToString(value2);
        }

    else
        {
        SymbolAttribute * symbolAttribute = pass1Assembler->getsymboltable()->searchSymbol(operand);
        int  value = 0;
        if(symbolAttribute != NULL)
            {
            value =  symbolAttribute->getValue();
            }
        objcode = opcode + convertIntToString(value) + "0"; 
        }

    return objcode;
    }
/********************************************************************
*** FUNCTION  convertIntToString                                  ***
*********************************************************************
*** DESCRIPTION : *** Used to trim the string                     ***
*** INPUT ARGS  :int num The number to be converted to string     ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The string of the number                        ***
********************************************************************/
string convertIntToString(int num)// convert int to string
    {
    stringstream ss;
    ss << num;
    return ss.str();
    }
//assemble the object code
/********************************************************************
*** FUNCTION  assembleExpressionObjectCode                        ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the object code for 
                 expression  
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
string assembleExpressionObjectCode(int format4Flag,int operandaddress,Expression * exp,OpcodeValue* data, string locttr,int baseVal){ 

    int eFlag = 0;
    int bFlag = 0;
    int pFlag = 0;
    string opcode =  data->getopcode();
    int format = data->getformat();
    string mnemonic = data->getmnemonic();
    int ilocttr = 0;
    std::stringstream stream;// convert location counter from hex to decimal
    stream << locttr;
    stream >> std::hex >> ilocttr;

    int immediateFlag = exp->immediateFlag;
    int indexFlag =  exp->indexFlag;
    int indirectFlag =  exp->indirectFlag;
    int relocatableflag = exp->relocatableFlag;
    string expname = exp->expname;
    //FIX 

    if(indirectFlag == 0 && immediateFlag == 0 ){
        indirectFlag = 1;
        immediateFlag = 1;
        }

    int value = exp->value;
    int displacement = 0;
    string sdisplacement = "";


    string firsthexbit =  opcode.substr(0,1); //first Hex Bit
    char opcode2 = opcode[1];
    string binary = convertToFirst2BitBinary(opcode2);

    //check for format 4.
    if(format4Flag == 1){

        displacement = value;
        bFlag = 0;
        pFlag =0;
        //indirectFlag = 1;
        //immediateFlag = 1;
        eFlag = 1;
        stringstream ss;
        ss  << hex << setw(5) <<setfill('0')<<displacement;
        sdisplacement = ss.str();
        }
    else{

        if(indirectFlag == 0 && immediateFlag == 1 && isNumber2(expname)) {
            displacement = value;
            bFlag = 0;
            pFlag =0;
            stringstream ss;
            ss  << hex << setw(3) <<setfill('0')<<displacement;
            sdisplacement = ss.str();
            }
        else {
            ilocttr = ilocttr + format;
            displacement = value - ilocttr;

            if(displacement >= 2048) { // value more than 7FF
                bFlag = 1;
                pFlag =0;
                displacement = value - baseVal; 
                }
            else {
                bFlag = 0;
                pFlag =1;
                }

            if(displacement < 0)
                {
                displacement = calc2scomplement(displacement);
                stringstream ss;
                ss  << hex << setw(3) <<setfill('F')<<displacement;
                sdisplacement = ss.str();
                }
            else {
                stringstream ss;
                ss  << hex << setw(3) <<setfill('0')<<displacement;
                sdisplacement = ss.str();
                }


            }


        }// else end for formate 3



    string secondHexBit = convertFirst4ToHex(binary ,indirectFlag,immediateFlag);

    string thirdHexBit = convertToThirdHexBit(indexFlag,bFlag , pFlag, eFlag);

    string objectcode = firsthexbit +secondHexBit+thirdHexBit+sdisplacement;
    //   cout<<"objectcode"<<objectcode<<endl;

    return objectcode;
    }

/********************************************************************
*** FUNCTION  assembleNoOperandObjectCode                         ***
*********************************************************************
*** DESCRIPTION :The function is used to assemble the object code for 
                 no opernad instructions   
*** INPUT ARGS  :OpcodeValue* data : The opcode date              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

string assembleNoOperandObjectCode(OpcodeValue* data){ 

    int bFlag = 0;
    int pFlag = 0;
    string opcode =  data->getopcode();

    int immediateFlag = 1;
    int indirectFlag = 1;

    string firsthexbit =  opcode.substr(0,1); //first Hex Bit
    char opcode2 = opcode[1];
    string binary = convertToFirst2BitBinary(opcode2);

    string secondHexBit = convertFirst4ToHex(binary ,indirectFlag,immediateFlag);

    string thirdHexBit = "0";
    string sdisplacement = "000";

    string objectcode = firsthexbit +secondHexBit+thirdHexBit+sdisplacement;
    //   cout<<"objectcode"<<objectcode<<endl;

    return objectcode;
    }
/********************************************************************
*** FUNCTION  calc2scomplement                                    ***
*********************************************************************
*** DESCRIPTION : *** Used to get the 2s complement of number     ***
*** INPUT ARGS  :int num The number                               ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The 2s complement of a no.                      ***
********************************************************************/
int  calc2scomplement(int value) {
    long dec,rem,i=1,sum=0;
    dec = - value;

    do
        {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
        }while(dec>0);
        //cout<<"The binary of the given number is:"<<sum<<endl;

        stringstream ss;//create a stringstream
        ss << sum;//add number to the stream
        string bin =  ss.str();
        //cout <<bin<<endl;
        string  val = bin;
        for(int i=0;i<bin.length();i++){
            if(bin[i] == '0') val = val.replace(i,1,1,'1');
            if(bin[i] == '1') val = val.replace(i,1,1,'0');

            }
        //cout <<"1s complement " <<val<<endl;

        string val2 = val;
        int length = val2.length();
        int carry = 1;
        for(int i = length-1; i>=0;i--){
            char c = val[i];
            if(c == '0' && carry ==0) {
                val2 = val2.replace(i,1,1,'0');
                carry = 0;
                }
            else if(c == '0' && carry ==1) {
                val2 = val2.replace(i,1,1,'1');
                carry = 0;
                }
            else if(c == '1' && carry ==0) {
                val2 = val2.replace(i,1,1,'1');
                carry = 0;
                }
            else if(c == '1' && carry ==1) {
                val2 = val2.replace(i,1,1,'0');
                carry = 1;
                }
            if(carry == 0) break;

            }
        return binToDec(val2);

    }

/********************************************************************
*** FUNCTION  convertToThirdHexBit                                   
*********************************************************************
*** DESCRIPTION : Calculates the Third bit of the object code     ***
                                                                  ***
*** INPUT ARGS  : string binary 
                  int indirectFlag 
                  int immediateFlag                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
string convertToThirdHexBit(int index,int bFlag ,int pFlag,int eFlag)
    {
    string indexs = "0";
    string bFlags = "0";
    string pFlags = "0";
    string eFlags = "0";

    if(index == 1) indexs = "1";
    if(bFlag == 1) bFlags = "1";
    if(pFlag == 1) pFlags = "1";
    if(eFlag == 1) eFlags = "1";

    string binary = indexs + bFlags + pFlags + eFlags ;

    // int value = atoi(binary.c_str());

    int value = binToDec(binary);

    stringstream ss;
    ss  << hex << value;
    string sHexVal= ss.str();

    return sHexVal;
    }

/********************************************************************
*** FUNCTION  convertFirst4ToHex                                   
*********************************************************************
*** DESCRIPTION : Calculates the First 4 Bit to Hex               ***
                                                                  ***
*** INPUT ARGS  : string binary 
                  int indirectFlag 
                  int immediateFlag                               ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/

string convertFirst4ToHex(string binary , int indirectFlag, int immediateFlag){
    string indirect ="0";
    string immediate = "0";
    if(indirectFlag == 1) indirect = "1";
    if(immediateFlag == 1) immediate = "1";

    binary = binary + indirect + immediate ;
    int value = binToDec(binary);
    // int value = atoi(binary.c_str());

    stringstream ss;
    ss  << hex << value;
    string sHexVal= ss.str();

    return sHexVal;
    }

/********************************************************************
*** FUNCTION  convertToFirst2BitBinary                                   
*********************************************************************
*** DESCRIPTION : Calculates the First2 Bit binary                ***
                  comment line                                    ***
*** INPUT ARGS  : char opcode The data to be converted             ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
string convertToFirst2BitBinary(char opcode){
    string binary = "";
    switch(opcode) {
    case '0' : binary = "00";break;
    case '4' : binary = "01";break;
    case '8' : binary = "10";break;
    case 'C' : binary = "11";break;

        }
    return binary;
    }

/********************************************************************
*** FUNCTION  binToDec                                   
*********************************************************************
*** DESCRIPTION : Converts bin to Dec                             ***
                  comment line                                    ***
*** INPUT ARGS  : string binaryData The data to be converted      ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
int binToDec(string binaryData)
    {
    int number = 0;
    int length = binaryData.length();

    for(int i=0; i<length; i++)
        {
        char bit = binaryData[length-1-i];
        if(bit == '0'){

            }
        else {
            long int value = pow(2.0, i);
            number = number + value;
            }
        }

    return number;
    // ltoa(number, HexData, 16);
    }
/********************************************************************
*** FUNCTION  processintline                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to process intermediate line 
                 It extracts the opcode,operand from
                 the line.

*** INPUT ARGS  :string progline : The line to be processed    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass2Assembler :: processintline(string progline,string &linenum ,string &locttr, string &label,string &opcode,string &operand)
    {
    if(progline.length() == 0) return;
    linenum = progline.substr (0,8);
    trim(linenum);
    locttr = progline.substr (8,8);
    trim(locttr);
    label =  progline.substr (16,12);
    trim(label);
    opcode = progline.substr (28,12);
    trim(opcode);
    operand =  progline.substr (40,24);
    trim(operand);


    }
/*** FUNCTION  processlstline                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to process list line 
                 It extracts the opcode,operand,object code from
                 the line.

*** INPUT ARGS  :string progline : The line to be processed    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void Pass2Assembler :: processlstline(string progline,string &linenum ,string &locttr, string &label,string &opcode,string &operand,string &objectcode)
    {
    if(progline.length() == 0) return;
    linenum = progline.substr (0,8);
    trim(linenum);
    locttr = progline.substr (8,8);
    trim(locttr);
    label =  progline.substr (16,12);
    trim(label);
    opcode = progline.substr (28,12);
    trim(opcode);
    operand =  progline.substr (40,20);
    trim(operand);
    objectcode=  progline.substr (60,8);
    trim(objectcode);


    }
bool Pass2Assembler :: searchoptab(string opcode, OpcodeValue** data){
    bool found = false;
    OpcodeTable* opcodetable = pass1Assembler->getopcodetable();
    (*data)  =  opcodetable->searchOpcodeValue(opcode);


    if((*data)!= NULL)
        {
        found = true;
        }
    else if(opcode[0] == '+') { // processing format 4
        string temp = opcode.substr(1);

        (*data)  =  opcodetable->searchOpcodeValue(temp);
        if((*data) != NULL) {
            found =  true;
            }
        }
    return found;
    }
/********************************************************************
*** FUNCTION  isNotCommentLine2                                   
*********************************************************************
*** DESCRIPTION : Checks whether the string is a literal          ***
                                                                  ***
*** INPUT ARGS  : string line                                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is a literal         ***
                  line or returns false                           ***
********************************************************************/
bool isLiteral(string exp){

    if(exp[0] == '=')
        {
        return true;
        }
    else
        {
        return false;
        }


    }
/********************************************************************
*** FUNCTION  getLiteral                                          ***
*********************************************************************
*** DESCRIPTION :The function is used to get the literal from the 
                 literal table  
                 
*** INPUT ARGS  :string operand : The operand to get the value    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
bool Pass2Assembler :: getLiteral(string operand, literals &searchliteral){

    bool found = false;

    Linklist<literals,string> *literallist = pass1Assembler-> getliterallist();
    bool found1 =  literallist->retrievedata(operand, searchliteral);//check to see if the literal is already present in the list
    if(found1){
        found = true;
        }
    else
        {
        string tmpexp = operand.substr(1); //remove =
        char firstChar = tmpexp[0];

        string tmpchar;
        if(firstChar == 'X') tmpchar = "x";
        else  if(firstChar == 'x') tmpchar = "X";
        else  if(firstChar == 'C') tmpchar = "c";
        else  if(firstChar == 'c') tmpchar = "C";

        tmpexp = tmpexp.substr(1);
        tmpexp = "="+tmpchar +tmpexp;

        bool found2 =  literallist->retrievedata(tmpexp, searchliteral);//check to see if the literal is already present in the list
        found = found2;
        }//else found
    return found;
    }

/********************************************************************
*** FUNCTION  isNotCommentLine2                                   
*********************************************************************
*** DESCRIPTION : Checks whether the program line is a            ***
                  comment line                                    ***
*** INPUT ARGS  : string line                                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : bool Returns true if a line is comment          ***
                  line or returns false                           ***
********************************************************************/
bool isNotCommentLine2(string line){
    if(line.length() == 0) return false;
    char c = line[0];
    if(c == ';') return false;
    else return true;

    }
/********************************************************************
*** FUNCTION  trim()                                              ***
*********************************************************************
*** DESCRIPTION : *** Used to trim the string                     ***
*** INPUT ARGS  :string &str The string to be terminated          ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void trim( string &str){

    if(containsOnlySpaces(str)) {
        str = "";
        return;
        }
    size_t found = str.find_first_not_of(" ");

    if(found !=string::npos)
        str = str.substr(found,(str.length()-found));


    found=str.find_last_not_of(" \n\r");
    if (found!=string::npos)
        str.erase(found+1);
    }
/********************************************************************
*** FUNCTION  containsOnlySpaces                                  ***
*********************************************************************
*** DESCRIPTION : *** Used to determine if the string only contains
                  spaces                                          ***
*** INPUT ARGS  :int num The number                               ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : True if the string only contains spaces         ***
********************************************************************/
bool containsOnlySpaces(string str){
    bool onlySpaces = true;
    for(int i = 0; i<str.length() ; i++){
        if(str[i] != ' ') {
            onlySpaces = false;
            break;
            }
        }
    return onlySpaces;

    }

/********************************************************************
*** FUNCTION isNumber2                                             
*********************************************************************
*** DESCRIPTION :  Validates if the string is a number            ***
*** INPUT ARGS  :string value  The expr to be tested              ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : - Returns true if the expr is number or false 
                    otherwise                                     ***
********************************************************************/

bool isNumber2(string value)
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
