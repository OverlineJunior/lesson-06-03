#include <stdbool.h>

#define SET_SIZE 64

typedef struct {
    bool is_some;
    int value;
} MaybeInt;

typedef struct {
    MaybeInt elements[SET_SIZE];
} IntSet;

IntSet intset_new(void);
IntSet intset_push(IntSet intset, int n);
IntSet intset_remove(IntSet intset, int index);
void intset_display(IntSet intset);
