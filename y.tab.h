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
typedef union
{
    int   yint;
    char  ystr[81];
    struct AstNode_tag *stnode;
} YYSTYPE;
extern YYSTYPE yylval;
