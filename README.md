📓 Journal Entry Management System

A secure, modular, console-based application written in C for managing journal entries.
The system uses user authentication and a clean, menu-driven interface to efficiently handle journal records.

✨ Features

🔐 User Authentication
Ensures only authorized users can access the system.

➕ Add Entries
Create new journal records with author and date details.

📄 View All Entries
Display all stored journal entries in an organized format.

✏️ Edit Entries
Modify existing records to maintain data accuracy.

❌ Delete Entries
Remove unwanted or outdated journal entries.

🔍 Search Entries
Search journal records by:

Author ID

Title

Date

👤 Author Management
Retrieve and display author-specific information.

📊 Generate Reports
View journal contributions grouped by author.

main.c
    # Main program logic and menu handling

auth.h / auth.c
    # User authentication module

add_entry.h / add_entry.c
    # Add new journal entries

view_entry.h / view_entry.c
    # Display all journal entries

edit_entry.h / edit_entry.c
    # Edit existing journal entries

delete_entry.h / delete_entry.c
    # Delete journal entries

search_by_id.h / search_by_id.c
    # Search entries by Author ID

search_by_title.h / search_by_title.c
    # Search entries by Title

search_by_date.h / search_by_date.c
    # Search entries by Date

author.h / author.c
    # Author details handling

report_by_author.h / report_by_author.c
    # Generate author-based reports
✨ Designed with simplicity, clarity, and modularity in mind.
📘 A practical C-based project focused on clean structure and efficient data management.
