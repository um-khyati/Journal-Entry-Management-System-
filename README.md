📓 Journal Entry Management System

A secure, modular, console-based application written in C for managing journal entries. The system uses user authentication and a clean, menu-driven interface to efficiently handle journal records.

✨ Features

🔐 User Authentication – Ensures only authorized access

➕ Add Entries – Create new journal records

📄 View All Entries – Display all stored entries

✏️ Edit Entries – Modify existing records

❌ Delete Entries – Remove unwanted entries

🔍 Search Entries – Search by Author ID, Title, or Date

👤 Author Management – Retrieve and display author details

📊 Generate Reports – View journal contributions grouped by author
main.c                  # Main program logic and menu
auth.h / auth.c         # User authentication
add_entry.h / add_entry.c
                        # Add new journal entries
view_entry.h / view_entry.c
                        # Display all entries
edit_entry.h / edit_entry.c
                        # Edit existing entries
delete_entry.h / delete_entry.c
                        # Delete entries
search_by_id.h / search_by_id.c
                        # Search by Author ID
search_by_title.h / search_by_title.c
                        # Search by Title
search_by_date.h / search_by_date.c
                        # Search by Date
author.h / author.c     # Author details handling
report_by_author.h / report_by_author.c
                        # Generate author-based reports
