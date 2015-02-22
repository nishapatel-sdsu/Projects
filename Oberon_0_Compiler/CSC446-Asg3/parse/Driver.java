package parse;

import java.io.FileNotFoundException;
import java.io.FileReader;

import analyzer.Token;
import analyzer.TokenType;

/**
 * This is the Driver Function.It read the file and call Parser prog method to
 * parse the program.
 * 
 * @author Nisha Patel Date : 02/14/2013
 */
public class Driver {

	public static void main(String args[]) {

		RecDescParser parser = null;
		try {
			parser = new RecDescParser(new FileReader(args[0]));// open the file
            //Gets the First Token
			parser.getNextToken();
            
			parser.prog();
			Token lastToken = parser.getCurToken();
			if (lastToken.getType() == TokenType.EOF)
				System.out.println("Success: The program parsed successfully");
			else
				System.out.println("Failure: End of File not reached");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (RuntimeException e) {
			System.out.println(e.getLocalizedMessage());
		}

	}
}
