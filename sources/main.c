#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};

int main()
{

    struct user usr;
    int opt;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register a new account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\n");
    scanf("%d", &opt);

    if (opt == 1){
        system("clear");
        printf("Enter your account no:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone no:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        printf("Account Created!\n");
    }

    return 0;
}