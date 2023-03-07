#include <stdio.h>
#include "../int_set.h"

int main(void) {
    IntSet intset = intset_new();
    intset = intset_push(intset, 1);
    intset = intset_push(intset, 4);
    intset = intset_push(intset, 2);
    intset = intset_push(intset, 5);
    intset = intset_push(intset, 3);

    intset = intset_remove(intset, 2);

    intset_display(intset);

    return 0;
}

