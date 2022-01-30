%{
  #include <cstdio>
  #include <iostream>
  using namespace std;

  // Declare stuff from Flex that Bison needs to know about:
  extern int yylex();
  extern int yyparse();
  extern FILE *yyin;
 
  void yyerror(const char *s);
%}

%union {
  int ival;
  float fval;
  char *sval;
  bool bval;
  char *oval;
  char *spval;
  
  // keywords
  char *ifval;
  char *elseval;
  char *iqval;
  char *wival;
  char *aival;
  char *locval;
  char *endval;
  char *displayval;
  char *readval;
  char *whileval;
  char *includeval;
  char *libraryval;
  
  // special char
  char *hashval;
  char *atval;
  char *dollarval;
  char *percentval;
  char *andval;
  char *orval;
  char *openbrval;
  char *closebrval;
  
  // delimiter
  char *semival;
  char *commaval;
  char *opencurlyval;
  char *closecurlyval;
  char *oinvertedval;
  char *cinvertedval;
  char *fstopval;
  char *uscoreval;

  
  char *pval;
  char *dval;
  char *fuval;
  char *idval;
  char *sival;
}


%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <oval> OVAL
%token <spval> SPVAL

  // keywords
%token <ifval> IFVAL
%token <elseval> ELSEVAL
%token <iqval> IQVAL
%token <wival> WIVAL
%token <aival> AIVAL
%token <locval> LOCVAL
%token <endval> ENDVAL
%token <displayval> DISPLAYVAL
%token <readval> READVAL
%token <whileval> WHILEVAL
%token <includeval> INCLUDEVAL
%token <libraryval> LIBRARYVAL

// special chars 
%token <hashval> HASHVAL
%token <atval> ATVAL
%token <dollarval> DOLLARVAL
%token <percentval> PERCENTVAL
%token <andval> ANDVAL
%token <orval> ORVAL
%token <openbrval> OPENBRVAL
%token <closebrval> CLOSEBRVAL

//delimiter
%token <semival> SEMIVAL
%token <commaval> COMMAVAL
%token <opencurlyval> OPENCURLYVAL
%token <closecurlyval> CLOSECURLYVAL
%token <oinvertedval> OINVERTEDVAL
%token <cinvertedval> CINVERTEDVAL
%token <fstopval> FSTOPVAL
%token <uscoreval> USCOREVAL

%token <pval> PREPROVAL
%token <idval> IDVAL
%token <sival> SIVAL


%%

P:
  P DATATYPE IDVAL OVAL VALUE SEMIVAL    {
      cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n " << endl;
    }
  | DATATYPE IDVAL OVAL VALUE SEMIVAL    {
      cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P CONDITION DELIMITERS IDVAL OVAL VALUE DELIMITERS {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | CONDITION DELIMITERS IDVAL OVAL VALUE DELIMITERS {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P ELSEVAL OPENBRVAL CLOSEBRVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | ELSEVAL OPENBRVAL CLOSEBRVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P DISPLAYVAL OPENBRVAL VALUE CLOSEBRVAL SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | DISPLAYVAL OPENBRVAL VALUE CLOSEBRVAL SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P READVAL OPENBRVAL IDVAL CLOSEBRVAL SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | READVAL OPENBRVAL IDVAL CLOSEBRVAL SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P DIRECTIVE DIRECTIVE OPENBRVAL DIRECTIVE CLOSEBRVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | DIRECTIVE DIRECTIVE OPENBRVAL DIRECTIVE CLOSEBRVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P LOCEND SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  |  LOCEND SEMIVAL {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P COMMENT STRING {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  |  COMMENT STRING {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  | P DELIMITERS {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}
  |  DELIMITERS {
	  cout << "\n ----- STATEMENT ----- SUCCESSFULLY PARSED \n" << endl;
	}

;

VALUE: INT {cout << "Bison found an int " << endl; } |
	   FLOAT {cout << "Bison found a float " << endl; } |
	   STRING {cout << "Bison found a string" << endl; }
;	

DATATYPE: 
	IQVAL {cout << "Bison found an iq datatype " << endl; } |
	WIVAL {cout << "Bison found a wi datatype " << endl; } |
	AIVAL {cout << "Bison found an ai datatype " << endl; }
; 

LOCEND: 
	LOCVAL {cout << "Bison found a location keyword" << endl; } |
	ENDVAL {cout << "Bison found an end keyword" << endl; }
; 

CONDITION: 
	WHILEVAL {cout << "Bison found a whileloop keyword" << endl; } |
	IFVAL {cout << "Bison found an if keyword" << endl; }
; 

DELIMITERS: 
	OPENCURLYVAL {cout << "Bison found an opening curly bracket" << endl;} |
	CLOSECURLYVAL {cout << "Bison found an closing curly bracket" << endl;}
;

COMMENT: 
	SIVAL {cout << "Bison found a single comment" << endl;}
;

DIRECTIVE: 
	HASHVAL {cout << "Bison found a hash symbol" << endl; } |
	INCLUDEVAL {cout << "Bison found an include keyword" << endl;} |
	LIBRARYVAL {cout << "Bison found a library keyword" << endl;}
;

%%

int main(int, char**) {
  // Open a file handle to a particular file:
  FILE *read = fopen("input.wai", "r");
  // Make sure it is valid:
  if (!read) {
    cout << "input.wai cannot be opened! " << endl;
    return -1;
  }

  yyin = read;
  
  // Parse through the input:
  yyparse();
  
}

void yyerror(const char *s) {
  cout << "PARSING UNSUCESSFUL Message: " << s << endl;
  exit(-1);
}