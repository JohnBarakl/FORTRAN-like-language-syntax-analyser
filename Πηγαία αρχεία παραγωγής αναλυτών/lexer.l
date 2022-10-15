%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions (these are used by flex).
int yylex();
int yyerror(char*);

// Function Definitions.
void saveString(const char* tokenType);
void* safeMalloc(size_t size);
  
#include "y.tab.h" 
#define T_EOF 0

unsigned long linecounter = 1;

%}

%option noyywrap
%option caseless

alphabetical ([a-z])
arithmetic ([0-9])
alpharithmetic ([a-z]|[0-9])
real_fraction ([0-9]*[1-9][0-9]*)
integer (0|[1-9][0-9]*)
hexadecimal_int ([1-9ABCDEF][0-9ABCDEF]*)
octal_int ([1-7][0-7]*)
binary_int (1[01]*)
printable_ascii [ !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ\[\\\]^_`abcdefghijklmnopqrstuvwxyz{|}~]


%%

"ENDIF"  { return T_ENDIF; }
"FUNCTION"       { return T_FUNCTION; } 
"SUBROUTINE"     { return T_SUBROUTINE; }
"END"    { return T_END; }
"COMMON"         { return T_COMMON; }
"INTEGER"        { return T_INTEGER; }
"REAL"   { return T_REAL; }
"COMPLEX"        { return T_COMPLEX; }
"LOGICAL"        { return T_LOGICAL; }
"CHARACTER"      { return T_CHARACTER; }
"STRING"         { return T_STRING; }
"LIST"   { return T_LIST; }
"DATA"   { return T_DATA; }
"CONTINUE"       { return T_CONTINUE; }
"GOTO"   { return T_GOTO; }
"CALL"   { return T_CALL; }
"READ"   { return T_READ; }
"WRITE"  { return T_WRITE; }
"LENGTH"         { return T_LENGTH; }
"NEW"    { return T_NEW; }
"IF"     { return T_IF; }
"THEN"   { return T_THEN; }
"ELSE"   { return T_ELSE; }
"DO"     { return T_DO; }
"ENDDO"  { return T_ENDDO; }
"STOP"   { return T_STOP; }
"RETURN"         { return T_RETURN; }

"C"("A""D"*|"D"+)"R" { /* LISTFUNC */
    saveString("LISTFUNC");
    return T_LISTFUNC;
}

".TRUE."|".FALSE." { /* LCONST */
    saveString("LCONST");
    return T_LCONST;
}


[a-z](({alpharithmetic}*)|(_?({alpharithmetic}+_)*{alpharithmetic}+_))	{ /* ID : Identifier */
    saveString("ID");
    return T_ID;
}

({integer}|0X{hexadecimal_int}|0O{octal_int}|0B{binary_int})	{ /* ICONST : Constant*/
    saveString("ICONST");
    return T_ICONST;
}

((({integer}?"."{real_fraction}|{integer}"."?{real_fraction}?)(E[\-\+]?{integer})?)|(0X(({hexadecimal_int}|0)?"."(0*{hexadecimal_int})|({hexadecimal_int}|0)"."?(0*{hexadecimal_int})?))|(0O(({octal_int}|0)?"."(0*{octal_int})|({octal_int}|0)"."?(0*{octal_int})?))|(0B(({binary_int}|0)?"."(0*{binary_int})|({binary_int}|0)"."?(0*{binary_int})?))) {
    /* RCONST */
    saveString("RCONST");
    return T_RCONST;
}

\'({printable_ascii}|"\""|"\\n"|"\\f"|"\\t"|"\\r"|"\\b"|"\\v")\' { /* CCONST */
    saveString("CCONST");
    return T_CCONST;
}

\"({printable_ascii}|"\\\""|\\\n)*\"    { /* SCONST */
    saveString("SCONST");
    return T_SCONST;
}

"**" {
   return T_POWEROP;
}

"/" {
    return T_DIVOP;
}

"*" {
    return T_MULOP;
}

"+"|"-" {
    saveString("T_ADDOP"); return T_ADDOP;
}

".GT."|".GE."|".LT."|".LE."|".EQ."|".NE." {
    saveString("T_RELOP"); return T_RELOP;
}

".NOT." {
    return T_NOTOP;
}

".AND." {
    return T_ANDOP;
}

".OR." {
    return T_OROP;
}

"(" { return T_LPAREN; }

")" { return T_RPAREN; }

"," { return T_COMMA; }

"=" { return T_ASSIGN; }

":" { return T_COLON; }

"[" { return T_LBRACK; }

"]" { return T_RBRACK; }

<<EOF>> { return T_EOF; }

"$".*\n { /* Comments */ linecounter++; }

[ \t\r] /* Remove whitespaces */

[\n] {linecounter++;}

.	{ yyerror("Lexical error"); }

%%

void saveString(const char* tokenType){
    // Empty token type means that the token has no string to be saved that cannot be deduced from it's type.
    if (strcmp(tokenType, "")){
        yylval.valueString = (char*) strcpy(safeMalloc((1+strlen(yytext))*sizeof(char)), yytext);
    }
}

/*
 *  To avoid constantly checking for malloc error, while using safeMalloc if one is encounted, the whole program is terminated.
 */
void* safeMalloc(size_t size){
    void* temp = malloc(size);
    if (temp){
        return temp;
    } else {
        fprintf(stderr, "Memory error");
        exit(-1);
    }
}

// When an error is encountered, the error message is printed following the line number in which it was found.
int yyerror(char* msg){
    fprintf(stderr,"Line %lu, Error: %s\n", linecounter, msg);
    exit(1);
}
