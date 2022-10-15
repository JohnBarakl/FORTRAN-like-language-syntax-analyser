%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function definitions (these are used by yacc).
int yylex();
int yyerror(char*);
int yyparse();

// Functions and types definitions.
void* safeMalloc(size_t size);

typedef struct TreeNode{
    struct TreeNode **children;
    short numberOfChildren;
    char *symbolName;
    char *symbolValue;
} TreeNode;

TreeNode* makeTreeNode(TreeNode** children, short numberOfChildren, char* symbolName, char* value);
void showTree(TreeNode* node, char* linePrefix, char isLastChild, long extendIterator);

TreeNode* syntaxTreeRoot;

%}

%union{
    struct TreeNode* node;
    char* valueString;
}

%token T_GOTO
%token T_RETURN
%token T_THEN
%token T_COMPLEX
%token T_DO
%token T_CALL
%token T_RPAREN
%token T_POWEROP
%token T_READ
%token T_LPAREN
%token T_COLON
%token T_REAL
%token<valueString> T_CCONST 
%token T_LOGICAL
%token T_LENGTH
%token T_CHARACTER
%token T_RBRACK
%token T_ELSE
%token<valueString> T_SCONST 
%token T_IF
%token T_COMMON
%token<valueString> T_LCONST 
%token<valueString> T_ANDOP
%token<valueString> T_RCONST 
%token T_FUNCTION
%token T_ENDDO
%token<valueString> T_ICONST 
%token T_CONTINUE
%token T_COMMA
%token<valueString> T_ID 
%token<valueString> T_RELOP 
%token T_STOP
%token T_INTEGER
%token T_DATA
%token T_WRITE
%token T_STRING
%token T_OROP
%token T_ASSIGN
%token T_MULOP
%token<valueString> T_ADDOP 
%token T_END
%token T_NOTOP
%token T_LIST
%token T_NEW
%token T_LBRACK
%token T_ENDIF
%token T_SUBROUTINE
%token T_DIVOP
%token<valueString> T_LISTFUNC 

%type<node> type
%type<node> tail
%type<node> value_list
%type<node> vals
%type<node> write_list
%type<node> loop_statement
%type<node> statements
%type<node> complex_constant
%type<node> id_list
%type<node> sign
%type<node> simple_statement
%type<node> iter_space
%type<node> formal_parameters
%type<node> dim
%type<node> cblock_list
%type<node> values
%type<node> labeled_statement
%type<node> subprograms
%type<node> label
%type<node> statement
%type<node> read_item
%type<node> io_statement
%type<node> subprogram
%type<node> program
%type<node> read_list
%type<node> listspec
%type<node> vars
%type<node> expressions
%type<node> listexpression
%type<node> expression
%type<node> goto_statement
%type<node> write_item
%type<node> simple_constant
%type<node> header
%type<node> declarations
%type<node> value
%type<node> cblock
%type<node> variable
%type<node> labels
%type<node> undef_variable
%type<node> compound_statement
%type<node> subroutine_call
%type<node> if_statement
%type<node> body
%type<node> assignment
%type<node> constant
%type<node> dims
%type<node> branch_statement
%type<node> repeat
%type<node> step

%left T_COLON
%left T_OROP
%left T_ANDOP
%left T_NOTOP
%nonassoc T_RELOP
%left T_ADDOP
%left T_MULOP T_DIVOP
%right T_POWEROP
%left T_LPAREN T_RPAREN

%%

program: body T_END subprograms{
    // Create tree root.
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_END", "");
	children[2] = $3;

	syntaxTreeRoot = makeTreeNode(children, 3, "program", "");
};

body: declarations statements{
    // Create tree node for nonterminal symbol "body".
    // The same procedure follows for all remaining nonterminal symbols that are identified during syntax analysis.
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "body", "");
};

declarations: declarations type vars {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "declarations", "");
}
            | declarations T_COMMON cblock_list {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMON", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "declarations", "");
}
            | declarations T_DATA vals {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_DATA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "declarations", "");
}
            | {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "EmptyDeclaration", "");

	$$ = makeTreeNode(children, 1, "declarations", "");
}
            ;
            
type: T_INTEGER {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_INTEGER", "");

	$$ = makeTreeNode(children, 1, "type", "");
}

 | T_REAL {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_REAL", "");

	$$ = makeTreeNode(children, 1, "type", "");
}
 | T_COMPLEX {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_COMPLEX", "");

	$$ = makeTreeNode(children, 1, "type", "");
}
 | T_LOGICAL {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LOGICAL", "");

	$$ = makeTreeNode(children, 1, "type", "");
}
 | T_CHARACTER {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CHARACTER", "");

	$$ = makeTreeNode(children, 1, "type", "");
} | T_STRING {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_STRING", "");

	$$ = makeTreeNode(children, 1, "type", "");
};

vars: vars T_COMMA undef_variable {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "vars", "");
}
    | undef_variable {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "vars", "");
};

undef_variable: listspec T_ID T_LPAREN dims T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);
	children[2] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[3] = $4;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 5, "undef_variable", "");
}
                | listspec T_ID {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);

	$$ = makeTreeNode(children, 2, "undef_variable", "");
};

listspec: T_LIST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LIST", "");

	$$ = makeTreeNode(children, 1, "listspec", "");
} |  {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	$$ = makeTreeNode(children, 1, "listspec", "");
};

dims: dims T_COMMA dim {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "dims", "");
}
    | dim {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "dims", "");
};

dim: T_ICONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", $1);

	$$ = makeTreeNode(children, 1, "dim", "");
}
    | T_ID {
        TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
        children[0] = makeTreeNode(NULL, 0, "T_ID", $1);

        $$ = makeTreeNode(children, 1, "dim", "");
};

cblock_list: cblock_list cblock {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "cblock_list", "");
}
            | cblock {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "cblock_list", "");
};

cblock: T_DIVOP T_ID T_DIVOP id_list {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);
	children[2] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[3] = $4;

	$$ = makeTreeNode(children, 4, "cblock", "");
};

id_list: id_list T_COMMA T_ID {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = makeTreeNode(NULL, 0, "T_ID", $3);

	$$ = makeTreeNode(children, 3, "id_list", "");
}
        | T_ID {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", $1);

	$$ = makeTreeNode(children, 1, "id_list", "");
};

vals: vals T_COMMA T_ID value_list {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = makeTreeNode(NULL, 0, "T_ID", $3);
	children[3] = $4;

	$$ = makeTreeNode(children, 4, "vals", "");
}    | T_ID value_list {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", $1);
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "vals", "");
};

value_list: T_DIVOP values T_DIVOP {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_DIVOP", "");

	$$ = makeTreeNode(children, 3, "value_list", "");
};

values: values T_COMMA value {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "values", "");
}
        | value {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "values", "");
};

value: repeat sign constant {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "value", "");
}    | T_ADDOP constant {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", $1);
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "value", "");
}
    | constant {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "value", "");
};

repeat: T_ICONST T_MULOP {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", $1);
	children[1] = makeTreeNode(NULL, 0, "T_MULOP", "");

	$$ = makeTreeNode(children, 2, "repeat", "");
}

        | T_MULOP {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_MULOP", "");

	$$ = makeTreeNode(children, 1, "repeat", "");
};

sign: T_ADDOP {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", $1);

	$$ = makeTreeNode(children, 1, "sign", "");
} |  {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	$$ = makeTreeNode(children, 1, "sign", "");
};

constant: simple_constant {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "constant", "");
}
            | complex_constant {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "constant", "");
};

simple_constant: T_ICONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", $1);

	$$ = makeTreeNode(children, 1, "simple_constant", "");
} | T_RCONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_RCONST", $1);

	$$ = makeTreeNode(children, 1, "simple_constant", "");
} | T_LCONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LCONST", $1);

	$$ = makeTreeNode(children, 1, "simple_constant", "");
} | T_CCONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CCONST", $1);

	$$ = makeTreeNode(children, 1, "simple_constant", "");
} | T_SCONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SCONST", $1);

	$$ = makeTreeNode(children, 1, "simple_constant", "");
};

complex_constant: T_LPAREN T_RCONST T_COLON sign T_RCONST T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = makeTreeNode(NULL, 0, "T_RCONST", $2);
	children[2] = makeTreeNode(NULL, 0, "T_COLON", "");
	children[3] = $4;
	children[4] = makeTreeNode(NULL, 0, "T_RCONST", $5);
	children[5] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 6, "complex_constant", "");
};

statements: statements labeled_statement {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "statements", "");
}
        | labeled_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "statements", "");
};

labeled_statement: label statement {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "labeled_statement", "");
}
                | statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "labeled_statement", "");
};

label: T_ICONST {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", $1);

	$$ = makeTreeNode(children, 1, "label", "");
};

statement: simple_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "statement", "");
}
        | compound_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "statement", "");
};

simple_statement: assignment {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | goto_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | if_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | subroutine_call {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | io_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}

                | T_CONTINUE {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CONTINUE", "");

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | T_RETURN {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_RETURN", "");

	$$ = makeTreeNode(children, 1, "simple_statement", "");
}
                | T_STOP {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_STOP", "");

	$$ = makeTreeNode(children, 1, "simple_statement", "");
};

assignment: variable T_ASSIGN expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "assignment", "");
};

variable: T_ID T_LPAREN expressions T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", $1);
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 4, "variable", "");
}
        | T_LISTFUNC T_LPAREN expression T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LISTFUNC", $1);
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 4, "variable", "");
}
        | T_ID {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", $1);

	$$ = makeTreeNode(children, 1, "variable", "");
};

expressions: expressions T_COMMA expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expressions", "");
}
            | expression {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "expressions", "");
};

expression: expression T_OROP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_OROP", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | expression T_ANDOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_ANDOP", $2);
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | expression T_RELOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_RELOP", $2);
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}

            | expression T_ADDOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_ADDOP", $2);
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | expression T_MULOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_MULOP", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | expression T_DIVOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | expression T_POWEROP expression {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_POWEROP", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "expression", "");
}
            | T_NOTOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_NOTOP", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "expression", "");
}
            | T_ADDOP expression {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", $1);
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "expression", "");
}
            | variable {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "expression", "");
}
            | simple_constant {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "expression", "");
}
            | T_LENGTH T_LPAREN expression T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LENGTH", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 4, "expression", "");
}
            | T_NEW T_LPAREN expression T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_NEW", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 4, "expression", "");
}
            | T_LPAREN expression T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 3, "expression", "");
}

            | T_LPAREN expression T_COLON expression T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_COLON", "");
	children[3] = $4;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 5, "expression", "");
}
            | listexpression {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "expression", "");
};

listexpression: T_LBRACK expressions T_RBRACK {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LBRACK", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_RBRACK", "");

	$$ = makeTreeNode(children, 3, "listexpression", "");
}
                | T_LBRACK T_RBRACK {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LBRACK", "");
	children[1] = makeTreeNode(NULL, 0, "T_RBRACK", "");

	$$ = makeTreeNode(children, 2, "listexpression", "");
};

goto_statement: T_GOTO label {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_GOTO", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "goto_statement", "");
}
                | T_GOTO T_ID T_COMMA T_LPAREN labels T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_GOTO", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[4] = $5;
	children[5] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 6, "goto_statement", "");
};

labels: labels T_COMMA label {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "labels", "");
}
        | label{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "labels", "");
};

if_statement: T_IF T_LPAREN expression T_RPAREN label T_COMMA label T_COMMA label {
	TreeNode** children = (TreeNode **) safeMalloc(9*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = $5;
	children[5] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[6] = $7;
	children[7] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[8] = $9;

	$$ = makeTreeNode(children, 9, "if_statement", "");
}
                | T_IF T_LPAREN expression T_RPAREN simple_statement {
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = $5;

	$$ = makeTreeNode(children, 5, "if_statement", "");
};

subroutine_call: T_CALL variable {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CALL", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "subroutine_call", "");
};

io_statement: T_READ read_list {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_READ", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "io_statement", "");
}
            | T_WRITE write_list {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_WRITE", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "io_statement", "");
};

read_list: read_list T_COMMA read_item {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "read_list", "");
}
            | read_item {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "read_list", "");
};

read_item: variable {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "read_item", "");
}
        | T_LPAREN read_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", $4);
	children[4] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[5] = $6;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 7, "read_item", "");
};

iter_space: expression T_COMMA expression step {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;
	children[3] = $4;

	$$ = makeTreeNode(children, 4, "iter_space", "");
};

step: T_COMMA expression {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "step", "");
}
        |  {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	$$ = makeTreeNode(children, 1, "step", "");
};

write_list: write_list T_COMMA write_item {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = $3;

	$$ = makeTreeNode(children, 3, "write_list", "");
}
            | write_item {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "write_list", "");
};

write_item: expression {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "write_item", "");
}
                | T_LPAREN write_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", $4);
	children[4] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[5] = $6;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 7, "write_item", "");
};

compound_statement: branch_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "compound_statement", "");
}
                | loop_statement {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = $1;

	$$ = makeTreeNode(children, 1, "compound_statement", "");
};

branch_statement: T_IF T_LPAREN expression T_RPAREN T_THEN body tail {
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = $3;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = makeTreeNode(NULL, 0, "T_THEN", "");
	children[5] = $6;
	children[6] = $7;

	$$ = makeTreeNode(children, 7, "branch_statement", "");
};

tail: T_ELSE body T_ENDIF {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ELSE", "");
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_ENDIF", "");

	$$ = makeTreeNode(children, 3, "tail", "");
}
    | T_ENDIF {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ENDIF", "");

	$$ = makeTreeNode(children, 1, "tail", "");
};

loop_statement: T_DO T_ID T_ASSIGN iter_space body T_ENDDO {
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DO", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);
	children[2] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[3] = $4;
	children[4] = $5;
	children[5] = makeTreeNode(NULL, 0, "T_ENDDO", "");

	$$ = makeTreeNode(children, 6, "loop_statement", "");
};

subprograms: subprograms subprogram {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "subprograms", "");
}
            |  {
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	$$ = makeTreeNode(children, 1, "subprograms", "");
};

subprogram: header body T_END {
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_END", "");

	$$ = makeTreeNode(children, 3, "subprogram", "");
};

header: type listspec T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_FUNCTION", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", $4);
	children[4] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[5] = $6;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 7, "header", "");
}       | T_SUBROUTINE T_ID T_LPAREN formal_parameters T_RPAREN {
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SUBROUTINE", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);
	children[2] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[3] = $4;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	$$ = makeTreeNode(children, 5, "header", "");
}
        | T_SUBROUTINE T_ID {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SUBROUTINE", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", $2);

	$$ = makeTreeNode(children, 2, "header", "");
};

formal_parameters: type vars T_COMMA formal_parameters {
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = $4;

	$$ = makeTreeNode(children, 4, "formal_parameters", "");
}
                   | type vars {
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = $1;
	children[1] = $2;

	$$ = makeTreeNode(children, 2, "formal_parameters", "");
}


%%

int main(){
    // syntaxTreeRoot is initialized to NULL, because the syntax analysis procedure might fail, and there needs
    // to be a default value to check that.
	syntaxTreeRoot = NULL;

	// Beginning the syntax analysis and syntax tree construction.
    int parseResult = yyparse();

    // If syntax analysis and syntax tree construction was successfull, then the syntax tree's root (pointer)
    // is saved in syntaxTreeRoot.
    // In that case, the syntax tree is printed.
	if (syntaxTreeRoot){
		showTree(syntaxTreeRoot, "", 0, 0);
	}
}

// The syntax tree is printed in the predefined output.
void showTree(TreeNode* node, char* linePrefix, char isLastChild, long extendIterator){
    printf("%s%s", linePrefix, node->symbolName); // Prints symbol name.
	
	// If the current symbol is a terminal one (has no children) and has a symbol value to print, then it is printed.
	if (node->numberOfChildren == 0 && strcmp(node->symbolValue, "")){
		printf(" = %s", node->symbolValue);
	}
	printf("\n");

	// Graphics.
    if (isLastChild){
        linePrefix[extendIterator] = ' ';
    }

    if (node->numberOfChildren != 0){
        long linePrefLen = strlen(linePrefix);
        long printLen = strlen(node->symbolName);

        char* newLinePrefix = (char*) safeMalloc((4+linePrefLen+4));
        long newLinePrefixIterator = 0;

        long extendLinePos;

        long i;
        for (i = 0; i < linePrefLen; i++){
            if (linePrefix[i] == '-'){
                newLinePrefix[newLinePrefixIterator++] = ' ';
            } else {
                newLinePrefix[newLinePrefixIterator++] = linePrefix[i];
            }
        }
        extendLinePos = newLinePrefixIterator;
        newLinePrefix[newLinePrefixIterator++] = '|';
        for(i = 0; i < 4; i++){
            newLinePrefix[newLinePrefixIterator++] = '-';
        }
        newLinePrefix[newLinePrefixIterator++] = ' ';
        newLinePrefix[newLinePrefixIterator++] = '\0';

        // Recursive call for children (subtrees).
        for (i = 0; i < node->numberOfChildren - 1; i++){
            showTree(node->children[i], newLinePrefix, 0, 0);
        }
        showTree(node->children[node->numberOfChildren-1], newLinePrefix, 1, extendLinePos);      

        free(newLinePrefix);
    }
}

// Creates a tree node with given parameters.
TreeNode* makeTreeNode(TreeNode** children, short numberOfChildren, char* symbolName, char* value){
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->children = children;
    node->numberOfChildren = numberOfChildren;
    node->symbolName = (char*) malloc(strlen(symbolName));
    strcpy(node->symbolName, symbolName);
    node->symbolValue = value;

    return node;
}
