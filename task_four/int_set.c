#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../libs/maybe_int.h"

#define SET_SIZE 64

typedef struct {
    MaybeInt elements[SET_SIZE];
} IntSet;

MaybeInt intset_index_of(IntSet intset, int n) {
    MaybeInt index = maybeint_none();

    for (int i = 0; i < SET_SIZE; i++) {
        if (!intset.elements[i].is_some || intset.elements[i].value != n) continue;

        index.is_some = true;
        index.value = i;

        break;
    }

    return index;
}

IntSet intset_swap_down(IntSet intset, int start_index) {
    for (int i = start_index; i < SET_SIZE - 1; i++) {
        maybeint_swap(&intset.elements[i], &intset.elements[i + 1]);
    }

    return intset;
}

IntSet intset_new(void) {
    IntSet int_set = {};

    return int_set;
}

bool intset_has(IntSet intset, int n) {
    return intset_index_of(intset, n).is_some;
}

bool intset_are_equal(IntSet intset_a, IntSet intset_b) {
    for (int i = 0; i < SET_SIZE; i++) {
        if (intset_a.elements[i].value != intset_b.elements[i].value) {
            return false;
        }
    }

    return true;
}

bool intset_is_empty(IntSet intset) {
    return !intset.elements[0].is_some;
}

int intset_size(IntSet intset) {
    MaybeInt first_none_i = maybeint_first_none_index(intset.elements, SET_SIZE);

    return first_none_i.is_some ? first_none_i.value : SET_SIZE;
}

IntSet intset_push(IntSet intset, int n) {
    if (intset_index_of(intset, n).is_some) {
        printf("%i ja esta presente no set\n", n);
        exit(EXIT_FAILURE);
    }

    MaybeInt index = maybeint_first_none_index(intset.elements, SET_SIZE);

    if (index.is_some) {
        intset.elements[index.value] = maybeint_some(n);
    } else {
        printf("Nao e possivel exceder o tamanho de %i\n", SET_SIZE);
    }

    maybeint_sort(intset.elements, SET_SIZE);

    return intset;
}

IntSet intset_remove(IntSet intset, int n) {
    MaybeInt index = intset_index_of(intset, n);

    if (index.is_some) {
        intset.elements[index.value] = maybeint_none();

        return intset_swap_down(intset, index.value);
    }

    return intset;
}

IntSet intset_union(IntSet intset_a, IntSet intset_b) {
    for (int i = 0; i < SET_SIZE; i++) {
        MaybeInt n = intset_b.elements[i];

        if (n.is_some && !intset_has(intset_a, n.value)) {
            intset_a = intset_push(intset_a, n.value);
        }
    }

    return intset_a;
}

IntSet intset_intersection(IntSet intset_a, IntSet intset_b) {
    IntSet intersec = intset_new();

    for (int i = 0; i < SET_SIZE; i++) {
        MaybeInt n = intset_a.elements[i];

        if (!n.is_some) break;

        if (intset_has(intset_b, n.value)) {
            intersec = intset_push(intersec, n.value);
        }
    }

    return intersec;
}

IntSet intset_difference(IntSet intset_a, IntSet intset_b) {
    for (int i = 0; i < SET_SIZE; i++) {
        MaybeInt n = intset_b.elements[i];

        if (!n.is_some) break;

        intset_a = intset_remove(intset_a, n.value);
    }

    return intset_a;
}

MaybeInt intset_highest_number(IntSet intset) {
    MaybeInt highest = intset.elements[0];

    for (int i = 1; i < SET_SIZE; i++) {
        MaybeInt n = intset.elements[i];

        if (n.is_some && n.value > highest.value) {
            highest = n;
        }
    }

    return highest;
}

MaybeInt intset_lowest_number(IntSet intset) {
    MaybeInt lowest = intset.elements[0];

    for (int i = 0; i < SET_SIZE; i++) {
        MaybeInt n = intset.elements[i];

        if (n.is_some && n.value < lowest.value) {
            lowest = n;
        }
    }

    return lowest;
}

void intset_display(IntSet intset) {
    printf("[");

    for (int i = 0; i < SET_SIZE; i++) {
        MaybeInt maybeint = intset.elements[i];

        if (!maybeint.is_some) break;

        printf("%i", maybeint.value);

        if (i + 1 != SET_SIZE && intset.elements[i + 1].is_some) {
            printf(", ");
        }
    }

    printf("]\n");
}
