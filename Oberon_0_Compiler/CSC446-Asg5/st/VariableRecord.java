package st;

/**
 * 
 * Class to represent the Variable type symbol Table Entry
 *
 */
public class VariableRecord extends Record {
	int offset;
	int size = 0;
	VarType varType;
	public int getOffset() {
		return offset;
	}
	public void setOffset(int offset) {
		this.offset = offset;
	}
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	public VarType getVarType() {
		return varType;
	}
	public void setVarType(VarType varType) {
		this.varType = varType;
	}
}

