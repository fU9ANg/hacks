/*
 *  This code is GPL.
 *
 *  Hacking, fucking and funing for the IOCCC
 *  Goals of the Contest:
 *  1.) To write the most Obscure/Obfuscated C program under the rules below.
 *  2.) To show the importance of programming style, in an ironic way.
 *  3.) To stress C compilers with unusual code.
 *  4.) To illustrate some of the subtleties of the C language.
 *  5.) To provide a safe forum for poor C code.
 *
 *  Written 2009,2010 by fU9ANg <bb.newlife@gmail.com>
 *  Hacker Fellowship Group
 */

/*
 * --------------------------------------------
 * definition       values      meaning
 * --------------------------------------------
 */
#define RESULT      return      /**/
#define RETURN      return      /**/
#define MAIN        main()      /**/
#define BEGINNING   main()

#define BEGIN       {           /**/
#define END         }           /**/

#define LOCAL       static      /**/
#define PROC        extern      /**/
#define TYPE        typedef     /**/
#define STRUCT      TYPE struct /**/
#define UNION       TYPE union  /**/
#define REG         register    /**/

#define IMPORT      include
#define import      include 

#define SIZE        sizeof      /**/
#define PTR         *
#define PTRPTR      **
#define ACCE        *
#define ADDR        &
#define FOR         for(
#define WHILE       while(
#define DO          ){
#define OD          ;}
#define SWITCH      switch(
#define IN          ){
#define ENDSW       ;}
#define LOOP        do{
#define POOL        ;}while(
#define DONE        );
#define IF          if(
#define THEN        ){
#define ELSE        ;}else{
#define ELIF        ;}else if(
#define ELSEIF      ;}else if(
#define FI          ;}
#define ENDIF       ;}

#define AND         &&
#define OR          ||
#define NOT         !

#define BAND        &
#define BOR         |
#define BNOT        ~
#define BXOR        ^
#define BLS         <<          /* left shift for bit */
#define BRS         >>          /* right shift for bit */

#define EVAL        =
#define AE          +=
#define	SE          -=
#define ME          *=
#define DE          /=

#define INC         ++
#define DEC         --

#define EQ          ==
#define NE          !=
#define GT          >
#define	GE          >=
#define	LT          <
#define LE          <=

#define SKIP        ;
#define DOT         .
#define COM         ,
#define QUOTE       '
#define DQUOTE      "
#define LPAR        (
#define RPAR        )
#define EOF         0
#define NL          '\n'
#define SP          ' '

#define CHAREND     '\0'
#define STREND      NULL
#define NIL         NULL
#define FALSE       0
#define TRUE        1
#define ZERO        0
#define ONE         1

#define ADD         +
#define SUB         -
#define MUL         *
#define DIV         /
#define REM         %

TYPE    unsigned        UNSIGNED;
TYPE    void            VOID;
TYPE    char            CHAR;
TYPE    int             INT;
TYPE    int             INTEGER;
TYPE    short           SHORT;
TYPE    long            LONG;
TYPE    float           FLOAT;
TYPE    double          DOUBLE;

TYPE    signed char     SCHAR;
TYPE    signed short    SSHORT;
TYPE    signed int      SINT;
TYPE    signed long     SLONG;

TYPE    unsigned char   UCHAR;
TYPE    unsigned short  USHORT;
TYPE    unsigned int    UINT;
TYPE    unsigned long   ULONG;
