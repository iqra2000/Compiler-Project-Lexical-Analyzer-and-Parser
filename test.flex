%{

int sum =0, prepro, sp_char, deli, op, key, flot, ident, integer, string, com, mcom,dt ;

%}

%%

[0-9]+\.[0-9]+ { printf("This is Float: %s\n\n",yytext); sum++; ++flot;}

#.* {printf("This is Pre-processor directive: %s\n\n",yytext); sum++; ++prepro;}

[''|,|;(|)|{|}|.|_] {printf("This is Delimiter: %s\n\n",yytext); sum++; ++deli;}

"#"|"@"|"$"|"^"|"%"|"^"|"&" {printf("This is Special Characters: %s\n\n",yytext); sum++; ++sp_char;}

"["|"]" {printf("This is Delimiter: %s\n\n",yytext); sum++; ++deli;}

"+"|"-"|"*"|"++"|"--"|"%"|"&&"|"||"|"!"|"<="|">="|"!="|"=="|"<"|">"|"=" { printf("This is Operator: %s\n\n",yytext); sum++; ++op;}

("if")|("else")|("whileloop")|("location")|("end")|("read")|("display")|("library")|("include") { printf("This is Keyword: %s\n\n",yytext); sum++; ++key;}

("iq")|("wi")|("ai") {printf("This is Datatype:%s\n\n",yytext); sum++; ++dt;}

[a-zA-Z_][a-zA-Z0-9_]* {printf("This is Identifier: %s\n\n",yytext); sum++; ++ident;}

[0-9]+ { printf("This is Integer: %s\n\n",yytext); sum++; ++integer;}

["]([^"\\\n]|\\.|\\\n)*["] { printf("This is String:%s\n\n",yytext); sum++; ++string;}

"//" {printf("This is single line Commments: %s\n\n",yytext); sum++; ++com;}


[\n\t]+

%%
int yywrap(void)
{
return 1;
}

int main(int argc, char *argv[])
{
	extern FILE *yyin;
	
		yyin = fopen("Input.wai", "r+"); 
    yylex();
	
	if(prepro>0)
	{
		printf("\nThere are %d preprocessors",prepro);
	}
	if(deli>0)
	{
		printf("\nThere are %d delimeters",deli);
	}
	if(sp_char>0)
	{
		printf("\nThere are %d special char",sp_char);
	}
	if(op>0)
	{
		printf("\nThere are %d Operators",op);
	}
	if(key>0)
	{
		printf("\nThereare %d Keywords",key);
	}
	if(flot>0)
	{
		printf("\nThere are %d float",flot);
	}
	if(ident>0)
	{
		printf("\nThere are %d identifiers",ident);
	}
	if(integer>0)
	{
		printf("\nThere are %d integer",integer);
	}
	if(string>0)
	{
		printf("\nThere are %d string",string);
	}
	if(com>0)
	{
		printf("\nThere are %d Single comments",com);
	}
	if(dt>0)
	{
		printf("\nThere are %d Datatype",dt);
	}

	printf("\n\n Total Tokens = %d",sum);
	 

    return 0; 
}