#include <stdio.h>
#include <stdbool.h>

#define SET_SIZE 64

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

typedef struct {
    MaybeInt elements[SET_SIZE];
} IntSet;

MaybeInt maybeint_some(int n) {
    MaybeInt some = {
        .is_some = true,
        .value = n,
    };

    return some;
}

MaybeInt maybeint_none(void) {
    MaybeInt none = {
        .is_some = false,
        .value = 0,
    };

    return none;
}

MaybeInt maybeint_first_none_index(MaybeInt arr[], int size) {
    MaybeInt res = maybeint_none();

    for (int i = 0; i < size; i++) {
        if (arr[i].is_some) continue;

        res.is_some = true;
        res.value = i;

        break;
    }

    return res;
}

IntSet intset_new(void) {
    IntSet int_set = {};

    return int_set;
}

IntSet intset_push(IntSet intset, int n) {
    MaybeInt index = maybeint_first_none_index(intset.elements, SET_SIZE);

    if (index.is_some) {
        intset.elements[index.value] = maybeint_some(n);
    } else {
        printf("Nao e possivel exceder o tamanho de %i\n", SET_SIZE);
    }

    return intset;
}

// TODO: Shift elements after index to the left.
IntSet intset_remove(IntSet intset, int index) {
    intset.elements[index] = maybeint_none();

    return intset;
}
