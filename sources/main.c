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

    struct user usr, usr1;
    FILE *fp;
    char filename[50], phone[50], pword[50];
    int opt, choice;
    char cont = 'y';
    float amount;

    printf("\nWhat do you want to do?");
    printf("\n\n1. Register a new account");
    printf("\n2. Login to an account");

    printf("\n\nYour choice:\n");
    scanf("%d", &opt);

    if (opt == 1){
        system("clear");
        printf("Enter your account number:\t");
        scanf("%s", usr.ac);
        printf("Enter your phone number:\t");
        scanf("%s", usr.phone);
        printf("Enter your new password:\t");
        scanf("%s", usr.password);
        usr.balance = 0;
        strcpy(filename, usr.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&usr, sizeof(struct user), 1, fp);
        if (fwrite != 0) {
            printf("\n\nAccount created successfully!");
        } else {
            printf("\n\nSomething went wrong, please try again.\n");
        }
        fclose(fp);
    }

    if (opt == 2){
        system("clear");
        printf("\nPhone number:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", pword);
        strcpy(filename, phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if(fp == NULL){
            printf("\nAccount number not found!\n");
        } else {
            fread(&usr, sizeof(struct user), 1, fp);
            fclose(fp);
            if (!strcmp(pword, usr.password)){
                while(cont == 'y'){
                    system("clear");
                    printf("\nPress 1 for balance inquiry");
                    printf("\nPress 2 for depositing cash");
                    printf("\nPress 3 for cash withdrawal");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for password change");
                    printf("\n\nYour choice:\t");
                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                            printf("\nYour current balance is $%.2f",usr.balance);
                            break;
                        case 2:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            usr.balance += amount;
                            fp = fopen(filename, "w");
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if(fwrite != NULL) printf("\nSuccessfully deposited.");
                            fclose(fp);
                            break;
                        case 3:
                            printf("\nEnter the amount:\t");
                            scanf("%f", &amount);
                            usr.balance -= amount;
                            fp = fopen(filename, "w");
                            fwrite(&usr, sizeof(struct user), 1, fp);
                            if(fwrite != NULL) printf("\nSuccessfully withdrawn.");
                            fclose(fp);
                            break;
                        case 4:
                            printf("\nPlease enter the phone number to transfer the balance:\t");
                            scanf("%s", phone);
                            printf("\nPlease enter the amount to transfer:\t");
                            scanf("%f", &amount);
                            if(amount > usr.balance) printf("\nInsufficient balance!");
                            else {
                                strcpy(filename, phone);
                                fp = fopen(strcat(filename, ".dat"), "r");
                                fread(&usr1, sizeof(struct user), 1, fp);
                                fclose(fp);
                                fp = fopen(filename, "w");
                                usr1.balance += amount;
                                fwrite(&usr1, sizeof(struct user), 1 ,fp);
                                fclose(fp);
                                if(fwrite != NULL) {
                                    printf("\nSuccessfully transferred $%.2f to %s", amount, phone);
                                    strcpy(filename, usr.phone);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    usr.balance -= amount;
                                    fwrite(&usr, sizeof(struct user), 1, fp);
                                    fclose(fp);
                                }
                            }
                    }

                    printf("\nDo you want to continue the transaction? [y/n]\t");
                    scanf("%s", &cont);
                }
            }else{
                printf("\nInvalid password");
            }
        }
    }

    return 0;
}