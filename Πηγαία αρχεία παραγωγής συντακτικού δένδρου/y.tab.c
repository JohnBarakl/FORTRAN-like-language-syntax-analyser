#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function definitions (these are used by yacc).*/
int yylex();
int yyerror(char*);
int yyparse();

/* Functions and types definitions.*/
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

#line 28 "parser.y"
typedef union{
    struct TreeNode* node;
    char* valueString;
} YYSTYPE;
#line 42 "y.tab.c"
#define T_GOTO 257
#define T_RETURN 258
#define T_THEN 259
#define T_COMPLEX 260
#define T_DO 261
#define T_CALL 262
#define T_RPAREN 263
#define T_POWEROP 264
#define T_READ 265
#define T_LPAREN 266
#define T_COLON 267
#define T_REAL 268
#define T_CCONST 269
#define T_LOGICAL 270
#define T_LENGTH 271
#define T_CHARACTER 272
#define T_RBRACK 273
#define T_ELSE 274
#define T_SCONST 275
#define T_IF 276
#define T_COMMON 277
#define T_LCONST 278
#define T_ANDOP 279
#define T_RCONST 280
#define T_FUNCTION 281
#define T_ENDDO 282
#define T_ICONST 283
#define T_CONTINUE 284
#define T_COMMA 285
#define T_ID 286
#define T_RELOP 287
#define T_STOP 288
#define T_INTEGER 289
#define T_DATA 290
#define T_WRITE 291
#define T_STRING 292
#define T_OROP 293
#define T_ASSIGN 294
#define T_MULOP 295
#define T_ADDOP 296
#define T_END 297
#define T_NOTOP 298
#define T_LIST 299
#define T_NEW 300
#define T_LBRACK 301
#define T_ENDIF 302
#define T_SUBROUTINE 303
#define T_DIVOP 304
#define T_LISTFUNC 305
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,   43,   34,   34,   34,   34,    1,    1,    1,    1,
    1,    1,   26,   26,   39,   39,   25,   25,   46,   46,
   14,   14,   15,   15,   36,    9,    9,    4,    4,    3,
   16,   16,   35,   35,   35,   48,   48,   10,   10,   45,
   45,   32,   32,   32,   32,   32,    8,    7,    7,   17,
   17,   19,   20,   20,   11,   11,   11,   11,   11,   11,
   11,   11,   44,   37,   37,   37,   27,   27,   29,   29,
   29,   29,   29,   29,   29,   29,   29,   29,   29,   29,
   29,   29,   29,   29,   28,   28,   30,   30,   38,   38,
   42,   42,   41,   22,   22,   24,   24,   21,   21,   12,
   49,   49,    5,    5,   31,   31,   40,   40,   47,    2,
    2,    6,   18,   18,   23,   33,   33,   33,   13,   13,
};
short yylen[] = {                                         2,
    3,    2,    3,    3,    3,    0,    1,    1,    1,    1,
    1,    1,    3,    1,    5,    2,    1,    0,    3,    1,
    1,    1,    2,    1,    4,    3,    1,    4,    2,    3,
    3,    1,    3,    2,    1,    2,    1,    1,    0,    1,
    1,    1,    1,    1,    1,    1,    6,    2,    1,    2,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    3,    4,    4,    1,    3,    1,    3,    3,
    3,    3,    3,    3,    3,    2,    2,    1,    1,    4,
    4,    3,    5,    1,    3,    2,    2,    6,    3,    1,
    9,    5,    2,    2,    2,    3,    1,    1,    7,    4,
    2,    0,    3,    1,    1,    7,    1,    1,    7,    3,
    1,    6,    2,    0,    3,    7,    5,    2,    4,    2,
};
short yydefred[] = {                                      6,
    0,    0,    0,    0,   61,    9,    0,    0,    0,    8,
   10,   11,    0,    0,   52,   60,    0,   62,    7,    0,
    0,   12,    0,    0,  108,    0,   53,   49,    0,   51,
   59,   56,    0,   54,   58,   57,   55,  107,  114,    0,
   87,    0,   93,    0,   97,    0,   98,    0,    0,    0,
   24,    0,    0,    0,    0,   45,    0,   46,   44,   43,
   42,    0,    0,    0,    0,    0,   84,    0,  104,   79,
   78,    0,   17,    0,    0,   14,   48,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   23,    0,    0,
    0,   29,    0,    0,    0,    0,    0,    0,    0,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  113,    6,    0,    6,    0,
    0,   96,    0,    0,    0,   64,    0,    0,    0,   37,
    0,   41,    0,   40,   32,   35,    0,    0,    0,   82,
    0,    0,    0,   85,  103,    0,    0,    0,    0,    0,
    0,    0,   65,    0,   13,    0,    0,    0,   90,    0,
    0,    0,    0,    6,    0,   92,    0,   27,    0,    0,
    0,   36,   34,    0,   30,   38,    0,   28,    0,    0,
   80,   81,   21,   22,   20,    0,    0,    0,  115,   88,
    0,  112,    0,    0,    0,    0,    0,    0,    0,   31,
   33,    0,   83,   15,    0,    0,    0,    0,   89,    0,
  100,    0,    6,  111,  109,    0,    0,   26,    0,    0,
   19,    0,  117,    0,    0,   99,    0,    0,    0,    0,
  106,    0,    0,  110,   91,   47,  119,  116,
};
short yydgoto[] = {                                       1,
  206,  215,   92,   54,   66,   25,   26,  132,  169,  177,
   27,  119,  207,  185,   50,  133,   28,   80,   29,   30,
   45,   31,  116,   46,   74,   75,   89,   67,   68,   32,
   69,   70,  117,    2,  135,   51,   71,  160,   76,   34,
   35,   36,    3,   37,  136,  186,   38,  137,  211,
};
short yysindex[] = {                                      0,
    0,  497, -284, -260,    0,    0, -201, -275, -233,    0,
    0,    0, -237, -213,    0,    0, -141,    0,    0, -146,
  987,    0, -123, -187,    0, -184,    0,    0, -221,    0,
    0,    0, -149,    0,    0,    0,    0,    0,    0, -131,
    0, -138,    0, -233,    0, -128,    0, 1011, -117, -213,
    0, 1011, -134, -114,  987,    0,  -92,    0,    0,    0,
    0, 1011, 1011,  -82,  963,  -99,    0,  935,    0,    0,
    0, 1011,    0,  -93,  -90,    0,    0,    0, 1011,  834,
  -52, 1011,  -70, -233, 1011,  729,  -88,    0, -242,  935,
 1054,    0,  -68,  -62,  691, 1011, -216,  774, 1011,    0,
 -157,  987, 1011, 1011, 1011, 1011, 1011, 1011, 1011,  767,
  -42, -187,  935,  -64, -187,    0,    0,  -58,    0,  909,
 -215,    0,  691,  827,  -55,    0, 1011,  -39,  -59,    0,
 1039,    0, -257,    0,    0,    0,  -49, -134, 1035,    0,
 1011,  864,  871,    0,    0,  -26,  774, -250, -169,  -26,
 -216,  -26,    0, -178,    0,  -23,  -31,  -45,    0, -174,
  -29, 1011, -197,    0,    4,    0,  -19,    0,  -14,  935,
    5,    0,    0, 1054,    0,    0, 1039,    0, -180,  876,
    0,    0,    0,    0,    0, -154, 1006,  -13,    0,    0,
  -58,    0,  913, 1011, -173, 1011,  -58,   -6,  -49,    0,
    0, 1011,    0,    0, -178, -187,   12,   19,    0, 1011,
    0,   24,    0,    0,    0,  883,   11,    0,   10,   29,
    0,   14,    0, 1006,  935,    0,   13,  833,  -58,   38,
    0,  980,   39,    0,    0,    0,    0,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -85,    0,    0,    0,
    0,    0,    0,   33,    0, -199,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  715,    0,    0,    0,  533,
    0,    0,    0,  569,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  753,    0,  677,    0,    0,
    0,    0,    0,    0,  605,    0,    0,    0,    0,  320,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -251,
    0,    0,    0,    0,   36,    0,  119,  211,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -124,   33,  791,    0,   41,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -153,    0,
    0,    0,    0,    0,    0,    0, 1073,    0,    0,    0,
    0,    0,    0,    0,    0,  -28,  257,  303,  349,   21,
  165,   70,    0,    0,    0,  641,    0,    0,    0,    0,
    0,    0,   44,    0,    0,    0,    0,    0,  387, -143,
    0,    0,    0,    0,    0,    0,    0,    0,  931,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  425,    0,    0,    0,    0,    0,   54,    0,
    0,    0,    0,    0,    0,   33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   61,    0,    0,  461,    0,    0,    0,    0,    0,
    0,   33,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    7,    0,  198,    0,  284,    0,    0,    0,    0,  142,
 -122,  -44,  -11,  140,    0,    0,  322,    0,   -1,  321,
  -53,    0,    0,  307,  249,  162,  304,    0,  -47,    0,
  -63,  -81,    0,    0,  196,  323,   -2,    0, -108,    0,
    0,    0, -100,    0, -111,    0,    0,    0,    0,
};
#define YYTABLESIZE 1356
short yytable[] = {                                      33,
   86,  166,   41,  155,   90,   43,   47,   95,   24,  134,
   17,   68,   39,  103,   97,   98,  158,   90,  161,  173,
  126,   68,   15,   33,  110,   40,   33,  174,   48,   23,
  122,  113,   44,   68,  120,    4,    5,  123,  145,    7,
    8,   47,  127,    9,  107,  108,  175,  103,  142,  134,
   44,  143,   17,  109,   13,  146,  147,  148,  149,  150,
  151,  152,   16,  195,   17,  201,   18,  122,   52,   21,
  163,   23,    4,    5,    2,  145,    7,    8,  107,  170,
    9,   47,    2,   23,   42,   52,  115,  109,  190,   23,
   49,   13,  134,  180,  103,  134,  194,    2,   15,   16,
  213,   17,    2,   18,  183,  166,   21,  184,  204,  104,
  191,   73,  227,  202,  193,  144,  159,  105,   47,   67,
   23,   33,  167,  155,   52,  107,  108,  127,  214,   67,
  205,   42,   16,   16,  109,   16,   16,   16,   16,   53,
   16,   67,   72,   16,   79,   16,  120,   16,  216,  212,
   42,   16,   16,   81,  120,   82,   84,  220,   16,   16,
   16,   16,  225,   16,   16,   16,   16,   16,   87,   91,
   93,   66,   66,   96,   66,   66,   66,   66,   66,   66,
   16,   66,   66,   99,   66,  102,   66,   66,   66,  209,
   66,   66,  111,   66,  112,  217,   66,   66,   66,   66,
   66,   66,   66,   66,   66,   66,   66,   66,   66,   66,
   66,   66,  233,  118,  121,  125,   66,  138,   66,   66,
  237,  156,  139,  154,   15,   33,  167,  235,   75,   75,
  168,   75,   75,   75,   75,  172,   75,  103,   75,   75,
  171,   75,  187,   75,   75,   75,  176,   75,   75,  188,
   75,  189,  192,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,  197,   75,   75,   75,  196,
  198,  199,  208,   75,  223,   75,   75,   73,   73,  218,
   73,   73,   73,   73,  224,   73,  226,   73,   73,  230,
   73,  231,   73,   73,   73,  229,   73,   73,  232,   73,
  236,  238,   73,   73,   73,   73,   73,   73,   73,   73,
   73,   73,   73,   73,  234,   73,   73,   73,   18,    1,
  105,   18,   73,  120,   73,   73,   74,   74,   66,   74,
   74,   74,   74,   39,   74,  178,   74,   74,   94,   74,
  219,   74,   74,   74,  221,   74,   74,   77,   74,   78,
   83,   74,   74,   74,   74,   74,   74,   74,   74,   74,
   74,   74,   74,  157,   74,   74,   74,  222,  101,  200,
    0,   74,   88,   74,   74,   77,   77,    0,   77,   77,
   77,   77,    0,   77,    0,   77,   77,    0,   77,    0,
   77,   77,   77,    0,   77,   77,    0,   77,    0,    0,
   77,   77,   77,   77,   77,   77,   77,   77,   77,   77,
   77,   77,    0,    0,   77,   77,    0,    0,    0,    0,
   77,   72,   72,   77,   72,   72,   72,   72,    0,   72,
    0,   72,   72,    0,   72,    0,   72,   72,   72,    0,
   72,   72,    0,   72,    0,    0,   72,   72,   72,   72,
   72,   72,   72,   72,   72,   72,   72,   72,    0,    0,
   72,   72,    0,    0,    0,    0,   72,   76,   76,   72,
   76,   76,   76,   76,    0,   76,    0,   76,   76,    0,
   76,    0,   76,   76,   76,    0,   76,   76,    0,   76,
    0,    0,   76,   76,   76,   76,   76,    0,   76,   76,
   76,   76,   76,   76,    0,    0,    0,   76,    0,    0,
    0,    0,   76,   70,   70,   76,   70,   70,   70,   70,
    0,   70,    0,   70,   70,    0,   70,    0,   70,   70,
   70,    0,   70,   70,    0,   70,    0,    0,   70,   70,
   70,   70,   70,    0,   70,   70,   70,   70,   70,   70,
    0,    0,    0,   70,    0,    0,    0,    0,   70,   71,
   71,   70,   71,   71,   71,   71,    0,   71,    0,   71,
   71,    0,   71,    0,   71,   71,   71,    0,   71,   71,
    0,   71,    0,    0,   71,   71,   71,   71,   71,    0,
   71,   71,   71,   71,   71,   71,    0,    0,    0,   71,
    0,    0,    0,    0,   71,   69,   69,   71,   69,   69,
   69,   69,    0,   69,    0,   69,   69,    0,   69,    0,
   69,   69,   69,    0,   69,   69,    0,    0,    0,    0,
   69,   69,   69,   69,   69,    0,   69,   69,   69,   69,
   69,   69,    0,   25,   25,   69,   25,   25,   25,    0,
   69,   25,    0,   69,   25,    0,   25,    0,   25,    0,
    0,    0,   25,   25,    0,    0,    0,    0,    0,   25,
   25,    0,   25,    0,   25,   25,   25,   25,   25,    0,
    0,  102,  102,    0,  102,  102,  102,  102,    0,  102,
   25,   25,  102,    0,  102,    0,  102,    0,    0,    0,
  102,  102,    0,    0,    0,    0,    0,  102,  102,    0,
  102,    0,  102,  102,  102,  102,  102,  101,  101,    0,
  101,  101,  101,  101,    0,  101,    0,    0,  101,  102,
  101,    0,  101,    0,    0,    0,  101,  101,    0,    0,
    0,    0,    0,  101,  101,    0,  101,    0,  101,  101,
  101,  101,  101,    4,    5,    0,    6,    7,    8,    0,
    0,    9,    0,    0,   10,  101,   11,    0,   12,    0,
    0,    0,   13,   14,    0,    0,    0,    0,    0,   15,
   16,    0,   17,    0,   18,   19,   20,   21,   22,    4,
    4,    0,    4,    4,    4,    0,    0,    4,    0,    0,
    4,   23,    4,    0,    4,    0,    0,    0,    4,    4,
    0,    0,    0,    0,    0,    4,    4,    0,    4,    0,
    4,    4,    4,    4,    4,    5,    5,    0,    5,    5,
    5,    0,    0,    5,    0,    0,    5,    4,    5,    0,
    5,    0,    0,    0,    5,    5,    0,    0,    0,    0,
    0,    5,    5,    0,    5,    0,    5,    5,    5,    5,
    5,    3,    3,    0,    3,    3,    3,    0,    0,    3,
    0,    0,    3,    5,    3,    0,    3,    0,    0,    0,
    3,    3,    0,    0,    0,    0,    0,    3,    3,    0,
    3,    0,    3,    3,    3,    3,    3,  118,  118,    0,
  118,  118,  118,    0,    0,  118,    0,    0,  118,    3,
  118,    0,  118,    0,    0,    0,  118,  118,    0,    0,
    0,    0,    0,  118,  118,    0,  118,    0,  118,  118,
  118,  118,  118,  105,  105,    0,    0,  105,  105,    0,
    0,  105,    0,    0,    0,  118,    0,    0,    0,    0,
  105,    0,  105,  140,  103,    0,    0,  141,  105,  105,
  105,  105,  105,    0,  105,    0,    0,  105,    0,  104,
    0,   94,   94,  105,    0,   94,   94,  105,  105,   94,
    0,  105,    0,  106,    0,  107,  108,    0,   94,    0,
   94,  124,  103,    0,  109,    0,   94,   94,   94,    0,
   94,    0,   94,    0,    0,   94,    0,  104,    0,   95,
   95,   94,    0,   95,   95,  105,   94,   95,    0,   94,
    0,  106,    0,  107,  108,    0,   95,    0,   95,  153,
  103,    0,  109,    0,   95,   95,   95,  103,   95,    0,
   95,    0,    0,   95,    0,  104,    0,   63,   63,   95,
    0,   63,   63,  105,   95,   63,    0,   95,    0,  106,
  105,  107,  108,    0,   63,    0,   63,    0,  107,  108,
  109,    0,   63,   63,   63,    0,   63,  109,   63,    0,
    0,   63,    0,    4,    5,  164,    0,   63,    8,    4,
    5,    9,   63,    6,    8,   63,    0,    9,    0,    0,
    0,   10,  165,   11,    0,   12,    0,    0,  165,   15,
   16,    0,   17,    0,   18,   15,   16,   21,   17,    0,
   18,    0,   19,   21,    0,   22,  181,  103,    0,    0,
    0,   23,    0,  182,  103,    0,  114,   23,  203,  103,
    0,    0,  104,    0,    0,  228,  103,    0,    0,  104,
  105,    0,    0,    0,  104,    0,  106,  105,  107,  108,
    0,  104,  105,  106,    0,  107,  108,  109,  106,  105,
  107,  108,  103,    0,  109,  106,  103,  107,  108,  109,
    0,    0,    0,    0,    0,    0,  109,  104,    0,    0,
    0,  104,    0,  162,   66,  105,    0,  210,  103,  105,
    0,  106,    0,  107,  108,  106,    0,  107,  108,   66,
    0,    0,  109,  104,    0,   66,  109,   66,    0,    0,
    0,  105,    0,   66,    0,   66,   66,  106,   85,  107,
  108,   56,    0,   57,   66,  100,    0,   58,  109,    6,
   59,    0,   60,    0,    0,   61,    0,   10,   17,   11,
    0,   12,   55,    0,    0,   56,    0,   57,   62,    0,
   63,   58,   64,   65,   59,    6,   60,   23,   19,   61,
    0,   22,   17,   10,    0,   11,   85,   12,   73,   56,
    0,   57,   62,    0,   63,   58,   64,   65,   59,    0,
   60,   23,    0,   61,   19,    0,   17,   22,    0,    0,
   55,    0,    0,   56,  128,   57,   62,   56,   63,   58,
   64,   65,   59,   58,   60,   23,   59,   61,   60,  128,
  179,   61,   56,    0,    0,    0,    0,    0,   58,    0,
   62,   59,   63,   60,   64,   65,  129,    0,   39,   23,
    0,   39,    0,    0,    0,    0,    0,   39,  130,  131,
   39,    0,   39,    0,    0,   39,
};
short yycheck[] = {                                       2,
   48,  124,    4,  112,   52,    8,    9,   55,    2,   91,
  286,  263,  297,  264,   62,   63,  117,   65,  119,  131,
  263,  273,  283,   26,   72,  286,   29,  285,  266,  305,
   84,   79,  266,  285,   82,  257,  258,   85,  102,  261,
  262,   44,  285,  265,  295,  296,  304,  264,   96,  131,
  266,   99,  286,  304,  276,  103,  104,  105,  106,  107,
  108,  109,  284,  164,  286,  177,  288,  121,  266,  291,
  286,  305,  257,  258,  274,  139,  261,  262,  295,  127,
  265,   84,  282,  305,  286,  266,   80,  304,  263,  305,
  304,  276,  174,  141,  264,  177,  294,  297,  283,  284,
  274,  286,  302,  288,  283,  228,  291,  286,  263,  279,
  285,  299,  213,  294,  162,  273,  118,  287,  121,  263,
  305,  124,  124,  232,  266,  295,  296,  285,  302,  273,
  285,  285,  257,  258,  304,  260,  261,  262,  263,  286,
  265,  285,  266,  268,  294,  270,  194,  272,  196,  194,
  304,  276,  277,  285,  202,  294,  285,  202,  283,  284,
  285,  286,  210,  288,  289,  290,  291,  292,  286,  304,
  285,  257,  258,  266,  260,  261,  262,  263,  264,  265,
  305,  267,  268,  266,  270,  285,  272,  273,  274,  191,
  276,  277,  286,  279,  285,  197,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  297,  224,  266,  285,  304,  302,  286,  304,  305,
  232,  286,  285,  266,  283,  228,  228,  229,  257,  258,
  286,  260,  261,  262,  263,  295,  265,  264,  267,  268,
  280,  270,  266,  272,  273,  274,  296,  276,  277,  281,
  279,  297,  282,  282,  283,  284,  285,  286,  287,  288,
  289,  290,  291,  292,  293,  285,  295,  296,  297,  266,
  285,  267,  286,  302,  263,  304,  305,  257,  258,  286,
  260,  261,  262,  263,  266,  265,  263,  267,  268,  280,
  270,  263,  272,  273,  274,  285,  276,  277,  285,  279,
  263,  263,  282,  283,  284,  285,  286,  287,  288,  289,
  290,  291,  292,  293,  302,  295,  296,  297,  286,    0,
  285,  281,  302,  263,  304,  305,  257,  258,  285,  260,
  261,  262,  263,  280,  265,  138,  267,  268,   55,  270,
  199,  272,  273,  274,  205,  276,  277,   26,  279,   29,
   44,  282,  283,  284,  285,  286,  287,  288,  289,  290,
  291,  292,  293,  115,  295,  296,  297,  206,   65,  174,
   -1,  302,   50,  304,  305,  257,  258,   -1,  260,  261,
  262,  263,   -1,  265,   -1,  267,  268,   -1,  270,   -1,
  272,  273,  274,   -1,  276,  277,   -1,  279,   -1,   -1,
  282,  283,  284,  285,  286,  287,  288,  289,  290,  291,
  292,  293,   -1,   -1,  296,  297,   -1,   -1,   -1,   -1,
  302,  257,  258,  305,  260,  261,  262,  263,   -1,  265,
   -1,  267,  268,   -1,  270,   -1,  272,  273,  274,   -1,
  276,  277,   -1,  279,   -1,   -1,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,   -1,   -1,
  296,  297,   -1,   -1,   -1,   -1,  302,  257,  258,  305,
  260,  261,  262,  263,   -1,  265,   -1,  267,  268,   -1,
  270,   -1,  272,  273,  274,   -1,  276,  277,   -1,  279,
   -1,   -1,  282,  283,  284,  285,  286,   -1,  288,  289,
  290,  291,  292,  293,   -1,   -1,   -1,  297,   -1,   -1,
   -1,   -1,  302,  257,  258,  305,  260,  261,  262,  263,
   -1,  265,   -1,  267,  268,   -1,  270,   -1,  272,  273,
  274,   -1,  276,  277,   -1,  279,   -1,   -1,  282,  283,
  284,  285,  286,   -1,  288,  289,  290,  291,  292,  293,
   -1,   -1,   -1,  297,   -1,   -1,   -1,   -1,  302,  257,
  258,  305,  260,  261,  262,  263,   -1,  265,   -1,  267,
  268,   -1,  270,   -1,  272,  273,  274,   -1,  276,  277,
   -1,  279,   -1,   -1,  282,  283,  284,  285,  286,   -1,
  288,  289,  290,  291,  292,  293,   -1,   -1,   -1,  297,
   -1,   -1,   -1,   -1,  302,  257,  258,  305,  260,  261,
  262,  263,   -1,  265,   -1,  267,  268,   -1,  270,   -1,
  272,  273,  274,   -1,  276,  277,   -1,   -1,   -1,   -1,
  282,  283,  284,  285,  286,   -1,  288,  289,  290,  291,
  292,  293,   -1,  257,  258,  297,  260,  261,  262,   -1,
  302,  265,   -1,  305,  268,   -1,  270,   -1,  272,   -1,
   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,  283,
  284,   -1,  286,   -1,  288,  289,  290,  291,  292,   -1,
   -1,  257,  258,   -1,  260,  261,  262,  263,   -1,  265,
  304,  305,  268,   -1,  270,   -1,  272,   -1,   -1,   -1,
  276,  277,   -1,   -1,   -1,   -1,   -1,  283,  284,   -1,
  286,   -1,  288,  289,  290,  291,  292,  257,  258,   -1,
  260,  261,  262,  263,   -1,  265,   -1,   -1,  268,  305,
  270,   -1,  272,   -1,   -1,   -1,  276,  277,   -1,   -1,
   -1,   -1,   -1,  283,  284,   -1,  286,   -1,  288,  289,
  290,  291,  292,  257,  258,   -1,  260,  261,  262,   -1,
   -1,  265,   -1,   -1,  268,  305,  270,   -1,  272,   -1,
   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,   -1,  283,
  284,   -1,  286,   -1,  288,  289,  290,  291,  292,  257,
  258,   -1,  260,  261,  262,   -1,   -1,  265,   -1,   -1,
  268,  305,  270,   -1,  272,   -1,   -1,   -1,  276,  277,
   -1,   -1,   -1,   -1,   -1,  283,  284,   -1,  286,   -1,
  288,  289,  290,  291,  292,  257,  258,   -1,  260,  261,
  262,   -1,   -1,  265,   -1,   -1,  268,  305,  270,   -1,
  272,   -1,   -1,   -1,  276,  277,   -1,   -1,   -1,   -1,
   -1,  283,  284,   -1,  286,   -1,  288,  289,  290,  291,
  292,  257,  258,   -1,  260,  261,  262,   -1,   -1,  265,
   -1,   -1,  268,  305,  270,   -1,  272,   -1,   -1,   -1,
  276,  277,   -1,   -1,   -1,   -1,   -1,  283,  284,   -1,
  286,   -1,  288,  289,  290,  291,  292,  257,  258,   -1,
  260,  261,  262,   -1,   -1,  265,   -1,   -1,  268,  305,
  270,   -1,  272,   -1,   -1,   -1,  276,  277,   -1,   -1,
   -1,   -1,   -1,  283,  284,   -1,  286,   -1,  288,  289,
  290,  291,  292,  257,  258,   -1,   -1,  261,  262,   -1,
   -1,  265,   -1,   -1,   -1,  305,   -1,   -1,   -1,   -1,
  274,   -1,  276,  263,  264,   -1,   -1,  267,  282,  283,
  284,  285,  286,   -1,  288,   -1,   -1,  291,   -1,  279,
   -1,  257,  258,  297,   -1,  261,  262,  287,  302,  265,
   -1,  305,   -1,  293,   -1,  295,  296,   -1,  274,   -1,
  276,  263,  264,   -1,  304,   -1,  282,  283,  284,   -1,
  286,   -1,  288,   -1,   -1,  291,   -1,  279,   -1,  257,
  258,  297,   -1,  261,  262,  287,  302,  265,   -1,  305,
   -1,  293,   -1,  295,  296,   -1,  274,   -1,  276,  263,
  264,   -1,  304,   -1,  282,  283,  284,  264,  286,   -1,
  288,   -1,   -1,  291,   -1,  279,   -1,  257,  258,  297,
   -1,  261,  262,  287,  302,  265,   -1,  305,   -1,  293,
  287,  295,  296,   -1,  274,   -1,  276,   -1,  295,  296,
  304,   -1,  282,  283,  284,   -1,  286,  304,  288,   -1,
   -1,  291,   -1,  257,  258,  259,   -1,  297,  262,  257,
  258,  265,  302,  260,  262,  305,   -1,  265,   -1,   -1,
   -1,  268,  276,  270,   -1,  272,   -1,   -1,  276,  283,
  284,   -1,  286,   -1,  288,  283,  284,  291,  286,   -1,
  288,   -1,  289,  291,   -1,  292,  263,  264,   -1,   -1,
   -1,  305,   -1,  263,  264,   -1,  303,  305,  263,  264,
   -1,   -1,  279,   -1,   -1,  263,  264,   -1,   -1,  279,
  287,   -1,   -1,   -1,  279,   -1,  293,  287,  295,  296,
   -1,  279,  287,  293,   -1,  295,  296,  304,  293,  287,
  295,  296,  264,   -1,  304,  293,  264,  295,  296,  304,
   -1,   -1,   -1,   -1,   -1,   -1,  304,  279,   -1,   -1,
   -1,  279,   -1,  285,  264,  287,   -1,  285,  264,  287,
   -1,  293,   -1,  295,  296,  293,   -1,  295,  296,  279,
   -1,   -1,  304,  279,   -1,  285,  304,  287,   -1,   -1,
   -1,  287,   -1,  293,   -1,  295,  296,  293,  266,  295,
  296,  269,   -1,  271,  304,  273,   -1,  275,  304,  260,
  278,   -1,  280,   -1,   -1,  283,   -1,  268,  286,  270,
   -1,  272,  266,   -1,   -1,  269,   -1,  271,  296,   -1,
  298,  275,  300,  301,  278,  260,  280,  305,  289,  283,
   -1,  292,  286,  268,   -1,  270,  266,  272,  299,  269,
   -1,  271,  296,   -1,  298,  275,  300,  301,  278,   -1,
  280,  305,   -1,  283,  289,   -1,  286,  292,   -1,   -1,
  266,   -1,   -1,  269,  266,  271,  296,  269,  298,  275,
  300,  301,  278,  275,  280,  305,  278,  283,  280,  266,
  286,  283,  269,   -1,   -1,   -1,   -1,   -1,  275,   -1,
  296,  278,  298,  280,  300,  301,  283,   -1,  266,  305,
   -1,  269,   -1,   -1,   -1,   -1,   -1,  275,  295,  296,
  278,   -1,  280,   -1,   -1,  283,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"T_GOTO","T_RETURN","T_THEN",
"T_COMPLEX","T_DO","T_CALL","T_RPAREN","T_POWEROP","T_READ","T_LPAREN",
"T_COLON","T_REAL","T_CCONST","T_LOGICAL","T_LENGTH","T_CHARACTER","T_RBRACK",
"T_ELSE","T_SCONST","T_IF","T_COMMON","T_LCONST","T_ANDOP","T_RCONST",
"T_FUNCTION","T_ENDDO","T_ICONST","T_CONTINUE","T_COMMA","T_ID","T_RELOP",
"T_STOP","T_INTEGER","T_DATA","T_WRITE","T_STRING","T_OROP","T_ASSIGN",
"T_MULOP","T_ADDOP","T_END","T_NOTOP","T_LIST","T_NEW","T_LBRACK","T_ENDIF",
"T_SUBROUTINE","T_DIVOP","T_LISTFUNC",
};
char *yyrule[] = {
"$accept : program",
"program : body T_END subprograms",
"body : declarations statements",
"declarations : declarations type vars",
"declarations : declarations T_COMMON cblock_list",
"declarations : declarations T_DATA vals",
"declarations :",
"type : T_INTEGER",
"type : T_REAL",
"type : T_COMPLEX",
"type : T_LOGICAL",
"type : T_CHARACTER",
"type : T_STRING",
"vars : vars T_COMMA undef_variable",
"vars : undef_variable",
"undef_variable : listspec T_ID T_LPAREN dims T_RPAREN",
"undef_variable : listspec T_ID",
"listspec : T_LIST",
"listspec :",
"dims : dims T_COMMA dim",
"dims : dim",
"dim : T_ICONST",
"dim : T_ID",
"cblock_list : cblock_list cblock",
"cblock_list : cblock",
"cblock : T_DIVOP T_ID T_DIVOP id_list",
"id_list : id_list T_COMMA T_ID",
"id_list : T_ID",
"vals : vals T_COMMA T_ID value_list",
"vals : T_ID value_list",
"value_list : T_DIVOP values T_DIVOP",
"values : values T_COMMA value",
"values : value",
"value : repeat sign constant",
"value : T_ADDOP constant",
"value : constant",
"repeat : T_ICONST T_MULOP",
"repeat : T_MULOP",
"sign : T_ADDOP",
"sign :",
"constant : simple_constant",
"constant : complex_constant",
"simple_constant : T_ICONST",
"simple_constant : T_RCONST",
"simple_constant : T_LCONST",
"simple_constant : T_CCONST",
"simple_constant : T_SCONST",
"complex_constant : T_LPAREN T_RCONST T_COLON sign T_RCONST T_RPAREN",
"statements : statements labeled_statement",
"statements : labeled_statement",
"labeled_statement : label statement",
"labeled_statement : statement",
"label : T_ICONST",
"statement : simple_statement",
"statement : compound_statement",
"simple_statement : assignment",
"simple_statement : goto_statement",
"simple_statement : if_statement",
"simple_statement : subroutine_call",
"simple_statement : io_statement",
"simple_statement : T_CONTINUE",
"simple_statement : T_RETURN",
"simple_statement : T_STOP",
"assignment : variable T_ASSIGN expression",
"variable : T_ID T_LPAREN expressions T_RPAREN",
"variable : T_LISTFUNC T_LPAREN expression T_RPAREN",
"variable : T_ID",
"expressions : expressions T_COMMA expression",
"expressions : expression",
"expression : expression T_OROP expression",
"expression : expression T_ANDOP expression",
"expression : expression T_RELOP expression",
"expression : expression T_ADDOP expression",
"expression : expression T_MULOP expression",
"expression : expression T_DIVOP expression",
"expression : expression T_POWEROP expression",
"expression : T_NOTOP expression",
"expression : T_ADDOP expression",
"expression : variable",
"expression : simple_constant",
"expression : T_LENGTH T_LPAREN expression T_RPAREN",
"expression : T_NEW T_LPAREN expression T_RPAREN",
"expression : T_LPAREN expression T_RPAREN",
"expression : T_LPAREN expression T_COLON expression T_RPAREN",
"expression : listexpression",
"listexpression : T_LBRACK expressions T_RBRACK",
"listexpression : T_LBRACK T_RBRACK",
"goto_statement : T_GOTO label",
"goto_statement : T_GOTO T_ID T_COMMA T_LPAREN labels T_RPAREN",
"labels : labels T_COMMA label",
"labels : label",
"if_statement : T_IF T_LPAREN expression T_RPAREN label T_COMMA label T_COMMA label",
"if_statement : T_IF T_LPAREN expression T_RPAREN simple_statement",
"subroutine_call : T_CALL variable",
"io_statement : T_READ read_list",
"io_statement : T_WRITE write_list",
"read_list : read_list T_COMMA read_item",
"read_list : read_item",
"read_item : variable",
"read_item : T_LPAREN read_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN",
"iter_space : expression T_COMMA expression step",
"step : T_COMMA expression",
"step :",
"write_list : write_list T_COMMA write_item",
"write_list : write_item",
"write_item : expression",
"write_item : T_LPAREN write_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN",
"compound_statement : branch_statement",
"compound_statement : loop_statement",
"branch_statement : T_IF T_LPAREN expression T_RPAREN T_THEN body tail",
"tail : T_ELSE body T_ENDIF",
"tail : T_ENDIF",
"loop_statement : T_DO T_ID T_ASSIGN iter_space body T_ENDDO",
"subprograms : subprograms subprogram",
"subprograms :",
"subprogram : header body T_END",
"header : type listspec T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN",
"header : T_SUBROUTINE T_ID T_LPAREN formal_parameters T_RPAREN",
"header : T_SUBROUTINE T_ID",
"formal_parameters : type vars T_COMMA formal_parameters",
"formal_parameters : type vars",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 1075 "parser.y"

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
#line 737 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 146 "parser.y"
{
    /* Create tree root.*/
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_END", "");
	children[2] = yyvsp[0].node;

	syntaxTreeRoot = makeTreeNode(children, 3, "program", "");
}
break;
case 2:
#line 156 "parser.y"
{
    /* Create tree node for nonterminal symbol "body".*/
    /* The same procedure follows for all remaining nonterminal symbols that are identified during syntax analysis.*/
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "body", "");
}
break;
case 3:
#line 166 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = yyvsp[-1].node;
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "declarations", "");
}
break;
case 4:
#line 174 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMON", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "declarations", "");
}
break;
case 5:
#line 182 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_DATA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "declarations", "");
}
break;
case 6:
#line 190 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "EmptyDeclaration", "");

	yyval.node = makeTreeNode(children, 1, "declarations", "");
}
break;
case 7:
#line 198 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_INTEGER", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 8:
#line 205 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_REAL", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 9:
#line 211 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_COMPLEX", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 10:
#line 217 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LOGICAL", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 11:
#line 223 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CHARACTER", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 12:
#line 228 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_STRING", "");

	yyval.node = makeTreeNode(children, 1, "type", "");
}
break;
case 13:
#line 235 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "vars", "");
}
break;
case 14:
#line 243 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "vars", "");
}
break;
case 15:
#line 250 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = yyvsp[-4].node;
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[3] = yyvsp[-1].node;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 5, "undef_variable", "");
}
break;
case 16:
#line 260 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 2, "undef_variable", "");
}
break;
case 17:
#line 268 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LIST", "");

	yyval.node = makeTreeNode(children, 1, "listspec", "");
}
break;
case 18:
#line 273 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	yyval.node = makeTreeNode(children, 1, "listspec", "");
}
break;
case 19:
#line 280 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "dims", "");
}
break;
case 20:
#line 288 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "dims", "");
}
break;
case 21:
#line 295 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "dim", "");
}
break;
case 22:
#line 301 "parser.y"
{
        TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
        children[0] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

        yyval.node = makeTreeNode(children, 1, "dim", "");
}
break;
case 23:
#line 308 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "cblock_list", "");
}
break;
case 24:
#line 315 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "cblock_list", "");
}
break;
case 25:
#line 322 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-2].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[3] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 4, "cblock", "");
}
break;
case 26:
#line 332 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 3, "id_list", "");
}
break;
case 27:
#line 340 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "id_list", "");
}
break;
case 28:
#line 347 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = yyvsp[-3].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-1].valueString);
	children[3] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 4, "vals", "");
}
break;
case 29:
#line 355 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-1].valueString);
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "vals", "");
}
break;
case 30:
#line 363 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[1] = yyvsp[-1].node;
	children[2] = makeTreeNode(NULL, 0, "T_DIVOP", "");

	yyval.node = makeTreeNode(children, 3, "value_list", "");
}
break;
case 31:
#line 372 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "values", "");
}
break;
case 32:
#line 380 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "values", "");
}
break;
case 33:
#line 387 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = yyvsp[-1].node;
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "value", "");
}
break;
case 34:
#line 394 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", yyvsp[-1].valueString);
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "value", "");
}
break;
case 35:
#line 401 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "value", "");
}
break;
case 36:
#line 408 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", yyvsp[-1].valueString);
	children[1] = makeTreeNode(NULL, 0, "T_MULOP", "");

	yyval.node = makeTreeNode(children, 2, "repeat", "");
}
break;
case 37:
#line 416 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_MULOP", "");

	yyval.node = makeTreeNode(children, 1, "repeat", "");
}
break;
case 38:
#line 423 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "sign", "");
}
break;
case 39:
#line 428 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	yyval.node = makeTreeNode(children, 1, "sign", "");
}
break;
case 40:
#line 435 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "constant", "");
}
break;
case 41:
#line 441 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "constant", "");
}
break;
case 42:
#line 448 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "simple_constant", "");
}
break;
case 43:
#line 453 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_RCONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "simple_constant", "");
}
break;
case 44:
#line 458 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LCONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "simple_constant", "");
}
break;
case 45:
#line 463 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CCONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "simple_constant", "");
}
break;
case 46:
#line 468 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SCONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "simple_constant", "");
}
break;
case 47:
#line 475 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = makeTreeNode(NULL, 0, "T_RCONST", yyvsp[-4].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_COLON", "");
	children[3] = yyvsp[-2].node;
	children[4] = makeTreeNode(NULL, 0, "T_RCONST", yyvsp[-1].valueString);
	children[5] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 6, "complex_constant", "");
}
break;
case 48:
#line 487 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "statements", "");
}
break;
case 49:
#line 494 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "statements", "");
}
break;
case 50:
#line 501 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "labeled_statement", "");
}
break;
case 51:
#line 508 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "labeled_statement", "");
}
break;
case 52:
#line 515 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ICONST", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "label", "");
}
break;
case 53:
#line 522 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "statement", "");
}
break;
case 54:
#line 528 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "statement", "");
}
break;
case 55:
#line 535 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 56:
#line 541 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 57:
#line 547 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 58:
#line 553 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 59:
#line 559 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 60:
#line 566 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CONTINUE", "");

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 61:
#line 572 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_RETURN", "");

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 62:
#line 578 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_STOP", "");

	yyval.node = makeTreeNode(children, 1, "simple_statement", "");
}
break;
case 63:
#line 585 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "assignment", "");
}
break;
case 64:
#line 594 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-1].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 4, "variable", "");
}
break;
case 65:
#line 603 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LISTFUNC", yyvsp[-3].valueString);
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-1].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 4, "variable", "");
}
break;
case 66:
#line 612 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 1, "variable", "");
}
break;
case 67:
#line 619 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expressions", "");
}
break;
case 68:
#line 627 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "expressions", "");
}
break;
case 69:
#line 634 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_OROP", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 70:
#line 642 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_ANDOP", yyvsp[-1].valueString);
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 71:
#line 650 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_RELOP", yyvsp[-1].valueString);
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 72:
#line 659 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_ADDOP", yyvsp[-1].valueString);
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 73:
#line 667 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_MULOP", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 74:
#line 675 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_DIVOP", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 75:
#line 683 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_POWEROP", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 76:
#line 691 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_NOTOP", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "expression", "");
}
break;
case 77:
#line 698 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ADDOP", yyvsp[-1].valueString);
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "expression", "");
}
break;
case 78:
#line 705 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "expression", "");
}
break;
case 79:
#line 711 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "expression", "");
}
break;
case 80:
#line 717 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LENGTH", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-1].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 4, "expression", "");
}
break;
case 81:
#line 726 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_NEW", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-1].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 4, "expression", "");
}
break;
case 82:
#line 735 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = yyvsp[-1].node;
	children[2] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 3, "expression", "");
}
break;
case 83:
#line 744 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = yyvsp[-3].node;
	children[2] = makeTreeNode(NULL, 0, "T_COLON", "");
	children[3] = yyvsp[-1].node;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 5, "expression", "");
}
break;
case 84:
#line 754 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "expression", "");
}
break;
case 85:
#line 761 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LBRACK", "");
	children[1] = yyvsp[-1].node;
	children[2] = makeTreeNode(NULL, 0, "T_RBRACK", "");

	yyval.node = makeTreeNode(children, 3, "listexpression", "");
}
break;
case 86:
#line 769 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LBRACK", "");
	children[1] = makeTreeNode(NULL, 0, "T_RBRACK", "");

	yyval.node = makeTreeNode(children, 2, "listexpression", "");
}
break;
case 87:
#line 777 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_GOTO", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "goto_statement", "");
}
break;
case 88:
#line 784 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_GOTO", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-4].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[4] = yyvsp[-1].node;
	children[5] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 6, "goto_statement", "");
}
break;
case 89:
#line 796 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "labels", "");
}
break;
case 90:
#line 804 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "labels", "");
}
break;
case 91:
#line 811 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(9*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-6].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = yyvsp[-4].node;
	children[5] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[6] = yyvsp[-2].node;
	children[7] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[8] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 9, "if_statement", "");
}
break;
case 92:
#line 825 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-2].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 5, "if_statement", "");
}
break;
case 93:
#line 836 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_CALL", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "subroutine_call", "");
}
break;
case 94:
#line 844 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_READ", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "io_statement", "");
}
break;
case 95:
#line 851 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_WRITE", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "io_statement", "");
}
break;
case 96:
#line 859 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "read_list", "");
}
break;
case 97:
#line 867 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "read_list", "");
}
break;
case 98:
#line 874 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "read_item", "");
}
break;
case 99:
#line 880 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = yyvsp[-5].node;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[4] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[5] = yyvsp[-1].node;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 7, "read_item", "");
}
break;
case 100:
#line 893 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = yyvsp[-3].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[-1].node;
	children[3] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 4, "iter_space", "");
}
break;
case 101:
#line 903 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "step", "");
}
break;
case 102:
#line 910 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	yyval.node = makeTreeNode(children, 1, "step", "");
}
break;
case 103:
#line 917 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[2] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 3, "write_list", "");
}
break;
case 104:
#line 925 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "write_list", "");
}
break;
case 105:
#line 932 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "write_item", "");
}
break;
case 106:
#line 938 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[1] = yyvsp[-5].node;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[4] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[5] = yyvsp[-1].node;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 7, "write_item", "");
}
break;
case 107:
#line 951 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "compound_statement", "");
}
break;
case 108:
#line 957 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 1, "compound_statement", "");
}
break;
case 109:
#line 964 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_IF", "");
	children[1] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[2] = yyvsp[-4].node;
	children[3] = makeTreeNode(NULL, 0, "T_RPAREN", "");
	children[4] = makeTreeNode(NULL, 0, "T_THEN", "");
	children[5] = yyvsp[-1].node;
	children[6] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 7, "branch_statement", "");
}
break;
case 110:
#line 977 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ELSE", "");
	children[1] = yyvsp[-1].node;
	children[2] = makeTreeNode(NULL, 0, "T_ENDIF", "");

	yyval.node = makeTreeNode(children, 3, "tail", "");
}
break;
case 111:
#line 985 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_ENDIF", "");

	yyval.node = makeTreeNode(children, 1, "tail", "");
}
break;
case 112:
#line 992 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(6*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_DO", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-4].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_ASSIGN", "");
	children[3] = yyvsp[-2].node;
	children[4] = yyvsp[-1].node;
	children[5] = makeTreeNode(NULL, 0, "T_ENDDO", "");

	yyval.node = makeTreeNode(children, 6, "loop_statement", "");
}
break;
case 113:
#line 1004 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "subprograms", "");
}
break;
case 114:
#line 1011 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(1*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "Empty", "");

	yyval.node = makeTreeNode(children, 1, "subprograms", "");
}
break;
case 115:
#line 1018 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(3*sizeof(TreeNode*));
	children[0] = yyvsp[-2].node;
	children[1] = yyvsp[-1].node;
	children[2] = makeTreeNode(NULL, 0, "T_END", "");

	yyval.node = makeTreeNode(children, 3, "subprogram", "");
}
break;
case 116:
#line 1027 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(7*sizeof(TreeNode*));
	children[0] = yyvsp[-6].node;
	children[1] = yyvsp[-5].node;
	children[2] = makeTreeNode(NULL, 0, "T_FUNCTION", "");
	children[3] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[4] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[5] = yyvsp[-1].node;
	children[6] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 7, "header", "");
}
break;
case 117:
#line 1038 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(5*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SUBROUTINE", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[-3].valueString);
	children[2] = makeTreeNode(NULL, 0, "T_LPAREN", "");
	children[3] = yyvsp[-1].node;
	children[4] = makeTreeNode(NULL, 0, "T_RPAREN", "");

	yyval.node = makeTreeNode(children, 5, "header", "");
}
break;
case 118:
#line 1048 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = makeTreeNode(NULL, 0, "T_SUBROUTINE", "");
	children[1] = makeTreeNode(NULL, 0, "T_ID", yyvsp[0].valueString);

	yyval.node = makeTreeNode(children, 2, "header", "");
}
break;
case 119:
#line 1056 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(4*sizeof(TreeNode*));
	children[0] = yyvsp[-3].node;
	children[1] = yyvsp[-2].node;
	children[2] = makeTreeNode(NULL, 0, "T_COMMA", "");
	children[3] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 4, "formal_parameters", "");
}
break;
case 120:
#line 1065 "parser.y"
{
	TreeNode** children = (TreeNode **) safeMalloc(2*sizeof(TreeNode*));
	children[0] = yyvsp[-1].node;
	children[1] = yyvsp[0].node;

	yyval.node = makeTreeNode(children, 2, "formal_parameters", "");
}
break;
#line 2119 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
