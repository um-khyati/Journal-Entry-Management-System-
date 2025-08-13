#include <stdio.h>
#include <string.h>

struct Journal {
    char date[20];
    char title[50];
    char content[1000];
};

void editEntry() {
    FILE *ptr = fopen("journal.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct Journal j;
    char line[1100], title_to_edit[50], new_content[1000];
    int found = 0;

    if (ptr == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter title to edit: ");
    fgets(title_to_edit, sizeof(title_to_edit), stdin);
    int len = strlen(title_to_edit);
    if (title_to_edit[len - 1] == '\n') {
        title_to_edit[len - 1] = '\0';
    }

    while (fgets(line, sizeof(line), ptr)) {
        sscanf(line, "%[^|]|%[^|]|%[^\n]", j.date, j.title, j.content);

        if (strcmp(j.title, title_to_edit) == 0) {
            found = 1;
            printf("Enter new content: ");
            fgets(new_content, sizeof(new_content), stdin);
            int clen = strlen(new_content);
            if (new_content[clen - 1] == '\n') {
                new_content[clen - 1] = '\0';
            }
            fprintf(temp, "%s|%s|%s\n", j.date, j.title, new_content);
        } else {
            fprintf(temp, "%s", line);
        }
    }

    fclose(ptr);
    fclose(temp);
    remove("journal.txt");
    rename("temp.txt", "journal.txt");

    if (found)
        printf("Entry updated.\n");
    else
        printf("Title not found.\n");
}
