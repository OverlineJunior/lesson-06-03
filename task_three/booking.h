#include <stdbool.h>

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
    int schedule_size;
} SportsCourt;

Customer customer_new(char name[CUSTOMER_NAME_SIZE], int age);
SportsCourt sports_court_new(void);
void check_in(SportsCourt *s_court, Customer *cust);
void check_out(SportsCourt *s_court, Customer *cust);
