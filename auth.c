#include<stdio.h>
#include<string.h>
#define MAX 100
int authenticate(){
    char stored_user[] = "admin";
    char stored_pass[] = "1234";
    char username[MAX],password[MAX];
    printf("Enter the username:");
    scanf("%s",username);
    printf("Enter the password:");
   scanf("%s",password);
    if(strcmp(username,stored_user)==0&&strcmp(password,stored_pass)==0){
        printf("Login successful!\n");
        return 1;
    }
    else{
        printf("Invalid credentials.\n");
        return 0;
    }
}
