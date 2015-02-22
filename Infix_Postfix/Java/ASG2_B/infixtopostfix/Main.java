
/********************************************************************
 Compiler : Java compiler
IDE : Eclipse

Part1:
Folder : ASG2_B
Main File : Main.java
Run : 

1.Copy the folder CSc710Asg2 on local computer which has java installed. 

2.Open a command prompt. 

3.Go to folder CSc710Asg2/Java/ASG2_B/infixtopostfix/

c:/CSc710Asg2/Java/ASG2_B/infixtopostfix/

4. Compile using javac *.java

5. Go one folder level up to ASG2_B

c:/CSc710Asg2/Java/ASG2_B

6. Provide the input file input.txt in ASG2_B folder

Run the Main propgram using java infixtopostfix..Main

Enter input file : input.txt
Alternatively you can also run the program as  : infixtopostfix..Main input.txt
Output : After running the program output would be shown on the screen as well in output.txt 

 ********************************************************************/





/********************************************************************
 *** NAME       : NISHA PATEL                                      
 *** CLASS      : CSc 710                                          
 *** ASSIGNMENT : Asg2_B  Java                                        
 *** DUE DATE   : 09/23/2012                                       
 *** INSTRUCTOR : Dr.Shin                                          
 *********************************************************************
 *** DESCRIPTION :This is the main function. This function call 
                   processInputFile function.
 ********************************************************************/


package infixtopostfix;

import java.io.IOException;
import java.util.Scanner;



public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		String inputFilename = "";
	
		
	//	StringBuilder newtemp = new StringBuilder ();
		
		Infixtopostfix infix = new Infixtopostfix();
        
		    
		    //Read the name of the expression file.
		    if(args.length == 0){
		        System.out.println("Please enter the file name");
		     
		        Scanner sc = new Scanner(System.in);
		        inputFilename = sc.nextLine();
		        }
		    else{
		        inputFilename = args[0] ;
		        }
		     
		    try {
				infix.processInputFile(inputFilename);// calling processInputFile
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				System.exit(0);
			}// reading input file 
		// TODO Auto-generated method stub
		   	}

}
