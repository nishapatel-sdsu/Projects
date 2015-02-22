! NAME       : NISHA PATEL
! CLASS      : CSc 710
!ASSIGNMENT : Asg 1_A Fortran
! DUE DATE   : 09/11/2012
! INSTRUCTOR : Dr.Shin


! Main function
 program main
 USE recordDf
    implicit none

!Type (Stack) , Target :: stackobj
!Type (Stack) , Pointer :: stackobjPtr
logical :: success = .false.
character (LEN =200) :: newdata = "a"
integer :: args
character (LEN =10) :: fileName



args = command_argument_count()
call get_command_argument(1,fileName)
if(args == 0) then

write (*, *) 'Please enter the file name'
read(*,*) fileName
end if

call processInputFile(fileName)
end program main
