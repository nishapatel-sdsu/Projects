package st;

/**
 * This class is used to store the Type.
 * @author nisha04
 *
 */
public class Type {
	private VarType varType = null;
	
	private int offset = 0;
	

	public int getOffset() {
		return offset;
	}

	public void setOffset(int offset) {
		this.offset = offset;
	}

	public VarType getVarType() {
		return varType;
	}

	public void setVarType(VarType varType) {
		this.varType = varType;
	}
	

}
