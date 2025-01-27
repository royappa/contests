#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cfg.tab.h"

// Static variables to manage the input
static const char *input;
static char *current_token;

// Initialize the input for tokenization
void initialize_lexer(const char *sentence) {
    input = strdup(sentence); // Make a copy of the input string
    current_token = strtok((char *)input, ",");
}

// Lexer function
int yylex() {
    if (current_token == NULL) {
        return 0; // End of input
    }

    // Map the token to its corresponding terminal
    int token = 0;
    if (strcmp(current_token, "C") == 0) token = C;
    else if (strcmp(current_token, "Rn") == 0) token = Rn;
    else if (strcmp(current_token, "Ar") == 0) token = Ar;
    else if (strcmp(current_token, "Y") == 0) token = Y;
    else if (strcmp(current_token, "a") == 0) token = a;
    else if (strcmp(current_token, "b") == 0) token = b;
    else if (strcmp(current_token, "c") == 0) token = c;
    else if (strcmp(current_token, "d") == 0) token = d;
    else if (strcmp(current_token, "f") == 0) token = f;
    else if (strcmp(current_token, "g") == 0) token = g;
    else if (strcmp(current_token, "h") == 0) token = h;
    else if (strcmp(current_token, "i") == 0) token = i;
    else if (strcmp(current_token, "j") == 0) token = j;
    else if (strcmp(current_token, "k") == 0) token = k;
    else if (strcmp(current_token, "l") == 0) token = l;
    else if (strcmp(current_token, "m") == 0) token = m;
    else {
        fprintf(stderr, "Unknown token: %s\n", current_token);
        return 0;
    }

    // Move to the next token
    current_token = strtok(NULL, ",");
    return token;
}
