Library Management System
Project Description
This Library Management System is a C++ console-based application designed to streamline library operations. It allows administrators to manage books and users, while users can create accounts and manage their balances. The project demonstrates key programming concepts such as data validation, user authentication, and menu-driven navigation.

Features
Admin Features
Login: Secure admin authentication with a predefined username and password.
Add Books: Add new books with details such as title, author, and ISBN.
Remove Books: Remove books using their ISBN.
Modify Book Details: Update book information, such as title and author.
List All Books: View all books, including their availability status.
View All Users: Display all registered users and their details (shows "No users available" if none exist).
User Features
Create Account:
Register with a unique User ID (format: USRXXXX).
Set a secure password (minimum 8 characters with uppercase, lowercase, number, and special character).
Deposit a minimum of $50 to activate the account.
Login:
Authenticate using your unique User ID.
Access user-specific features post-login.
User Menu:
View Balance: Check the current account balance.
Deposit Funds: Add funds to your account.
(Planned Feature) Borrow books.
Project Workflow
Admin Workflow
Login as Admin using:
Username: admin
Password: Admin@123
Access the Admin Menu to:
Add, remove, or modify books.
View the list of books and registered users.
User Workflow
Create an Account with a unique User ID and secure password.
Login to:
View and manage your account balance.
(Planned) Borrow or return books.
Validation Rules
User IDs: Must follow the format USRXXXX (e.g., USR0001).
Passwords: Must include at least:
8 characters.
1 uppercase letter.
1 lowercase letter.
1 number.
1 special character.
Book ISBNs: Must follow the format BXXXXX (e.g., B0001).
Technologies Used
Programming Language: C++
Core Concepts: Arrays, strings, functions, loops, and input validation using regex.
How to Use
Clone this repository to your local machine:
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
Follow the on-screen instructions to explore Admin and User functionalities.
Future Enhancements
Add file handling for persistent data storage.
Implement a feature to borrow and return books.
Add search functionality for books and users.
Improve the console interface for better user experience.
Contributing
Contributions are welcome! Follow these steps to contribute:

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
Open a pull request for review.
License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
If you have questions or suggestions, feel free to reach out:

Email: your-email@example.com
GitHub: YourUsername
