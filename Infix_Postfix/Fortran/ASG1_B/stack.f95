! NAME       : NISHA PATEL
! CLASS      : CSc 710
!ASSIGNMENT : Asg 1_B Fortran
! DUE DATE   : 09/11/2012
! INSTRUCTOR : Dr.Shin

! This function pushes an item onto the stack
Subroutine pushstack(datain,stackObjPtr,success)
 USE recordDf
  character (*) :: datain
   Type ( Stack ) , Target :: stackObjPtr
   Type ( Node ) , Pointer :: newptr
logical :: success
Allocate ( newptr )


success = .false.
    if (.not.(Associated(newptr))) then



    else
         newptr%data = datain
        newptr%next => stackObjPtr%top
            stackObjPtr%top => newptr
        stackObjPtr%count = stackObjPtr%count +1
                success = .true.
           end if


return
end Subroutine pushstack
!This function print the  stack
Subroutine printStack(stackObjPtr)
 USE recordDf


   Type ( Stack ) , Target :: stackObjPtr
   Type ( Node ) , Pointer :: temp


    temp => stackObjPtr%top
    write(*,*) 'Stack Contents: ['
  do  while(Associated(temp))

      write(*,*),temp%data, ' '
       temp => temp%next

end do
    write(*,*) ']'


return
end Subroutine printStack
!This function pop the item on the top of the stack
Subroutine  popstack(dataout,stackObjPtr,success)
USE recordDf

 character (*) :: dataout
   Type ( Stack ) , Target :: stackObjPtr
   Type ( Node ) , Pointer :: dltptr
logical :: success
!Allocate ( newptr )
success = .false.


    if  (stackObjPtr%count == 0)then

    else

        dltptr => stackObjPtr%top
        dataout = stackObjPtr%top%data
        stackObjPtr%top =>  stackObjPtr%top%next

               stackObjPtr%count = stackObjPtr%count -1
        Deallocate (dltptr)
             success = .true.

    end if


return
end Subroutine popstack
!This function retrieves the data from the top of the stack without changing the stack

Subroutine  stacktop(dataout,stackObjPtr,success)
USE recordDf

 character (*) :: dataout
   Type ( Stack ) , Target :: stackObjPtr
   !Type ( Node ) , Pointer :: dltptr
logical :: success
!Allocate ( newptr )
success = .false.


 if  (stackObjPtr%count == 0)then
     success = .false.
     else

       dataout = stackObjPtr%top%data
        success = .true.
   end if


return
end Subroutine stacktop



