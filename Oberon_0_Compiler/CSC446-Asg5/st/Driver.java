package st;

import analyzer.TokenType;

public class Driver {

	public static void main (String args[]) {
	String lexeme1 = "hell";
	TokenType tokenType = TokenType.ID;
	SymbolTable symbolTable = new SymbolTable();
	symbolTable.insert(lexeme1,tokenType,0);
	
	
	 String lexeme2 = "if";
	 tokenType = TokenType.RESWORD;
	 symbolTable.insert(lexeme2,tokenType,0);
	 
	 String lexeme3 = "else";
	 tokenType = TokenType.RESWORD;
	 symbolTable.insert(lexeme3,tokenType,1);
	
	
	TableEntry entry = symbolTable.lookup(lexeme1);
	
	if(entry != null) {
		System.out.println("Look up successfull");
		System.out.println("Lookup Lexeme " + entry.getLexeme());
		System.out.println("Lookup Lexeme Token Type " + entry.getTokenType());
		
	}
	
	System.out.println("-------------  Write Table -------------");
	symbolTable.writeTable(0);
	System.out.println("----------------------------------------");
	
	
	
	symbolTable.deleteDepth(1);
	TableEntry entry2 = symbolTable.lookup(lexeme1);
	if(entry2 != null) {
		System.out.println("Look up successfull");
		System.out.println("Lookup Lexeme " + entry2.getLexeme());
		System.out.println("Lookup Lexeme Token Type " + entry2.getTokenType());
		
	}
	else {
		System.out.println("Could not find the token");
	}
	
	System.out.println("-------------  Write Table -------------");
	symbolTable.writeTable(0);
	symbolTable.writeTable(1);
	System.out.println("----------------------------------------");
	}
}
