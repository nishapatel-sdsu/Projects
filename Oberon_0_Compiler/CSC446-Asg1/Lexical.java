

import java.io.IOException;
import java.io.Reader;
import java.io.StreamTokenizer;

/**
 * Given a java.io.Reader,the Tokenizer reads a stream from it and returns a
 * series of tokens.
 * 
 * 
 * @author Nisha
 * @version February 1,2013
 */

public class Lexical {
	 private StreamTokenizer streamTokenizer;
	 private boolean         pastEndOfInput = false;
	 private String[]        keywords       = { "BEGIN", "MODULE", "PROCEDURE", "VAR", "IF", "THEN", 
			 "ELSE", "ELSIF", "WHILE", "DO", "ARRAY", "RECORD", "CONST", "TYPE", "INTEGER", "REAL", 
			 "CHAR", "END" };
	private char[] validSymbols = { '(', ')','{','}', '[',']', ',', ':', ';', '.','\'', '~','"'};
	 
	 
	 /**
	     * Constructor for Lexical. Sets the string or file to be tokenized.
	     * 
	     * @param reader
	     *            The input to be tokenized.
	     */
	 public Lexical(Reader reader) {
		 streamTokenizer = new StreamTokenizer(reader);
		 streamTokenizer.ordinaryChar('/');
		 streamTokenizer.ordinaryChar('.');
		
		 
	 }
	 /**
	     * Method to display output.
	     * 
	     * @param word
	     *            The input is Token.
	     * 
	     */
	 
	 public void displayOutput(Token token){
		 System.out.format("%2s%10s%15s%20s", token.getLinenum(), token.getType(), token.getLexeme(),token.getValue());
	     System.out.println();
		 //	 System.out.println(token.getLinenum() + "   " + token.getType() +  "   " + token.getLexeme()+ "   " + token.getValue());
		 
	 }
	 
	 /**
	     * Method to determine whether a word is a keyword.
	     * 
	     * @param word
	     *            The word to be checked whether it is a keyword.
	     * @return true if the word is a keyword.
	     */

	    private boolean isKeyword(String word) {
	        for (String keyword : keywords)
	            if (keyword.equals(word))
	                return true;
	        return false;
	    }
	    /**
	     * Method to determine whether a symbol is valid.
	     * 
	     * @param word
	     *            The symbol to be checked whether it valid symbol.
	     * @return true if the symbol is valid.
	     */
	    private boolean isValidSymbol(char symbol) {
	        for (char sym : validSymbols)
	            if (sym == symbol)
	                return true;
	        return false;
	    }
	    /**
	     * Method to determine whether there are more tokens left in the input.
	     * Returns <code>true</code> up till that the EOF token is returned. After
	     * that, returns <code>false</code>
	     * 
	     * 
	     * @return True if there are one or more tokens to be returned.
	     */
	    public boolean hasNext() {
	        return !pastEndOfInput;
	    }


/**
 * Method to return the next token from the input(string or file) Returns
 * the next token.The last "valid" token returned will be an EOF token.
 * Further one or more calls will result in an ERROR token.
 * 
 * @return The next token.
 */

public Token getNextToken() {
	
	 

    if (pastEndOfInput) {
    return new Token(TokenType.ERROR, "Error","Error",streamTokenizer.lineno());
    }

    try {
    streamTokenizer.nextToken();
    } catch (IOException ioe) {
    System.out.println("Error :" + ioe);

    }

   
    
    switch (streamTokenizer.ttype) {

        case StreamTokenizer.TT_WORD:
            if (isKeyword(streamTokenizer.sval))
                return new Token(TokenType.RESWORD, streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());
            else if(streamTokenizer.sval.equals("OR")) {
                	return new Token(TokenType.ADDOP, streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());
                  }
                else if (streamTokenizer.sval.equals("DIV") || streamTokenizer.sval.equals("MOD")  || streamTokenizer.sval.equals("AND")){
                	return new Token(TokenType.MULOP, streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());
                }
            	
                else return new Token(TokenType.ID, streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());
            

        case StreamTokenizer.TT_NUMBER:
        	if(Double.toString(streamTokenizer.nval).endsWith(".0"))  {
        	    int val = (int)streamTokenizer.nval;
        	    
        		return new Token(TokenType.NUMBER, val + "",val  + "",streamTokenizer.lineno());
        	}
        		return new Token(TokenType.NUMBER, streamTokenizer.nval + "",streamTokenizer.nval + "",streamTokenizer.lineno());

        case StreamTokenizer.TT_EOL:
            return new Token(TokenType.EOL, "\n","\n",streamTokenizer.lineno());

        case StreamTokenizer.TT_EOF:
            pastEndOfInput = true;
            return new Token(TokenType.EOF, "","",streamTokenizer.lineno());
            
        case '"' :
        	return new Token(TokenType.LITERAL,streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());

        case '\'' :
        	return new Token(TokenType.LITERAL,streamTokenizer.sval,streamTokenizer.sval,streamTokenizer.lineno());

        default:
        	
            return evalSymbolToken((char) streamTokenizer.ttype);

    }
    
}

/**
 * Method to  evaluate the symbol Token.It also Remove the Comment.
 * 
 * @return The  token for the symbol.
 */
private Token  evalSymbolToken(char symbol){
		
	if(symbol == '>' || symbol == '<' || symbol == ':') {
		  try {
			streamTokenizer.nextToken();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		  
		  if((char) streamTokenizer.ttype == '='){
			  if(symbol == ':') return new Token(TokenType.ASSIGNOP, symbol+"=" + "",symbol+"=",streamTokenizer.lineno());
			  else return new Token(TokenType.MULOP, symbol+"=" + "",symbol+"=",streamTokenizer.lineno());
			    
		  }
		  else {
			  streamTokenizer.pushBack();
			   return new Token(TokenType.MULOP, symbol+"" ,symbol+"",streamTokenizer.lineno());
		  }
	}
	/**
	 * evaluate the  Comment. */
	
	/*
	if(symbol == '(') {
		 try {
				streamTokenizer.nextToken();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			  
			  if((char) streamTokenizer.ttype == '*'){
				 
				  while(true){
				  try {
					    streamTokenizer.nextToken();
					    if((char) streamTokenizer.ttype == '*') {
					    	streamTokenizer.nextToken();
					    	 if((char) streamTokenizer.ttype == ')') {
					    		 break;
					    	 }
					    }
					    } catch (IOException ioe) {
					    System.out.println("Error :" + ioe);

					    }
				  }
				  return getNextToken();
			  }
			  else {
				  streamTokenizer.pushBack();
				  return new Token(TokenType.SYMBOL, "(", "(",streamTokenizer.lineno());
			  }
		
	   }
	*/
	
	int count = 0;
		if (symbol == '(') {

			if (isStartOfComment()) {
				count++;
				while (true) {
					try {
						streamTokenizer.nextToken();
					} catch (IOException e) {
						e.printStackTrace();
					}
					if (((char) streamTokenizer.ttype) == '*') {
						if (isEndOfComment()) {
							count--;
							if (count == 0)
								break;
						try {
							streamTokenizer.nextToken();
						} catch (IOException e) {
							e.printStackTrace();
						}
						}
					}
					if (((char) streamTokenizer.ttype) == '(')
						if (isStartOfComment())
							count++;

					

				}
				return getNextToken();

			} else {
		 return new Token(TokenType.SYMBOL, "(", "(",streamTokenizer.lineno());
	}
	
	}
	
	
	if(symbol == '+' || symbol == '-' )
		return new Token(TokenType.ADDOP, (char) streamTokenizer.ttype + "",(char) streamTokenizer.ttype + "",streamTokenizer.lineno());
	
	if(symbol == '*' || symbol == '/' )
	   return new Token(TokenType.MULOP, (char) streamTokenizer.ttype + "",(char) streamTokenizer.ttype + "",streamTokenizer.lineno());
	
	if(symbol == '=' || symbol == '#')
		   return new Token(TokenType.MULOP, (char) streamTokenizer.ttype + "",(char) streamTokenizer.ttype + "",streamTokenizer.lineno());
    
	
	if(isValidSymbol(symbol))
	return new Token(TokenType.SYMBOL, (char) streamTokenizer.ttype + "",(char) streamTokenizer.ttype + "",streamTokenizer.lineno());
	else return new Token(TokenType.ERROR, (char) streamTokenizer.ttype + "",(char) streamTokenizer.ttype + "",streamTokenizer.lineno());
}
/**
 * Method to check start of a comment 
 * 
 * @return True or False
 */
 private boolean isStartOfComment(){
	
		 try {
				streamTokenizer.nextToken();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			  
			  if((char) streamTokenizer.ttype == '*'){
				return true; 
	          }
			  
			  else {
				  streamTokenizer.pushBack();
				  return false;
			  }
	 
	
 }
 /**
 * Method to check End of a comment 
 * 
 * @return True or False
 */

 private boolean isEndOfComment(){
	
		 try {
				streamTokenizer.nextToken();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			  
			  if((char) streamTokenizer.ttype == ')'){
				return true; 
	          }
			  
			  else {
				  streamTokenizer.pushBack();
				  return false;
			  }
	
 }

 
 }



