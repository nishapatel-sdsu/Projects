#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <sstream>
/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 5                                            ***
*** DUE DATE   : 12/07/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This class implements the Pass1 and Pass2 of the
                  linker and loader module.
                  Pass1 is used to create a 
                  symbol table. Pass two is used to relocate and load 
                  the data in memory.
********************************************************************/
#include<vector>
#include <stdlib.h>
#include <cctype>
#include "pass1loader.h"
#include <algorithm>
#include <math.h>
#include "patelnsymbolattribute.h"

using namespace std;
/********************************************************************
*** FUNCTION  calc2scomplement                                    ***
*********************************************************************
*** DESCRIPTION : *** Used to get the 2s complement of number     ***
*** INPUT ARGS  :string num The number to be converted in hex     ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The 2s complement of a no.                      ***
********************************************************************/
int  calc2scomplement(string hexnum);

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
*** FUNCTION  convertIntToHex                                     ***
*********************************************************************
*** DESCRIPTION : *** Used to convert int to Hex                  ***
*** INPUT ARGS  :int num The number to be converted to hex        ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string convertIntToHex(int number);

/********************************************************************
*** FUNCTION  paddZeros                                           ***
*********************************************************************
*** DESCRIPTION : *** Used to padd zeros at start                 ***
*** INPUT ARGS  :string the number after padding zeros            ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string paddZeros(string operand);


/********************************************************************
*** FUNCTION  paddZeros6                                           ***
*********************************************************************
*** DESCRIPTION : *** Used to padd zeros at start                 ***
*** INPUT ARGS  :string the number after padding zeros            ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string paddZeros6(string operand);
/********************************************************************
*** FUNCTION  FourBitBinary                                   
*********************************************************************
*** DESCRIPTION : Converts a char to Four bit binary              ***
comment line                                    ***
*** INPUT ARGS  : c character to be converted                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : string  Returns four bit binary for the hex bit ***
********************************************************************/
string FourBitBinary(char c);
int linesPrinted = 0;

void tocontinue(){
    linesPrinted++;
    if(linesPrinted==19){
        char m;
        cout<<"\nDo you want to continue?y/n ";
        linesPrinted=0;
        cin>>m;
        if(m=='n')
            exit(1);
        }

    }

/********************************************************************
*** FUNCTION  Pass1loader                                         ***
*********************************************************************
*** DESCRIPTION : *** The default constructor for the class       ***
*** INPUT ARGS  :                                                 ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      :                                                 ***
********************************************************************/
Pass1loader :: Pass1loader(){
    loadaddr = "03590";
    csaddr = loadaddr;
    maxLoc = 0;
    totalproglength = 0;
    intialMemoryLoc();
    execaddr = loadaddr;
    }

/********************************************************************
*** FUNCTION  readFile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read thefile
                 It processes the file to generate the symbol table  
                                                                  ***
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass1loader::readFile(string filename)
    {
    ifstream inf;
    inf.open(filename.c_str(),ios::in);
    if (!inf) {
        cout << "can't open file";
        return;
        }

    string line = "";
    getline(inf, line);

    int icsaddr=strtoul(csaddr.c_str(),0,16);

    string proglength = ""; 

    processFirstline(line,proglength);

    int iproglength = strtoul(proglength.c_str(),0,16);
    totalproglength = totalproglength + iproglength;

    getline(inf, line);
    char type = line[0];
    while ( type != 'E') {
        if(type == 'D')
            {
            int length = line.length()-1;
            int num = length/14;
            for(int i = 0; i < num; i ++){
                string name = line.substr(1 +14 *i,8);
                size_t found=name.find_last_not_of(" \n\r");
                if (found!=string::npos)
                    name.erase(found+1);

                string value = line.substr(9+14 *i,6);
                int iaddr=strtoul(value.c_str(),0,16);
                int iLdaddr = iaddr + icsaddr;
                string hexLaddr =    convertIntToHex(iLdaddr);
                std::transform(hexLaddr.begin(), hexLaddr.end(), hexLaddr.begin(),(int (*)(int))std::toupper);

                hexLaddr = paddZeros(hexLaddr);
                SymbolAttribute dataA(name,name,"",value,"",hexLaddr, ""); //to do 
                literallist.append(dataA);


                }   
            }
        getline(inf, line);
        type = line[0];
        }


    int inextcsaddr = icsaddr + iproglength;
    csaddr =    convertIntToHex(inextcsaddr);
    csaddr = paddZeros(csaddr);
    std::transform(csaddr.begin(), csaddr.end(), csaddr.begin(),(int (*)(int))std::toupper);

    inf.close();
    }

/********************************************************************
*** FUNCTION  showSymbolTable                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to show symbol table   
                                                                  ***
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS :                                                 ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass1loader :: showSymbolTable(){
    //print symbol table
    cout <<endl ;

    literallist.display();

    }
/********************************************************************
*** FUNCTION  processFirstline                                    ***
*********************************************************************
*** DESCRIPTION :The function is used to process the first line 
                 to extract the symbol header and length   
                                                                  ***
*** INPUT ARGS  : string line : The header line to be processed   *** 
*** OUTPUT ARGS : -string length : The length of the section      ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void  Pass1loader:: processFirstline(string line,string &length)
    {

    string hlabel = line.substr(1,8);
    length = line.substr(15,6);


    size_t found=hlabel.find_last_not_of(" \n\r");
    if (found!=string::npos)
        hlabel.erase(found+1);

    SymbolAttribute dataA(hlabel,"",hlabel,"",csaddr,"", length); //to do 
    literallist.append(dataA);



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
string convertIntToHex(int number){
    string hexString;
    stringstream ss;
    ss << hex << number; //int to hex string
    hexString = ss.str(); //assgn string to temp string
    return hexString;
    }

/********************************************************************
*** FUNCTION  paddZeros                                           ***
*********************************************************************
*** DESCRIPTION : *** Used to padd zeros at start                 ***
*** INPUT ARGS  :string the number after padding zeros            ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string paddZeros(string operand){
    string objectcode = operand;
    int length = operand.length();
    for(int i = length; i<5; i++){
        objectcode = "0"+ objectcode;
        }
    return objectcode;
    }

/********************************************************************
*** FUNCTION  paddZeros6                                           ***
*********************************************************************
*** DESCRIPTION : *** Used to padd zeros at start                 ***
*** INPUT ARGS  :string the number after padding zeros            ***
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : The hex string of the number                    ***
********************************************************************/
string paddZeros6(string operand){
    string objectcode = operand;
    int length = operand.length();
    for(int i = length; i<6; i++){
        objectcode = "0"+ objectcode;
        }
    return objectcode;
    }

/********************************************************************
*** FUNCTION  initializeCSAddr                                    ***
*********************************************************************
*** DESCRIPTION :The function is used to initialize the control 
                 section address to progaddr 
                 
*** INPUT ARGS  :   string filename : file to be processed        *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void Pass1loader :: initializeCSAddr() {

    csaddr = loadaddr;

    }


/********************************************************************
*** FUNCTION  pass2Loader                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the file for pass2 
                 relocation and loading of program in memory
                 
*** INPUT ARGS  :   string filename : file to be processed        *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void  Pass1loader:: pass2Loader(string filename){

    ifstream inf;
    inf.open(filename.c_str(),ios::in);
    if (!inf) {
        cout << "can't open file";
        return;
        }

    string line = "";
    getline(inf, line);

    string hlabel = line.substr(1,8);
    string  proglength = line.substr(15,6);
    int icsaddr=strtoul(csaddr.c_str(),0,16);




    size_t found=hlabel.find_last_not_of(" \n\r");
    if (found!=string::npos)
        hlabel.erase(found+1);


    getline(inf, line);
    char type = line[0];
    while ( type != 'E') {
        if(type == 'T')
            {
            string strAddr = line.substr(1,6);
            int tAddress =strtoul(strAddr.c_str(),0,16);
            int tabsAddr = icsaddr + tAddress;
            string stabsAddr = convertIntToHex(tabsAddr);
            string slength = line.substr(7,2);
            int ilength =strtoul(slength.c_str(),0,16);
            for(int i = 0; i<ilength; i++)
                {
                string  rvalue = line.substr(9+2*i,2);
                int irAddr =  tabsAddr + i;
                string srAddr = convertIntToHex(irAddr);
                int iloadaddr =strtoul(loadaddr.c_str(),0,16);
                int iloc = irAddr -iloadaddr;
                memory[iloc] = rvalue;
                maxLoc = iloc;

                }// for end
            }// if end
        else if (type == 'M')
            {
            string schgAddr = line.substr(1,6);
            string schglength = line.substr(7,2);
            string operation = line.substr(9,1);
            string symbol = line.substr(10);
            SymbolAttribute dataA;
            literallist.retrievedata(symbol,dataA);
            string ldaddr = "";
            if(dataA.csect.length() > 0)
                ldaddr = dataA.csaddr;
            else ldaddr = dataA.ldaddr;
            int ildaddr =strtoul(ldaddr.c_str(),0,16);

            int ichgAddr =strtoul(schgAddr.c_str(),0,16);
            int abschgaddr = icsaddr + ichgAddr;
            int iloadaddr =strtoul(loadaddr.c_str(),0,16);
            int memloc = abschgaddr - iloadaddr;
            string value1 =    memory[memloc];
            string value2 =    memory[memloc +1];
            string value3 =    memory[memloc+ 2];


            string targaddress = value1 + value2 + value3;
            int itargaddress =strtoul(targaddress.c_str(),0,16);

            if(value1[0] == 'F') { // it is a negative number
                itargaddress =   calc2scomplement(targaddress);
                }

            int imodifyValue = 0;
            if(operation == "+")
                {
                imodifyValue = itargaddress + ildaddr;
                }
            else
                {
                imodifyValue = itargaddress - ildaddr;
                }
            string smodifyValue = convertIntToHex(imodifyValue);
            smodifyValue = paddZeros6(smodifyValue);
            std::transform(smodifyValue.begin(), smodifyValue.end(), smodifyValue.begin(),(int (*)(int))std::toupper);

            memory[memloc] = smodifyValue.substr(0,2);
            memory[memloc+1] = smodifyValue.substr(2,2);
            memory[memloc+2] = smodifyValue.substr(4,2);


            }
        getline(inf, line);
        type = line[0];
        }// while type end

    string schgAddr = line.substr(1,6);
    if(schgAddr.length() > 0) {
        int iendaddr =strtoul(schgAddr.c_str(),0,16);
        int iexecaddr = icsaddr +  iendaddr;
        execaddr =    convertIntToHex(iexecaddr);
        execaddr = paddZeros6(execaddr);
        std::transform(execaddr.begin(), execaddr.end(), execaddr.begin(),(int (*)(int))std::toupper);

        }

    //    }// while end

    int iproglength =strtoul(proglength.c_str(),0,16);
    int inextcsaddr = icsaddr + iproglength;
    csaddr =    convertIntToHex(inextcsaddr);
    csaddr = paddZeros(csaddr);
    std::transform(csaddr.begin(), csaddr.end(), csaddr.begin(),(int (*)(int))std::toupper);
    inf.close();
    }


void  Pass1loader:: printMemory(){

    cout <<"MEMORY LAYOUT"<<endl;
    cout <<endl<<endl;
    //  cout<<endl <<totalproglength<<endl;

    cout<<"       "<<" 0"<<"  "<<"1"<<"  "<<"2"<<"  "<<"3"<<"  "<<"4"<<"  "<<"5"<<"  "<<"6"<<"  "<<"7"<<"  "<<"8"<<"  "<<"9"<<"  "<<"A"<<"  "<<"B"<<"  "<<"C"<<"  "<<"D"<<"  "<<"E"<<"  "<<"F"<<endl;
    outf<<"       "<<" 0"<<"  "<<"1"<<"  "<<"2"<<"  "<<"3"<<"  "<<"4"<<"  "<<"5"<<"  "<<"6"<<"  "<<"7"<<"  "<<"8"<<"  "<<"9"<<"  "<<"A"<<"  "<<"B"<<"  "<<"C"<<"  "<<"D"<<"  "<<"E"<<"  "<<"F"<<endl;

    cout<<loadaddr<<"  ";
    outf<<loadaddr<<"  ";
    int linecount = 0;
    for(int i = 1; i<= totalproglength; i++)
        {
        cout<<memory[i-1]<<" ";
        //tocontinue();
        outf<<memory[i-1]<<" ";
        if(i > 1 && i% 16 == 0 && i!= totalproglength){
            cout<<endl;
            outf<<endl;
            linecount ++;
            int iloadaddr =strtoul(loadaddr.c_str(),0,16);
            int irowaddress =iloadaddr + 16 *linecount;
            string  srowaddress = convertIntToHex(irowaddress);
            srowaddress = paddZeros(srowaddress);
            std::transform(srowaddress.begin(), srowaddress.end(), srowaddress.begin(),(int (*)(int))std::toupper);

            cout<<srowaddress<<"  ";
            outf<<srowaddress<<"  ";
            }

        }
    cout <<endl <<endl;
    outf <<endl <<endl;
    cout <<"Execution begins at address: " <<execaddr<<endl;
    outf <<"Execution begins at address: " <<execaddr<<endl;


    }
/********************************************************************
*** FUNCTION  intialMemoryLoc                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to initialize memory location 
                 
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void  Pass1loader:: intialMemoryLoc()
    {
    for(int i = 0; i<480; i++)
        {
        memory[i] = "??";
        }

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
int  calc2scomplement(string hexnum) {

    string binarynum = "";
    for(int i = 0; i<hexnum.length() ; i++ ){
        binarynum = binarynum + FourBitBinary(hexnum[i]);
        }
    string bin =  binarynum;
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
    return -binToDec(val2);

    }


/********************************************************************
*** FUNCTION  FourBitBinary                                   
*********************************************************************
*** DESCRIPTION : Converts a char to Four bit binary              ***
comment line                                    ***
*** INPUT ARGS  : c character to be converted                     ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : string  Returns four bit binary for the hex bit ***
********************************************************************/

string FourBitBinary(char c) {

    switch(c) {
    case '0' : return "0000"; break;
    case '1' : return "0001"; break;
    case '2' : return "0010"; break;
    case '3' : return "0011"; break;
    case '4' : return "0100"; break;
    case '5' : return "0101"; break;
    case '6' : return "0110"; break;
    case '7' : return "0111"; break;
    case '8' : return "1000"; break;
    case '9' : return "1001"; break;
    case 'A' : return "1010"; break;
    case 'B' : return "1011"; break;
    case 'C' : return "1100"; break;
    case 'D' : return "1101"; break;
    case 'E' : return "1110"; break;
    case 'F' : return "1111"; break;

        }


    }

/*********************************************************************
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
