#include <stdio.h>
#include "auth.h"
#include "add_entry.h"
#include "view_entry.h"
#include "edit_entry.h"
#include "search_by_id.h"
#include "search_by_title.h"
#include "search_by_date.h"
#include "delete_entry.h"
#include "author.h"  
#include "report_by_author.h"




int main() {
    if (!authenticate()) {
        printf("Authentication Failed.\n");
        return 1;
    }

    int choice;
    char authorName[50];
    int authorId;

    do {
        printf("\n--- Journal Entry Management System ---\n");
        printf("1. Add Entry\n");
        printf("2. View All Entries\n");
        printf("3. Edit Entry\n");
        printf("4. Search by Author ID\n");
        printf("5. Search by Date\n");
        printf("6. Search by Title\n");
        printf("7. Delete Entry\n");
        printf("8. View Author ID\n");  
        printf("9. Generate Author Report\n");

        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: editEntry(); break;
            case 4: searchByAuthorId(); break;
            case 5: searchByDate(); break;
            case 6: searchByTitle(); break;
            case 7: deleteEntry(); break;
            case 8: 
                getAuthorDetails(authorName, &authorId); 
                printf("Author: %s, Author ID: %d\n", authorName, authorId); 
                break;
            case 9: generateReportByAuthor(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}
