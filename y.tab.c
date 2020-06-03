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
#line 2 "simple_java.yacc"
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
#line 35 "simple_java.yacc"
typedef union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
} YYSTYPE;
#line 51 "y.tab.c"
#define ELSE 257
#define IF 258
#define PRINTLN 259
#define WHILE 260
#define FOR 261
#define T_STATIC 262
#define T_MAINCLASS 263
#define T_VOID 264
#define T_MAIN 265
#define T_PUBLIC 266
#define INT 267
#define FLOAT 268
#define GE 269
#define LE 270
#define NE 271
#define EQ 272
#define ID 273
#define LITERAL 274
#define NUM 275
#define UMINUS 276
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    7,    1,    1,    2,    2,    2,    2,    2,    2,
    2,    8,   10,   10,   11,   11,    9,    3,   12,   13,
   13,    4,   15,   15,   16,   16,    5,    6,   18,   18,
   17,   19,   19,   19,   19,   19,   19,   14,   14,   14,
   20,   20,   20,   21,   21,   21,   21,
};
short yylen[] = {                                         2,
   11,    3,    0,    2,    2,    1,    1,    1,    1,    2,
    5,    2,    1,    1,    3,    1,    1,    1,    3,    1,
    1,    9,    0,    1,    0,    1,    5,    6,    0,    2,
    3,    1,    1,    1,    1,    1,    1,    3,    3,    1,
    3,    3,    1,    3,    2,    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   13,   14,    0,    0,
    0,    0,    6,    7,    8,    9,    0,    0,   18,    1,
    0,    0,    0,    0,    0,    2,    4,   17,    5,   10,
    0,   12,    0,    0,    0,   47,   20,    0,    0,    0,
    0,   43,    0,    0,   24,    0,   19,    0,    0,   46,
   45,   36,   34,   35,   33,   37,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   15,   44,   31,    0,
    0,    0,   41,   42,   11,   27,    0,   26,    0,   28,
    0,   30,    0,    0,   22,
};
short yydgoto[] = {                                       2,
   20,   21,   22,   23,   24,   25,   26,   27,   39,   28,
   42,   47,   48,   49,   56,   87,   50,   90,   68,   51,
   52,
};
short yysindex[] = {                                   -234,
 -224,    0,  -73, -205, -200, -201, -199,   24,   27,  -54,
 -120,  -60,   31,   32,   33,   34,    0,    0,   17,  -46,
 -120,   21,    0,    0,    0,    0,   21, -192,    0,    0,
  -40,  -40,  -40, -191,  -40,    0,    0,    0,    0,    0,
   39,    0,  -40,  -39,   17,    0,    0,  -58,   10,   43,
  -30,    0,   44,   45,    0,   28,    0, -192,   47,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,  -39,  -39,
 -120,  -39,  -39,   21, -120,  -40,    0,    0,    0,  -30,
  -30, -168,    0,    0,    0,    0,   35,    0, -120,    0,
 -191,    0,   49, -120,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   36,    0,    0,    0,    0,    0,    0,
   38,    0,    0,    0,  -32,    0,    0,    0,  -15,    0,
  -27,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,    0,    0,    0,  -22,
   -2, -103,    0,    0,    0,    0,    0,    0,    0,    0,
   51,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   72,  -19,    0,    0,    0,    0,   88,    0,  -20,    0,
   46,   25,   -1,    0,   11,    0,  -25,    0,    0,  -45,
    4,
};
#define YYTABLESIZE 270
short yytable[] = {                                      43,
   43,   65,   11,   63,   44,   44,   40,   54,   46,   46,
   46,   72,   46,   40,   46,   40,   73,   40,   38,   29,
   38,   29,   38,   80,   81,   21,   46,   46,    1,   46,
   53,   40,   40,   57,   40,   29,   38,   38,   39,   38,
   39,   59,   39,   21,   21,   29,   21,   61,    3,    4,
   88,   82,   69,   85,   70,   86,   39,   39,   55,   39,
    5,    6,    7,    9,   30,    8,   79,   10,   11,   92,
   31,   32,   33,   34,   95,   83,   84,   35,   36,   38,
   41,   19,   58,   71,   74,   75,   76,   78,   89,   94,
    3,   23,   37,   91,   23,   29,   16,   12,   25,   29,
    0,   93,    0,   77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   29,    0,   55,    0,    0,   29,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   13,   14,   15,
   16,    0,    0,    0,    0,    0,   17,   18,    0,    0,
    0,    0,   19,    0,   29,   29,   29,   29,    0,    0,
    0,    0,    0,   29,   29,    0,    0,    0,    0,   29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,   64,   66,   67,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,   60,   46,   46,   46,   46,   46,   46,
    0,   40,   40,   40,   40,    0,   38,   38,   38,   38,
    0,    0,    0,   21,   21,   21,   21,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   39,   39,   39,   39,
};
short yycheck[] = {                                      40,
   40,   60,  123,   62,   45,   45,   27,   33,   41,   42,
   43,   42,   45,   41,   47,   43,   47,   45,   41,  123,
   43,  125,   45,   69,   70,   41,   59,   60,  263,   62,
   32,   59,   60,   35,   62,   11,   59,   60,   41,   62,
   43,   43,   45,   59,   60,   21,   62,   44,  273,  123,
   76,   71,   43,   74,   45,   75,   59,   60,   34,   62,
  266,  262,  264,   40,  125,  265,   68,   41,  123,   89,
   40,   40,   40,   40,   94,   72,   73,   61,  125,   59,
  273,  273,   44,   41,   41,   41,   59,   41,  257,   41,
  125,   41,   21,   59,   59,   71,   59,   10,   59,   75,
   -1,   91,   -1,   58,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   89,   -1,   91,   -1,   -1,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,  260,
  261,   -1,   -1,   -1,   -1,   -1,  267,  268,   -1,   -1,
   -1,   -1,  273,   -1,  258,  259,  260,  261,   -1,   -1,
   -1,   -1,   -1,  267,  268,   -1,   -1,   -1,   -1,  273,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  269,  270,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  273,  273,  275,  275,  269,  270,  271,  272,
   -1,  269,  270,  271,  272,   -1,  269,  270,  271,  272,
   -1,   -1,   -1,  269,  270,  271,  272,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,  270,  271,  272,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 276
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,
0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",
"'|'","'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ELSE","IF","PRINTLN","WHILE","FOR",
"T_STATIC","T_MAINCLASS","T_VOID","T_MAIN","T_PUBLIC","INT","FLOAT","GE","LE",
"NE","EQ","ID","LITERAL","NUM","UMINUS",
};
char *yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : T_MAINCLASS ID '{' T_PUBLIC T_STATIC T_VOID T_MAIN '(' ')' COMP_STMT '}'",
"COMP_STMT : '{' STMT_LIST '}'",
"STMT_LIST :",
"STMT_LIST : STMT STMT_LIST",
"STMT : ASSIGN_STMT NULL_STMT",
"STMT : FOR_STMT",
"STMT : WHILE_STMT",
"STMT : IF_STMT",
"STMT : COMP_STMT",
"STMT : DECLARATION NULL_STMT",
"STMT : PRINTLN '(' EXPR ')' NULL_STMT",
"DECLARATION : TYPE ID_LIST",
"TYPE : INT",
"TYPE : FLOAT",
"ID_LIST : ID ',' ID_LIST",
"ID_LIST : ID",
"NULL_STMT : ';'",
"ASSIGN_STMT : ASSIGN_EXPR",
"ASSIGN_EXPR : ID '=' EXPR",
"EXPR : ASSIGN_EXPR",
"EXPR : RVAL",
"FOR_STMT : FOR '(' OPASSIGN_EXPR ';' OPBOOL_EXPR ';' OPASSIGN_EXPR ')' STMT",
"OPASSIGN_EXPR :",
"OPASSIGN_EXPR : ASSIGN_EXPR",
"OPBOOL_EXPR :",
"OPBOOL_EXPR : BOOL_EXPR",
"WHILE_STMT : WHILE '(' BOOL_EXPR ')' STMT",
"IF_STMT : IF '(' BOOL_EXPR ')' STMT ELSE_PART",
"ELSE_PART :",
"ELSE_PART : ELSE STMT",
"BOOL_EXPR : EXPR C_OP EXPR",
"C_OP : EQ",
"C_OP : '<'",
"C_OP : '>'",
"C_OP : LE",
"C_OP : GE",
"C_OP : NE",
"RVAL : RVAL '+' TERM",
"RVAL : RVAL '-' TERM",
"RVAL : TERM",
"TERM : TERM '*' FACTOR",
"TERM : TERM '/' FACTOR",
"TERM : FACTOR",
"FACTOR : '(' EXPR ')'",
"FACTOR : '-' FACTOR",
"FACTOR : ID",
"FACTOR : NUM",
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
#line 479 "simple_java.yacc"

#include "simple_java_abstract_tree_src.c"
#line 286 "y.tab.c"
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
#line 65 "simple_java.yacc"
{
#ifdef DEBUG
printf("PROGRAM BEG #0\n");
#endif
		TreeRoot = MkNode(astProgram, NULL, yyvsp[-1].stnode, NULL, NULL, NULL);
	 }
break;
case 2:
#line 73 "simple_java.yacc"
{
#ifdef DEBUG
printf("COMP_STMT NOT EMPTY #2\n");
#endif

if(yyvsp[-1].stnode == NULL) {
	yyval.stnode = MkNode(astCompEmptyStmt, NULL, NULL, NULL, NULL, NULL);
} else {
	yyval.stnode = MkNode(astCompStmt, NULL, yyvsp[-1].stnode, NULL, NULL, NULL);
}

}
break;
case 3:
#line 87 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT_LIST EMPTY #3\n");
#endif

/*$$ = MkNode(astEmptyStmt, NULL, NULL, NULL, NULL, NULL);*/
yyval.stnode = NULL;
}
break;
case 4:
#line 97 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT_LIST NOT EMPTY #4\n");
#endif

if(yyvsp[0].stnode == NULL) {
	yyval.stnode = MkNode(astStmt, NULL, yyvsp[-1].stnode, NULL, NULL, NULL);
} else {
	yyval.stnode = MkNode(astStmt, NULL, yyvsp[-1].stnode, yyvsp[0].stnode, NULL, NULL);
}

}
break;
case 5:
#line 111 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-ASSIGN-STMT #5\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[-1].stnode;
}
break;
case 6:
#line 121 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-FOR_STMT #6\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 7:
#line 131 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-WHILE_STMT #7\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 8:
#line 141 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-IF_STMT #8\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 9:
#line 151 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-COMP_STMT #9\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 10:
#line 161 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-DECLARATION #10\n");
#endif

/*$$ = MkNode(astStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[-1].stnode;
}
break;
case 11:
#line 171 "simple_java.yacc"
{
#ifdef DEBUG
printf("STMT-println #12\n");
#endif

yyval.stnode = MkNode(astPrintlnStmt, NULL, yyvsp[-2].stnode, NULL, NULL, NULL);
/*$$ = MkNode(astStmt, NULL, MkNode(astPrintlnStmt, NULL, $3, NULL, NULL, NULL), NULL, NULL, NULL);*/
}
break;
case 12:
#line 181 "simple_java.yacc"
{
#ifdef DEBUG
printf("DECLARATION #13\n");
#endif

yyval.stnode = MkNode(astDeclSeqBeg, NULL, yyvsp[-1].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 13:
#line 189 "simple_java.yacc"
{
#ifdef DEBUG
printf("TYPE-INT #14\n");
#endif

yyval.stnode = MkNode(INT, NULL, NULL, NULL, NULL, NULL);
}
break;
case 14:
#line 198 "simple_java.yacc"
{
#ifdef DEBUG
printf("TYPE-FLOAT #15\n");
#endif

yyval.stnode = MkNode(FLOAT, NULL, NULL, NULL, NULL, NULL);
}
break;
case 15:
#line 206 "simple_java.yacc"
{
#ifdef DEBUG
printf("ID_LIST ID,ID_LIST #16\n");
#endif

p1=new_symbol(yyvsp[-2].ystr);
yyval.stnode=MkNode(astVarDcltr,p1,yyvsp[0].stnode,NULL,NULL,NULL);
push_vs(p1); 
add_symbols_to_table(p1);
}
break;
case 16:
#line 216 "simple_java.yacc"
{
#ifdef DEBUG
printf("ID_LIST ID #17\n");
#endif
p1=new_symbol(yyvsp[0].ystr);
yyval.stnode=MkNode(astVarDcltr,p1,NULL,NULL,NULL,NULL);
push_vs(p1); 
add_symbols_to_table(p1);
}
break;
case 17:
#line 226 "simple_java.yacc"
{
#ifdef DEBUG
printf("NULL_STMT #18\n");
#endif
}
break;
case 18:
#line 232 "simple_java.yacc"
{
#ifdef DEBUG
printf("ASSIGN_STMT-ASSIGN_EXPR #19\n");
#endif

/*$$ = MkNode(astAssignStmt, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 19:
#line 241 "simple_java.yacc"
{
#ifdef DEBUG
printf("ASSIGN_EXPR ID=EXPR #20\n");
#endif

p1=findsymb(yyvsp[-2].ystr);
if(!p1) {
   printf("Identifier %s not declared\n", yyvsp[-2].ystr);
   exit(1);
}

yyval.stnode = MkNode(astAssign, NULL, MkNode(astId, p1, NULL, NULL, NULL, NULL), yyvsp[0].stnode, NULL, NULL);
}
break;
case 20:
#line 255 "simple_java.yacc"
{
#ifdef DEBUG
printf("EXPR ASSIGN_EXPR #21\n");
#endif

yyval.stnode = yyvsp[0].stnode;
}
break;
case 21:
#line 263 "simple_java.yacc"
{
#ifdef DEBUG
printf("EXPR RVAL #22\n");
#endif

yyval.stnode = yyvsp[0].stnode;
}
break;
case 22:
#line 271 "simple_java.yacc"
{
#ifdef DEBUG
printf("FOR_STMT #23\n");
#endif

yyval.stnode = MkNode(astForStmt, NULL, yyvsp[-6].stnode, yyvsp[-4].stnode, yyvsp[-2].stnode, yyvsp[0].stnode);
}
break;
case 23:
#line 279 "simple_java.yacc"
{
#ifdef DEBUG
printf("OPASSIGN_EXPR EMPTY #24\n");
#endif

yyval.stnode = MkNode(astOPassignExprEmpty, NULL, NULL,NULL, NULL, NULL);
}
break;
case 24:
#line 287 "simple_java.yacc"
{
#ifdef DEBUG
printf("OPASSIGN_EXPR NOT EMPTY #25\n");
#endif

yyval.stnode = yyvsp[0].stnode;
}
break;
case 25:
#line 295 "simple_java.yacc"
{
#ifdef DEBUG
printf("OPBOOL_EXPR EMPTY #26\n");
#endif


yyval.stnode = MkNode(astOPboolExprEmpty, NULL, NULL, NULL, NULL, NULL);
}
break;
case 26:
#line 304 "simple_java.yacc"
{
#ifdef DEBUG
printf("OPBOOL_EXPR NOT EMPTY #27\n");
#endif

yyval.stnode = yyvsp[0].stnode;
}
break;
case 27:
#line 312 "simple_java.yacc"
{
#ifdef DEBUG
printf("WHILE_STMT #28\n");
#endif

yyval.stnode = MkNode(astWhileStmt, NULL, yyvsp[-2].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 28:
#line 320 "simple_java.yacc"
{
#ifdef DEBUG
printf("IF_STMT #29\n");
#endif

if(yyvsp[0].stnode==NULL) {
	yyval.stnode = MkNode(astIfStmt, NULL, yyvsp[-3].stnode, yyvsp[-1].stnode, NULL, NULL);
} else {
	yyval.stnode = MkNode(astIfElseStmt, NULL, yyvsp[-3].stnode, yyvsp[-1].stnode, yyvsp[0].stnode, NULL);
}
}
break;
case 29:
#line 332 "simple_java.yacc"
{
#ifdef DEBUG
printf("ELSE_PART EMPTY #30.1\n");
#endif

yyval.stnode = NULL;
}
break;
case 30:
#line 341 "simple_java.yacc"
{
#ifdef DEBUG
printf("ELSE_PART #30\n");
#endif

yyval.stnode = MkNode(astElseStmt, NULL, yyvsp[0].stnode, NULL, NULL, NULL);
}
break;
case 31:
#line 349 "simple_java.yacc"
{
#ifdef DEBUG
printf("BOOL_EXPR #31\n");
#endif

yyval.stnode = MkNode(astBoolExpr, NULL, yyvsp[-2].stnode, yyvsp[-1].stnode, yyvsp[0].stnode, NULL);
}
break;
case 32:
#line 357 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP EQ #32\n");
#endif

yyval.stnode = MkNode(astEq, NULL, NULL, NULL, NULL, NULL);
}
break;
case 33:
#line 364 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP < #33\n");
#endif

yyval.stnode = MkNode(astLess, NULL, NULL, NULL, NULL, NULL);
}
break;
case 34:
#line 371 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP > #34\n");
#endif
yyval.stnode = MkNode(astGreater, NULL, NULL, NULL, NULL, NULL);
}
break;
case 35:
#line 377 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP LE #35\n");
#endif

yyval.stnode = MkNode(astLeEq, NULL, NULL, NULL, NULL, NULL);
}
break;
case 36:
#line 384 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP GE #36\n");
#endif

yyval.stnode = MkNode(astGrEq, NULL, NULL, NULL, NULL, NULL);
}
break;
case 37:
#line 390 "simple_java.yacc"
{
#ifdef DEBUG
printf("C_OP NE #37\n");
#endif

yyval.stnode = MkNode(astNotEq, NULL, NULL, NULL, NULL, NULL);
}
break;
case 38:
#line 398 "simple_java.yacc"
{
#ifdef DEBUG
printf("RVAL RVAL+TERM #38\n");
#endif

yyval.stnode = MkNode(astAdd, NULL, yyvsp[-2].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 39:
#line 404 "simple_java.yacc"
{
#ifdef DEBUG
printf("RVAL RVAL-TERM #39\n");
#endif

yyval.stnode = MkNode(astSub, NULL, yyvsp[-2].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 40:
#line 410 "simple_java.yacc"
{
#ifdef DEBUG
printf("RVAL TERM #40\n");
#endif

/*$$ = MkNode(astRVALTerm, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 41:
#line 419 "simple_java.yacc"
{
#ifdef DEBUG
printf("TERM TERM*FACTOR #41\n");
#endif

yyval.stnode = MkNode(astMult, NULL, yyvsp[-2].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 42:
#line 426 "simple_java.yacc"
{
#ifdef DEBUG
printf("TERM TERM/FACTOR #42\n");
#endif

yyval.stnode = MkNode(astDiv, NULL, yyvsp[-2].stnode, yyvsp[0].stnode, NULL, NULL);
}
break;
case 43:
#line 432 "simple_java.yacc"
{
#ifdef DEBUG
printf("TERM FACTOR #43\n");
#endif

/*$$ = MkNode(astTermFact, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[0].stnode;
}
break;
case 44:
#line 441 "simple_java.yacc"
{
#ifdef DEBUG
printf("FACTOR (EXPR) #44\n");
#endif

/*$$ = MkNode(astFactor, NULL, $1, NULL, NULL, NULL);*/
yyval.stnode = yyvsp[-2].ystr;
}
break;
case 45:
#line 449 "simple_java.yacc"
{
#ifdef DEBUG
printf("FACTOR -FACTOR #45\n");
#endif

yyval.stnode = MkNode(astFactorN, NULL, yyvsp[0].stnode, NULL, NULL, NULL);
}
break;
case 46:
#line 456 "simple_java.yacc"
{
#ifdef DEBUG
printf("FACTOR ID #46\n");
#endif

p1=findsymb(yyvsp[0].ystr);
if(!p1) {
   printf("Identifier %s not declared\n", yyvsp[0].ystr);
   exit(1);
}

yyval.stnode = MkNode(astId, p1, NULL, NULL, NULL, NULL);
}
break;
case 47:
#line 468 "simple_java.yacc"
{
#ifdef DEBUG
printf("FACTOR NUM #47\n");
#endif

p1=new_symbol(yyvsp[0].ystr);
yyval.stnode = MkNode(astDecimConst, p1, NULL, NULL, NULL, NULL);
}
break;
#line 938 "y.tab.c"
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
