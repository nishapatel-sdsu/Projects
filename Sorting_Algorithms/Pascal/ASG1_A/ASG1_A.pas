{/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg 1  Pascal                                          ***
 *** DUE DATE   : 09/11/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module implement  Insertion Sort , Selection Sort
  Merge sort and Binary search tree.
 ********************************************************************/}


program ASG1_A;

{$mode objfpc}{$H+}

uses
  sysutils,
  {$IFDEF UNIX}{$IFDEF UseCThreads}
  cthreads,
  {$ENDIF}{$ENDIF}
  Classes
  { you can add units after this };
const
   maxsize = 30;
   maxsize2 = 31;


type
  {This is create the record for sort}
     inpArr = array [1.. maxsize] of integer;
     inpArr2 = array [1.. 2 * maxsize] of integer;
     sortPtr = ^Sort;
     Sort = record
      array1Size : integer;
       array2Size : integer;
       array3Size : integer;

      inpArr1:  inpArr;
       inpArr2: inpArr;
       inpArr3: inpArr2;
         target: integer;

     end;

var
 {main function varible}
  inputFile: string;
  Fname: textfile;
  fout:   textfile;
  Data : string;
    i: integer;
    count : integer;
    sortObjectPtr : sortPtr;

 {/********************************************************************************
 *** FUNCTION PrintArray                                                   ***
 *********************************************************************************
 *** DESCRIPTION : This function print array element.                         ***
 *** INPUT ARGS  : integer, integer *                                         ***
 *** OUTPUT ARGS : None                                                        ***
 *** IN/OUT ARGS : -                                                           ***
 *** RETURN      : void                                                        ***
 *********************************************************************************/}

procedure printArray(var inputArr : inpArr ; count : integer );

    begin
          write('[');
      write(fout,'[');

        for i :=1  to count  do
                begin
            write(' ',inputArr[i]);
        write(fout,' ',inputArr[i]);


                end;
         writeln(']');
                     writeln(fout,']');

    end;
         {
          FUNCTION printArrayMergSort
          This fuction print the merge array
         }
procedure printArrayMergSort(var inputArr : inpArr2 ; count : integer );
begin
     write('[');
      write(fout,'[');

  for i :=1  to count  do
       begin
      write(' ',inputArr[i]);
  write(fout,' ',inputArr[i]);

    end;
     writeln(']');
    writeln(fout,']');

end;

   {
  FUNCTION readInputFile
   DESCRIPTION : This function read the input file
  INPUT ARGS  : string. sortptr
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : void
 }
   procedure ReadInputFile(inputFileName:string; sortObjPtr : sortPtr );

   var
        Num : integer;
        code:  integer;
          begin
          Num := 0;
          code := 0;
        {Reading file start }
        assignfile(Fname, inputFileName);
              Reset(Fname);
                assignfile(fout, 'output.txt');
               Rewrite(fout);
              for i:= 1 to maxsize do


        begin

              Readln(Fname,Data);
               if Length(Data) = 0  then
               Break;
               val(Data, Num,code);
              sortObjPtr^.inpArr1[i] :=  Num;
             sortObjPtr^.array1Size :=  sortObjPtr^.array1Size + 1;

        end;
              writeln();
                 writeln(fout,'');
              writeln('The first array: ');
                 writeln(fout,'The first array: ');
                 writeln();
                 writeln(fout,'');
           printArray(sortObjPtr^.inpArr1, sortObjPtr^.array1Size);
              for i:= 1 to maxsize do
               begin

              Readln(Fname,Data);
               if Length(Data) = 0  then
               Break;
               val(Data, Num,code);
              sortObjPtr^.inpArr2[i] :=    Num;
             sortObjPtr^.array2Size :=  sortObjPtr^.array2Size + 1;



        end;
               writeln();
                 writeln(fout,'');
              writeln('The second array: ');
                 writeln(fout,'The second array: ');
                 writeln();
                 writeln(fout,'');

                printArray(sortObjPtr^.inpArr2, sortObjPtr^.array2Size);
                Writeln;
                    Writeln(fout,'');
                       Readln(Fname,Data);
                       val(Data,  sortObjPtr^.target,code);

           Close(Fname);


           {file reading end here}
   end;

      {
  FUNCTION insertionSort
   DESCRIPTION : This function sort the element from array 1
  INPUT ARGS  : integer. arraylist
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : void
 }

procedure insertionSort(var arrayList : inpArr; lastIndex: integer );
         var

    currVal :integer;
    temVal :integer;
    currentIndex :integer;
        begin

         currVal := 2;
        temVal :=0;
         currentIndex :=1;
         while currVal <=lastIndex   do

             begin
            temVal := arrayList[currVal];
             currentIndex := currVal-1;
             while (currentIndex >= 0 )and (temVal < arrayList[currentIndex]) do
                 begin
                 arrayList[currentIndex +1] := arrayList[currentIndex];
                 currentIndex :=  currentIndex -1;

                end;
             arrayList[currentIndex +1] := temVal;
             currVal := currVal +1;
             end;

          end;
{
  FUNCTION selectionSort
   DESCRIPTION : This function sort the element from array 2
  INPUT ARGS  : integer. arraylist
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : void
 }


procedure selectionSort(var arrayList : inpArr; lastIndex: integer );

 var
      currVal :integer;
      smallVal :integer;
      tempVal:integer;
      swapVal :integer;

begin

     currVal := 1;
     smallVal := 0;
     tempVal := 0;
     swapVal :=0;
           while currVal < lastIndex   do

              begin
              smallVal := currVal;

              tempVal := currVal +1;
              while tempVal <=lastIndex  do
                  begin

                  if arrayList[tempVal] < arrayList[smallVal] then
                      begin
                      smallVal := tempVal;
                      end;
                tempVal :=  tempVal+ 1;
                  end;
              swapVal :=arrayList[currVal];
              arrayList[currVal] :=arrayList[smallVal];
              arrayList[smallVal] := swapVal;
              currVal := currVal +1;
              end;


 end;
{
  FUNCTION mergSort
   DESCRIPTION : This function  mergr element from from array 1 and array 2. ***
Then it store the megre element  in array 3.
  INPUT ARGS  : integer. arraylist
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : void
 }


procedure mergSort(sort : sortPtr; const tempsize : integer);

 type
   inpArr11 =     array [1.. maxsize2] of integer;
 var
      i :integer;
      j :integer;
      l:integer;
      k :integer;
      maxarray3Size :integer;

       tempArray1:  inpArr11;
       tempArray2 :inpArr11;

begin
       i :=1;
       j :=1;
       l :=0;
       k := 0;


          for l := 1 to sort^.array1Size do

              begin
              tempArray1[l] :=sort^.inpArr1[l];

              end;
          for l := 1  to sort^.array2Size do
              begin
              tempArray2[l] :=sort^.inpArr2[l];
             end;

         tempArray1[sort^.array1Size +1] := 1000;

          tempArray2[sort^.array2Size +1] := 1000;

          maxarray3Size := sort^.array1Size + sort^.array2Size;

                 k :=1;

            while  k <= maxarray3Size do
             begin

             if tempArray1[i] < tempArray2[j] then
                 begin
                 if sort^.inpArr3[k-1] =tempArray1[i] then
                     begin
                     maxarray3Size := maxarray3Size -1;
                     k := k-1;
                     i := i +1;
                     end
                 else
                begin

                 sort^.inpArr3[k] := tempArray1[i];
                i := i +1;
                sort^.array3Size := sort^.array3Size + 1;
                     end;
                 end
             else if tempArray1[i] = tempArray2[j] then
                 begin
                  if sort^.inpArr3[k-1] =tempArray1[i] then
                     begin
                       maxarray3Size :=  maxarray3Size- 1;
                      k := k-1;
                   i := i +1;
                   j := j +1;
                     end

                  else
                  begin
                 sort^.inpArr3[k] := tempArray1[i];
                   i := i +1;
                   j := j +1;
                   sort^.array3Size := sort^.array3Size + 1;

                  maxarray3Size :=  maxarray3Size- 1;
                 end;
                 end
             else
               begin
                 if sort^.inpArr3[k-1] = tempArray2[j] then
                     begin
                    maxarray3Size :=  maxarray3Size- 1;
                      k := k-1;
                      j := j +1;
                     end
                 else
                 begin
                 sort^.inpArr3[k] := tempArray2[j];
                  j := j +1;
                 sort^.array3Size := sort^.array3Size + 1;
                 end;
                 end;
                    k:= k+ 1;
             end;





    end;
{
  FUNCTION mergSort
   DESCRIPTION : This function is used to serch value in the binary  search tree
  INPUT ARGS  : integer key. arraylist, integert left, integer right
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : Return the  search  value.
 }

function binarySearch(var inpArr3:inpArr2; key :integer;left:integer;right:integer) :integer;
var
  m :  integer;
begin
            m := 0;
            m := (left + right)div 2;
            if left > right then
                begin
            binarySearch := -1;
                end
           else if inpArr3[m] = key then
                begin
                  binarySearch :=  m;
                end

            else if key < inpArr3[m] then
                begin
                 binarySearch := binarySearch(inpArr3, key, left, m-1);
                end
            else
                begin
                  binarySearch :=  binarySearch(inpArr3, key, m+1, right);
                end ;


    end;
  {
  FUNCTION sortingArray
   DESCRIPTION :  This function use to call all sorting function.
  INPUT ARGS  : sortptr
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      :
 }
   procedure sortingArray(sortObjPtr : sortPtr);
     var
      target : integer;
      bsIndex  : integer;
   begin

            insertionSort(sortObjPtr^.inpArr1, sortObjPtr^.array1Size);
            Writeln('After sorting first array using insertion sort');
              Writeln;
               Writeln(fout,'After sorting first array using insertion sort');
              Writeln(fout,'');

         printArray(sortObjPtr^.inpArr1, sortObjPtr^.array1Size);
                   Writeln;
                    Writeln(fout,'');
                selectionSort(sortObjPtr^.inpArr2, sortObjPtr^.array2Size);
                  Writeln('After sorting second array using selection sort');
              Writeln;
               Writeln(fout,'After sorting second array using selection sort');
              Writeln(fout,'');

         printArray(sortObjPtr^.inpArr2, sortObjPtr^.array2Size);
                 Writeln;
                    Writeln(fout,'');
          mergSort(sortObjPtr,sortObjPtr^.array1Size);
   Writeln('After merging first and second array using merge sort');
              Writeln;
               Writeln(fout,'After merging first and second array using merge sort');
              Writeln(fout,'');
    printArrayMergSort(sortObjPtr^.inpArr3, sortObjPtr^.array3Size);
          Writeln;
                    Writeln(fout,'');
     target := sortObjPtr^.target;
    bsIndex := binarySearch(sortObjPtr^.inpArr3,target , 1,sortObjPtr^.array3Size);
   if bsIndex = -1 then
   begin
   writeln('The target value ' ,target,' not found');
   writeln;
   writeln(fout,'The target value ' ,target,' not found');
   writeln(fout,'');
       end
   else
   begin
  writeln('The target value: ',target, ' found at index:  ',bsIndex);
  writeln;
  writeln(fout,'The target value: ',target, ' found at index:  ',bsIndex);
  writeln(fout,'');

      end;
         Close(fout);
          end;

     {
  FUNCTION main
   DESCRIPTION :  This function readinput file and sortingarray function
  INPUT ARGS  :
  OUTPUT ARGS : None
  IN/OUT ARGS : -
  RETURN      : None
 }

begin
      {Read the file Name}
     New(sortObjectPtr);
              sortObjectPtr^.array1Size:= 0;
               sortObjectPtr^.array2Size:=0;
                sortObjectPtr^.array3Size:=0;
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

         Writeln('FIle Name is: ' ,inputFile);
         ReadInputFile(inputFile,sortObjectPtr);
         sortingArray(sortObjectPtr);
      readln;
end.

