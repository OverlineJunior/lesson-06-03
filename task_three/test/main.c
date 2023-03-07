#include <stdio.h>
#include "../booking.h"

int main(void) {
    SportsCourt sc = sports_court_new();

    Customer c = customer_new("Foo", 18);
    printf("Is scheduled: %i\n", c.is_scheduled);

    check_in(&sc, &c);
    printf("Is scheduled: %i\n", c.is_scheduled);

    check_out(&sc, &c);
    printf("Is scheduled: %i\n", c.is_scheduled);

    return 0;
}
