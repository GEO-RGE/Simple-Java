#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "y.tab.h"

extern AstNode *TreeRoot;

/* ----------------------------------------------------------- */
/* ---------------------- FUNCTIONS -------------------------- */
/* ----------------------------------------------------------- */

void kena(int n)
{  int i;
   
   for(i=0; i<n; i++) printf(" ");
}

void traverse(AstNode *p,int n)
{  int i;

   n=n+3;
   if(p)
   {
      switch (p->NodeType)
      {
		 case astDeclSeqBeg:
			kena(n); printf("astDeclSeqBeg\n");
			break;
         case astEmptyProgram: 
            kena(n); printf("astEmptyProgram\n"); 
         break;
         case astProgram: 
            kena(n); printf("astProgram\n"); 
         break;
         case astEmptyDeclSeq: 
            kena(n); printf("astEmptyDeclSeq\n"); 
         break;
         case astDeclSeq: 
            kena(n); printf("astDeclSeq\n"); 
         break;
         case astDecl: 
            kena(n); printf("astDecl\n"); 
         break;
         case INT: 
            kena(n); printf("INT\n"); 
         break;
		 case FLOAT:
			kena(n); printf("FLOAT\n");
			break;
         case astVarDcltr: 
            kena(n); printf("astVarDcltr\n"); 
         break;
         case astDcltrSeq: 
            kena(n); printf("astDcltrSeq\n"); 
         break;   
         case astEmptyStmtSeq: 
            kena(n); printf("astEmptyStmtSeq\n"); 
         break;
         case astStmtSeq:
            kena(n); printf("astStmtSeq\n"); 
         break;
         case astExprStmt: 
            kena(n); printf("astExprStmt\n"); 
         break;
         case astNullStmt: 
            kena(n); printf("astNullStmt\n"); 
         break;
         case astDecimConst:
            kena(n); printf("astDecimConst=%s\n",(p->SymbolNode)->name); 
         break;
         case astId: 
            kena(n); printf("astId=%s\n",(p->SymbolNode)->name); 
         break;
         case astMult:
            kena(n); printf("astMult\n"); 
         break;
         case astDiv: 
            kena(n); printf("astDiv\n"); 
         break;
         case astMod: 
            kena(n); printf("astMod\n"); 
         break;
         case astAdd: 
            kena(n); printf("astAdd\n"); 
         break;
         case astSub: 
            kena(n); printf("astSub\n"); 
         break;
         case astGreater: 
            kena(n); printf("astGreater\n"); 
         break;
         case astGrEq: 
            kena(n); printf("astGrEq\n"); 
         break;
         case astLess: 
            kena(n); printf("astLess\n"); 
         break;
         case astLeEq: 
            kena(n); printf("astLeEq\n"); 
         break;
         case astEq: 
            kena(n); printf("astEq\n"); 
         break;
         case astNotEq: 
            kena(n); printf("astNotEq\n"); 
         break;
         case astAssign: 
            kena(n); printf("astAssign\n"); 
         break;
		 case astStmt:
			kena(n); printf("astStmt\n");
			break;
		 case astPrintlnStmt:
			kena(n); printf("astPrintlnStmt\n");
			break;
		 case astCompStmt:
			kena(n); printf("astCompStmt\n");
			break;
		 case astStmtList:
			kena(n); printf("astStmtList\n");
			break;
		 case astEmptyStmt:
			kena(n); printf("astEmptyStmt\n");
			break;
		 case astAssignStmt:
			kena(n); printf("astAssignStmt\n");
			break;
		 case astAssignExpr:
			kena(n); printf("astAssignExpr\n");
			break;
		 case astRVALAdd:
			kena(n); printf("astRVALAdd\n");
			break;
		 case astRVALSubstract:
			kena(n); printf("astRVALSubstract\n");
			break;
		 case astRVALTerm:
			kena(n); printf("astRVALTerm\n");
			break;
		 case astTermMult:
			kena(n); printf("astTermMult\n");
			break;
		 case astTermDiv:
			kena(n); printf("astTermDiv\n");
			break;
		 case astTermFact:
			kena(n); printf("astTermFact\n");
			break;
		 case astFactor:
			kena(n); printf("astFactor\n");
			break;
		 case astFactorN:
			kena(n); printf("astFactorN\n");
			break; 
		 case astFactorID:
			kena(n); printf("astFactorID\n");
			break;
		 case astFactorNum:
			kena(n); printf("astFactorNum\n");
			break;
		 case astWhileStmt:
			kena(n); printf("astWhileStmt\n");
			break;
		 case astBoolExpr:
			kena(n); printf("astBoolExpr\n");
			break;
		case astForStmt:
			kena(n); printf("astForStmt\n");
			break;
		case astEmptyElseStmt:
			kena(n); printf("astEmptyElseStmt\n");
			break;
		case astIfStmt:
			kena(n); printf("astIfStmt\n");
			break;
		case astIfElseStmt:
			kena(n); printf("astIfElseStmt\n");
			break;
		case astCompEmptyStmt:
			kena(n); printf("astCompEmptyStmt\n");
			break;
		
			
         default: 
            printf("AGNOSTO=%d\n",p->NodeType);
      }
      for(i=0; i<4; i++) traverse(p->pAstNode[i],n);
   }
}

yyerror(s)
char *s;
{
  fprintf(stderr, "%s\n",s);
}

yywrap()
{
  return(1);
}


void main(void)
{  AstNode *p;
   int lathos,i;
  
   Init_Hash_Table();
   Init_Cross_Link_Head();
   lathos=yyparse();
   if(!lathos) 
   {
      p=TreeRoot;
      traverse(p,-3);
   }
}