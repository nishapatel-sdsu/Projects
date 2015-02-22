
/********************************************************************
 Compiler : Microsft Visual Studio C# compiler
IDE : Microsfy Visual Studio

Part1:
Folder : ASG2_A
Main File : Main.cs

Run : Create the project in Visual Studio. Import the source files. Create input file. Run the program. 

Output : After running the program output would be shown on the screen as well in output.txt 

Input:
The input can be specified in a file eg: input.txt. Please see the input.txt for the structure of the input file. 
The file starts with the first array. Each line lists one array value. After the last value of the first 
array there is an empty line.The empty line is used to seperate the two arrays. The second array starts 
after the empty line. Each value of the second array is 
also specified on a seperate line without any empty line between the values.After the last value of the second array there is an empty line. 
The target value is written after the empty line.The empty line is used to seperate the target from the array values.


 ********************************************************************/


/********************************************************************
 *** NAME       : NISHA PATEL                                      
 *** CLASS      : CSc 710                                          
 *** ASSIGNMENT : Asg2_A  C#                                       
 *** DUE DATE   : 09/23/2012                                       
 *** INSTRUCTOR : Dr.Shin                                          
 *********************************************************************
 *** DESCRIPTION :This is the main function. This function call 
                  readInputFile function.
 ********************************************************************/

using System;
using Algorithm;

namespace Main_NEW{



 public class main
    {
static void Main(string[] args)
{
  Sort sort = new Sort();
    string inputFilename = "";
		

		    
		    //Read the name of the expression file.
		    if(args.Length ==  0){
		         Console.WriteLine("Please enter the file name");
		     
		                        inputFilename = Console.ReadLine();
		        }
		    else{
		        inputFilename = args[0] ;
             
		        }
          // Console.WriteLine(inputFilename);  
            sort.readInputFile(inputFilename);// calling readInputFile function

            sort.sortingArray();  // calling sortingArray function.
            Console.ReadLine();
   
}
  
}
}