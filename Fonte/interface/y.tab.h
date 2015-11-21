/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INSERT = 258,
    INTO = 259,
    VALUES = 260,
    SELECT = 261,
    FROM = 262,
    WHERE = 263,
    OR = 264,
    AND = 265,
    IN = 266,
    EXISTS = 267,
    CREATE = 268,
    TABLE = 269,
    INTEGER = 270,
    VARCHAR = 271,
    DOUBLE = 272,
    CHAR = 273,
    PRIMARY = 274,
    KEY = 275,
    REFERENCES = 276,
    DATABASE = 277,
    DROP = 278,
    OBJECT = 279,
    NUMBER = 280,
    VALUE = 281,
    QUIT = 282,
    LIST_TABLES = 283,
    LIST_TABLE = 284,
    ALPHANUM = 285,
    CONNECT = 286,
    HELP = 287,
    LIST_DBASES = 288,
    CLEAR = 289
  };
#endif
/* Tokens.  */
#define INSERT 258
#define INTO 259
#define VALUES 260
#define SELECT 261
#define FROM 262
#define WHERE 263
#define OR 264
#define AND 265
#define IN 266
#define EXISTS 267
#define CREATE 268
#define TABLE 269
#define INTEGER 270
#define VARCHAR 271
#define DOUBLE 272
#define CHAR 273
#define PRIMARY 274
#define KEY 275
#define REFERENCES 276
#define DATABASE 277
#define DROP 278
#define OBJECT 279
#define NUMBER 280
#define VALUE 281
#define QUIT 282
#define LIST_TABLES 283
#define LIST_TABLE 284
#define ALPHANUM 285
#define CONNECT 286
#define HELP 287
#define LIST_DBASES 288
#define CLEAR 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "yacc.y" /* yacc.c:1909  */

    int intval;
    double floatval;
    int subtok;
    char *strval;

#line 129 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
