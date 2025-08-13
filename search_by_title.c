#include <stdio.h>
#include <string.h>

struct Journal {
    char date[20];
    char title[50];
    char content[1000];
};

void searchByTitle() {
    FILE *ptr = fopen("journal.txt", "r");
    if (ptr == NULL) {
        printf("Error opening file.\n");
        return;
    }

    struct Journal j;
    char title_to_search[50], line[1100];
    int found = 0;

    printf("Enter title to search: ");
    fgets(title_to_search, sizeof(title_to_search), stdin);
    int len = strlen(title_to_search);
    if (title_to_search[len - 1] == '\n') {
        title_to_search[len - 1] = '\0';
    }

    while (fgets(line, sizeof(line), ptr)){
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", j.date, j.title, j.content) == 3) {
            if (strcmp(j.title, title_to_search) == 0) {
                printf("\n--- Entry Found ---\n");
                printf("Date: %s\n", j.date);
                printf("Title: %s\n", j.title);
                printf("Content: %s\n", j.content);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No entries found with this title.\n");
    }

    fclose(ptr);
}
