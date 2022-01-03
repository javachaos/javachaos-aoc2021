#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define debug
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

const char *input = "[({(<(())[]>[[{[]{<()<>>\n"
"[(()[<>])]({[<{<<[]>>(\n"
"{([(<{}[<>[]}>{[]{[(<()>\n"
"(((({<>}<{<{<>}{[]{[]{}\n"
"[[<[([]))<([[{}[[()]]]\n"
"[{[{({}]{}}([{[{{{}}([]\n"
"{<[[]]>}<{[{[{[]{()[[[]\n"
"[<(<(<(<{}))><([]([]()\n"
"<{([([[(<>()){}]>(<<{{\n"
"<{([{{}}[<[[[<>{}]]]>[]]";


//const char* input = "{([(<{}[<>[]}>{[]{[(<()>";

Symbol sym;
int lineNum = 0;
int lineIdx = 0;

int nextsym(void) {
    char c = input[lineIdx++];

    if (c == '\0') {
        exit(1);
    }
    if (c == '\n') {
        sym = NL;
        printf("\n");
        printf("\n");
        printf("Line: %d", lineNum++);
        printf("\n");
        printf("%c", sym);
        return 1;
    } else if (c != 0) {
        sym = c;
        printf("%c", sym);
        return 1;
    } else {
        printf("Line: %d\n", lineNum++);
        return 0;
    }
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
    printf("Expected: %c", s);
    printf("\n");
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

int main() {
    nextsym();
    parens();
}
