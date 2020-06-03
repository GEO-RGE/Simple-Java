%{
#include<stdio.h>
#include <stdlib.h>
#include "defs.h"


#define DEBUG
#define DEBUG_YACC_ONLY

/* ----------------------------------------------------------- */
/* --------- Declarations for Syntax-Semantic Analysis ------- */
/* ----------------------------------------------------------- */
symbol *Cross_Link_Head[MAX_CROSS_LINKS];

typedef struct hash_tab {
   int numbsymbols;
   symbol *table[SYM_TABLE_SIZE];
} HASH_TAB;

HASH_TAB ht;

int TopOfStack=-1;
symbol *vs[30];

symbol *Symbol_free=NULL; /* -- Symbol-list of recycled symbols -- */
symbol *p,*p1,*p2,*p3;

AstNode *TreeRoot;

#ifdef YYDEBUG
yydebug = 1;
#endif
%}

%union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
}

%token <yint> ELSE IF PRINTLN WHILE FOR T_STATIC T_MAINCLASS T_VOID T_MAIN T_PUBLIC INT FLOAT
%token <ystr> '(' ')' '{' '}'
%token <ystr> '*' '/' '%' '+' '-' '=' ';' ',' '|' '&'
%token <ystr> GE '>' LE '<' NE EQ
%token <ystr> ID LITERAL
%token <ystr> NUM

%type <stnode> PROGRAM
%type <stnode> STMT_LIST STMT ASSIGN_STMT FOR_STMT WHILE_STMT
%type <stnode> IF_STMT COMP_STMT DECLARATION NULL_STMT TYPE ID_LIST ASSIGN_EXPR
%type <stnode> EXPR RVAL OPASSIGN_EXPR OPBOOL_EXPR BOOL_EXPR ELSE_PART C_OP TERM RVAL FACTOR

%start PROGRAM

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS  /*supplies precedence for unary minus */

%%                   /* beginning of rules section */

PROGRAM: T_MAINCLASS ID '{' T_PUBLIC T_STATIC T_VOID T_MAIN '(' ')' COMP_STMT '}'
	 {
#ifdef DEBUG
printf("PROGRAM BEG #0\n");
#endif
		TreeRoot = MkNode(astProgram, NULL, $10, NULL, NULL, NULL);
	 };

COMP_STMT: '{' STMT_LIST '}'
{
#ifdef DEBUG
printf("COMP_STMT NOT EMPTY #2\n");
#endif

if($2 == NULL) {
	$$ = MkNode(astCompEmptyStmt, NULL, NULL, NULL, NULL, NULL);
} else {
	$$ = MkNode(astCompStmt, NULL, $2, NULL, NULL, NULL);
}

};

STMT_LIST: /* EMPTY STATE */
{
#ifdef DEBUG
printf("STMT_LIST EMPTY #3\n");
#endif

$$ = NULL;
}
	 |
	 STMT STMT_LIST
{
#ifdef DEBUG
printf("STMT_LIST NOT EMPTY #4\n");
#endif

if($2 == NULL) {
	$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);
} else {
	$$ = MkNode(astStmt, NULL, $1, $2, NULL, NULL);
}

};

STMT: ASSIGN_STMT NULL_STMT
{
#ifdef DEBUG
printf("STMT-ASSIGN-STMT #5\n");
#endif

$$ = $1;
}
    |
      FOR_STMT
{
#ifdef DEBUG
printf("STMT-FOR_STMT #6\n");
#endif

$$ = $1;
}
    |
      WHILE_STMT
{
#ifdef DEBUG
printf("STMT-WHILE_STMT #7\n");
#endif

$$ = $1;
}
    |
      IF_STMT
{
#ifdef DEBUG
printf("STMT-IF_STMT #8\n");
#endif

$$ = $1;
}
    |
      COMP_STMT
{
#ifdef DEBUG
printf("STMT-COMP_STMT #9\n");
#endif

$$ = $1;
}
    |
      DECLARATION NULL_STMT
{
#ifdef DEBUG
printf("STMT-DECLARATION #10\n");
#endif

$$ = $1;
}
    |
      PRINTLN '(' EXPR ')' NULL_STMT
{
#ifdef DEBUG
printf("STMT-println #12\n");
#endif

$$ = MkNode(astPrintlnStmt, NULL, $3, NULL, NULL, NULL);
};

DECLARATION: TYPE ID_LIST
{
#ifdef DEBUG
printf("DECLARATION #13\n");
#endif

$$ = MkNode(astDeclSeqBeg, NULL, $1, $2, NULL, NULL);
};
TYPE: INT
{
#ifdef DEBUG
printf("TYPE-INT #14\n");
#endif

$$ = MkNode(INT, NULL, NULL, NULL, NULL, NULL);
}
    |
      FLOAT
{
#ifdef DEBUG
printf("TYPE-FLOAT #15\n");
#endif

$$ = MkNode(FLOAT, NULL, NULL, NULL, NULL, NULL);
};
ID_LIST: ID ',' ID_LIST
{
#ifdef DEBUG
printf("ID_LIST ID,ID_LIST #16\n");
#endif

p1=new_symbol($1);
$$=MkNode(astVarDcltr,p1,$3,NULL,NULL,NULL);
push_vs(p1); 
add_symbols_to_table(p1);
} | ID
{
#ifdef DEBUG
printf("ID_LIST ID #17\n");
#endif
p1=new_symbol($1);
$$=MkNode(astVarDcltr,p1,NULL,NULL,NULL,NULL);
push_vs(p1); 
add_symbols_to_table(p1);
};
NULL_STMT: ';'
{
#ifdef DEBUG
printf("NULL_STMT #18\n");
#endif
};
ASSIGN_STMT: ASSIGN_EXPR
{
#ifdef DEBUG
printf("ASSIGN_STMT-ASSIGN_EXPR #19\n");
#endif

//$$ = MkNode(astAssignStmt, NULL, $1, NULL, NULL, NULL);
$$ = $1;
};
ASSIGN_EXPR: ID '=' EXPR
{
#ifdef DEBUG
printf("ASSIGN_EXPR ID=EXPR #20\n");
#endif

p1=findsymb($1);
if(!p1) {
   printf("Identifier %s not declared\n", $1);
   exit(1);
}

$$ = MkNode(astAssign, NULL, MkNode(astId, p1, NULL, NULL, NULL, NULL), $3, NULL, NULL);
};
EXPR: ASSIGN_EXPR
{
#ifdef DEBUG
printf("EXPR ASSIGN_EXPR #21\n");
#endif

$$ = $1;
} |
RVAL
{
#ifdef DEBUG
printf("EXPR RVAL #22\n");
#endif

$$ = $1;
};
FOR_STMT: FOR '(' OPASSIGN_EXPR ';' OPBOOL_EXPR ';' OPASSIGN_EXPR ')' STMT
{
#ifdef DEBUG
printf("FOR_STMT #23\n");
#endif

$$ = MkNode(astForStmt, NULL, $3, $5, $7, $9);
}; 
OPASSIGN_EXPR: /* empty state */
{
#ifdef DEBUG
printf("OPASSIGN_EXPR EMPTY #24\n");
#endif

$$ = MkNode(astOPassignExprEmpty, NULL, NULL,NULL, NULL, NULL);
}
	     | ASSIGN_EXPR
{
#ifdef DEBUG
printf("OPASSIGN_EXPR NOT EMPTY #25\n");
#endif

$$ = $1;
};
OPBOOL_EXPR: /* empty state */
{
#ifdef DEBUG
printf("OPBOOL_EXPR EMPTY #26\n");
#endif


$$ = MkNode(astOPboolExprEmpty, NULL, NULL, NULL, NULL, NULL);
}
	   | BOOL_EXPR
{
#ifdef DEBUG
printf("OPBOOL_EXPR NOT EMPTY #27\n");
#endif

$$ = $1;
};
WHILE_STMT: WHILE '(' BOOL_EXPR ')' STMT
{
#ifdef DEBUG
printf("WHILE_STMT #28\n");
#endif

$$ = MkNode(astWhileStmt, NULL, $3, $5, NULL, NULL);
};
IF_STMT: IF '(' BOOL_EXPR ')' STMT ELSE_PART
{
#ifdef DEBUG
printf("IF_STMT #29\n");
#endif

if($6==NULL) {
	$$ = MkNode(astIfStmt, NULL, $3, $5, NULL, NULL);
} else {
	$$ = MkNode(astIfElseStmt, NULL, $3, $5, $6, NULL);
}
};
ELSE_PART: /* NO ELSE PART */
{
#ifdef DEBUG
printf("ELSE_PART EMPTY #30.1\n");
#endif

$$ = NULL;
}
		 |
ELSE STMT
{
#ifdef DEBUG
printf("ELSE_PART #30\n");
#endif

$$ = MkNode(astElseStmt, NULL, $2, NULL, NULL, NULL);
};
BOOL_EXPR: EXPR C_OP EXPR
{
#ifdef DEBUG
printf("BOOL_EXPR #31\n");
#endif

$$ = MkNode(astBoolExpr, NULL, $1, $2, $3, NULL);
};
C_OP: EQ
{
#ifdef DEBUG
printf("C_OP EQ #32\n");
#endif

$$ = MkNode(astEq, NULL, NULL, NULL, NULL, NULL);
} | '<' 
{
#ifdef DEBUG
printf("C_OP < #33\n");
#endif

$$ = MkNode(astLess, NULL, NULL, NULL, NULL, NULL);
} | '>' 
{
#ifdef DEBUG
printf("C_OP > #34\n");
#endif
$$ = MkNode(astGreater, NULL, NULL, NULL, NULL, NULL);
} | LE 
{
#ifdef DEBUG
printf("C_OP LE #35\n");
#endif

$$ = MkNode(astLeEq, NULL, NULL, NULL, NULL, NULL);
} | GE 
{
#ifdef DEBUG
printf("C_OP GE #36\n");
#endif

$$ = MkNode(astGrEq, NULL, NULL, NULL, NULL, NULL);
} | NE {
#ifdef DEBUG
printf("C_OP NE #37\n");
#endif

$$ = MkNode(astNotEq, NULL, NULL, NULL, NULL, NULL);
};
RVAL: RVAL '+' TERM 
{
#ifdef DEBUG
printf("RVAL RVAL+TERM #38\n");
#endif

$$ = MkNode(astAdd, NULL, $1, $3, NULL, NULL);
} | RVAL '-' TERM {
#ifdef DEBUG
printf("RVAL RVAL-TERM #39\n");
#endif

$$ = MkNode(astSub, NULL, $1, $3, NULL, NULL);
} | TERM {
#ifdef DEBUG
printf("RVAL TERM #40\n");
#endif

//$$ = MkNode(astRVALTerm, NULL, $1, NULL, NULL, NULL);
$$ = $1;
};
TERM: TERM '*' FACTOR 
{
#ifdef DEBUG
printf("TERM TERM*FACTOR #41\n");
#endif

$$ = MkNode(astMult, NULL, $1, $3, NULL, NULL);
} | TERM '/' FACTOR 
{
#ifdef DEBUG
printf("TERM TERM/FACTOR #42\n");
#endif

$$ = MkNode(astDiv, NULL, $1, $3, NULL, NULL);
} | FACTOR {
#ifdef DEBUG
printf("TERM FACTOR #43\n");
#endif

//$$ = MkNode(astTermFact, NULL, $1, NULL, NULL, NULL);
$$ = $1;
};
FACTOR: '(' EXPR ')' 
{
#ifdef DEBUG
printf("FACTOR (EXPR) #44\n");
#endif

//$$ = MkNode(astFactor, NULL, $1, NULL, NULL, NULL);
$$ = $1;
} | '-' FACTOR %prec UMINUS
{
#ifdef DEBUG
printf("FACTOR -FACTOR #45\n");
#endif

$$ = MkNode(astFactorN, NULL, $2, NULL, NULL, NULL);
} | ID 
{
#ifdef DEBUG
printf("FACTOR ID #46\n");
#endif

p1=findsymb($1);
if(!p1) {
   printf("Identifier %s not declared\n", $1);
   exit(1);
}

$$ = MkNode(astId, p1, NULL, NULL, NULL, NULL);
} | NUM {
#ifdef DEBUG
printf("FACTOR NUM #47\n");
#endif

p1=new_symbol($1);
$$ = MkNode(astDecimConst, p1, NULL, NULL, NULL, NULL);
};


%%

#include "simple_java_abstract_tree_src.c"