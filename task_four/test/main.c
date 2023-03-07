#include <stdio.h>
#include "../int_set.h"

int main(void) {
    IntSet intset = intset_new();
    intset = intset_push(intset, 1);
    intset = intset_push(intset, 2);
    intset = intset_push(intset, 3);

    intset_display(intset);

    return 0;
}

