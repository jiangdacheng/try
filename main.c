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
    unsigned long i,a,b;
    char s[255];
    char *c;
    FILE *fp, *fout;
    fp = fopen("firefox_1.log", "r");
    fout = fopen("temp.txt", "w");
    long unsigned int addr_start, addr_length;
    int frame_count = 1;
    scanf("%lx %lu", &addr_start, &addr_length);
    while (fgets(s, 255, fp) != NULL) {
        c = s;
        while (*c != ']') c++;
        c++;
        //if (string_is_Y(c)) continue;
        //if (string_is_N(c)) continue;
        //if (string_is_sam(c)) continue;
        //if (string_is_That(c)) continue;
        //if (string_is_other(c)) continue;
        if (string_is_quit(c)) break;
        if (string_is_That(c)) {
            //fprintf(fout, "%d\n", 0);
            frame_count++;
            continue;
        }
        if (!(string_is_hex(c))) continue;
        sscanf(c, "%lX - %lX", &a, &b);
        if ((a >= addr_start) && (a < (addr_start + addr_length * 1024))) {
            for (; a<=b; a+=4096) {
                fprintf(fout, "%d %lX\n", frame_count, a);
            }
        }
//        if ((a > addr_start))
//        printf("%lX - %lX\n", a, b);

//        do_with(a, b);
    }
}
