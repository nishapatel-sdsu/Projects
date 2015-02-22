/********************************************************************
*** NAME       : NISHA PATEL                                      ***
*** CLASS      : CSC 354                                          ***
*** ASSIGNMENT : Asg 3                                           ***
*** DUE DATE   : 10/31/2012                                       ***
*** INSTRUCTOR : GAMRADT                                          ***
*********************************************************************
*** DESCRIPTION : This module implement the Expression Evaluation.
********************************************************************/
#include<iostream>
#include<iomanip>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include<string.h>
#include "patelnexp.h"
#include "patelnst.h"
#include "patelnliteraltable.h"
#include"patelnerr.h"
#include <math.h>
using namespace std;

Expression :: Expression()
        {
        expname = "";
    value = 0;
   relocatableFlag = 0;
   indirectFlag = 0 ;
    immediateFlag = 0 ;
     indexFlag = 0;
        }
/********************************************************************
*** FUNCTION ExpressTable                                             
*********************************************************************
*** DESCRIPTION :This is the constructor of ExpressionTable class ***
                 It assigns the references for symbol table and   ***
                 literal list                                     ***

*** INPUT ARGS  :SymbolTable &symboltable1S: The reference of
                 symbol table.                                    *** 
                 Linklist<literals,string> &literalist1:The       ***
                 reference of the literal list.                   ***         
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : -                                               ***
********************************************************************/
   SymbolTable	defaultsymboltable ;
    Linklist<literals,string> defaultliterallist;

ExpressTable :: ExpressTable()
   
    {


    }
/*
ExpressTable ::ExpressTable(SymbolTable &symboltable1,Linklist<literals,string> &literalist1)

    :symboltable(symboltable1),
    literallist(literalist1)
    {
    }
    */
	/********************************************************************
*** FUNCTION setSymboltable                                       ***
*********************************************************************
*** DESCRIPTION :This function is used set the symbole table      ***
*** INPUT ARGS  :SymbolTable * - The value to be set              *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

 void ExpressTable :: setSymboltable(SymbolTable * symboltable1)
     {
     	symboltable = symboltable1;
    
     }
/********************************************************************
*** FUNCTION setliterallist                                      ***
*********************************************************************
*** DESCRIPTION :This function is used to set the literalist  ***
*** INPUT ARGS  :Linklist<literals,string> *  The value to be set*** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

  void ExpressTable :: setliterallist(Linklist<literals,string> * literallist1)
      {
      literallist = literallist1;
      }
  /********************************************************************
*** FUNCTION getliterallist                                    ***
*********************************************************************
*** DESCRIPTION :This function is used get the literallist       ***
*** INPUT ARGS  :                                                 *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : literallist                                     ***
********************************************************************/

   Linklist<literals,string>  * ExpressTable :: getliterallist()
      {
      return literallist;
       }

/********************************************************************
*** FUNCTION getHexFromAscii                                       ***
*********************************************************************
*** DESCRIPTION :This function is used convert asci value into hex ***
*** INPUT ARGS  :string value-                                     *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

string getHexFromAscii(string value)
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

/********************************************************************
*** FUNCTION  readexpfile                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable::readexpfile(string filename)
    {
    ifstream inf;
    inf.open(filename.c_str(), ios::in);
    if (!inf) {
        cout << "can't open file";
        }
    else
        {
        string exp = "";
        while (!inf.eof()) {
            getline(inf, exp);
            size_t found = exp.find_first_not_of(" ");

            if(found !=string::npos)
                exp = exp.substr(found,(exp.length()-found));

            found=exp.find_last_not_of(" \n\r");
            if (found!=string::npos)
                exp.erase(found+1);

            lines.push_back(exp);

            }
        }

    }

/********************************************************************
*** FUNCTION  validateLiteral                                     ***
*********************************************************************
*** DESCRIPTION :The function is used to validate the literals. 
It inserts the valid literals in a list          ***
*** INPUT ARGS  :string exp: The literal                          *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void  ExpressTable :: validateLiteral(string exp)
    {
    bool error = false;
    // get the address
    int address = literallist->count();
    //stringstream ss;
    //ss << count;
    //string address = ss.str();

    int literallength = 0;
    int explength = exp.length();

    string literalhexvalue = "";

    //check if the literal needs to be converted to hex
    if(exp[1] == 'C' || exp[1] == 'c'){
        if( exp[2] == '\'' && exp[explength-1] == '\''){ //check to see if the literal conatins the single quotes
            string ascii = exp.substr(3,explength - 4); //Read the literal between the single quotes
            literalhexvalue = getHexFromAscii(ascii);
            literallength = ascii.length();
            }
        else {
            cout <<"The literal "+exp +"is not valid. The literal is missing the single quotes"<<endl;
            error = true;
            tocontinue();
            }
        }
    //check if the literal is already in hex
    else if(exp[1] == 'X' || exp[1] == 'x'){
        if( exp[2] == '\'' && exp[explength-1] == '\''){ //check to see if the literal conatins the single quotes
            literalhexvalue = exp.substr(3,explength-4); //Read the literal between the single quotes

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
    if(!error){
        literals litobj (exp,literalhexvalue,address,literallength);
        literals searchliteral;

        bool found1 =  literallist->retrievedata(exp, searchliteral);//check to see if the literal is already present in the list
        
        string tmpexp = exp.substr(1); //remove =
        char firstChar = tmpexp[0];

        string tmpchar;
        if(firstChar == 'X') tmpchar = "x";
        else  if(firstChar == 'x') tmpchar = "X";
        else  if(firstChar == 'C') tmpchar = "c";
        else  if(firstChar == 'c') tmpchar = "C";

        tmpexp = tmpexp.substr(1);
        tmpexp = "="+tmpchar +tmpexp;

        bool found2 =  literallist->retrievedata(tmpexp, searchliteral);//check to see if the literal is already present in the list
        
        if(!found1 && !found2){
            literallist->append(litobj);
            }
        else {

            }
        }
    }



/********************************************************************
*** FUNCTION  checkValidExp                                       ***
*********************************************************************
*** DESCRIPTION :The function is heck if the expression is valid  ***
*** INPUT ARGS  :string exp : The exp to be checked for validity  *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

bool ExpressTable ::checkValidExp(string exp){
    bool isvalid = true;
    for(int i=0; i<exp.length();i++){
        char ch=exp[i];
        //checl if it only contains valid chars
        if(!(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z'||ch>='0'&&ch<='9'||ch=='#'||ch=='@'||ch==','||ch=='+'||ch=='-'||ch==':')){ 
            cout<<"Error! The expression "<<exp<<" has invalid char: ";
            cout <<ch<<endl;
            tocontinue();
            isvalid = false;
            break;
            }
        }
    //check if it does not contain invalid combinations
    if(exp.find(",") != string::npos) {

        if(exp[0] =='@'){
            cout<<"ERROR: The Expression"<<exp<<"has both ',' &'@' is invalid"<<endl;
            isvalid = false;
            }
        else if(exp[0] =='#'){
            cout<<"ERROR: The Expression"<<exp<<"has both ',' &'#' is invalid"<<endl;
            isvalid = false;
            }
        }
    return isvalid;
    }

/********************************************************************
*** FUNCTION  evaluateNumber                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluate a 
number expression                                ***
*** INPUT ARGS  :string filename : The expression to be evaluated *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable ::  evaluateNumber(string exp, Expression *expptr){
    bool error = false;
    string  symbol = "";
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = 0;
    int immediateFlag = 1;
    int indexFlag = 0;

    symbol = exp; 
    try{
        value =  calculateValue(symbol,*symboltable);    //calculate the value      
        relocatableFlag = calculateRflag(symbol,*symboltable); //claculate the rflag
        }catch(string value){
            cout << " The Expression "+ exp+ " is not valid. The symbol " + value + " is not in the symbol table"<<endl;
            error = true;
            tocontinue();
        }
        expptr->value = value;
        expptr->relocatableFlag = relocatableFlag;
        expptr->immediateFlag = immediateFlag;
        expptr->indexFlag = indexFlag ;
        expptr->indirectFlag = indirectFlag;
        expptr->expname = exp;
     
    //if(relocatableFlag == -1) {
    //    cout<<setw(10)<<exp<<setw(10)<<value<<setw(15)<<"ERROR"<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //    tocontinue();
    //    }
    //else {
    //    /*cout<<setw(10)<<exp<<setw(10)<<value<<setw(15)<<relocatableFlag<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;*/
    //    tocontinue();
    //    }
    }

/********************************************************************
*** FUNCTION  evaluateSymbol                                      ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluate the 
symbol expression read the expression file       ***
*** INPUT ARGS  :string exp : The symbol exp to be evaulated      *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable ::  evaluateSymbol(string exp, Expression * expptr){
    bool error = false;
    string  symbol = "";
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = 0;
    int immediateFlag = 0;
    int indexFlag = 0;

    symbol = exp; 
    try{
        value =  calculateValue(symbol,*symboltable); //calculate the value   
        relocatableFlag = calculateRflag(symbol,*symboltable); //calculate the rflag  
        }catch(string value){
            cout << " The Expression "+ exp+ " is not valid. The symbol " + value + " is not in the symbol table"<<endl;
            error = true;
            tocontinue();
        }
    
        expptr->value = value;
        expptr->relocatableFlag = relocatableFlag;
        expptr->immediateFlag = immediateFlag;
        expptr->indexFlag = indexFlag ;
        expptr->indirectFlag = indirectFlag;
        expptr->expname = exp;
    
    //if(relocatableFlag == -1) {
    //    cout<<setw(10)<<exp<<setw(10)<<value<<setw(15)<<"ERROR"<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //    tocontinue();
    //    }
    //else {
    //  /*  cout<<setw(10)<<exp<<setw(10)<<value<<setw(15)<<relocatableFlag<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;*/
    //    tocontinue();
    //    }
    }

/********************************************************************
*** FUNCTION  evaluateNumberOrSymbol                              ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluae a number or      ***
a symbol expression                              ***
*** INPUT ARGS  :string orgexp : The exp as fetched from the file ***
string exp    : The sub exp to be evaluated      ***
int indirect  : The indirect flag for this exp   ***
int immediate : The immediate flag for this exp  ***
int indexed   : The indexed flag for this exp    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable ::  evaluateNumberOrSymbol(string orgexp,string exp,int indirect,int immediate, int indexed,Expression * expptr){
    bool error = false;
    string  symbol = "";
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = indirect;
    int immediateFlag = immediate;
    int indexFlag = indexed;
    symbol = exp; 
    try{
        value =  calculateValue(symbol,*symboltable);
        relocatableFlag = calculateRflag(symbol,*symboltable);
        }catch(string value){
            cout << " The Expression "+ orgexp+ " is not valid. The symbol " + value + " is not in the symbol table"<<endl;
            error = true;
            tocontinue();
        }
    expptr->value = value;
        expptr->relocatableFlag = relocatableFlag;
        expptr->immediateFlag = immediateFlag;
        expptr->indexFlag = indexFlag ;
        expptr->indirectFlag = indirectFlag;
        expptr->expname = exp;
    
    /*if(relocatableFlag == -1) {
        cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<"ERROR"<<setw(10)<<indirectFlag<<setw(10)
            <<immediateFlag<<setw(10)<<indexFlag<<endl;
        tocontinue();
        }
    else {
        cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<relocatableFlag<<setw(10)<<indirectFlag<<setw(10)
            <<immediateFlag<<setw(10)<<indexFlag<<endl;
        tocontinue();
        }*/
    }

/********************************************************************
*** FUNCTION  evaluateImmediateExp                                ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluate an immediate exp***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable :: evaluateImmediateExp(string exp,Expression * expptr){
    string  symbol = "";
    int indirectFlag = 0;
    int immediateFlag = 1;
    int indexFlag = 0;
    string symbol1 = "";
    string symbol2 = "";
    int length = exp.length(); 
    symbol = exp.substr(1, length-1 ); // Remove the leading # sign

    if(symbol.find("+") != string::npos){    //check whether it contains two operans with a + sign
        evaluateSimpleSumExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else if(symbol.find("-") != string::npos){   //check whether it contains two operans with a - sign
        evaluateSimpleDiffExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else {                                       //its a simple number or symbol
        evaluateNumberOrSymbol(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr); 
        }
    }

/********************************************************************
*** FUNCTION  evaluateIndirectExp                                 ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluste a Indirect exp  ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable :: evaluateIndirectExp(string exp,Expression * expptr) {
    string  symbol = "";
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = 1;
    int immediateFlag = 0;
    int indexFlag = 0;

    int length = exp.length(); 
    symbol = exp.substr(1, length-1 ); // Remove the leading # char
    if(symbol.find("+") != string::npos){     //check whether it contains two operans with a + sign
        evaluateSimpleSumExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else if(symbol.find("-") != string::npos){  //check whether it contains two operans with a - sign
        evaluateSimpleDiffExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else {
        evaluateNumberOrSymbol(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr); //its a simple number or symbol
        }
    }

/********************************************************************
*** FUNCTION  evaluateIndexExp                                    ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluate a Index Exp     ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable :: evaluateIndexExp(string exp,Expression * expptr) {
    string  symbol = "";
    int relocatableFlag = 0;
    int indirectFlag = 0;
    int immediateFlag = 0;
    int indexFlag = 1;

    int i = exp.find(",");    
    symbol = exp.substr(0,i);  //remove the part conating ,X.
    if(symbol.find("+") != string::npos){   //check whether it contains two operans with a + sign
        evaluateSimpleSumExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else if(symbol.find("-") != string::npos){ //check whether it contains two operans with a - sign
        evaluateSimpleDiffExp(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);
        }
    else {
        evaluateNumberOrSymbol(exp,symbol,indirectFlag,immediateFlag,indexFlag,expptr);  //its a simple number or symbol
        }
    }
/********************************************************************
*** FUNCTION  evaluateSimpleSumExp                                ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluae a 
expression which conatins plus sign              ***
*** INPUT ARGS  :string orgexp : The exp as fetched from the file ***
string exp    : The sub exp to be evaluated      ***
int indirect  : The indirect flag for this exp   ***
int immediate : The immediate flag for this exp  ***
int indexed   : The indexed flag for this exp    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable :: evaluateSimpleSumExp(string orgexp,string exp,int indirect,int immediate, int indexed,Expression* expptr) {
    bool error = false;
    char firstChar = exp[0];
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = indirect;
    int immediateFlag = immediate;
    int indexFlag = indexed;
    string symbol1 = "";
    string symbol2 = "";

    int length = exp.length(); //  
    int i = exp.find("+");    // Find the loction of the + sign
    symbol1 = exp.substr(0,i);   // Extract the first operand
    symbol2 = exp.substr(i+1,length-(i+1));  // Extract the second operand
    //	cout<<"symbol1"<<symbol1<<endl;
    //		cout<<"symbol2"<<symbol2<<endl;
    try{
        value = calculateValue(symbol1,symbol2,'+',*symboltable);    // Calculate the value 
        relocatableFlag = calculateRflag(symbol1,symbol2,'+',*symboltable);  // claculate the rflag 

        }catch(string value){
            cout << " The Expression "+ orgexp+ " is not valid. The symbol " + value + " is not in the symbol table"<<endl;
            error = true;
            tocontinue();
        }

    expptr->value = value;
        expptr->relocatableFlag = relocatableFlag;
        expptr->immediateFlag = immediateFlag;
        expptr->indexFlag = indexFlag ;
        expptr->expname = orgexp;
        expptr->indirectFlag = indirectFlag;

    //if(relocatableFlag == -1) {
    //    cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<"ERROR"<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //    tocontinue();
    //    }
    //else {
    //    cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<relocatableFlag<<setw(10)<<indirectFlag<<setw(10)
    //        <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //    tocontinue();
    //    }
    }

/********************************************************************
*** FUNCTION  evaluateSimpleDiffExp                               ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluae a 
expression which conatins minus sign             ***

*** INPUT ARGS  :string orgexp : The exp as fetched from the file ***
string exp    : The sub exp to be evaluated      ***
int indirect  : The indirect flag for this exp   ***
int immediate : The immediate flag for this exp  ***
int indexed   : The indexed flag for this exp    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable :: evaluateSimpleDiffExp(string orgexp,string exp,int indirect,int immediate, int indexed,Expression * expptr) {
    bool error = false;
    string  symbol = "";
    char firstChar = exp[0];
    int value = 0;
    int relocatableFlag = 0;
    int indirectFlag = indirect;
    int immediateFlag = immediate;
    int indexFlag = indexed;
    string symbol1 = "";
    string symbol2 = "";

    int length = exp.length(); 

    int i = exp.find("-"); // find the location of - sign
    symbol1 = exp.substr(0,i); // Extract the first operand
    symbol2 = exp.substr(i+1,length-(i+1)); // Extraact the seconf operand
    try{
        value = calculateValue(symbol1,symbol2,'-',*symboltable);
        relocatableFlag = calculateRflag(symbol1,symbol2,'-',*symboltable);
        }catch(string value){
            cout << " The Expression "+ orgexp+ " is not valid. The symbol " + value + " is not in the symbol table"<<endl;
            error = true;
            tocontinue();
        }

    expptr->value = value;
        expptr->relocatableFlag = relocatableFlag;
        expptr->immediateFlag = immediateFlag;
        expptr->indexFlag = indexFlag ;
        expptr->expname = orgexp;
        expptr->indirectFlag = indirectFlag;

    //if( !error){
    //    if(relocatableFlag == -1) { //check if the rflag was invalid
    //        cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<"ERROR"<<setw(10)<<indirectFlag<<setw(10)
    //            <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //        tocontinue();
    //        }
    //    else {
    //        cout<<setw(10)<<orgexp<<setw(10)<<value<<setw(15)<<relocatableFlag<<setw(10)<<indirectFlag<<setw(10)
    //            <<immediateFlag<<setw(10)<<indexFlag<<endl;
    //        tocontinue();
    //        }
        } 
    

/********************************************************************
*** FUNCTION  validateExp                                         ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable ::validateExp(string exp,Expression* expptr)
    {
    char firstChar = exp[0];

    if(!checkValidExp(exp)){
        return;
        }

    if((firstChar == '+')||(firstChar == '-')) //if the expression starts with a + or - then it is a number
        {
        evaluateNumber(exp, expptr); 
        }
    else if(firstChar == '#')  //if the expression starts with # then it is an immediate expression
        {
        evaluateImmediateExp(exp,expptr);
        }
    else if(firstChar == '@')   //if the expression starts with # then it is an indirect expression
        {
        evaluateIndirectExp(exp ,expptr);
        }
    else if(exp.find(",") != string::npos)  //if the expression contains , then it is an iindexed expression
        {
        evaluateIndexExp(exp,expptr);
        }
    else if(exp.find("+") != string::npos)   //this is a simple expression
        {
        evaluateSimpleSumExp(exp,exp,0,0,0,expptr);
        }
    else if(exp.find("-") != string::npos)  //this is a simple expression
        {
        evaluateSimpleDiffExp(exp,exp,0,0,0,expptr);
        }
    else
        {
        if(isconst(exp)){
            evaluateNumber(exp,expptr); //this is a simple number
            }
        else{
            evaluateSymbol(exp,expptr); //this is a simple symbol
            }
        }
    }

/********************************************************************
*** FUNCTION  evaluateExpression                                  ***
*********************************************************************
*** DESCRIPTION :The function is used to read the expression file ***
*** INPUT ARGS  :string filename : The name of file to be read    *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

//
//void ExpressTable ::evaluateExpression()
//    {
//
//    vector<string>:: iterator itr;
//    itr= lines.begin();
//    cout<<setw(10)<<"Expression"<<setw(10)<<"Value"<<setw(15)<<"Relocatable"<<setw(10)<<"Indirect"<<setw(10)
//        <<"Immediate"<<setw(10)<<"Index"<<endl;
//    tocontinue();
//    while(itr != lines.end())
//        {
//        string exp = *itr;
//        if(exp.length() != 0){ 
//
//
//            char firstChar = exp[0];
//            if(firstChar == '=')
//                {
//                validateLiteral(exp);
//
//                }
//            else{
//                Expression expobj;
//                validateExp(exp,&expobj);
//                }
//
//            }
//        itr++;
//
//        }
//
//
//    }

/********************************************************************
*** FUNCTION  evaluatesingleExpression                             ***
*********************************************************************
*** DESCRIPTION :The function is used to evalute expression       ***
*** INPUT ARGS  :string exp: The expression to be evaluated
                 Expression* expptr  the pointer for the expression
				 object                                           *** 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/
void ExpressTable ::evaluatesingleExpression(string exp,Expression* expptr)
    {
         if(exp.length() != 0){ 
          validateExp(exp,expptr);
             }
    }
	/********************************************************************
*** FUNCTION               evaluateAllLiterals                     ***
*********************************************************************
*** DESCRIPTION :The function is used to evaluate the literals    ***
*** INPUT ARGS  :string exp: the literals expression
                 
*** OUTPUT ARGS : -                                               ***
*** IN/OUT ARGS : -                                               ***
*** RETURN      : void                                            ***
********************************************************************/

void ExpressTable ::evaluateAllLiterals(string exp)
    {
         if(exp.length() != 0){ 
        char firstChar = exp[0];
       
            if(firstChar == '=')
                {
                validateLiteral(exp);

                }
            else{
               //cout<<"It does not contain '=' sign"<<endl;
                }
             }
    }


   
