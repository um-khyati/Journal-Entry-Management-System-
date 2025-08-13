#include <stdio.h>
#include <string.h>

struct Journal {
    char date[20];
    char title[50];
    char content[1000];
};

void viewEntries() {
    FILE *fp = fopen("journal.txt", "r");
    struct Journal j;
    char line[1100];

    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("\n--- All Journal Entries ---\n");
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", j.date, j.title, j.content) == 3) {
            printf("\nDate   : %s\n", j.date);
            printf("Title  : %s\n", j.title);
            printf("Content: %s\n", j.content);
        }
    }

    fclose(fp);
}
