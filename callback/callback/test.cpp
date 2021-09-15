/* Copyright 2017 mozkzki */
#include <stdio.h>

typedef void(*FUNC_POINTER)(char *);

void func1(char *s) {
    printf("%s\n", s);
}

void func2(char *s) {
    for (int i = 0; i < 2; i++) {
        printf("%s\n", s);
    }
}

void func(char *s, FUNC_POINTER p) {
    p(s);
}

int main() {
    FUNC_POINTER p;

    p = func1;
    func("ありがと", p);

    p = func2;
    func("Thanks", p);

    return 0;
}
