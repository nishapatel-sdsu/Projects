package st;
import analyzer.TokenType;
 

  /**
   * @author nisha04
   * Date : 03/09/2013
   * 
   * This class is used to create a symbol table to store the tokens
   */
  public class SymbolTable {
	  static final  int tableSize = 213;
	  TableEntry[] table = null;
	  
	  /**
	   * Constructor to create a Symbol Table
	   */
	  public SymbolTable () {
		  initializeSymbolTable();
	  }
	  
	  /**
	   * This method initializes the Symbol Table
	   */
	  public void initializeSymbolTable() {
		  table = new TableEntry[tableSize];
		  for(int i=0; i<tableSize; i++){
			  table[i] = null;
		  }
	  }
	  
	  /**
	   * This method is used to insert an Entry into Symbol Table
	   * 
	   * @param lexeme The lexeme value of the Table Entry
	   * @param tokenType The Token Type of the Table Entry
	   * @param depth The depth of the Table Entry
	   */
	  public void insert(String lexeme, TokenType tokenType,int depth){
		  int hashValue;
		  TableEntry temp = new TableEntry();
		  hashValue = hash(lexeme);
		  
		  if(table[hashValue] != null) {
			 temp.setNext(table[hashValue]);
		  }
		  temp.setLexeme(lexeme);
		  temp.setDepth(depth);
		  //temp.setOffset(offset);
		  temp.setTokenType(tokenType);
		  table[hashValue] = temp;
		  
	  }
	
	  /**
	   * This method is used to lookup a value in synbol table.
	   * 
	   * @param lex The lexeme to be searched
	   * @return Returns the Table Entry corresponding the given lexeme
	   */
	  public TableEntry lookup(String lex){
		  int hashVal = hash(lex);
		  TableEntry entry = table[hashVal];
		  while (entry != null) {
			  if(entry.getLexeme().equals(lex)) return entry;
			  else entry = entry.getNext();
		  }
		  return null;
	  }
	  
	  /**
	   * This method is used to delete the Table Entry at the specified depth
	   * 
	   * @param depth The depth at which the table entries are to be deleted
	   */
	  public void deleteDepth(int depth) {
		  for (int i =0;i<tableSize;i++) {
			  TableEntry entry = table[i];
			  int count = 0;
			  TableEntry prevEntry = null;
			  while(entry != null) {
				  if(entry.getDepth() == depth) {
					 System.out.println("Lexeme :"+entry.getLexeme()); 
					 if(count == 0)
				     table[i] =  entry.getNext();
					 else 
						 prevEntry.setNext(entry.getNext());
				     System.out.println("Deleted :" + entry.getTokenType());
				  }
				  prevEntry = entry;
				  entry = entry.getNext();
				
				  count++;
			  }
			  
		  }
	  
	  }
	  
	  /**
	   * Prints out the entries in the symbol table
	   * @param depth The depth at which all the Table Entries are to be deleted
	   */
	  public void writeTable(int depth) {
		  for (int i =0;i<tableSize;i++) {
			  TableEntry entry = table[i];
			  while(entry != null) {
				  if(entry.getDepth() == depth) {
					 System.out.println("Lexeme :"+entry.getLexeme()); 
				  }
				  entry = entry.getNext();
			  }
			  
		  }
	  }
	  
	  /**
	   * Calculates the hash value of the given lexeme
	   * @param lexeme The value whose hash value is to be calculated
	   * 
	   * @return The hash value of the given lexeme
	   */
	  public int hash(String lexeme) {
		  int hashCode = lexeme.hashCode();
		  hashCode = hashCode % tableSize;
		  return hashCode;
	  }
	  
  }

 /**
  * This class represents an entry in the Symbol Table 
  * 
  *
  */
 class TableEntry {

	private TokenType tokenType = null;
	private String Lexeme = null;
	private int depth = 0;
	private int offset = 0;
	private Record record = null;
	private TableEntry next = null;

	/**
	 * Returns the lexeme
	 * @return The lexeme of the record
	 */
	public String getLexeme() {
		return Lexeme;
	}

	/**
	 * Set the value of lexeme
	 * @param lexeme The lexeme to be set
	 */
	public void setLexeme(String lexeme) {
		Lexeme = lexeme;
	}

	/**
	 * Returns the depth
	 * @return The depth of the record
	 */
	public int getDepth() {
		return depth;
	}

	/**
	 * Set the value of depth
	 * @param depth The depth to be set
	 */
	public void setDepth(int depth) {
		this.depth = depth;
	}

	/**
	 * Returns the offset
	 * @return Returns the offset
	 */
	public int getOffset() {
		return offset;
	}

	/**
	 * Set the value of offset
	 * @param offset The value of offset to be set
	 */
	public void setOffset(int offset) {
		this.offset = offset;
	}

	/**
	 * Returns the record
	 * @return Returns the record
	 */
	public Record getRecord() {
		return record;
	}

	/**
	 * Set the value of record
	 * @param record Set the record
	 */
	public void setRecord(Record record) {
		this.record = record;
	}

	/**
	 * Returns the next Table Entry
	 * @return The next entry
	 */
	public TableEntry getNext() {
		return next;
	}

	/**
	 * Set the value of next Table Entry
	 * @param next
	 */
	public void setNext(TableEntry next) {
		this.next = next;
	}

	/**
	 * Returns the TokenType
	 * @return The token type
	 */
	public TokenType getTokenType() {
		return tokenType;
	}

	/**
	 * Set the value of Token Type
	 * @param tokenType The Token Type to be set
	 */
	public void setTokenType(TokenType tokenType) {
		this.tokenType = tokenType;
	}

}

 /**
  * 
  * Enumeration to determine the type of the variable
  *
  */
enum VarType {
	charType, intType, realType
}

/**
 * 
 * Class to represent a Node in the Param List for the Procedure 
 *
 */
class ParamNode {
	VarType parameterType;
	ParamNode next;
}

/**
 * 
 * Base class to represent the generic type for different Table Entries to
 * be stored in the symbol table
 *
 */
class Record {

}

/**
 * 
 * Class to represent the Variable type symbol Table Entry
 *
 */
class VariableRecord extends Record {
	int offset;
	int size;
	VarType varType;
}

/**
 * 
 * Class to represent the Constant type symbol Table Entry
 *
 */
class ConstantRecord extends Record {
	int offset;
	float value;

}

/**
 * 
 * Class to represent the Procedure type symbol Table Entry
 *
 */
class ProcedureRecord extends Record {
	int sizeOfLocalVariables;
	int noOfParameters;
	ParamNode parameterList;
}
