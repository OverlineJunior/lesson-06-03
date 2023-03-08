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
bool intset_has(IntSet intset, int n);
bool intset_are_equal(IntSet intset_a, IntSet intset_b);
bool intset_is_empty(IntSet intset);
IntSet intset_push(IntSet intset, int n);
IntSet intset_remove(IntSet intset, int n);
IntSet intset_union(IntSet intset_a, IntSet intset_b);
IntSet intset_intersection(IntSet intset_a, IntSet intset_b);
IntSet intset_difference(IntSet intset_a, IntSet intset_b);
MaybeInt intset_highest_number(IntSet intset);
MaybeInt intset_lowest_number(IntSet intset);
void intset_display(IntSet intset);
