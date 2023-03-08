#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

MaybeInt maybeint_some(int n);
MaybeInt maybeint_none(void);
MaybeInt maybeint_first_none_index(MaybeInt arr[], int size);
void maybeint_swap(MaybeInt *a, MaybeInt *b);
void maybeint_sort(MaybeInt *arr, int size);
