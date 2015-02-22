package parse;

import st.TableEntry;

public class EntryObj {
	
	private TableEntry entry = null;
    private boolean sign = false;
	
	
	public boolean isSign() {
		return sign;
	}

	public void setSign(boolean sign) {
		this.sign = sign;
	}

	public TableEntry getEntry() {
		return entry;
	}

	public void setEntry(TableEntry entry) {
		this.entry = entry;
	} 
	

}
