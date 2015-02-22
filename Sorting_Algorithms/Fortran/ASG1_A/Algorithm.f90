! NAME       : NISHA PATEL
! CLASS      : CSc 710
!ASSIGNMENT : Asg 1_A Fortran
! DUE DATE   : 09/11/2012
! INSTRUCTOR : Dr.Shin




! This function read the the input file

Subroutine readInputFile(filename,maxsize,inpArr1,inpArr2,array1Size,array2Size,target)
integer :: line
character (LEN =10) :: fileName
integer  :: maxsize
integer ::array1Size
integer ::array2Size
integer ::array3Size
integer , Dimension (maxsize) :: inpArr1
integer , Dimension (maxsize) :: inpArr2
integer , Dimension (2*maxsize) :: inpArr3
integer :: target




 do i = 1,maxsize
open(unit = 10, file = filename)
 read(10 ,*,end=20) line
 if(line == -1) then
exit
 end if
inpArr1(i) = line
 array1Size = array1Size +1
!write (*, *)  '<',inpArr1(i), '>'

end do


20 do i = 1,maxsize
open(unit = 10, file = filename)
 read(10 ,*,end=40) line
 if(line == -1) then
exit
 end if
 inpArr2(i) = line
 array2Size = array2Size +1
!write (*, *)  '<',inpArr2(i), '>'

end do
40 read(10 ,*,end=60) target

 60 close(10)


return
 end Subroutine readInputFile

!This Subroutine print the array

Subroutine printArray(inpArray,count)
integer , Dimension (*) :: inpArray
!integer  :: maxsize
integer ::count
integer ::i

 ! write(*, *)  '['

 write (*,*) '[', (inpArray(i), i= 1,count), ']'
 write(*,*)
write(*,*)
write (70,*) '[', (inpArray(i), i= 1,count), ']'
 write(70,*)
write(70,*)
     !  do i = 1,count
    ! write(*, *)  inpArray(i)


     ! end do
!        write(*, *) ']'
 return
 end Subroutine printArray

! This insertionSort Subroutine sort the element from array 1

Subroutine insertionSort(arrayList,lastIndex)
integer , Dimension (*) :: arrayList
integer ::lastIndex
integer ::currVal = 2
integer ::temVal = 0
integer ::currentIndex = 1



         do while(currVal <=lastIndex)


            temVal = arrayList(currVal);
             currentIndex = currVal-1;
            do  while ((currentIndex >= 0 ).and. (temVal < arrayList(currentIndex)))

                 arrayList(currentIndex +1) = arrayList(currentIndex);
                 currentIndex =  currentIndex -1;

                end do
             arrayList(currentIndex +1) = temVal;
             currVal = currVal +1;
            end do


 return
 end Subroutine insertionSort
! This selectionSort Subroutine sort the element from array 2
 Subroutine selectionSort(arrayList,lastIndex)


 integer , Dimension (*) :: arrayList
integer ::lastIndex
integer ::currVal = 1
integer ::smallVal = 0
integer ::temVal = 0
integer ::swapVal = 0

do while( currVal < lastIndex )


              smallVal = currVal;

              tempVal = currVal +1;
      do while (tempVal <=lastIndex)


          if (arrayList(tempVal) < arrayList(smallVal) )then

             smallVal = tempVal;
            end if
           tempVal =  tempVal+ 1;
       end do
              swapVal =arrayList(currVal);
              arrayList(currVal) =arrayList(smallVal);
              arrayList(smallVal) = swapVal;
              currVal = currVal +1;
 end do

return
 end Subroutine selectionSort
!This Subroutine  mergr element from from array 1 and array 2.
!Then it store the megre element  in array 3.
 Subroutine mergSort(inpArr1,inpArr2,inpArr3,array1Size,array2Size,array3Size,maxsize)

integer  :: maxsize
integer ::array1Size
integer ::array2Size
integer ::array3Size
integer ::i =1
integer ::j =1
integer ::k =0
integer ::l =0
integer ::maxarray3Size
integer , Dimension (*) :: inpArr1
integer , Dimension (*) :: inpArr2
integer , Dimension (*) :: inpArr3
integer , Dimension (maxsize +1) :: tempArray1
integer , Dimension (maxsize +1) :: tempArray2

       do l = 1 , array1Size


              tempArray1(l) = inpArr1(l)

              end do
          do l = 1 , array2Size

              tempArray2(l) = inpArr2(l)
             end do;

         tempArray1(array1Size +1) = 1000

          tempArray2(array2Size +1) = 1000

          maxarray3Size = array1Size + array2Size

                 k =1

           do while  (k <= maxarray3Size)


             if (tempArray1(i) < tempArray2(j)) then

                 if (inpArr3(k-1) == tempArray1(i)) then

                     maxarray3Size = maxarray3Size -1;
                     k = k-1;
                     i = i +1;


                 else

                 inpArr3(k) = tempArray1(i);
                i = i +1;
                array3Size = array3Size + 1;

              end if
             else if (tempArray1(i) == tempArray2(j)) then

                  if (inpArr3(k-1) == tempArray1(i)) then

                       maxarray3Size =  maxarray3Size- 1;
                      k = k-1;
                   i = i +1;
                   j = j +1;


                  else

                 inpArr3(k) = tempArray1(i);
                   i = i +1;
                   j = j +1;
                   array3Size = array3Size + 1;

                  maxarray3Size =  maxarray3Size- 1;
                 end if

             else

                 if (inpArr3(k-1) == tempArray2(j)) then

                    maxarray3Size =  maxarray3Size- 1;
                      k = k-1;
                      j = j +1;

                 else

                 inpArr3(k) = tempArray2(j);
                  j = j +1;
                 array3Size = array3Size + 1;
                 end if


              end if
               k = k+ 1;
end do

  return
 end Subroutine mergSort
!This function is used to serch value in the  binary  search tree
!Return the  search  value.
 Recursive subroutine binarySearch(inpArr3,key, left,right,res)
integer  :: key
integer ::left
integer ::right
integer ::m =0
integer :: res
integer , Dimension (*) :: inpArr3

            m  = INT((left + right)/ 2)
            if (left > right) then

            res = -1

           else if (inpArr3(m) == key) then

                  res =  m


            else if (key < inpArr3(m)) then

                 call binarySearch(inpArr3, key, left, m-1,res)


            else

                 call binarySearch(inpArr3, key, m+1, right,res)
               end if

  return
 end subroutine binarySearch

!This function use to call all sorting Subroutine.
Subroutine  sortingArray(inpArr1,inpArr2,inpArr3,array1Size,array2Size,array3Size,maxsize,target)
integer ::array1Size
integer ::array2Size
integer ::array3Size
integer  :: maxsize
integer :: target
integer :: bsIndex = -1
integer , Dimension (*) :: inpArr1
integer , Dimension (*) :: inpArr2
integer , Dimension (*) :: inpArr3
integer :: out_unit = 70

open (unit=out_unit,file="output.txt",action="write",status="replace")

write (*, *) "Asg1_A Fortran program started"
write (out_unit, *) "Asg1_A Fortran program started"
write (*, *)
write (out_unit, *)



write (*, *) "The first array:"
write (out_unit, *) "The first array:"
write (*, *)
write (out_unit, *)
call printArray(inpArr1,array1Size)
write (*, *) "The second array:"
write (out_unit, *) "The second array:"
write (*, *)
write (out_unit, *)
call printArray(inpArr2,array2Size)
call insertionSort(inpArr1,array1Size)
write(*,*)'After sorting first array using insertion sort'
write (out_unit, *) "After sorting first array using insertion sort"
call printArray(inpArr1,array1Size)
call  selectionSort(inpArr2,array2Size)

write(*,*)'After sorting second array using selection sort'
write (out_unit, *) "After sorting second array using selection sort"
call printArray(inpArr2,array2Size)
call mergSort(inpArr1,inpArr2,inpArr3,array1Size,array2Size,array3Size,maxsize)
write(*,*) 'After merging first and second array using merge sort'
write (out_unit, *) "After merging first and second array using merge sort"


call printArray(inpArr3,array3Size)
call binarySearch(inpArr3,target, 1,array3Size,bsIndex)

  if(bsIndex == -1) then
      write(*,*) 'The target value ',target,' was not found'
       write(out_unit,*) 'The target value ',target,' was not found'

 else

    write(*,*)  'The target value ',target   ,' found at index '  ,bsIndex
    write(out_unit,*)  'The target value ',target   ,' found at index '  ,bsIndex
 end if



   return
 end subroutine sortingArray
