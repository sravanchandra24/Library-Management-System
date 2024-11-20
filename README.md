Library Management System
Project Description
This Library Management System is a C++ console application designed to manage a library's operations. It supports functionality for administrators and users, including book management, account management, and transaction handling. The project demonstrates fundamental programming concepts such as arrays, strings, file handling, and object-oriented programming while providing practical features like user authentication and data validation.

Features
Admin Features
Login: Secure admin authentication with username and password.
Add Books: Add new books to the library database with details like title, author, and ISBN.
Remove Books: Remove books from the library database using their ISBN.
Modify Book Details: Update existing book information such as title and author.
List All Books: View a list of all books in the library, including their availability status.
View All Users: See all registered users along with their details like balance and name.
Displays "No users available" if no users are registered.
User Features
Create Account:
Register with a unique User ID (format: USRXXXX).
Set a secure password (minimum 8 characters, including uppercase, lowercase, number, and special character).
Make an initial deposit of $50 or more.
Login:
Authenticate with your unique User ID.
View personalized details after login.
User Menu:
View Balance: Check current account balance.
Deposit Funds: Add money to the account.
Borrow Books: (Planned feature for future updates).
Project Structure
Global Variables:
Store user and book details in arrays and maintain counts.
Functions:
Admin Functions:
add_book(), remove_book(), modify_book_details(), view_all_users(), and list_all_books().
User Functions:
create_user_account(), login_user(), and view_user_details().
Key Functionalities
Data Validation
User IDs: Must follow the format USRXXXX (e.g., USR0001).
Passwords: Require at least 8 characters, including uppercase, lowercase, numeric, and special characters.
ISBNs: Must follow the format BXXXXX (e.g., B0001).
Dynamic Book and User Management
Ensures that new entries for books and users do not exceed predefined limits.
Automatically adjusts the list of books and users when additions or removals occur.
Technologies Used
Programming Language: C++
Features Utilized:
Strings and character arrays.
Functions for modularity.
Regex for input validation.
Loops and conditionals for navigation and processing.
Future Enhancements
Book Borrowing System: Allow users to borrow books and track borrow/return status.
File Handling: Persist data to files for user and book records.
Search Feature: Enable searching for books by title or author.
Enhanced User Interface: Improve user experience with better console designs.
How to Use
Clone the repository to your local machine:
bash
Copy code
git clone https://github.com/<your-username>/library-management-system.git
Compile the source code:
bash
Copy code
g++ -o library_management_system main.cpp
Run the executable:
bash
Copy code
./library_management_system
Follow the on-screen instructions to explore admin and user functionalities.
Contributing
Contributions are welcome! If you'd like to improve this project:

Fork the repository.
Create a new branch for your feature:
bash
Copy code
git checkout -b feature-name
Commit and push your changes:
bash
Copy code
git commit -m "Description of changes"
git push origin feature-name
Create a pull request for review.
