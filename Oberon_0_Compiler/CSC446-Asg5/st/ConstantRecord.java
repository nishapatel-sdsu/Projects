package st;

 /**
 * 
 * Class to represent the Constant type symbol Table Entry
 *
 */
public class ConstantRecord extends Record {
	int offset;
	float fValue = 0 ;
	int iValue = 0;
	VarType varType;
	
	
	public VarType getVarType() {
		return varType;
	}
	public void setVarType(VarType varType) {
		this.varType = varType;
	}
	public int getOffset() {
		return offset;
	}
	public void setOffset(int offset) {
		this.offset = offset;
	}
	public float getfValue() {
		return fValue;
	}
	public void setfValue(float fValue) {
		this.fValue = fValue;
	}
	public int getiValue() {
		return iValue;
	}
	public void setiValue(int iValue) {
		this.iValue = iValue;
	}
}