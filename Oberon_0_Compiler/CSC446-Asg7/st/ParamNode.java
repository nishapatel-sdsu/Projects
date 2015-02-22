package st;

/**
 * 
 * Class to represent a Node in the Param List for the Procedure 
 *
 */
public class ParamNode {
	VarType parameterType;
	public int getSize() {
		return size;
	}
	public void setSize(int size) {
		this.size = size;
	}
	int size = 0;
	
	public int getOffset() {
		return offset;
	}
	public void setOffset(int offset) {
		this.offset = offset;
	}
	int offset = 0;
	
	ParamNode next = null;
	
	public VarType getParameterType() {
		return parameterType;
	}
	public void setParameterType(VarType parameterType) {
		this.parameterType = parameterType;
	}
	public ParamNode getNext() {
		return next;
	}
	public void setNext(ParamNode next) {
		this.next = next;
	}
}
