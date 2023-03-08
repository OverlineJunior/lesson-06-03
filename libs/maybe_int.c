#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

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

void maybeint_sort(MaybeInt *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (!arr[i].is_some) break;

        for (int j = i + 1; j < size; j++) {
            if (!arr[j].is_some) break;

            if (arr[i].value > arr[j].value) {
                maybeint_swap(&arr[i], &arr[j]);
            }
        }
    }
}
