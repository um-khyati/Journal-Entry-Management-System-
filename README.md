📓 Journal Entry Management System
A secure, modular C-based console application for managing journal entries. Designed with authentication and a clean, menu-driven interface, it allows adding, viewing, editing, deleting, and searching entries by author, title, or date, plus generating author-specific reports.
✨ Features
User Authentication – Ensures only authorized access.
Add Entries – Create new journal records quickly.
View All Entries – Display entries in an organized format.
Edit or Delete – Maintain accuracy of stored data.
Search Options – Locate entries by Author ID, Title, or Date.
Author Management – Retrieve and display author details.
Generate Reports – View contributions grouped by author.
📂 Project Structure
main.c                # Main program logic and menu
auth.h / auth.c       # User authentication
add_entry.h / .c      # Add new journal entries
view_entry.h / .c     # Display all entries
edit_entry.h / .c     # Edit existing entries
search_by_id.h / .c   # Search entries by Author ID
search_by_title.h / .c# Search entries by Title
search_by_date.h / .c # Search entries by Date
delete_entry.h / .c   # Delete entries
author.h / .c         # Author details handling
report_by_author.h/.c # Generate author reports
⚙️ Installation & Compilation
Clone this repository:
git clone https://github.com/yourusername/journal-entry-management.git
cd journal-entry-management
Compile the program:
gcc main.c auth.c add_entry.c view_entry.c edit_entry.c search_by_id.c search_by_title.c search_by_date.c delete_entry.c author.c report_by_author.c -o journal
Run the program:
./journal
🛠 Requirements
GCC or any C compiler
C standard library
