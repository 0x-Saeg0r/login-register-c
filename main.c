#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linker.h"

int validate_login(char username[30], char password[20])
{
    int answer;
    char passwordinput[20], new_pass[20], new_user[20], new_total[50];
    system("clear");
    printf("You are now logged in %s.\n\n", username);
    printf("Do you want to change login or password ?\n\n");
    printf("0 : Nothing\n\n");
    scanf("%d", &answer);
    switch(answer)
    {
    case 0:
        printf("Okay let's keep it !");
        break;
    }


    return 0;
}

int login_account()
{
    system("clear");
    char line[70], inputuser[30], inputpassword[20], total[50];


    printf("Enter your username -> ");
    scanf("%s", &inputuser);
    printf("Enter your password -> ");
    scanf("%s", &inputpassword);
    strcpy(total, inputuser);
    strcat(total, " ");
    strcat(total, inputpassword);
    strcat(total, "\n");

    FILE * fptr = fopen("datas.txt", "r");
    while(fgets(line, 70, fptr)!=NULL)
    {
        printf("%s %s", line, total);
        if (strcmp(line, total) == 0)
        {
            system("clear");
            validate_login(inputuser, inputpassword);
        }

    }

    return 0;
}
int reset_file()
{
    char username[30], password[20];
    FILE * flogin = fopen("datas.txt", "w");

    printf("Choose a new username -> ");
    scanf("%s", &username);
    printf("Choose a new password -> ");
    scanf("%s", &password);
    fprintf(flogin, "%s %s\n", username, password);

    fclose(flogin);
    system("clear");
    main();
    return 0;
}

int new_account()
{
    char username[30], password[20];
    FILE * flogin = fopen("datas.txt", "a");

    printf("Choose a new username -> ");
    scanf("%s", &username);
    printf("Choose a new password -> ");
    scanf("%s", &password);
    fprintf(flogin, "%s %s\n", username, password);

    fclose(flogin);
    system("clear");
    main();
    return 0;
}

int testfunc(void)
{

    char line[70], inputuser[30], inputpassword[20], total[50];


    printf("Enter your username -> ");
    scanf("%s", &inputuser);
    printf("Enter your password -> ");
    scanf("%s", &inputpassword);
    strcpy(total, inputuser);
    strcat(total, " ");
    strcat(total, inputpassword);
    strcat(total, "\n")

    FILE * fptr = fopen("datas.txt", "r");
    while(fgets(line, 70, fptr)!=NULL)
    {

        if (strcmp(line, total) == 0)
        {
            printf("Login success");
            break;
        }

    }
    return 0;

}

int start(void)
{
    int answer;
    printf("Choose between :\n1 : Login\n2 : Register\n3 : Reset file with new user\n4 : Test\n\n");
    scanf("%d", &answer);
    switch(answer)
    {
    case 1:
        login_account();
        break;
    case 2:
        new_account();
        break;
    case 3:
        reset_file();
        break;
    case 4:
        testfunc();
        break;
    }


    return 0;
}
