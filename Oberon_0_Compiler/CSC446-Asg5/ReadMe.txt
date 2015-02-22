The project implements recursive descent parser.

It conssists of three packages/folders in CSC446-ASG5.

1. parse : The parse package contains two classes.
a. RecDescParser : This class implements the grammar rules and parses the program.
b. Driver : This is the main class to run the parser

2. analyzer : The analyzer package contains four classes.

a.Driver.java :  This is the main class to run the lexical analyzer
b.Lexical.java : This class implements the lexical analyzer to return one token at a time
c.Token.java :  This class is used to represent the token object.
d.TokenType.java : This class is used to represent the TokenTypes

3. st : The symbol table package contains 12 classes

a. ConstantRecord.java
b. Driver.java
c. Offset.java
d. ParamNode.java
e.ProcedureRecord.java
f. Record.java
g. SymbolTable.java : Implements the Symbol Table
h. TableEntry.java : Represents an entry in symbol Table.
i. Total.java
j. Type.java
k. VariableRecord.java
l. VarType.java
To run the project :

1. Compile the java classes. 
a. Go to the dir CSC446-Asg2 : cd CSC446-ASG5
b. Compile the java classes in analyzer folder : CSC446-ASG5> javac ./analyzer/*.java
c. Compile the java classes in st folder : CSC446-ASG5> javac ./st/*.java
d.Compile the java classes in parse foldr : CSC446-ASG5> javac ./parse/*.java

2. Run the Driver program  of the parse package passing one input argument i.e. the file containg the program 
  CSC446-ASG5> java parse.Driver program.obr
