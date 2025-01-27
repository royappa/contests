/* Asked ChatGPT to generate this bison file to parse the grammar */
/*
bison -d cfg.y -Wno-conflicts-sr -Wno-other
gcc -Wl,-subsystem,console -o parser.exe cfg.tab.c lexer.c
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "cfg.tab.h"

int yylex(void);

// Declare the external lexer initialization function
void initialize_lexer(const char *sentence);

// Declare the error handling function
void yyerror(const char *s);
%}

/* Tokens */
%token C Rn Ar Y a b c d f g h i j k l m

/* Start symbol */
%start e

%%
e  : H F             { printf("e  -> H F\n"); }
   | N Al            { printf("e  -> N Al\n"); }
   | O Mg            { printf("e  -> O Mg\n"); }
   ;

Al : Th F            { printf("Al -> Th F\n"); }
   | Th Rn F Ar      { printf("Al -> Th Rn F Ar\n"); }
   | a               { printf("Al -> a (TERM)\n"); }
   ;

B  : B Ca            { printf("B  -> B Ca\n"); }
   | Ti B            { printf("B  -> Ti B\n"); }
   | Ti Rn F Ar      { printf("B  -> Ti Rn F Ar\n"); }
   | b               { printf("B  -> b (TERM)\n"); }
   ;

Ca : Ca Ca           { printf("Ca -> Ca Ca\n"); }
   | P B             { printf("Ca -> P B\n"); }
   | P Rn F Ar       { printf("Ca -> P Rn F Ar\n"); }
   | Si Rn F Y F Ar  { printf("Ca -> Si Rn F Y F Ar\n"); }
   | Si Rn Mg Ar     { printf("Ca -> Si Rn Mg Ar\n"); }
   | Si Th           { printf("Ca -> Si Th\n"); }
   | c               { printf("Ca -> c (TERM)\n"); }
   ;

F  : Ca F            { printf("F  -> Ca F\n"); }
   | P Mg            { printf("F  -> P Mg\n"); }
   | Si Al           { printf("F  -> Si Al\n"); }
   | d               { printf("F  -> d (TERM)\n"); }
   ;

H  : C Rn Al Ar      { printf("H  -> C Rn Al Ar\n"); }
   | C Rn F Y F Y F Ar { printf("H  -> C Rn F Y F Y F Ar\n"); }
   | C Rn F Y Mg Ar  { printf("H  -> C Rn F Y Mg Ar\n"); }
   | C Rn Mg Y F Ar  { printf("H  -> C Rn Mg Y F Ar\n"); }
   | H Ca            { printf("H  -> H Ca\n"); }
   | N Rn F Y F Ar   { printf("H  -> N Rn F Y F Ar\n"); }
   | N Rn Mg Ar      { printf("H  -> N Rn Mg Ar\n"); }
   | N Th            { printf("H  -> N Th\n"); }
   | O B             { printf("H  -> O B\n"); }
   | O Rn F Ar       { printf("H  -> O Rn F Ar\n"); }
   | f               { printf("H  -> f (TERM)\n"); }
   ;

Mg : B F             { printf("Mg -> B F\n"); }
   | Ti Mg           { printf("Mg -> Ti Mg\n"); }
   | g               { printf("Mg -> g (TERM)\n"); }
   ;

N  : C Rn F Ar       { printf("N  -> C Rn F Ar\n"); }
   | H Si            { printf("N  -> H Si\n"); }
   | h               { printf("N  -> h (TERM)\n"); }
   ;

O  : C Rn F Y F Ar   { printf("O  -> C Rn F Y F Ar\n"); }
   | C Rn Mg Ar      { printf("O  -> C Rn Mg Ar\n"); }
   | H P             { printf("O  -> H P\n"); }
   | N Rn F Ar       { printf("O  -> N Rn F Ar\n"); }
   | O Ti            { printf("O  -> O Ti\n"); }
   | i               { printf("O  -> i (TERM)\n"); }
   ;

P  : Ca P            { printf("P  -> Ca P\n"); }
   | P Ti            { printf("P  -> P Ti\n"); }
   | Si Rn F Ar      { printf("P  -> Si Rn F Ar\n"); }
   | j               { printf("P  -> j (TERM)\n"); }
   ;

Si : Ca Si           { printf("Si -> Ca Si\n"); }
   | k               { printf("Si -> k (TERM)\n"); }
   ;

Th : Th Ca           { printf("Th -> Th Ca\n"); }
   | l               { printf("Th -> l (TERM)\n"); }
   ;

Ti : B P             { printf("Ti -> B P\n"); }
   | Ti Ti           { printf("Ti -> Ti Ti\n"); }
   | m               { printf("Ti -> m (TERM)\n"); }
   ;


%%

/* Error handling function */
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/* Main function */
int main() {
    // Input string to parse
    const char *sentence = "C,Rn,k,Rn,c,j,m,g,Y,c,j,m,Rn,d,Ar,k,l,d,Ar,c,k,l,k,l,j,b,c,c,k,Rn,k,Rn,m,m,g,Ar,j,b,c,j,g,Y,j,m,Rn,d,Ar,d,Ar,c,k,Rn,b,j,g,Ar,j,Rn,c,j,m,Rn,d,Ar,c,k,l,c,c,d,Ar,j,b,c,c,j,m,m,Rn,d,Ar,c,k,Rn,k,a,Y,k,l,Rn,d,Ar,Ar,c,k,Rn,b,d,Ar,c,c,k,Rn,k,l,c,c,c,d,Y,c,j,m,b,c,k,l,c,k,l,j,g,Ar,k,Rn,c,j,b,d,Y,c,c,d,Ar,c,c,c,c,k,l,c,k,Rn,j,Rn,d,Ar,j,b,k,l,j,Rn,d,Ar,k,Rn,g,Ar,c,d,Y,d,Ar,c,k,Rn,k,a,Ar,m,m,m,m,m,m,m,Rn,j,g,Ar,j,m,m,m,b,k,Rn,k,a,Ar,m,m,Rn,j,g,Ar,c,d,Y,b,j,b,j,m,Rn,k,Rn,g,Ar,k,l,c,d,Ar,c,k,l,d,Ar,j,Rn,d,Ar,c,k,Rn,m,b,k,l,k,Rn,k,a,Y,c,d,Ar,j,Rn,d,Ar,k,l,c,d,Ar,c,c,k,l,c,c,c,k,Rn,j,Rn,c,d,Ar,d,Y,j,g,Ar,c,j,b,c,j,b,k,Rn,d,Y,j,b,c,d,Ar,c,k,a";
    initialize_lexer(sentence); // Initialize the lexer
    return yyparse();           // Start parsing
}
