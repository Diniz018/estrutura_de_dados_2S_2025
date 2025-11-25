#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "expressao.h"

// ---------------------------
// Helpers internos
// ---------------------------

static int isFunctionToken(const char *tok) {
    return (strcmp(tok, "raiz") == 0 ||
            strcmp(tok, "sen") == 0  ||
            strcmp(tok, "cos") == 0  ||
            strcmp(tok, "tg")  == 0  ||
            strcmp(tok, "log") == 0);
}

static int isNumberToken(const char *tok) {
    if (!tok || *tok == '\0') return 0;
    int i = 0;
    if (tok[0] == '+' || tok[0] == '-') i++;
    int hasDigit = 0, hasDot = 0;
    for (; tok[i]; i++) {
        if (isdigit(tok[i])) hasDigit = 1;
        else if (tok[i] == '.') {
            if (hasDot) return 0;
            hasDot = 1;
        } else return 0;
    }
    return hasDigit;
}

static void normalize_spaces(char *s) {
    char tmp[1024];
    int i=0, j=0;

    while (s[i] && isspace(s[i])) i++;

    for (; s[i]; i++) {
        if (isspace(s[i])) {
            tmp[j++] = ' ';
            while (s[i+1] && isspace(s[i+1])) i++;
        } else tmp[j++] = s[i];
    }

    while (j>0 && isspace(tmp[j-1])) j--;
    tmp[j] = '\0';
    strcpy(s, tmp);
}

// ---------------------------
// Avaliar POSFIXA
// ---------------------------
float getValorPosFixa(char *StrPosFixa) {
    char buffer[1024];
    strncpy(buffer, StrPosFixa, sizeof(buffer)-1);
    buffer[sizeof(buffer)-1] = '\0';

    normalize_spaces(buffer);

    float stack[1024];
    int top = -1;

    char *tok = strtok(buffer, " ");
    while (tok) {
        if (isNumberToken(tok)) {
            stack[++top] = atof(tok);
        }
        else if (!strcmp(tok, "+") || !strcmp(tok, "-") ||
                 !strcmp(tok, "*") || !strcmp(tok, "/") ||
                 !strcmp(tok, "%") || !strcmp(tok, "^")) {

            float b = stack[top--];
            float a = stack[top--];
            float r = 0;

            if (!strcmp(tok, "+")) r = a + b;
            else if (!strcmp(tok, "-")) r = a - b;
            else if (!strcmp(tok, "*")) r = a * b;
            else if (!strcmp(tok, "/")) r = a / b;
            else if (!strcmp(tok, "%")) r = fmod(a, b);
            else if (!strcmp(tok, "^")) r = pow(a, b);

            stack[++top] = r;
        }
        else if (isFunctionToken(tok)) {
            float x = stack[top--];
            float r = 0;

            if (!strcmp(tok, "raiz")) r = sqrt(x);
            else if (!strcmp(tok, "sen")) r = sin(x * M_PI / 180);
            else if (!strcmp(tok, "cos")) r = cos(x * M_PI / 180);
            else if (!strcmp(tok, "tg"))  r = tan(x * M_PI / 180);
            else if (!strcmp(tok, "log")) r = log10(x);

            stack[++top] = r;
        }
        else return 0;

        tok = strtok(NULL, " ");
    }

    return stack[top];
}

// ---------------------------
// Pós-Fixa → Infixa
// ---------------------------
char *getFormaInFixa(char *Str) {
    static char out[1024];

    char buffer[1024];
    strncpy(buffer, Str, sizeof(buffer)-1);
    buffer[sizeof(buffer)-1] = '\0';

    normalize_spaces(buffer);

    char stack[1024][512];
    int top = -1;

    char *tok = strtok(buffer, " ");
    while (tok) {

        if (isNumberToken(tok)) {
            strcpy(stack[++top], tok);
        }
        else if (!strcmp(tok, "+") || !strcmp(tok, "-") ||
                 !strcmp(tok, "*") || !strcmp(tok, "/") ||
                 !strcmp(tok, "%") || !strcmp(tok, "^")) {

            if (top < 1) return NULL;

            char b[512], a[512], tmp[1024];
            strcpy(b, stack[top--]);
            strcpy(a, stack[top--]);

            sprintf(tmp, "(%s%s%s)", a, tok, b);
            strcpy(stack[++top], tmp);
        }
        else if (isFunctionToken(tok)) {
            if (top < 0) return NULL;

            char a[512], tmp[1024];
            strcpy(a, stack[top--]);

            sprintf(tmp, "%s(%s)", tok, a);
            strcpy(stack[++top], tmp);
        }
        else return NULL;

        tok = strtok(NULL, " ");
    }

    strcpy(out, stack[top]);

    int j = 0;
    for (int i = 0; out[i]; i++) {
        if (!isspace(out[i])) out[j++] = out[i];
    }
    out[j] = '\0';

    return out;
}