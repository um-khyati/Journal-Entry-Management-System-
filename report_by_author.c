#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "report_by_author.h"

void generateReportByAuthor() {
    char searchName[50];
    char line[1200];
    int found = 0;

    printf("Enter author name to generate report: ");
    fgets(searchName, sizeof(searchName), stdin);
    size_t len = strlen(searchName);
    if (len > 0 && searchName[len - 1] == '\n') {
        searchName[len - 1] = '\0'; 
    }

    FILE *fp = fopen("journal.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open journal.txt\n");
        return;
    }

    printf("\n--- Report for Author: %s ---\n", searchName);

    while (fgets(line, sizeof(line), fp)) {
        char date[11], title[50], content[1000], author[50];
        int authorId;

        if (sscanf(line, "%10[^|]|%49[^|]|%999[^|]|%49[^|]|%d",
                   date, title, content, author, &authorId) == 5) {
            if (strcmp(author, searchName) == 0) {
                printf("\nDate: %s\nTitle: %s\nContent: %s\nAuthor: %s\nAuthor ID: %d\n",
                       date, title, content, author, authorId);
                found = 1;
            }
        }
    }

    fclose(fp);

    if (!found) {
        printf("No entries found for author: %s\n", searchName);
    }
}
