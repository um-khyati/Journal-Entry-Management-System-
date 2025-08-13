#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getAuthorDetails(char *authorName, int *authorId) {
    FILE *fp = fopen("authors.txt", "a+");
    if (!fp) {
        printf("Error opening authors.txt\n");
        exit(1);
    }
    char line[100], name[50];
    int id;
    int found = 0;
    printf("Enter author name: ");
    fgets(authorName, 50, stdin);
    size_t len = strlen(authorName);
    if (len > 0 && authorName[len - 1] == '\n') {
        authorName[len - 1] = '\0';  
    }
    rewind(fp);
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%49[^|]|%d", name, &id);
        if (strcmp(name, authorName) == 0) {
            *authorId = id;
            found = 1;
            break;
        }
    }
    if (!found) {
        
        FILE *idFile = fopen("author_id_counter.txt", "r+");
        if (!idFile) {
            idFile = fopen("author_id_counter.txt", "w+");
            if (!idFile) {
                printf("Error opening author_id_counter.txt\n");
                exit(1);
            }
            fprintf(idFile, "1000\n");
            rewind(idFile);
        }
        fscanf(idFile, "%d", &id);
        *authorId = id;
        rewind(idFile);
        fprintf(idFile, "%d\n", id + 1); 
        fclose(idFile);

        fprintf(fp, "%s|%d\n", authorName, *authorId);
    }
    fclose(fp);
}

