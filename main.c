#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validate_login(char username[30], char password[20])
{
    int answer;
    char passwordinput[20], new_pass[20], new_user[20], new_total[50];
    system("clear");
    printf("You are now logged in %s.\n\n", username);
    printf("Do you want to change login or password ?\n\n");
    printf("1 : Username --- 2 : Password --- 0 : Nothing\n\n");
    scanf("%d", &answer);
    switch(answer)
    {
    case 0:
        printf("Okay let's keep it !");
        break;
    case 1:
        printf("Please enter password to change username -> ");
        scanf("%s", &passwordinput);
        if(strcmp(password, passwordinput) == 0)
        {
            printf("Enter new username -> ");
            scanf("%s", new_user);
            FILE * flogin = fopen("datas.txt", "w");
            strcpy(new_total, new_user);
            strcat(new_total, " ");
            strcat(new_total, password);
            fprintf(flogin, new_total);
            fclose(flogin);
            printf("Your new username is %s", new_user);
            validate_login(new_user, password);
            sleep(3);
        }
        else
        {
            printf("Error in the password");
            validate_login(username, password);
        }
        break;
    case 2:
        printf("Please enter password to change password -> ");
        scanf("%s", &passwordinput);
        if(strcmp(password, passwordinput) == 0)
        {
            printf("Enter new password -> ");
            scanf("%s", new_pass);
            FILE * flogin = fopen("datas.txt", "w");
            strcpy(new_total, username);
            strcat(new_total, " ");
            strcat(new_total, new_pass);
            fprintf(flogin, new_total);
            fclose(flogin);
            printf("Your new password is %s", new_pass);
            validate_login(username, new_pass);
        }
        else
        {
            printf("Error in the password");
            validate_login(username, password);
        }
        break;
    }


    return 0;
}

int login_account()
{
    system("clear");
    char line[50];
    char total[50];
    FILE * flogin = fopen("datas.txt", "r");
    char username[30], password[20];
    printf("Enter your username -> ");
    scanf("%s", username);
    printf("Enter your password -> ");
    scanf("%s", password);
    fgets(line, 70, flogin);
    strcpy(total, username);
    strcat(total, " ");
    strcat(total, password);


    fclose(flogin);

    if (strcmp(line, total) == 0)
    {
        printf("Login successful\n");
        validate_login(username, password);
        return 0;
    }
    else
    {
        printf("Error, try again\n");
        sleep(2);
        login_account();

    }


    return 0;
}
int new_account()
{
    char username[30], password[20];
    FILE * flogin = fopen("datas.txt", "w");

    printf("Choose a new username -> ");
    scanf("%s", &username);
    printf("Choose a new password -> ");
    scanf("%s", &password);
    fprintf(flogin, "%s %s", username, password);

    fclose(flogin);
    return 0;
}

int main(void)
{
    int answer;
    printf("Choose between :\n1 : Login\n2 : Register\n\n");
    scanf("%d", &answer);
    switch(answer)
    {
    case 1:
        login_account();
        break;
    case 2:
        new_account();
        break;
    }


    return 0;
}
