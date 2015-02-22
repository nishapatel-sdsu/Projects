! NAME       : NISHA PATEL
! CLASS      : CSc 710
!ASSIGNMENT : Asg 1_B Fortran
! DUE DATE   : 09/11/2012
! INSTRUCTOR : Dr.Shin

! main function

program main
implicit none





integer , parameter :: maxsize = 30
integer ::array1Size = 0
integer ::array2Size = 0
integer ::array3Size = 0
integer , Dimension (maxsize) :: inpArr1
integer , Dimension (maxsize) :: inpArr2
integer , Dimension (2*maxsize) :: inpArr3
integer :: target = 0





integer :: args
character (LEN =10) :: fileName
args = command_argument_count()
call get_command_argument(1,fileName)
if(args == 0) then

write (*, *) 'Please enter the file name'
read(*,*) fileName
end if

!write (*, *) args
!write (*, *) fileName
! call input file
call readInputFile(filename,maxsize,inpArr1,inpArr2,array1Size,array2Size,target)
call sortingArray(inpArr1,inpArr2,inpArr3,array1Size,array2Size,array3Size,maxsize,target)

end program main


