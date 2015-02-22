package st;

import analyzer.TokenType;

/**
 * This class represents an entry in the Symbol Table 
 * 
 *
 */
public class TableEntry {

	
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


