#include <stdio.h>
#include <string.h>
#include "search_by_id.h"

void searchByAuthorId() {
    int targetId;
    char line[1200];
    int found = 0;

    printf("Enter Author ID to search: ");
    scanf("%d", &targetId);
    getchar();  

    FILE *fp = fopen("journal.txt", "r");
    if (!fp) {
        printf("Could not open journal.txt\n");
        return;
    }

    printf("\n--- Entries by Author ID: %d ---\n", targetId);

    while (fgets(line, sizeof(line), fp)) {
        char date[11], title[50], content[1000], author[50];
        int authorId;

        if (sscanf(line, "%10[^|]|%49[^|]|%999[^|]|%49[^|]|%d",
                   date, title, content, author, &authorId) == 5) {
            if (authorId == targetId) {
                printf("\nDate: %s\nTitle: %s\nContent: %s\nAuthor: %s\nAuthor ID: %d\n",
                       date, title, content, author, authorId);
                found = 1;
            }
        }
    }

    fclose(fp);

    if (!found) {
        printf("No entries found for Author ID: %d\n", targetId);
    }
}
