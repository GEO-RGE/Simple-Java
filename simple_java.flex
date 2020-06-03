%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
#include "defs.h"

// DEBUG PROPERTIES
#define DEBUG
//#define DEBUG_FLEX_ONLY

%}

_INT_ [[:digit:]]+

_FLOAT_ [[:digit:]]+\.[[:digit:]]+

id [[:alpha:]]([[:alpha:]]|[[:digit:]]|'_')*
literal \'[[:alpha:]]([[:alpha:]]|[[:digit:]]|'_')*\'
W [ \t\n\b\r]+

%%

"main" { 
#ifdef DEBUG
printf("MAIN KEYWORD\n");
#endif
yylval.yint=T_MAIN;
return(T_MAIN); }
"if"   {
#ifdef DEBUG
printf("IF KEYWORD\n");
#endif
yylval.yint=IF;
return(IF);     }
"else" { 
#ifdef DEBUG
printf("ELSE KEYWORD\n");
#endif
yylval.yint=ELSE;
return(ELSE);   }
"static" {
#ifdef DEBUG
printf("STATIC KEYWORD\n");
#endif
yylval.yint=T_STATIC;
return(T_STATIC); }
"void" { 
#ifdef DEBUG
printf("VOID KEYWORD\n");
#endif
yylval.yint=T_VOID;
return(T_VOID); }
"mainclass" { 
#ifdef DEBUG
printf("MAINCLASS KEYWORD\n");
#endif
yylval.yint=T_MAINCLASS;
return(T_MAINCLASS); }
"public" { 
#ifdef DEBUG
printf("PUBLIC KEYWORD\n");
#endif
yylval.yint=T_PUBLIC;
return(T_PUBLIC); }
"for" { 
#ifdef DEBUG
printf("FOR KEYWORD\n");
#endif
yylval.yint=FOR;
return(FOR); }
"while" { 
#ifdef DEBUG
printf("WHILE KEYWORD\n");
#endif
yylval.yint=WHILE;
return(WHILE); }
"println" { 
#ifdef DEBUG
printf("PRINTLN KEYWORD\n");
#endif
yylval.yint=PRINTLN;
return(PRINTLN); }
"int" {
#ifdef DEBUG
printf("INT KEYWORD\n");
#endif
yylval.yint=INT;
return(INT); }
"float" {
#ifdef DEBUG
printf("FLOAT KEYWORD\n");
#endif
yylval.yint=FLOAT;
return(FLOAT); }


"<=" { 
strcpy(yylval.ystr, yytext);
return(LE); }
">="  { 
strcpy(yylval.ystr, yytext);
return(GE); }
"==" { 
strcpy(yylval.ystr, yytext);
return(EQ); }
"!=" { 
strcpy(yylval.ystr, yytext);
return(NE); }

{literal} {
#ifdef DEBUG
printf("LITERAL %s\n", yytext);
#endif
strcpy(yylval.ystr, yytext);
return(LITERAL);
}


{_FLOAT_} { 
#ifdef DEBUG
printf("_FLOAT_: %s\n", yytext);
#endif
strcpy(yylval.ystr, yytext);
return(NUM);}

{_INT_} { 
#ifdef DEBUG
printf("_INT_: %s\n", yytext);
#endif
strcpy(yylval.ystr, yytext);
return(NUM);}


{id} {   
#ifdef DEBUG
	printf("ID: %s\n", yytext);
#endif
strcpy(yylval.ystr, yytext);
return(ID);}

[\{\}\(\)\,\;+-/*\=\<\>\!\%\/\&] { 
#ifdef DEBUG
printf("Special character %c\n", yytext[0]);
#endif
strcpy(yylval.ystr, yytext);
return yytext[0];}

{W} { /* eat them all! */ }
. { printf("Lexical error bad character %c\n", yytext[0]); } 


%%

#ifdef DEBUG_FLEX_ONLY
int yywrap(void) { return(1); }
int main(void) { while(yylex()); return(0); } 
#endif