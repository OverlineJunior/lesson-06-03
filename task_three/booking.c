#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../libs/maybe_int.h"

#define MAX_CUSTOMERS 30
#define CUSTOMER_NAME_SIZE 64

typedef struct {
    char name[CUSTOMER_NAME_SIZE];
    int age;
    int id;
    bool is_scheduled;
} Customer;

typedef struct {
    Customer schedule[MAX_CUSTOMERS];
} SportsCourt;

MaybeInt first_empty_schedule_index(SportsCourt s_court) {
    MaybeInt res = maybeint_none();

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        if (s_court.schedule[i].is_scheduled) continue;

        res = maybeint_some(i);

        break;
    }

    return res;
}

MaybeInt find_customer_index_by_id(SportsCourt s_court, int cust_id) {
    MaybeInt res = maybeint_none();

    for (int i = 0; i < MAX_CUSTOMERS; i++) {
        Customer cust = s_court.schedule[i];

        if (cust.is_scheduled && cust.id == cust_id) {
            res = maybeint_some(i);

            break;
        }
    }

    return res;
}

Customer customer_new(char name[CUSTOMER_NAME_SIZE], int age) {
    Customer c = {
        .age = age,
        .id = rand(),
        .is_scheduled = false,
    };

    strncpy(c.name, name, CUSTOMER_NAME_SIZE);

    return c;
}

SportsCourt sports_court_new(void) {
    SportsCourt sc = {};

    return sc;
}

void check_in(SportsCourt *s_court, Customer *cust) {
    MaybeInt index = first_empty_schedule_index(*s_court);

    if (index.is_some) {
        cust->is_scheduled = true;
        s_court->schedule[index.value] = *cust;
    } else {
        printf("Nao e possivel exceder o numero maximo de clientes (%i)\n", MAX_CUSTOMERS);
    }
}

void check_out(SportsCourt *s_court, Customer *cust) {
    MaybeInt index = find_customer_index_by_id(*s_court, cust->id);

    if (index.is_some) {
        cust->is_scheduled = false;
        s_court->schedule[index.value].is_scheduled = false;
    } else {
        printf("Nao foi encontrado nenhum cliente com o ID %i\n", cust->id);
    }
}
