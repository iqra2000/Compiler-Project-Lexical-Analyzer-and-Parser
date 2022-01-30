/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     FLOAT = 259,
     STRING = 260,
     OVAL = 261,
     SPVAL = 262,
     IFVAL = 263,
     ELSEVAL = 264,
     IQVAL = 265,
     WIVAL = 266,
     AIVAL = 267,
     LOCVAL = 268,
     ENDVAL = 269,
     DISPLAYVAL = 270,
     READVAL = 271,
     WHILEVAL = 272,
     INCLUDEVAL = 273,
     LIBRARYVAL = 274,
     HASHVAL = 275,
     ATVAL = 276,
     DOLLARVAL = 277,
     PERCENTVAL = 278,
     ANDVAL = 279,
     ORVAL = 280,
     OPENBRVAL = 281,
     CLOSEBRVAL = 282,
     SEMIVAL = 283,
     COMMAVAL = 284,
     OPENCURLYVAL = 285,
     CLOSECURLYVAL = 286,
     OINVERTEDVAL = 287,
     CINVERTEDVAL = 288,
     FSTOPVAL = 289,
     USCOREVAL = 290,
     PREPROVAL = 291,
     IDVAL = 292,
     SIVAL = 293
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 14 "bison.y"

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


/* Line 2058 of yacc.c  */
#line 146 "bison.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */
