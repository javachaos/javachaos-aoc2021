#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define debug
#define NUM_LINES 106
/**
 * Going to attempt a Recursive Descent Parser (Top-down)
 * 
 *parens :
 *      | '(' parens ')' parens
 *      | '[' parens ']' parens
 *      | '{' parens '}' parens
 *      | '<' parens '>' parens
 *      | NL parens
 */
typedef enum {lparen = 40, rparen = 41, lbrack = 91, rbrack = 93,
              gts = 62, lts = 60, lbrace = 123, rbrace = 125, NL = '\n' } Symbol;

char *input = NULL;
unsigned long long tally[NUM_LINES];
Symbol sym;
int lineNum = 0;
int lineIdx = 0;
clock_t t;

int nextsym(void) {
    char c = input[lineIdx++];
    if (c == '\0') {
        unsigned long long int total = 0;
        for (int i = 0; i < NUM_LINES; i++) {
            total += tally[i];
        }
        printf("\nFinal Total: %lld \n", total);
        
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        printf("AOC10 took %f seconds to execute \n", time_taken);
        free(input);
        exit(1);
    }
    if (c == '\n') {
        sym = NL;
        #ifdef debug
            printf("\n");
            printf("\n");
            printf("Line: %d", lineNum);
            printf("\n");
            printf("%c", sym);
        #endif
        lineNum++;
        return 1;
    } else if (c != 0) {
        sym = c;
        #ifdef debug
            printf("%c", sym);
        #endif
        return 1;
    } else {
        #ifdef debug
            printf("Line: %d\n", lineNum);
        #endif
        lineNum++;
        return 0;
    }
}

unsigned long long get_score(Symbol s) {
    unsigned long long score = 0;
    switch (s)
    {
    case rparen:
        score = 3;
        break;
    case rbrack:
        score = 57;
        break;
    case rbrace:
        score = 1197;
        break;
    case gts:
        score = 25137;
        break;
    default:
        break;
    }
    return score;
}

int accept(Symbol s) {
    if (sym == s) {
        nextsym();
        return 1;
    }
    return 0;
}
int expect(Symbol s) {
    if (accept(s))
        return 1;
    
    #ifdef debug
        printf("Line: %d Pos: %d\n", lineNum, lineIdx);
        printf("Expected: %c\n", s);
        printf("Found: %c\n", input[lineIdx - 1]);
    #endif
    if (tally[lineNum] == 0) {
        tally[lineNum] = get_score((Symbol) input[lineIdx - 1]);
    }
    #ifdef debug
        printf("\n");
    #endif
    return 0;
}

void parens(void) {
    if (accept(lparen)) {
        parens();
        expect(rparen);
        parens();
    } else if (accept(lbrack)) {
        parens();
        expect(rbrack);
        parens();
    } else if (accept(lbrace)) {
        parens();
        expect(rbrace);
        parens();
    } else if (accept(lts)) {
        parens();
        expect(gts);
        parens();
    } else if (accept(NL)) {
        parens();
    }
}

void read_file_to_memory() {
FILE *fp = fopen("./data/aoc10.txt", "r");
    if (fp != NULL) {
        /* Go to the end of the file. */
        if (fseek(fp, 0L, SEEK_END) == 0) {
            /* Get the size of the file. */
            long bufsize = ftell(fp);
            if (bufsize == -1) { /* Error */ }

            /* Allocate our buffer to that size. */
            input = malloc(sizeof(char) * (bufsize + 1));

            /* Go back to the start of the file. */
            if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

            /* Read the entire file into memory. */
            size_t newLen = fread(input, sizeof(char), bufsize, fp);
            if ( ferror( fp ) != 0 ) {
                fputs("Error reading file", stderr);
            } else {
                input[newLen++] = '\0'; /* Just to be safe. */
            }
        }
        fclose(fp);
    }
}

int main() {
    read_file_to_memory();
    t = clock();
    nextsym();
    parens();
}
