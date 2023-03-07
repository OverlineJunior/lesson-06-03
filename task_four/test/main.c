#include <stdio.h>
#include "../int_set.h"

int main(void) {
    IntSet intset_a = intset_new();
    intset_a = intset_push(intset_a, 4);
    intset_a = intset_push(intset_a, 2);

    IntSet intset_b = intset_new();
    intset_b = intset_push(intset_b, 3);
    intset_b = intset_push(intset_b, 4);
    intset_b = intset_push(intset_b, 2);

    IntSet intset_c = intset_intersection(intset_a, intset_b);
    intset_display(intset_c);

    return 0;
}

