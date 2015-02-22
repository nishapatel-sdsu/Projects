/*package parse;

import static org.junit.Assert.*;

import java.io.StringReader;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

import analyzer.TokenType;


public class RecDescParserTest {

	private RecDescParser parser;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
	}

	@Before
	public void setUp() throws Exception {
	
	}

	@After
	public void tearDown() throws Exception {
	}


	@Test
	public final void testGetNextToken() {
		use("ONE END");
		parser.getNextToken();
		assertTrue(parser.getCurToken().getType() == TokenType.RESWORD);
	}

	@Test
	public final void testGetCurToken() {
		use("ONE END");
		parser.getCurToken();
		assertTrue(parser.getCurToken().getType() == TokenType.ID);
	}

	@Test
	public final void testSeqOfStatements() {
		use("END");
		parser.seqOfStatements();
		assertTrue(parser.getCurToken().getType() == TokenType.RESWORD);
	}

	@Test
	public final void testStatementPart() {
		use("BEGIN ONE");
		parser.statementPart();
		assertTrue(parser.getCurToken().getType() == TokenType.ID);
	}

	@Test
	public final void testMode() {
		use("VAR ONE");
		parser.mode();
		assertTrue(parser.getCurToken().getType() == TokenType.ID);
	}

	@Test
	public final void testMoreArgs() {
		use("ONE");
		parser.moreArgs();
		assertTrue(parser.getCurToken().getType() == TokenType.ID);
		use(";  VAR arg: INTEGER");
		parser.moreArgs();
		System.out.println(parser.getCurToken().getValue());
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		use(";  VAR arg: INTEGER; VAR arg: INTEGER");
		parser.moreArgs();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testArgList() {
		use("VAR arg: INTEGER");
		parser.argList();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		use("VAR arg: INTEGER; VAR arg: INTEGER");
		parser.argList();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testArgs() {
		use("VAR");
		parser.args();
		assertTrue(parser.getCurToken().getType() == TokenType.RESWORD);
		use("(VAR arg: INTEGER)");
		parser.args();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		use("(VAR arg: INTEGER; VAR arg: INTEGER)");
		parser.args();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testProcBody() {
		use("END");
		parser.procBody();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("CONST one = 1 ; two = 4; VAR four, five: CHAR; PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1; END");
		parser.procBody();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("CONST one = 1 ; two = 4; VAR four, five: CHAR; PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1; END");
		parser.procBody();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testProcHeading() {
		
		use("PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER )");
		parser.procHeading();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testProcedureDecl() {
		use("PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1;");
		parser.procedureDecl();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; BEGIN END fun1;");
		parser.procedureDecl();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testProcPart() {
		use("PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1;");
		parser.procPart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1; PROCEDURE fun2 ( VAR eight: INTEGER) ; END fun2;");
		parser.procPart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
			}

	@Test
	public final void testValue() {
		use("10");
		parser.value();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("12.2");
		parser.value();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testTypeMark() {
		use("INTEGER");
		parser.typeMark();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("REAL");
		parser.typeMark();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use("CHAR");
		parser.typeMark();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testIdentifierList() {
		
		
		use ("five");
		parser.identifierList();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use ("two , five");
		parser.identifierList();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use ("nine , five , seven , eight");
		parser.identifierList();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testIdentifierList1() {
		use (", five");
		parser.identifierList1();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use (", five , seven , eight");
		parser.identifierList1();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testVarTail() {
		use ("four, five: CHAR;");
		parser.varTail();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use ("four, five: CHAR; seven: REAL;");
		parser.varTail();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testVarPart() {
		use ("VAR four, five: CHAR;");
		parser.varPart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testConstTail() {
		use ("one = 1 ;");
		parser.constTail();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testConstPart() {
		use ("CONST one = 1 ; two = 4;");
		parser.constPart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
	}

	@Test
	public final void testDeclarativePart() {
		use ("VAR four, five: CHAR;");
		parser.declarativePart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use ("CONST one = 1 ; two = 4; VAR four, five: CHAR;");
		parser.declarativePart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		use ("CONST one = 1 ; two = 4; VAR four, five: CHAR; PROCEDURE fun1 ( VAR seven: INTEGER; eight: INTEGER ) ; END fun1;");
		parser.declarativePart();
		assertTrue(parser.getCurToken().getType() == TokenType.EOF);
		
		
		
	}

	@Test
	public final void testProg() {
use("MODULE three;"+  "CONST one = 1 ; two = 4;"+
	
	"VAR four, five: CHAR;"+
	 " PROCEDURE six ( VAR seven: INTEGER; eight: INTEGER );"+
	  
	 " END six;"+

	"END three.");

parser.prog();
assertTrue(parser.getCurToken().getType() == TokenType.EOF);

	}

	@Test
	public final void testError() {
		use("( VAR (");
		try {
		parser.args();
		assertFalse(true);
		}
		catch(RuntimeException e){
			assertTrue(true);
		}
	}

	private void use(String val){
		parser = new RecDescParser(new StringReader(val));
		parser.getNextToken();
		
	}
}*/
