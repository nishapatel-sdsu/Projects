package analyzer;



/**
 * This class use to represent the Token.It also define the Various Token Types.
 * The token is represented by token Type,lexeme and its value.
 * 
 * 
 * @author Nisha 
 * @version February 1,2013
 */


//enum TokenType {
  // ID, RESWORD, NUMBER, RELOP, ADDOP,MULOP,ASSIGNOP,EOF,ERROR,EOL,LITERAL,SYMBOL
//}

/**
 * A Token has a type,value,lexeme and linenum. The value is a String containing the exact
 * characters that make up the Token. The type is a TokenType that tells what
 * kind of thing the Token represents--a variable, keyword, number, or symbol
 * (punctuation mark).lexeme represents actual character. linenum represents the line number of the each Token.
 */ 
public class Token {

	private TokenType type;
    private String    value;
    private String    lexeme;
    private int linenum;
    
    /**
     * constructor for the  Token class  */  


public Token(TokenType type, String value,String lexeme,int linenum) {
        this.type = type;
        this.value = value;
        if(lexeme.length() >15) lexeme = lexeme.substring(0,14);
        this.lexeme = lexeme;
        
        this.linenum = linenum;
    }

public Token(TokenType type, String value) {
    this.type = type;
    this.value = value;
   
}

/**
 * A getLinenum method 
 * 
 * @return Type of the linenum.
 */
	
	 public int getLinenum() {
			return linenum;
		}
	/**
     * A getter method for the Lexeme
     * 
     * @return Type of the lexeme.
     */
	public String getLexeme() {
		return lexeme;
	}

    /**
     * A getter method for the token's value
     * 
     * @return Type of the Token.
     */

    public TokenType getType() {
        return type;
    }

    /**
     * A getter method for the tokens value
     * 
     * @return Value of the Token
     */
    public String getValue() {
        return value;
    }
   
	
    @Override
    public boolean equals(Object object) {
        Token that = (Token) object;
        return this.type == that.type && this.value.equals(that.value);
    }

    @Override
    public String toString() {
        return linenum + ":" + value + ":" + type;
    }
}
