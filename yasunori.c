/*
1. `y` ポインタをインクリメントする。ポインタをptrとすると、C言語の「ptr++;」に相当する。
2. `a` ポインタをデクリメントする。C言語の「ptr--;」に相当。
3. `s` ポインタが指す値をインクリメントする。C言語の「(*ptr)++;」に相当。
4. `u` ポインタが指す値をデクリメントする。C言語の「(*ptr)--;」に相当。
5. `n` ポインタが指す値を出力に書き出す。C言語の「putchar(*ptr);」に相当。
6. `o` 入力から1バイト読み込んで、ポインタが指す先に代入する。C言語の「*ptr=getchar();」に相当。
7. `r` ポインタが指す値が0なら、対応する `i` の直後にジャンプする。C言語の「while(*ptr){」に相当。
8. `i` ポインタが指す値が0でないなら、対応する `r` （の直後）にジャンプする。C言語の「}」に相当。
*/

#include <stdio.h>
#include <stdlib.h>

void yasunori(const char *src) {
    unsigned char mem[30000] = {0};
    unsigned char *ptr = mem;

    while (*src) {
        switch (*src) {
            case 'y':
                ptr++;
                break;
            case 'a':
                ptr--;
                break;
            case 's':
                (*ptr)++;
                break;
            case 'u':
                (*ptr)--;
                break;
            case 'n':
                putchar(*ptr);
                break;
            case 'o':
                *ptr = getchar();
                break;
            case 'r':
                if (*ptr == 0) {
                    int cnt = 1;
                    while (cnt != 0) {
                        src++;
                        if (*src == 'r') cnt++;
                        else if (*src == 'i') cnt--;
                    }
                }
                break;
            case 'i':
                if (*ptr != 0) {
                    int cnt = 1;
                    while (cnt != 0) {
                        src--;
                        if (*src == 'i') cnt++;
                        else if (*src == 'r') cnt--;
                    }
                }
                break;
        }
        src++;
    }
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char src[10000];
    fread(src, 1, length, file);
    src[length] = '\0';
    fclose(file);

    yasunori(src);

    return 0;
}
