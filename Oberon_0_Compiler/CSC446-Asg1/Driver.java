
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
/**
 * This is the Driver Function.It is read the file and call the GetNextToken method.
 * It also call the Display Output Method.
 * 
 * @author Nisha
 * @version February 1,2013
 */ 
public class Driver {
	
	
	

	public static void main(String args[]) {
	
		Lexical lexical = null;
		try {
			lexical = new Lexical(new FileReader(args[0]));// open the file
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.format("%2s%10s%15s%20s", "Line" ,"Token","Lexeme","Value");
		System.out.println();
		
		while(lexical.hasNext()) {
		Token token = lexical.getNextToken();// call the GetNextToken Methode	
		lexical.displayOutput(token);//display the output
		}
		}
	}

