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
	  private int depth = 0;
	  
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
		  System.out.println("Inserted Entry :<"+lexeme+"> Token Type:<"+ tokenType + "> Depth:<" + depth+">");
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
		 System.out.println("\n---------------------------------------------------------------------");
		 System.out.println("Deleting Entries in  Symbol Table at depth : "+ depth);
		
		  for (int i =0;i<tableSize;i++) {
			  TableEntry entry = table[i];
			  int count = 0;
			  TableEntry prevEntry = null;
			  while(entry != null) {
				  if(entry.getDepth() == depth) {
					 if(count == 0)
				     table[i] =  entry.getNext();
					 else 
						 prevEntry.setNext(entry.getNext());
			     System.out.println("Deleted Entry : Lexeme="+entry.getLexeme() +" Type="+ entry.getTokenType());
				  }
				  prevEntry = entry;
				  entry = entry.getNext();
				
				  count++;
			  }
			  
		  }
		  System.out.println("---------------------------------------------------------------------\n");
	  }
	  
	  /**
	   * Prints out the entries in the symbol table
	   * @param depth The depth at which all the Table Entries are to be printed
	   */
	  public void writeTable(int depth) {
		  System.out.println("\n---------------------------------------------------------------------");
		  System.out.println("Writing Symbol Table at depth : "+ depth);
		  for (int i =0;i<tableSize;i++) {
			  TableEntry entry = table[i];
			  while(entry != null) {
				  if(entry.getDepth() == depth) {
					  
					 System.out.println("Entry : ");
					 System.out.println("\tLexeme = "+entry.getLexeme());
					 System.out.println("\tType   = "+ entry.getTokenType()); 
					 //System.out.println("\tOffset = "+ entry.getOffset());
					 Record record = entry.getRecord();
					 if(record != null){
						 if(record instanceof ConstantRecord ) {
							 ConstantRecord constantRecord = (ConstantRecord)record;
								
							 
							 System.out.println("\tRecord Type = Constant Record");
							 System.out.println("\t\tVar Type  = "+constantRecord.getVarType());
							 if(constantRecord.getVarType() == VarType.intType){
								 System.out.println("\t\tInt Value = "+constantRecord.getiValue());
							 }
							 else if(constantRecord.getVarType() == VarType.realType){
								 System.out.println("\t\tFloat Value = "+constantRecord.getfValue());
							 }
							 System.out.println("\t\tOffset = "+constantRecord.getOffset());
						 }
						 else if(record instanceof VariableRecord) {
                             VariableRecord variableRecord = (VariableRecord)record;
							 System.out.println("\tRecord Type  = Variable Record");
							 System.out.println("\t\tVar Type   = "+variableRecord.getVarType());
							 System.out.println("\t\tVar Size   = "+variableRecord.getSize());
							 System.out.println("\t\tVar Offset = "+variableRecord.getOffset());
							
						 }
						 
						 else if (record instanceof ProcedureRecord){
							 
							 ProcedureRecord procedureRecord = (ProcedureRecord)record;
							 System.out.println("\tRecord Type = Procedure Record");
							 System.out.println("\t\tNo Of Parameters      = "+procedureRecord.getNoOfParameters());
							 System.out.println("\t\tSize Of All Variables = "+procedureRecord.getSizeOfLocalVariables());
							 ParamNode paramNode = procedureRecord.getParameterList();
							 while(paramNode != null) {
								 System.out.println("\t\tParameter List");
								 System.out.println("\t\t\tParameter Type = "+paramNode.getParameterType());
								 System.out.println("\t\t\tParameter Size = "+paramNode.getSize());
								 System.out.println("\t\t\tParameter Offset = "+paramNode.getOffset());
								 paramNode = paramNode.getNext();
							 }
								 
							 
						 }
					 }
					
					 
				  }
				  entry = entry.getNext();
			  }
			  
		  }
		  System.out.println("---------------------------------------------------------------------\n");
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
		  if(hashCode < 0) hashCode = -hashCode;
		  return hashCode;
	  }
	  
	  /**
	   * This method checks for duplicate lexeme at the same depth.
	   * @param lex
	   * @param depth
	   * @param lineNo
	   */
	  public void checkForDups(String lex,int depth,int lineNo )
	  {  
		  
		TableEntry entry  = lookup(lex);
		if(entry != null){
	  	if (entry.getDepth() == depth){
	  	   System.out.println("Error - duplicate identifier " + lex + " on line " + lineNo);
	  	   System.exit(1);
	  	}
	  	 }
	
	  } 

	public int getDepth() {
		return depth;
	}

	public void setDepth(int depth) {
		this.depth = depth;
	}
 }

 
 







