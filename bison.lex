%{
	#include<iostream>
	
	#include "bison.tab.h"
	using namespace std;
	extern int yylex();
	
%}

%option noyywrap
%% 
[ \t\n]		;
[0-9]+\.[0-9]+		{ yylval.fval = atof(yytext); return FLOAT; 	};
[0-9]+				{ yylval.ival = atof(yytext); return INT;		};
"+"|"-"|"*"|"++"|"--"|"%"|"&&"|"||"|"!"|"<="|">="|"!="|"=="|"<"|">"|"=" 	{ cout << "Bison found an operator" << endl; yylval.oval = strdup(yytext); return OVAL;	};
"if"														{ yylval.ifval = strdup(yytext); return IFVAL;	};
"else"														{ cout << "Bison found an else keyword" << endl; yylval.elseval = strdup(yytext); return ELSEVAL;	};
"location"													{ yylval.locval = strdup(yytext); return LOCVAL;	};
"end"														{ yylval.endval = strdup(yytext); return ENDVAL;	};
"display"													{ cout << "Bison found a display keyword" << endl; yylval.displayval = strdup(yytext); return DISPLAYVAL;	};
"read"														{ cout << "Bison found a read keyword" << endl; yylval.readval = strdup(yytext); return READVAL;	};
"whileloop"													{ yylval.whileval = strdup(yytext); return WHILEVAL;	};
"include"													{ yylval.includeval = strdup(yytext); return INCLUDEVAL;	};
"library"													{ yylval.libraryval = strdup(yytext); return LIBRARYVAL;	};
"iq"														{ yylval.iqval = strdup(yytext); return IQVAL;	};
"wi"														{ yylval.wival = strdup(yytext); return WIVAL;	};
"ai"														{ yylval.aival = strdup(yytext); return AIVAL;	};
"#"															{ yylval.hashval = strdup(yytext); return HASHVAL;	};
"@"															{ cout << "Bison found a " << endl; yylval.atval = strdup(yytext); return ATVAL;	};
"$"															{ cout << "Bison found a dollar symbol" << endl; yylval.dollarval = strdup(yytext); return DOLLARVAL;	};
"%"															{ cout << "Bison found a percent symbol" << endl; yylval.percentval = strdup(yytext); return PERCENTVAL;	};
"&"															{ cout << "Bison found an and symbol" << endl; yylval.andval = strdup(yytext); return ANDVAL;	};
")"															{ cout << "Bison found a closing round bracket symbol" << endl; yylval.openbrval = strdup(yytext); return CLOSEBRVAL; 	};
"(" 														{ cout << "Bison found an opening round bracket symbol" << endl; yylval.closebrval = strdup(yytext); return OPENBRVAL;};
";" 														{ cout << "Bison found a semi colon" << endl; yylval.semival = strdup(yytext); return SEMIVAL;	};
"," 														{ cout << "Bison found a comma " << endl; yylval.commaval = strdup(yytext); return COMMAVAL;	};
"{" 														{ yylval.opencurlyval = strdup(yytext); return OPENCURLYVAL;	};
"}" 														{ yylval.closecurlyval = strdup(yytext); return CLOSECURLYVAL;	};
"." 														{ cout << "Bison found a full stop" << endl; yylval.fstopval = strdup(yytext); return FSTOPVAL;	};
"_" 														{ cout << "Bison found an underscore" << endl; yylval.uscoreval = strdup(yytext); return USCOREVAL;	};




"#.*"  														{ yylval.pval = strdup(yytext); return PREPROVAL;	};
[a-zA-Z_][a-zA-Z0-9_]+										{ cout << "Bison found an identifier " << endl; yylval.idval = strdup(yytext); return IDVAL;	};
["]([^"\\\n]|\\.|\\\n)*["]  						    	{ yylval.sval = strdup(yytext); return STRING;	};
"//"                                                    	{ yylval.sival = strdup(yytext); return SIVAL;	};

.                ;
%%

