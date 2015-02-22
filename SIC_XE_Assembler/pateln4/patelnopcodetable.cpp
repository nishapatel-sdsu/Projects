/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                            ***
*** DUE DATE   : 10/03/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module is used to create a Opcode Table using 
binary search tree.
********************************************************************/
#include<iostream>
#include<iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
#include <stdlib.h>
#include <stdio.h>
#include"patelnerr.h"
#include "patelnopcodetable.h"
#include<algorithm>
using namespace std;

/********************************************************************************
*** FUNCTION readFile                                                         ***
*********************************************************************************
*** DESCRIPTION : This function is used to read the file used to              ***
create the symbol table.                                                      ***                 
*** INPUT ARGS  : string filename : The name of the file to be read           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void OpcodeTable ::readFile(string filename)
    {
    ifstream inf;
    inf.open(filename.c_str(),ios::in);
    if (!inf) {
        cout << "can't open file";
        }
    else
        {
        string line = "";
        while (!inf.eof()) {
            getline(inf, line);
            size_t found = line.find_first_not_of(" ");

            if(found !=string::npos)
                line = line.substr(found,(line.length()-found));


            found=line.find_last_not_of(" \n\r");
            if (found!=string::npos)
                line.erase(found+1);


            lines.push_back(line);
            }
        }

    }

/********************************************************************************
*** FUNCTION insertData                                                       ***
*********************************************************************************
*** DESCRIPTION : This function is the wrapper functon for inserting          ***
the symbols and its arguments in symbol table.              ***                 
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void OpcodeTable::insertData()
    {
    vector<string>:: iterator itr;
    itr= lines.begin();
    while(itr != lines.end())
        {
        string line = *itr;
        itr++;
        validateAndInsert(line);
        }
    } 

/********************************************************************************
*** FUNCTION validateAndInsert                                                ***
*********************************************************************************
*** DESCRIPTION : This function first validates the symbol and its arguments. ***
Only valid symbols along with its argumnets are inserted in ***
in the symbol table.                                        ***                 
*** INPUT ARGS  : string line : The symbol and its attributes                 ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/

void OpcodeTable ::validateAndInsert(string line)
    {

    string buffer = "";
    stringstream ss(line);
    vector<string> tokens;

    while (ss>>buffer)
        {
        tokens.push_back(buffer);
        }
    if(tokens.size() != 3)
        {
        cout<<"ERROR : invalid number of arguments in the input file : " + line <<endl;
        tocontinue();
        return;
        }
    string mnemonic = tokens[0];
    string sformat  = tokens[1];
    string opcode = tokens[2];

    int format = atoi(sformat.c_str());
   OpcodeValue data ( mnemonic,format,opcode);
   opbsttree.insert(mnemonic ,data);
 
  /*  bool validrflage = false;
    bool validvalue = false;
    bool validsymbol = false;
*/
    /*validrflage = validateRflag(rflag,symbol);

    if(validrflage){
        validvalue = validateValue(value,symbol);
        if(validvalue){
            validsymbol = validateSymbol(symbol);
            }
        }
*/
     /*if(validrflage && validsymbol && validvalue ){
        int i_rflag = calculaterflag(rflag);
        int iflag = 0;
        int mflag = 0;
        int i_value = atoi(value.c_str());
        int length = symbol.size();
        if(length>8)
            symbol = symbol.substr(0,8);
        if(bsttree.contains(symbol))
            {
            SymbolAttribute* sbAttr = bsttree.search(symbol);
            sbAttr->setMflag(1);
            cout<<"ERROR : symbol previously defined : " + symbol  <<endl;
            tocontinue();
            }
        else
            {
            iflag = 1;
            SymbolAttribute data(i_rflag, iflag, mflag, i_value, symbol);
            bsttree.insert(symbol ,data);
            }
        }*/
    }

        /********************************************************************************
        *** FUNCTION viewOpcodeTable                                                 ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It perrforms inodrder traversal  ***
        of the opcode table.                                       ***                 
        *** INPUT ARGS  : -                                                           ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/
void OpcodeTable ::viewOpcodeTable()
    {
    cout<<setw(10)<<" mnemonic"<<setw(10)<<"format"<<setw(10)<<"opcode"<<endl<<endl;
    opbsttree.inorder();
    tocontinue();
    }
/********************************************************************************
*** FUNCTION searchOpcodeValue                                                ***
*********************************************************************************
*** DESCRIPTION : This function is used to calculate the rflag value          ***                 

*** INPUT ARGS  : -  string mnemonic : The mnemonic to search                 ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      :    OpcodeValue*                                            ***
                                                               
*********************************************************************************/

  OpcodeValue* OpcodeTable ::searchOpcodeValue(string symbol)
    {
      OpcodeValue* data ;

    data = opbsttree.search(symbol);

    return data;
    }
  
        /********************************************************************************
        *** FUNCTION createOpcodeTable                                            ***
        *********************************************************************************
        *** DESCRIPTION : This is a wrapper function.It is read the opcode file and  ***
        then insert the data in the opcode table.                  ***                 
        *** INPUT ARGS  : string filename: The name of the file to be read            ***
        *** OUTPUT ARGS : -                                                           ***
        *** IN/OUT ARGS : -                                                           ***
        *** RETURN      : void                                                        ***
        *********************************************************************************/
void OpcodeTable ::createOpcodeTable(string filename)
    {
    readFile(filename);
    insertData();
    }


/********************************************************************************
*** FUNCTION readsearchfile                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to read the search file.The search    ***         
file contains the symbol which need to be search in the symbole table.        ***                 
*** INPUT ARGS  : string filename : The name of the file to be read           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/
//void OpcodeTable::readsearchfile(string filename)
//    {
//    ifstream inf;
//    inf.open(filename.c_str(), ios::in);
//    if (!inf) {
//        cout << "can't open file";
//        }
//    else
//        {
//        string symbol = "";
//        while (!inf.eof()) {
//            getline(inf, symbol);
//            size_t found = symbol.find_first_not_of(" ");
//
//            if(found !=string::npos)
//                symbol = symbol.substr(found,(symbol.length()-found));
//
//            found=symbol.find_last_not_of(" \n\r");
//            if (found!=string::npos)
//                symbol.erase(found+1);
//            searchsymbols.push_back(symbol);
//            }
//        searchSymbol();
//        }
//    }

/********************************************************************************
*** FUNCTION searchSymbol                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to search the symbol in the symbol    ***                 
table.it print the symbol attribute of the symbol          ***
*** INPUT ARGS  : -                                                           ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : void                                                        ***
*********************************************************************************/
//void OpcodeTable ::searchOpcodeValue()
//    {
//    vector<string>:: iterator itr;
//    itr= searchsymbols.begin();
//    cout<<setw(10)<<"symbol"<<setw(10)<<"Rflag"<<setw(10)<<"Value"<<setw(10)<<"Mflag"<<setw(10)<<"Iflag"<<endl<<endl;
//    SymbolAttribute* data ;
//    tocontinue();
//    while(itr != searchsymbols.end())
//        {
//        string symbol = *itr;
//        if(validateSymbol(symbol))
//            {
//            int length = symbol.size();
//            if(length >8){
//                symbol = symbol.substr(0,8);
//                }
//            data = bsttree.search(symbol);
//
//            if(data!=NULL){
//                cout<<setw(10)<<symbol<<setw(10)<<data->getRflag()<<setw(10)<<data->getValue()
//                    <<setw(10)<<data->getMflag()<<setw(10)<<data->getIflag()<<endl<<endl;
//                tocontinue();
//                }
//            else 
//                cout<<"  ERROR - " +symbol +" not found in symbol table"<<endl<<endl;
//            tocontinue();
//            }
//        else{
//            cout<<"  ERROR - " +symbol +" is not valid "<<endl<<endl;
//            tocontinue();
//            }
//        itr++;
//        }
//
//    } 

/********************************************************************************
*** FUNCTION calculaterflag                                                   ***
*********************************************************************************
*** DESCRIPTION : This function is used to calculate the rflag value          ***                 

*** INPUT ARGS  : -  string rflag : The rflag as a string                     ***
*** OUTPUT ARGS : -                                                           ***
*** IN/OUT ARGS : -                                                           ***
*** RETURN      : Return 1 if rflag is true/1 or returns 0 if rflag is        ***
                  false/0                                                
*********************************************************************************/
//
//int  OpcodeTable :: calculaterflag(string rflag)
//    {
//
//    transform(rflag.begin(), rflag.end(),rflag.begin(), ::tolower);
//
//    if(rflag.compare("1")==0){
//        return 1;
//
//        }
//    else if(rflag.compare("0")==0){
//        return 0;
//
//        }
//    else if(rflag.compare("true")==0){
//        return 1;
//
//        }
//    else if(rflag.compare("false")==0){
//        return 0;
//
//        }
//    else
//        return 0;
//    }

