/********************************************************************
 *** NAME       : NISHA PATEL                                      ***
 *** CLASS      : CSc 710                                          ***
 *** ASSIGNMENT : Asg2_B  java                                      ***
 *** DUE DATE   : 09/23/2012                                       ***
 *** INSTRUCTOR : Dr.Shin                                          ***
 *********************************************************************
 *** DESCRIPTION : This module implement stack.
 ********************************************************************/

package infixtopostfix;

public class Stack {
	
	
	
	private
		int count;
		Node  top;

	public
	/*
	 * =============Constructor for the Class===========
	 */
		
	Stack(){
		}
	/*============PushStack=======================
	 * DESCRIPTION :This function pushes an item onto the stack
	 * INPUT ARGS :- String datain
	 * OUTPUT ARGS : None 
	 * IN/OUT ARGS : None
	 * RETURN : - boolean 
	 */
		boolean pushstack(String datain){
		
		boolean success;
		Node newptr;

		newptr = new Node();
			if (newptr == null)
			success = false;
			
		else {
			newptr.data = datain;
			newptr.next = top;
			top = newptr;
			count++;
			success = true;

		}

	  return success;
		}
		/*============PophStack=======================
		 * DESCRIPTION :This function pop the item on the top of the stack
		 * INPUT ARGS :- None
		 * OUTPUT ARGS : None 
		 * IN/OUT ARGS : None
		 * RETURN : - String data
		 */
		String popstack(){
			
			
			
			//Node dltptr;
			String success;

			if (count == 0)
				success = null;
			else {
				//dltptr = top;
				
				success = top.data;
				top = top.next;
				count--;
				
				

			}
			return success;
			
		}
		/*============Stacktop=======================
		 * DESCRIPTION :This function retrieves the data from the top of the stack without changing the stack
		 * INPUT ARGS :- None
		 * OUTPUT ARGS : None 
		 * IN/OUT ARGS : None
		 * RETURN : - String data
		 */
		String  stacktop(){
			
			String success;

			if (count == 0)
				success = null;
			else {
				
				success = top.data;
				
			}
			return success;

				
		}
		/*================emptystack==================
		 * DESCRIPTION :This function determines if a stack is empty
		 * RETURN : - boolean
		 */
		boolean emptystack(){
			return (count == 0);
		}
	
		/*================Printstack==================
		 * DESCRIPTION :This function print the stack
		 * RETURN : - none
		 */
	    void printStack(){
	    	
	    	  Node temp;
	    	    temp = top;
	    	    System.out.print("[");
	    	    while (temp != null) {
	    	        
	    	        System.out.print( temp.data + " ");
	    			
	    			temp = temp.next;
	    			

	    		}
	    	    System.out.print("]");
	    	
	    }


}
