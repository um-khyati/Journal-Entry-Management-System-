#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void deleteEntry() {
    FILE *fp, *temp;
    char line[MAX_LINE];
    int choice, found = 0;
    int inputAuthorId = -1;
    char inputAuthorName[100] = "";
    char inputTitle[100] = "";

    printf("\nChoose deletion method:\n");
    printf("1. Delete by Author ID\n");
    printf("2. Delete by Author Name\n");
    printf("3. Delete by Title\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); 

    switch (choice) {
        case 1:
            printf("Enter Author ID: ");
            scanf("%d", &inputAuthorId);
            getchar(); 
            break;
        case 2:
            printf("Enter Author Name: ");
            fgets(inputAuthorName, sizeof(inputAuthorName), stdin);
            inputAuthorName[strcspn(inputAuthorName, "\n")] = 0;
            break;
        case 3:
            printf("Enter Title: ");
            fgets(inputTitle, sizeof(inputTitle), stdin);
            inputTitle[strcspn(inputTitle, "\n")] = 0;
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }

    fp = fopen("journal.txt", "r");
    if (fp == NULL) {
        printf("Could not open journal.txt\n");
        return;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Could not create temp.txt\n");
        fclose(fp);
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        char date[100], title[100], content[512], author[100];
        int authorId;

        if (sscanf(line, "%99[^|]|%99[^|]|%511[^|]|%99[^|]|%d",
                   date, title, content, author, &authorId) == 5) {
            int match = 0;

            if (choice == 1 && authorId == inputAuthorId)
                match = 1;
            else if (choice == 2 && strcmp(author, inputAuthorName) == 0)
                match = 1;
            else if (choice == 3 && strcmp(title, inputTitle) == 0)
                match = 1;

            if (match) {
                found = 1;
                printf("Deleted entry: %s", line);
                continue; 
            }
        }

        fputs(line, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("journal.txt");
    rename("temp.txt", "journal.txt");

    if (found)
        printf("Entry deleted successfully.\n");
    else
        printf("No matching entry found.\n");
}


