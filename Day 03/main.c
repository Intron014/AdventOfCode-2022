#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char data[400][50]={"0"};
    char donely[500];
    int line = 0;
    int i, len, fh, sh, tot=0;
    FILE *file;
    file = fopen("C:\\Users\\me\\Documents\\GitHub\\AdventOfCode-2022\\Day 03\\input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while (!feof(file) && !ferror(file))
        if (fgets(data[line], 60, file) != NULL)
            line++;
    fclose(file);
    for (i = 0; i <= line; i++) {
        NX:
        len = strlen(data[i]);
        len--;
        fh = 0;
        for(;fh<len/2;fh++){
            for (sh=len/2; sh < len; sh++) {
                if (data[i][sh] == data[i][fh]) {
                    donely[i] = data[i][fh];
                    if (islower(donely[i])) {
                        tot += (donely[i] - 'a') + 1;
                    }
                    else {
                        tot += (donely[i] - 'A') + 27;
                    }
                    printf("found - Line %i - %c %c\n", i, data[i][sh], data[i][fh]);
                    i++;
                    goto NX;
                }
                else
                    printf("skipp - Line %i - %c %c\n", i, data[i][sh], data[i][fh]);
            }
        }
    }
    printf("Total: %i", tot);
}