#include <stdio.h>
#include <string.h>
#include "author.h"

struct Journal {
    char date[11];
    char title[50];
    char content[1000];
    char author[50];
    int authorId;
};

void addEntry() {
    FILE *ptr = fopen("journal.txt", "a");
    if (ptr == NULL) {
        printf("Error opening journal.txt\n");
        return;
    }

    struct Journal j;

    printf("Enter date (dd-mm-yyyy): ");
    scanf(" %[^\n]", j.date);
    printf("Enter title: ");
    scanf(" %[^\n]", j.title);
    printf("Enter content (single line): ");
    scanf(" %[^\n]", j.content);
    getchar();  

    getAuthorDetails(j.author, &j.authorId);

    fprintf(ptr, "%s|%s|%s|%s|%d\n", j.date, j.title, j.content, j.author, j.authorId);
    fclose(ptr);

    printf("Entry added successfully.\n");
}
