#include "treeset.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    TreeSet ts = TREESET_new();
    TREESET_add(&ts, 5);
    printf("***\n");
    TREESET_add(&ts, 2);
    printf("***\n");
    TREESET_add(&ts, 5);
    printf("***\n");
    TREESET_add(&ts, 3);
    printf("***\n");
    TREESET_add(&ts, 10);
    printf("***\n");
    TREESET_add(&ts, -1);
}
