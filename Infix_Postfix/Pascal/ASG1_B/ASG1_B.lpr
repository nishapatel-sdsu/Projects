{/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1_B  Pascal                                  ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION :Convert infix to postfix and evaluate the postfix string
 ********************************************************************/


}


program ASG1_B;

{$mode objfpc}{$H+}

uses
  sysutils,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
  {Node record and stack record}
type
  nodeptr =  ^Node;
  stackptr = ^Stack;
    Node = record
     data: String;
      next : nodeptr;
        end;
        Stack = record
       count: integer;
        top : nodeptr;
       end;


var
 {main varible}
  inputFile: string;
  Fname: textfile;
  Fout:  textfile;
  Data : string;
   stackObjptr : stackptr;
    tempVal : integer;
   i : String;


   {
  PushStack
 This function pushes an item onto the stack

   }
   function pushstack(datain:String;stackObjPtr : stackptr ) :integer;
var

  success : integer;
  newptr : nodeptr;
begin
    New(newptr);
     success := 0;

    if newptr = nil  then
	begin
	pushstack := success;
        end
    else
         begin
                newptr^.data := datain;
		newptr^.next := stackObjPtr^.top;
	        stackObjPtr^.top := newptr;
		stackObjPtr^.count := stackObjPtr^.count +1;
                success := 1;

           end;

         pushstack := success;

 end;
{
 popstack
 This function pop the item on the top of
 the stack

  }
function popstack(var dataout:String;stackObjPtr : stackptr ) :integer;
var

  success : integer;
  dltptr : nodeptr;

      begin
       success := 0;
	if  stackObjPtr^.count = 0 then
                begin

                popstack := success;
                end
	else
        begin
		dltptr := stackObjPtr^.top;
		dataout := stackObjPtr^.top^.data;
		stackObjPtr^.top :=  stackObjPtr^.top^.next;

               stackObjPtr^.count := stackObjPtr^.count -1;
		dispose (dltptr);
	         success := 1;

	end;
	 popstack := success;

 end;
{
 stacktop
 This function retrieves the data from the
 top of the stack without changing the stack

  }
function stacktop(var dataout:String;stackObjPtr : stackptr ) :integer;
var
     success : integer;
begin

   success := 0;

	if stackObjPtr^.count = 0 then

          begin
        stacktop := success ;
        end

     else
        begin


                dataout := stackObjPtr^.top^.data;
		success := 1;
        end ;
        stacktop := success ;




 end;

    {   printStack
This function print the element from the stack }
  procedure printStack(stackObjPtr : stackptr);
    var
  temp : nodeptr;
     begin



    temp := stackObjPtr^.top;

    while temp <> nil  do
       begin
        //cout<<"hello:";
       write(temp^.data, ' ');
       temp := temp^.next;


end;
    writeln(']');
  end;
{   emptystack
This function determines if a stack is empty }
function emptystack(stackObjPtr : stackptr ) :integer;
begin
   if stackObjPtr^.count = 0 then
     begin
        emptystack := 1;
     end

    else
    begin
         emptystack := 0;
    end;

 end;
{   operatorf
This function check the operator }

function operatorf(c:char) :integer;
begin

    if (c  = '+') OR (c  = '*' )OR (c  = '-' )OR (c = '/') then
        begin
        operatorf := 1;
        end

    else
    begin
         operatorf := 0;
    end;

 end;
{   prority
This function check the prority for the operator }
function prority(c:char) :integer;
begin

    if( c = '+') OR (c = '-') then
        begin
        prority := 1;
        end
    else if(c = '*') OR (c = '/') then
        begin
         prority := 2;
        end

    else
     begin
       prority := -1;
    end;

     end;
{   infixtopostfix
This function convert infix string to postfix string }

function infixtopostfix(var formula:String) :String;
  var
  mystack : stackptr;
  postfix : String;
  valLoop : integer;
  token : String;
tokenout : String;
toptoken : String;
    begin

 mystack := nil;
 postfix := '';
 valLoop := 0;
 token := '';
 tokenout := '';
toptoken := '';
new(mystack);
mystack^.count:= 0;
          mystack^.top:= nil;
   writeln('The formula length is ',Length(formula));
   for valLoop := 1 to  Length(formula)  do

     begin
        token := formula[valLoop];

        if token = ' '  then
            begin
            Continue;
            end;
        if token = '\n' then
            begin
        Continue;

        end;
	if token = '\r' then
            begin
	Continue;
        end;

{ check it is open parenthesis  }
        if token  = '(' then
              begin
            pushstack(token,mystack);

              end
        { check it is close parenthesis }
        else if token = ')' then
            begin
         popstack(token,mystack);
            while token <>  '(' do
                begin

                 postfix :=  postfix + token;
			popstack(token,mystack);
                end
            end

        { check if it is a operator }

        else if (operatorf(token[1]) = 1) then
          begin

              stacktop(toptoken,mystack);
            while ((emptystack(mystack) = 0) and (prority(token[1]) <= prority(toptoken[1]))) do
                        begin


                        popstack(tokenout,mystack);
                        postfix :=  postfix + tokenout;

                            stacktop(toptoken,mystack);
                            end;

                        pushstack(token,mystack);

            end
        else
         begin
            postfix :=  postfix + token;

            end

        end;
     while (emptystack(mystack) = 0) do
     begin
		popstack(token,mystack);
                 postfix :=  postfix + token;

     end;
    infixtopostfix :=  postfix;

 end;
{   calculate
This function calculate the postfix string }
 function calculate(operand1:String;operatorc: char;operand2:String):integer;
    var
        x : integer;
     opera1 : integer;
     opera2 : integer;
      Num : integer;
      code:  integer;
 begin
 Num := 0;
 code := 0;
 x:= 0;

 opera1 := 0;
 opera2 := 0;
 val(operand1, Num,code);
 opera1 := Num;
val(operand2, Num,code);
opera2 := Num;


	if operatorc  = '+' then
          begin
		calculate := (opera1 + opera2);

          end
 else if operatorc = '-' then
            begin
		calculate := (opera1 - opera2);

             end
 else if operatorc = '*' then
               begin
		calculate := (opera1 * opera2);

               end
 else if operatorc ='/' then
       begin
       if opera2 = 0 then
          begin
            calculate :=  0;
          end
       else
           begin
            calculate:= (opera1 DIV opera2);

           end;
      end;




end;
 {   postfixtoevaluate
This function  evaluate postfix string  }
function postfixtoevaluate(exp:String):integer;
var
  exprsize :integer;
  index :integer;
      mystack : stackptr;
      ctoken : char;
      tempresult :  string;
      stoken :  string;
      operand2: string;
      operand1 : string;
      value :integer;
     svalue : string;
     finalresult :integer;
     code : integer;

begin
 new(mystack);
  index := 1;
   finalresult := 0;
   value := 0;
   tempresult := '';
   stoken := '';
   operand2 := '';
   operand1 := '';
   svalue := '';
   code := 0;
     exprsize :=  Length(exp);

      {check the expration size }
        while (index <= exprsize) do
            begin
             ctoken := exp[index];
             stoken := '';
            stoken  := ctoken;
            {check operator is a token}

            if (operatorf(ctoken) = 1) then
               begin

                 popstack(operand2,mystack);
                 popstack(operand1,mystack);
                 //call calculate function

                  value :=  calculate(operand1, ctoken, operand2);
                      Str(value, svalue);

			pushstack(svalue,mystack);

                end
            {check if it is a operand than push into a stack}

            else
                begin
                pushstack(stoken,mystack);

                end;
            index := index +1;

            end;

        popstack(tempresult,mystack);

        {convert final result string to integer}
        val(tempresult, finalresult,code);

       postfixtoevaluate := finalresult;


end;
{ReadInputFile
This function read the input file
      }
procedure ReadInputFile(inputFileName:string);
      var
       postfixnotation : string;
       finalresult : integer;
      begin
      postfixnotation := '';
      finalresult := 0;
   assignfile(Fname, inputFileName);
       Reset(Fname);
        assignfile(Fout, 'output.txt');
       Rewrite(Fout);


       while not Eof (Fname)   do
   begin
       Readln(Fname,Data);
       writeln();
       writeln(fout,' ');
       writeln('The infix notation is: ',Data);
       writeln(fout,'The infix notation is: ',Data);


         {call infixtopostfix function}
       postfixnotation := infixtopostfix(Data);

      writeln('The postfix notation is ' , postfixnotation );
      writeln(fout,'The postfix notation is ' , postfixnotation );


      {call postfixtoevalute function}
	 finalresult := postfixtoevaluate(postfixnotation);

	writeln('The postfix evaluation is : ',finalresult);
       writeln(fout,'The postfix evaluation is : ',finalresult);


   end;
       writeln;
     writeln('Program completed');
      writeln(fout,'Program completed');
       Close(Fname);
       Close(fout);
        end;




   {Main start here}
begin


           New(stackObjptr);
           stackObjptr^.count:= 0;
           stackObjptr^.top:= nil;
  {Read the file Name}

  Writeln('Program: ',ParamStr(0));
        if ParamCount <1  then
        begin
        Writeln('Please enter the file name');
        readln(inputFile);
        end
          else
          begin
              inputFile := ParamStr(1);
            end;

             {Read end here}

                 ReadInputFile(inputFile);

              readln;
end.
        {Main end here}
