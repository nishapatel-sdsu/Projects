
--ADA 
--Compiler used : Gnat 
--IDE : GPS
--Part1:
--Folder : ASG2_A
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
-- *** ASSIGNMENT : Asg2_A  ADA
 ----*** DUE DATE   : 09/23/2012
-- *** INSTRUCTOR : Dr.Shin
-- *********************************************************************
-- *** DESCRIPTION :This module implement  Insertion Sort , Selection Sort
 -- Merge sort and Binary search tree and main .
-- ********************************************************************/

with ada.text_io; use ada.text_io;
with ada.integer_text_io; use ada.integer_text_io;
with ada.command_line; use ada.command_line;
with ada.Strings.Unbounded.Text_IO; use ada.Strings.Unbounded.Text_IO;
with ada.Strings.Unbounded; use ada.Strings.Unbounded;

-- Main start here
procedure main is

   Input_File,OUTF    : File_Type;
   LINE         : STRING(1 .. 200);
   LINE_LENGTH :Integer ;
   type InpArr is array (1..30) of Integer;
    type newInpArr is array (1..60) of Integer;
    type tmpInpArr is array (1..31) of Integer;
   subtype ArrayRange IS Integer  RANGE 1..30;
   inputFile :  Unbounded_String := To_Unbounded_String("");

-- sort Record
   type Sort is
      record

   InpArr1 : InpArr ;
   InpArr2 : InpArr;
   InpArr3:newInpArr;


   array1Size : integer := 0;
       array2Size : integer := 0;
         array3Size : integer := 0;
         target : integer := 0;
      end record;
-- record end here
    i: ArrayRange;
    sortobj:Sort;
--/********************************************************************************
--*** procedure printArray
--*********************************************************************************
--*** DESCRIPTION : This procedure print Array.
 --*** INPUT ARGS  : Integer array, Integer count
-- *** OUTPUT ARGS : None
-- *** IN/OUT ARGS : -
-- *** RETURN      : void
-- *********************************************************************************/

   procedure printArray(inputArr : in InpArr ; count : in integer ) is

    begin
      put('[');
       Put(OUTF,'[');
      --write(fout,'[');

        for  i in 1  .. count  loop
              put("");
         put(INTEGER'Image(inputArr(i)));
         put(OUTF,INTEGER'Image(inputArr(i)));
        --write(fout,' ',inputArr[i]);


                end loop;
      put(']');
      Put(OUTF,']');
                     --writeln(fout,']');

   end printArray;
--/********************************************************************************
--*** procedure printArrayMergSort
--*********************************************************************************
--*** DESCRIPTION : This procedure print merge Array.
 --*** INPUT ARGS  : Integer array, Integer count
-- *** OUTPUT ARGS : None
-- *** IN/OUT ARGS : -
-- *** RETURN      : void
-- *********************************************************************************/

   procedure printArrayMergSort(inputArr : in newInpArr ; count : in integer )is
begin
     put('[');
       Put(OUTF,'[');

   for  i in 1  .. count  loop
              put("");
         put(INTEGER'Image(inputArr(i)));
         put(OUTF,INTEGER'Image(inputArr(i)));



                end loop;
    put(']');
      Put(OUTF,']');

end printArrayMergSort;

--/********************************************************************************
--*** FUNCTION InsertionSort
-- *********************************************************************************
--*** DESCRIPTION : This function sort the element from array 1
-- INPUT ARGS : integer array , integer last index
-- OUTPUT ARGS : None
--IN/OUT ARGS : None
-- RETURN : void
 --********************************************************************************* */

   procedure insertionSort(arrayList : in out InpArr ; lastIndex: in integer ) is


    currVal :integer;
    temVal :integer;
    currentIndex :integer;
        begin

         currVal := 2;
        temVal :=0;
         currentIndex :=1;
         while (currVal <=lastIndex)   loop


            temVal := arrayList(currVal);
         currentIndex := currVal-1;

             while (currentIndex >= 1 ) loop

            if(temVal >= arrayList(currentIndex)) then
               goto i12;
            end if;

                 arrayList(currentIndex +1) := arrayList(currentIndex);


                 currentIndex :=  currentIndex -1;

         end loop;
         <<i12>>
             arrayList(currentIndex+1) := temVal;
             currVal := currVal +1;
             end loop;

   end insertionSort;
--/********************************************************************************
-- *** FUNCTION selectionSort
--*********************************************************************************
 --*** DESCRIPTION : This function sort the element from array 2
-- *** INPUT ARGS : integer array, integer last index
--*** OUTPUT ARGS : None
--*** IN/OUT ARGS : None
--*** RETURN : void
--*********************************************************************************/
   procedure selectionSort(arrayList : in out InpArr ; lastIndex: in integer ) is

       currVal :integer;
      smallVal :integer;
      tempVal:integer;
      swapVal :integer;

begin

     currVal := 1;
     smallVal := 0;
     tempVal := 0;
     swapVal :=0;
           while (currVal < lastIndex )  loop


              smallVal := currVal;

              tempVal := currVal +1;
              while (tempVal <=lastIndex)  loop


                  if (arrayList(tempVal) < arrayList(smallVal)) then

                      smallVal := tempVal;
                      end if;
                tempVal :=  tempVal+ 1;
                  end loop;
              swapVal :=arrayList(currVal);
              arrayList(currVal) :=arrayList(smallVal);
              arrayList(smallVal) := swapVal;
              currVal := currVal +1;
              end loop;


 end selectionSort;
--/********************************************************************************
-- *** procedure mergSort
--*********************************************************************************
-- *** DESCRIPTION : This procedure mergr element from from array 1 and array 2.
--Then it store the megre element in array 3
 --*** INPUT ARGS : sortobj : in out Sort
--*** OUTPUT ARGS : None
--**** IN/OUT ARGS : None
--*** RETURN : void
--*********************************************************************************/

procedure mergSort(sortobj : in out Sort) is




      i :integer;
      j :integer;
     -- l:integer;
      k :integer;
      maxarray3Size :integer;

       tempArray1:  tmpInpArr;
       tempArray2 :tmpInpArr;

begin
       i :=1;
       j :=1;
      -- l :=0;
       k := 0;


          for l in 1 .. sortobj.array1Size loop


              tempArray1(l) :=sortobj.inpArr1(l);

              end loop;
          for l in  1  .. sortobj.array2Size loop

              tempArray2(l) :=sortobj.inpArr2(l);
             end loop;

         tempArray1(sortobj.array1Size +1) := 1000;

          tempArray2(sortobj.array2Size +1) := 1000;

          maxarray3Size := sortobj.array1Size + sortobj.array2Size;

                 k :=1;

            while  k <= maxarray3Size loop


             if tempArray1(i) < tempArray2(j) then

                 if sortobj.inpArr3(k-1) =tempArray1(i) then

                     maxarray3Size := maxarray3Size -1;
                     k := k-1;
                     i := i +1;

                 else


                 sortobj.inpArr3(k) := tempArray1(i);
                i := i +1;
                sortobj.array3Size := sortobj.array3Size + 1;
                      end if;

             elsif tempArray1(i) = tempArray2(j) then

                  if sortobj.inpArr3(k-1) =tempArray1(i) then

                       maxarray3Size :=  maxarray3Size- 1;
                      k := k-1;
                   i := i +1;
                   j := j +1;


                  else
                  sortobj.inpArr3(k) := tempArray1(i);
                   i := i +1;
                   j := j +1;
                   sortobj.array3Size := sortobj.array3Size + 1;

                  maxarray3Size :=  maxarray3Size- 1;
                 end if;

             else
                if k > 1 then
                    if ( sortobj.inpArr3(k-1) = tempArray2(j)) then

                    maxarray3Size :=  maxarray3Size- 1;
                      k := k-1;
                      j := j +1;

                   else

                    sortobj.inpArr3(k) := tempArray2(j);
                    j := j +1;
                    sortobj.array3Size := sortobj.array3Size + 1;
                   end if;
              else
                   sortobj.inpArr3(k) := tempArray2(j);
                   j := j +1;
                    sortobj.array3Size := sortobj.array3Size + 1;
               end if;
               end if;
                    k:= k+ 1;
             end loop;


    end mergSort;


--/********************************************************************
-- *** FUNCTION BST_search
--*********************************************************************
--*** DESCRIPTION :This function is used to serch value in the binary  search tree
--*** INPUT ARGS  :integer array*,Integer key, integer left,integer right
--*** OUTPUT ARGS : None
 --*** IN/OUT ARGS : None
-- *** RETURN      : Return the  search  value.
-- ********************************************************************/

   function binarySearch(inpArr3 : in  newInpArr ; key : in  integer;left: in  integer;right: in  integer) return integer is

  m :  integer;
begin
            m := 0;
            m := (left + right)/ 2;
            if (left > right) then

           return -1;

           elsif (inpArr3(m) = key) then

                return   m;


            elsif key < inpArr3(m) then
              -- right := m-1;
                  return  binarySearch(inpArr3, key, left,  m-1);

            else
              -- left := m+1;
                 return   binarySearch(inpArr3, key,  m+1, right);
                end if ;


   end binarySearch;
--/********************************************************************************
--*** procedure sortingArray ***
--*********************************************************************************
--*** DESCRIPTION : This procedure use to call all sorting function.
-- *** INPUT ARGS : sortObj : in out Sort
 --*** OUTPUT ARGS : None
--*** IN/OUT ARGS : None
--*** RETURN : void
--********************************************************************************* */
   procedure sortingArray(sortObj : in out Sort) is


      bsIndex  : integer;
       key : integer;
      right  : integer;
       left : integer;

   begin

      insertionSort(sortObj.inpArr1, sortObj.array1Size); -- calling insertionSort
      put_line("");
   put_line(OUTF,"");
           put("After sorting first array using insertion sort");
              put_Line("");
              put(OUTF,"After sorting first array using insertion sort");
              put_Line(OUTF,"");

         printArray(sortObj.inpArr1, sortObj.array1Size);

               put_Line("");
             put_Line(OUTF,"");

      selectionSort(sortObj.inpArr2, sortObj.array2Size); -- calling selectionSort
      put_line("");
   put_line(OUTF,"");
                  put("After sorting second array using selection sort");
             put_Line("");
               put(OUTF,"After sorting second array using selection sort");

  put_Line(OUTF,"");
         printArray(sortObj.inpArr2, sortObj.array2Size);
                 put_Line("");
      put_Line(OUTF,"");

      mergSort(sortObj);  -- calling mergSort
      put_line("");
   put_line(OUTF,"");
   put("After merging first and second array using merge sort");
              put_Line("");
             put_Line(OUTF,"");
               put(OUTF,"After merging first and second array using merge sort");
  put_Line(OUTF,"");
    printArrayMergSort(sortObj.inpArr3, sortObj.array3Size);
          put_Line("");
          put_Line(OUTF,"");
       key := sortObj.target;
    -- put(key);
         left := 1 ;
     right := sortObj.array3Size;
      bsIndex := binarySearch(sortObj.inpArr3,key, left,right);  -- calling mergSort
      -- put( bsIndex);
      put_line("");
   put_line(OUTF,"");
   if (bsIndex = -1) then

         put("The target value ");
         put(INTEGER'Image(key));
         put(" not found");
   put_Line("");
         put(OUTF,"The target value " );
         put(OUTF, INTEGER'Image(key));
         put(OUTF," not found");
   put_Line(OUTF,"");

   else

     put("The target value ");
         put( INTEGER'Image(key));
         put(" found at index ");
         put(INTEGER'Image(bsIndex));

    put(OUTF,"The target value " );
         put(OUTF, INTEGER'Image(key));
         put(OUTF," found at index ");
    put_Line(OUTF,INTEGER'Image( bsIndex));

      end if;
        put_Line("");
      put_Line(outf,"");
       put_Line("Program completed");
      put_Line(outf,"Program completed");
       put_Line("");
      put_Line(outf,"");

 Ada.Text_IO.Close (File => OUTF);

        -- Close(fout);
   end sortingArray;

-- FUNCTION readInputFile
-- DESCRIPTION : This function read the input file.
 --INPUT ARGS  : String filename



    procedure ReadInputFile(inputFileName:Unbounded_String) is

   begin

      Ada.Text_IO.Open (File => Input_File, Mode => Ada.Text_IO.In_File, Name =>To_String(inputFileName));
   CREATE ( OUTF,NAME => "output.txt");
   while not End_OF_File (Input_File) loop
      Ada.Text_IO.Get_Line (Input_File, LINE,LINE_LENGTH);

      if LINE_LENGTH = 0  then
        goto i10 ;
      end if;

      sortobj.InpArr1(i) := Integer'Value(LINE(1..LINE_LENGTH));

      i := i +1;
      sortobj.array1Size := sortobj.array1Size +1;



   end loop;

   <<i10>>
    put_Line("");
                put_Line(OUTF,"");
              put("The first array: ");
                put(OUTF,"The first array: ");
                  put_Line("");
                  put_Line(OUTF,"");
   printArray(sortobj.InpArr1,sortobj.array1Size);
   put_line("");
   put_line(OUTF,"");
   i := 1;
   while not End_OF_File (Input_File) loop
      Ada.Text_IO.Get_Line (Input_File, LINE,LINE_LENGTH);

      if LINE_LENGTH = 0  then
        goto i11 ;
      end if;

      sortobj.InpArr2(i) := Integer'Value(LINE(1..LINE_LENGTH));

      i := i +1;
      sortobj.array2Size := sortobj.array2Size +1;



   end loop;
   <<i11>>
    put_Line("");
                put_Line(OUTF,"");
              put("The Second array: ");
                put(OUTF,"The second array: ");
                  put_Line("");
                  put_Line(OUTF,"");
   printArray(sortobj.InpArr2,sortobj.array2Size);
   put_line("");
   put_line(OUTF,"");
   put_line("");
   put_line(OUTF,"");
   Ada.Text_IO.Get_Line (Input_File, LINE,LINE_LENGTH);
   sortobj.target := Integer'Value(LINE(1..LINE_LENGTH));
    put("The Index: ");
   PUT(INTEGER'Image(sortobj.target));
   put_line("");

   put(OUTF,"The Index: ");
   put_line(OUTF,INTEGER'Image(sortobj.target));
    put_line(OUTF,"");




        end ReadInputFile;
-- main begin
begin

    if Argument_Count = 0 then
      put_Line("Please enter the file name");
     inputFile := get_Line;
      -- inputFile := To_Unbounded_String(inputFile1);
     -- put(Argument(1));
      else
      inputFile := To_Unbounded_String(Argument(1));
      end if;
   i := 1;
 ReadInputFile(inputFile);



   Ada.Text_IO.Close (File => Input_File);
   sortingArray(sortObj);
-- end main

end main;
