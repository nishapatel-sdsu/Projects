The project implements recursive descent parser.

It conssists of two packages.

1. parse : The parse package contains two classes.
a. RecDescParser : This class implements the grammar rules and parses the program.
b. Driver : This is the main class to run the parser

2. analyzer : The analyzer package contains four classes.

a.Driver.java :  This is the main class to run the lexical analyzer
b.Tokenizer.java : This class implements the lexical analyzer to return one token at a time
c.Token.java :  This class is used to represent the token object.
d.TokenType.java : This class is used to represent the TokenTypes

To run the project :

1. Compile the java classes. 
a. Go to the dir CSC446-Asg2 : cd CSC446-Asg2
b. Compile the java classes in parse folder : CSC446-Asg2> javac ./analyzer/*.java
c.Compile the java classes in parse foldr : CSC446-Asg2> javac ./parse/*.java

2. Run the Driver program  of the parse package passing one input argument i.e. the file containg the program 
  CSC446-Asg2> java parse.Driver program.obr
