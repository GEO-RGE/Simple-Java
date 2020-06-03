#define SYM_TABLE_SIZE 41
#define MAX_CROSS_LINKS 1
#define NAME_MAX  32

#define astEmptyProgram	399
#define astProgram	400
#define astEmptyDeclSeq	401
#define astDeclSeq	402
#define astDecl         403
#define astVarDcltr	404
#define astArrayDcltr	405
#define astDcltrSeq	406
#define astWhileStmt	407
#define astIfElseStmt	408
#define astIfStmt       409
#define astEmptyStmt	410
#define astStmtList     411
#define astExprStmt	412
#define astNullStmt	413
#define astReadStmt	414
#define astPrintStmt	415
#define astDecimConst	416
#define astId		417
#define astArrayElem	418
#define astMinus        419
#define astNot		420
#define astMult		421
#define astDiv		422
#define astMod		423
#define astAdd		424
#define astSub		425
#define astGreater	426
#define astGrEq		427
#define astLess		428
#define astLeEq		429
#define astEq		430
#define astNotEq        431
#define astAnd		432
#define astOr		433
#define astAssignStmt       434
#define astCompStmt     437
#define astCompEmptyStmt 438
#define astEmptyStmtSeq 450
#define astStmtSeq 460
#define astAssign 461
#define astPrintlnStmt 462
#define astAssignExpr 463
#define astForStmt 464
#define astOPassignExprEmpty 465
#define astOPboolExprEmpty 466
#define astElseStmt 467
#define astBoolExpr 468
#define astStmt 475
#define astDeclSeqBeg 477
#define astRVALAdd 478
#define astRVALSubstract 479
#define astRVALTerm 480
#define astTermMult 481
#define astTermDiv 482
#define astTermFact 483
#define astFactor 484
#define astFactorN 485
#define astFactorID 486
#define astFactorNum 487
#define astEmptyElseStmt 488

#define TRUE  1
#define FALSE 0

#define POINTER         1
#define ARRAY           2
#define CONSTANT        3
#define MEMORY          4
#define REGISTER        5
#define STACK           6
#define INTCONST        7
#define IDENTIFIER      8
#define ARRAYELEM       9
#define ARITHEXPR      10
#define LOGICEXPR      11
#define ASSIGNMENT     12
#define CONST_VAL      13

/* ----------------------------------------------------------- */
/* ------------ THE STRUCTURE FOR THE SYMBOL NODES ----------- */
/* ----------------------------------------------------------- */

typedef struct dcl_tag {
   int dcl_type;                    /* -- ARRAY -------------- */
   int dim;                         /* -- Array dimension ---- */
   struct dcl_tag *next_dcl_type;
} dcl;

typedef struct symbol_tag {
   unsigned char name[NAME_MAX+1];  /* -- Variable name .----- */
   int sclass;                      /* -- REGISTER, CONSTANT,- */
                                    /* -- MEMORY, STACK. ----- */
   int typos;                       /* -- INT, FLOAT.--------------- */
   int timi;                        /* -- Value assigned . --- */
   int has_timi;                    /* -- FALSE if no value .- */
   int comes_from;                  /* -- IDENTIFIER, INTCONST,*/
                                    /* -- ARRAYELEM, ARITHEXPR,*/
                                    /* -- LOGICEXPR .--------- */
   int disposable;                  /* -- TRUE or FALSE .----- */
   int lvalue;                      /* -- TRUE or FALSE .----- */
   dcl *dcl_ptr;
   int dims;                        /* -- Temp for array dim . */
   struct symbol_tag *Next_in_Cross_Link;
   struct symbol_tag *NextSymbol;
   struct symbol_tag *PrevSymbol;
} symbol;

/* ----------------------------------------------------------- */
/* ----- THE STRUCTURE FOR THE ABSTRACT SYNTAX TREE NODES ---- */
/* ----------------------------------------------------------- */

typedef struct AstNode_tag {
    int NodeType;
    struct symbol_tag *SymbolNode;
    struct AstNode_tag *pAstNode[4];
} AstNode;

/* ----------------------------------------------------------- */
/* ----------------------- PROTOTYPES ------------------------ */
/* ----------------------------------------------------------- */

void yyerror(char *);
void Init_Hash_Table(void);
void Init_Cross_Link_Head(void);
AstNode *MkNode(int,symbol *,AstNode *,AstNode *,AstNode *,AstNode *);
void push_vs(symbol *);
symbol *pop_vs(void);
symbol *new_symbol(char *);
int hash_function(char *);
int set_class_types(symbol *, int);
void cpy_attributes(symbol *, symbol *);
symbol *reverse_cross_links(symbol *);
void Link_Symbol_to_Cross_Link(symbol *);
void addsymb(symbol *);
symbol *findsymb(char *);
void add_symbols_to_table(symbol *);
void discard_symbol(symbol *);
void add_array_dcl(symbol *);
void add_pointer_dcl(symbol *);
void copy_value(symbol *, symbol *);
void copy_symbol(symbol *, symbol *);
symbol *create_id(symbol *);
void dixe(symbol *);
int types_equivalent(symbol *, symbol *);
int is_integral(symbol *);
int is_scalar(symbol *);
void apply_unary_conv(symbol *);
void allowable_assignment(symbol *, symbol *);
symbol *check_indir(symbol *);
symbol *check_array(symbol *, symbol *);
symbol *check_minusop(symbol *);
symbol *check_notop(symbol *);
symbol *check_multop(symbol *, symbol *);
symbol *check_divop(symbol *, symbol *);
symbol *check_modop(symbol *, symbol *);
symbol *check_addop(symbol *, symbol *);
symbol *check_subop(symbol *, symbol *);
symbol *check_gtop(symbol *, symbol *);
symbol *check_geop(symbol *, symbol *);
symbol *check_ltop(symbol *, symbol *);
symbol *check_leop(symbol *, symbol *);
symbol *check_eqop(symbol *, symbol *);
symbol *check_neop(symbol *, symbol *);
symbol *check_andop(symbol *, symbol *);
symbol *check_orop(symbol *, symbol *);
symbol *check_assignment(symbol *,symbol *);
void check_if(symbol *, symbol *);
void check_ifelse(symbol *, symbol *, symbol *);
void check_while(symbol *, symbol *);
void check_read(symbol *);
void check_print(symbol *);
void kena(int);
void traverse(AstNode *,int);
void NewLabel(char *);
void emit_code(char,char *,char *,char *,char *);
void ProcessProgram(AstNode *, int);
void ProcessDeclSeq(AstNode *, int, int);
void ProcessDecl(AstNode *, int, int);
void ProcessVarDcltr(AstNode *);
void ProcessArrayDcltr(AstNode *, int, int);
void ProcessDcltrSeq(AstNode *, int, int);
void ProcessEmptyStmtSeq(void);
void ProcessStmtSeq(AstNode *, int, int);
void ProcessIfElseStmt(AstNode *, int, int);
void ProcessIfStmt(AstNode *, int, int);
void ProcessWhileStmt(AstNode *, int, int);
void ProcessExprStmt(AstNode *, int, int);
void ProcessNullStmt(void);
void ProcessReadStmt(AstNode *, int); 
void ProcessPrintStmt(AstNode *, int);
void ProcessDecimConst(AstNode *);
void ProcessId(AstNode *);
void ProcessArrayElem(AstNode *, int, int, int);
void ProcessMinus(AstNode *, int, int, int);
void ProcessNot(AstNode *, int, int, int);
void ProcessMult(AstNode *, int, int, int);
void ProcessDivMod(AstNode *, int, int, int);
void ProcessAdd(AstNode *, int, int, int);
void ProcessSub(AstNode *, int, int, int);
void ProcessComp(AstNode *, int, int, int);
void ProcessAnd(AstNode *, int, int, int);
void ProcessOr(AstNode *, int, int, int);
void ProcessAssign(AstNode *, int, int);
void CodeGeneration(AstNode *, int, int, int);
