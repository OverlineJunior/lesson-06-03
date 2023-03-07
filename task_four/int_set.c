#include <stdio.h>
#include <stdlib.h>
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

void maybeint_swap(MaybeInt *a, MaybeInt *b) {
    MaybeInt aux = *a;
    *a = *b;
    *b = aux;
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

MaybeInt intset_index_of(IntSet intset, int n) {
    MaybeInt index = maybeint_none();

    for (int i = 0; i < SET_SIZE; i++) {
        if (!intset.elements[i].is_some || intset.elements[i].value != n) continue;

        index.is_some = true;
        index.value = n;

        break;
    }

    return index;
}

IntSet intset_remove(IntSet intset, int index) {
    if (index >= SET_SIZE) {
        printf(
            "Nao e possivel entrar com indice acima de %i\n",
            SET_SIZE
        );
        exit(EXIT_FAILURE);
    }

    intset.elements[index] = maybeint_none();

    return intset_swap_down(intset, index);
}

// TODO: Automatically sort elements on push.
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

    return intset;
}

IntSet intset_pop(IntSet intset) {
    MaybeInt first_none_i = maybeint_first_none_index(intset.elements, SET_SIZE);
    int index = first_none_i.is_some ? first_none_i.value - 1 : SET_SIZE - 1;

    return intset_remove(intset, index);
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
