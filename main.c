#include <stdio.h>

int string_is_xx(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "xx", 2) == 0) return 1;
    return 0;
}

int string_is_Y(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "Y:", 2) == 0) return 1;
//    printf("Y");
    return 0;
}

int string_is_N(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "N:", 2) == 0) return 1;
    return 0;
}

int string_is_sam(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "sample", 6) == 0) return 1;
    return 0;
}

int string_is_That(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "That", 4) == 0) return 1;
    return 0;
}

int string_is_other(char *c) {
    while (*c == ' ') c++;
    if ((strncmp(c, "That", 4) == 0) || (strncmp(c, "Hell", 4) == 0) || (strncmp(c, "PID", 3) == 0) || (strncmp(c, "task", 4) == 0) || (strncmp(c, "trans", 5) == 0)) return 1;
    return 0;
}

int string_is_quit(char *c) {
    while (*c == ' ') c++;
    if (strncmp(c, "quit", 4) == 0) return 1;
    return 0;
}

int string_is_hex(char *c) {
    while (*c == ' ') c++;
    while (*c != ' ') {
        if (!(((*c >= '0') && (*c <= '9')) || ((*c >= 'A') && (*c <= 'F')))) return 0;
        c++;
    }
    return 1;
}

int main() {
    char s[255];
    char *c;
    FILE *fp;
    fp = fopen("../kern.log", "r");
    fout = fopen("temp.txt", "w");
}
