#include <stdio.h>
#include <string.h>

struct Journal {
    char date[11];
    char title[50];
    char content[1000];
};

void searchByDate() {
    FILE *ptr = fopen("journal.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char date_to_search[20];
    struct Journal j;
    char line[1100];
    int found = 0;

    printf("Enter date to search (dd-mm-yyyy): ");
    scanf(" %[^\n]", date_to_search);

    printf("Entries for %s:\n", date_to_search);

    while (fgets(line, sizeof(line), ptr)) {
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", j.date, j.title, j.content) == 3) {
            if (strcmp(j.date, date_to_search) == 0) {
                printf("Date: %s\nTitle: %s\nContent: %s\n", j.date, j.title, j.content);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No entries found for this date.\n");
    }

    fclose(ptr);
}

