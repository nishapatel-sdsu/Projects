
--ADA 
--Compiler used : Gnat 
--IDE : GPS
--Part1:
--Folder : ASG2_A
--Main File :

--Part2:
--Folder : ASG2_B
--Main File :
--Run : 
--1.Copy the folder CSc710Asg2 on local computer which has java installed. 
--2.Open a command prompt. 
--3.Go to folder CSc710Asg2/ADA/ASG2_A/
--c:/CSc710Asg2/ADA/ASG2_A/
--4. Compile using gnatmake *.adb
--5. Provide the input file input.txt in ASG2_A folder

--Run the Main propgram using : main
--Enter the file name : input.txt
--Alternatively you can also run the program as  : main input.txt

--Input:
--Tht input can be specified in a file eg: input.txt. Please see the input.txt for the structure of the input file. 
--The file starts with the first array. Each line lists one array value. After the last value of the first array there is an empty line.
--The empty line is used to seperate the two arrays. The second array starts after the empty line. Each value of the second array is 
--also specified on a seperate line without any empty line between the values.After the last value of the second array there is an empty line. 
--The target value is written after the empty line.The empty line is used to seperate the target from the array values.



--/********************************************************************
-- *** NAME       : NISHA PATEL
-- *** CLASS      : CSc 710
-- *** ASSIGNMENT : Asg2_B  ADA
-- *** DUE DATE   : 09/23/2012
 --*** INSTRUCTOR : Dr.Shin
-- *********************************************************************
-- *** DESCRIPTION : This module convert Infix  string too PostFix and
 --convert postfixnotation to evaluate. It also  implement stack main
 --  and  link list
 --********************************************************************/

with ada.command_line; use ada.command_line;
with ada.Strings.Unbounded; use ada.Strings.Unbounded;
with Ada.Unchecked_Deallocation;
with Ada.Strings.Unbounded.Text_IO; use Ada.Strings.Unbounded.Text_IO;

--with Ada.Strings.Unbounded_Text_IO; use Ada.Strings.Unbounded_Text_IO;

with ada.text_io; use ada.text_io;
with ada.integer_text_io; use ada.integer_text_io;
-- main start

procedure main is


   Input_File,outf    : File_Type;
   LINE         : STRING(1 .. 200);
   LINE_LENGTH :Integer ;
   inputFile :  Unbounded_String := To_Unbounded_String("");


   type Node;
    type Stack;
   type nodeptr  is access Node;
   type stackptr  is access Stack;
   -- Node record
   type Node is

   record
         data: Unbounded_String ;
         next :  nodeptr;
      end record ;
   -- stack record
   type Stack is
   record
       count: integer;
         top : nodeptr;
       end record;

  stackObjptr : stackptr;
  data1  : Unbounded_String := To_Unbounded_String("a");
  pushRtr : Integer;
--/*============PushStack=======================
-- *This function pushes an item onto the stack
 --*/

 function pushstack(datain:in  Unbounded_String ;stackObjPtr : in stackptr ) return integer is


  success : integer;
  newptr : nodeptr;
 begin
      newptr := new Node;
      newptr.data := To_Unbounded_String("");
      newptr.next := null;

     success := 0;

    if newptr = null  then

	return success;

    else

                newptr.data := datain;
		newptr.next := stackObjPtr.top;
	        stackObjPtr.top := newptr;
		stackObjPtr.count := stackObjPtr.count +1;
                success := 1;

           end if;

         return success;

   end pushstack;
  -- /*=================PopStack=================
 --*This function pop the item on the top of the stack

   procedure popstack(dataout: in out Unbounded_String ;stackObjPtr : in out stackptr )  is


  dltptr : nodeptr;
 procedure Free_Node is new Ada.Unchecked_Deallocation
      (Object => Node, Name => nodeptr);
   begin


	if  (stackObjPtr.count = 0) then


              put("");

	else

		dltptr := stackObjPtr.top;
		dataout := stackObjPtr.top.data;
		stackObjPtr.top :=  stackObjPtr.top.next;

               stackObjPtr.count := stackObjPtr.count -1;
		Free_Node(dltptr);


	end if;


 end popstack;
--==============StackTop=====================
-- This function retrieves the data from the top of the stack without changing the stack

   procedure stacktop(dataout: in out Unbounded_String ;stackObjPtr : in out stackptr ) is


begin
if (stackObjPtr.count > 0) then

       dataout := stackObjPtr.top.data;

      end if;
end stacktop;
--================printStack==================
-- This procedure print the stack
  procedure printStack(stackObjPtr : in out stackptr) is

  temp : nodeptr;
     begin



    temp := stackObjPtr.top;
       put("[ ");
    while (temp /=  null)  loop


         put(temp.data);
         put(" ");
       temp := temp.next;


end loop;
    put(" ]");
  end  printStack;


   procedure call(a : in integer) is
      begin


    pushRtr :=  pushstack(data1,stackObjptr);


      printStack(stackObjPtr);

   end call;
 --================emptystack==================
-- This function determines if a stack is empty

function emptystack(stackObjPtr : in  stackptr) return integer is
begin
   if stackObjPtr.count = 0 then

        return 1;

    else

         return 0;
    end if;

 end emptystack;
--================operatorf==================
-- This function  check the operator
   function operatorf(c:in Unbounded_String) return integer is
begin

    if (c  = "+") OR (c  = "*" )OR (c  = "-" )OR (c = "/") then

        return 1;


    else

        return  0;
    end if;

   end operatorf;

--================prority==================
-- This function  check the priroty of the oprator
   function prority(c:in  Unbounded_String) return integer is
begin

    if( c = "+") OR (c = "-") then

        return  1;

    elsif(c = "*") OR (c = "/") then

        return  2;


    else

      return  -1;
    end if;

   end prority;
--================infixtopostfix==================
-- This function  convert infix notation to postfix
   function infixtopostfix(formula:in String ; frmLength : integer) return Unbounded_String is

  mystack : stackptr;
      postfix : Unbounded_String;
      token : Unbounded_String;
      tokenout : Unbounded_String;
      toptoken : Unbounded_String;

    begin

 mystack := null;
 postfix := To_Unbounded_String("");
 --valLoop := 0;
      token := To_Unbounded_String("");

 tokenout := To_Unbounded_String("");
toptoken := To_Unbounded_String("");
 mystack := new Stack;
      mystack.count := 0;
      mystack.top := null;


   for valLoop in 1..frmLength  loop


         token := TO_Unbounded_String(formula(valLoop..valLoop));


          if (token = " ")  then

           put("");

-- check it is open parenthesis  }
        elsif (token  = "(" ) then

          pushRtr:=  pushstack(token,mystack);


       -- { check it is close parenthesis }
        elsif (token = ")" )then

         popstack(token,mystack);
            while (token /=   "(") loop


                 postfix :=  postfix & token;
		 popstack(token,mystack);
                end loop;


        --{ check if it is a operator }

        elsif (operatorf (token) = 1) then


             stacktop(toptoken,mystack);
         --   stoptoken := TO_String(toptoken);
            while ((emptystack(mystack) = 0) and (prority(token) <= prority(toptoken))) loop



                        popstack(tokenout,mystack);
                        postfix :=  postfix & tokenout;

                          stacktop(toptoken,mystack);
                            end loop;

                     pushRtr :=    pushstack(token,mystack);


        else

            postfix :=  postfix & token;

            end if;



      end loop;
      -- PUT_LINE("End Str");

      while (emptystack(mystack) = 0) loop
        --  PUT_LINE("Inside while");
		popstack(token,mystack);
         postfix :=  postfix & token;



     end loop;


      return  postfix;
 end infixtopostfix;
--================calculate==================
-- This function  calculate the vale base on the operator.
 function calculate(operand1:in  Unbounded_String;operatorc: in Unbounded_String;operand2:in  Unbounded_String) return integer is


        x : integer;
     opera1 : integer;
     opera2 : integer;
      Num : integer;
      code:  integer;
      result : integer;
 begin
 Num := 0;
 code := 0;
 x:= 0;

 opera1 := 0;
 opera2 := 0;
 opera1 := Integer'Value(To_String(operand1));
 opera2 := Integer'Value(To_String(operand2));


	if (operatorc  = "+") then

		result := (opera1 + opera2);


 elsif (operatorc = "-") then

		result :=  (opera1 - opera2);


 elsif (operatorc = "*") then

		result := (opera1 * opera2);


 elsif (operatorc ="/") then

       if (opera2 = 0) then

           result := 0;

       else

           result := (opera1 / opera2);

         end if;

     end if;

      return result;
   end calculate;

--================postfixtoevaluate==================
-- This function  evalaue postfix to value
 function postfixtoevaluate (exp: in  Unbounded_String;  frmLength : in  integer) return integer is

  exprsize :integer;
  index :integer;
      mystack : stackptr;
      ctoken : Unbounded_String;
      tempresult :  Unbounded_String;
      --stoken :  Unbounded_String;
      operand2: Unbounded_String;
      operand1 : Unbounded_String;
      value :integer;
     svalue : Unbounded_String;
     finalresult : integer;
     code : integer;

begin

       mystack := new Stack;
      mystack.count := 0;
      mystack.top := null;
   index := 1;
   finalresult := 0;
   value := 0;
   tempresult := To_Unbounded_String("");

   operand2 := To_Unbounded_String("");
   operand1 := To_Unbounded_String("");
   svalue := To_Unbounded_String("");
   code := 0;
     exprsize :=  frmLength;

     -- {check the expration size }
        while (index <= exprsize) loop


         ctoken := TO_Unbounded_String(slice(exp,index,index));

           -- {check operator is a token}

            if (operatorf(ctoken) = 1) then


                 popstack(operand2,mystack);
                 popstack(operand1,mystack);
                -- //call calculate function

                  value :=  calculate(operand1, ctoken, operand2);

            svalue :=  To_Unbounded_String(Integer'Image(value));

		pushRtr := pushstack(svalue,mystack);


            --{check if it is a operand than push into a stack}

            else

               pushRtr := pushstack(ctoken,mystack);

                end if;
            index := index +1;

            end loop;

          popstack(tempresult,mystack);

      --{convert final result string to integer}
      if(tempresult = "") then
         finalresult := 0;
         else
         finalresult := Integer'Value(To_String(tempresult));
         end if;


       return  finalresult;


end postfixtoevaluate;
--================ReadInputFile==================
-- This function  read input file
   procedure ReadInputFile(inputFileName:Unbounded_String) is
    postfixnotation :Unbounded_String;
      finalresult : integer;
      formula1 : Unbounded_String;

   begin

       Ada.Text_IO.Open (File => Input_File, Mode => Ada.Text_IO.In_File, Name => To_String(inputFileName));
   CREATE ( OUTF,NAME => "output.txt");
   while not End_OF_File (Input_File) loop
      Ada.Text_IO.Get_Line (Input_File, LINE,LINE_LENGTH);
      put_Line("");
      put_Line(outf,"");
     if LINE_LENGTH = 0  then
        goto i10 ;
    end if;
   put("The infix notation is: " );
       put(outf,"The infix notation is: " );
      put(LINE(1..LINE_LENGTH));
      put(outf,LINE(1..LINE_LENGTH));



 <<i10>>

         --call infixtopostfix function}
         formula1 :=To_Unbounded_String(LINE);
       postfixnotation := infixtopostfix(LINE,LINE_LENGTH);
 put_Line("");
      put_Line(outf,"");
      put_Line("The postfix notation is: " & postfixnotation );
      put_Line(outf,"The postfix notation is: " & postfixnotation );

         ---{call postfixtoevalute function}

	 finalresult := postfixtoevaluate(postfixnotation,length(postfixnotation));

	put_Line("The postfix evaluation is : " & Integer'Image(finalresult));
       put_Line(outf,"The postfix evaluation is : " & Integer'Image(finalresult));


      end loop;
      put_Line("");
      put_Line(outf,"");
       put_Line("Program completed");
      put_Line(outf,"Program completed");

    Ada.Text_IO.Close (File => outf);

        end ReadInputFile;
-- main begin
begin

   if Argument_Count = 0 then
      put_Line("Please enter the file name");
      inputFile := get_Line;


      else
      inputFile := To_Unbounded_String(Argument(1));
      end if;

   ReadInputFile(inputFile);

   stackObjptr := new Stack;
   stackObjptr.count := 0;
   stackObjptr.top := null;
   put_line("");
    Ada.Text_IO.Close (File => Input_File);


-- main end here
   end main;
