package st;

/**
 * 
 * Class to represent the Procedure type symbol Table Entry
 *
 */
public class ProcedureRecord extends Record {
	int sizeOfLocalVariables;
	int noOfParameters = 0;
	ParamNode parameterList = null;
	
	public int getSizeOfLocalVariables() {
		return sizeOfLocalVariables;
	}
	public void setSizeOfLocalVariables(int sizeOfLocalVariables) {
		this.sizeOfLocalVariables = sizeOfLocalVariables;
	}
	public int getNoOfParameters() {
		return noOfParameters;
	}
	public void setNoOfParameters(int noOfParameters) {
		this.noOfParameters = noOfParameters;
	}
	public ParamNode getParameterList() {
		return parameterList;
	}
	public void setParameterList(ParamNode parameterList) {
		this.parameterList = parameterList;
	}
	
}


