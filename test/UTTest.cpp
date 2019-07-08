#include <stdio.h>

#include "add.h"

int main()
{
    int a = 100, b = 99;
    printf("customized add %d + %d = %d\n", a, b, add(a, b));
    return 0;
}
