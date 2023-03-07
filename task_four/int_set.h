#define SET_SIZE 64

typedef struct {
    bool exists;
    int value;
} MaybeInt;

typedef struct {
    MaybeInt elements[SET_SIZE];
} IntSet;

IntSet new_int_set(void);
