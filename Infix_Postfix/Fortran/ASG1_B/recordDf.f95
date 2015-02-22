! NAME       : NISHA PATEL
! CLASS      : CSc 710
!ASSIGNMENT : Asg 1_B Fortran
! DUE DATE   : 09/11/2012
! INSTRUCTOR : Dr.Shin


module recordDf
! record for node
Type Node
    character (LEN =200) :: data
    Type ( Node ) , Pointer :: next => NULL()
     end Type Node
! record for stack
    Type Stack
    integer :: count = 0
   Type ( Node ) , Pointer :: top => NULL()
    end Type Stack


contains


! This function check the pirority of the operator
integer  function  prority(c)

!integer :: pror
character  (*) :: c

    if(( c == '+') .OR. (c == '-')) then

        prority = 1

    else if((c == '*') .OR. (c == '/')) then

         prority = 2
     else

      prority = -1
    end if

    return
 end function  prority

!This function determines if a stack is empty
 logical function   emptystack(stackObjPtr)


 Type ( Stack ) , Target :: stackObjPtr

!logical :: success

 if  (stackObjPtr%count == 0)then
     emptystack = .true.

 else

         emptystack = .false.
    end if


return
end function emptystack
! This function check the operator
 integer function operatorf(c)

!integer :: status
character (*) :: c

    if ((c  == '+') .OR. (c  == '*' ) .OR. (c  == '-' ) .OR. (c == '/')) then

      operatorf = 1

    else
        operatorf = 0
    end if

return
 end function operatorf


! This Subroutine convert the infix string to postfix string
Subroutine infixtopostfix(formula1,infixpostfix)

Type ( Stack ) , Pointer :: mystack
  character (*) :: formula1
  character (LEN =200) :: infixpostfix
 character (LEN = 200) :: postfix
 character  :: token
 character :: tokenout
 character  :: toptoken

  integer ::valLoop
  integer ::tempvalLoop
  integer :: fomLen
  logical :: success

allocate(mystack)
mystack%count = 0
mystack%top =>  NUll()

! mystack := nil
success = .false.
 postfix = ""
 valLoop = 0

 tokenout = ''
toptoken = ''

fomLen = len_trim(formula1)

   write(*,*)'The formula1 length is ',fomLen
  do  valLoop = 1 ,  fomLen
      tempvalLoop = valLoop +1
        token = formula1(valLoop : valLoop)
        if (token == " ") then
            Cycle
    end if
  !check it is open parenthesis
        if (token  == '(') then
          ! write(*,*) "Inside open paranthesis"
           call pushstack(token,mystack,success)
     ! call    printStack(mystack)
        ! check it is close parenthesis }
        else if (token == ')' ) then
      !  write(*,*) "Inside close paranthesis"

        call popstack(token,mystack,success)
        ! write(*,*) token
           do  while ( .not.(trim(token) ==  '('))
       !   write(*,*) token

      !     write(*,*) "Inside while close paranthesis"

                 postfix =  trim(postfix) // token
           call popstack(token,mystack,success)
            end do
     !write(*,*) "outside  while close paranthesis"


        else if (operatorf(token(1:1)) == 1) then
              call stacktop(toptoken,mystack,success)
            do while ((.not.(emptystack(mystack))) .and. (prority(token(1:1)) <= prority(toptoken(1:1))))



                        call popstack(tokenout,mystack,success)
                        postfix =  trim(postfix) //  tokenout
                           call stacktop(toptoken,mystack,success)


                            end do

                       call pushstack(token,mystack,success)


              else

                  postfix =  trim(postfix) //  token
         end if
       !  write(*,*) "Postfix ", postfix

        end do


    do while (.not.(emptystack(mystack)))

        call popstack(token,mystack,success)
                 postfix =  trim(postfix) //  token

     end do
    infixpostfix =  trim(postfix)


return
 end Subroutine infixtopostfix



! This function calculate the value
integer function calculate(operand1 ,operatorc,operand2)


character :: operatorc
character (*) :: operand1
character (*) :: operand2
integer :: opera1 = 0
integer :: opera2 = 0

 calculate = 0
read (operand1,*) opera1

read (operand2,*) opera2


    if (operatorc  == '+') then

        calculate = (opera1 + opera2)


 else if (operatorc == '-' )then

       calculate = (opera1 - opera2)


 else if (operatorc == '*' )then

       calculate = (opera1 * opera2)


 else if (operatorc =='/') then

       if (opera2 == 0)then

           calculate =  0

       else

            calculate = INT(opera1 / opera2)

           end if
      end if

 return
 end function calculate


! This function convert the evaluate  postfix string
integer function postfixtoevaluate(exp)
Type ( Stack ) , Pointer :: mystack
character (*) :: exp
character (Len = 200) :: tempresult
character (Len = 200) :: operand1
character (Len =200) :: operand2
!character (Len =200) :: operand2
character (Len =200) :: svalue
character  :: ctoken
integer :: exprsize
integer :: value
integer :: finalresult
integer :: index
logical :: success

Allocate(mystack)
mystack%count = 0
mystack%top =>  NUll()
  index = 1
   finalresult = 0
   value = 0
   tempresult = ''
   !stoken = ''
   operand2 = ''
   operand1 = ''
   svalue = ''
   success = .false.

      exprsize = len_trim(exp)

      !check the expration size }
       do while (index <= exprsize)

             ctoken = exp(index:index)

            !{check operator is a token}

            if (operatorf(ctoken) == 1) then


                 call popstack(operand2,mystack,success)
               call popstack(operand1,mystack,success)
                 !call calculate function

                  value =  calculate(operand1, ctoken, operand2)
                      !Str(value, svalue);
                      write(svalue,'(i10)')value

           call pushstack(svalue,mystack,success)


           ! {check if it is a operand than push into a stack}

            else

               call pushstack(ctoken,mystack,success)

                end if
            index = index +1

            end do

       call popstack(tempresult,mystack,success)

       ! {convert final result string to integer}

        read (tempresult,*) finalresult

       postfixtoevaluate = finalresult

return
 end function postfixtoevaluate



!input file This function process the
Subroutine processInputFile(filename)
!integer :: i
character (LEN =50) :: line
character (LEN =200) :: infixpostfix
character (LEN =10) :: fileName
integer:: finresult
integer :: out_unit = 10

open (unit=out_unit,file="output.txt",action="write",status="replace")

write (*, *) "Asg1_B Fortran program started"
write (out_unit, *) "Asg1_B Fortran program started"
write (*, *)
write (out_unit, *)

do while(1 ==1)
open(unit = 40, file = filename)
 read(40 ,'(A)',end=20) line




write (*, *) , 'Infix notation : ', line
 write (out_unit,*)'Infix notation : ' ,line
call infixtopostfix(line,infixpostfix)
write (*, *)  "The postfix notation is: ", infixpostfix

write (out_unit, *)  "The postfix notation is: ", infixpostfix
!write (out_unit, *)
 finresult = postfixtoevaluate(infixpostfix)


  write (*, *) "The postfixevaluation is: ",finresult
  write (*, *)
   write (out_unit, *) "The postfixevaluation is: ",finresult
  write (out_unit, *)


end do

20 close(40)
write (*, *) "Program completed"
write (out_unit, *) "Program completed"
close(out_unit)
return
 end Subroutine processInputFile








end module recordDf
