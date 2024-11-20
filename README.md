# Library Management System

## Project Description
This **Library Management System** is a C++ console-based application designed to streamline library operations. It allows **administrators** to manage books and users, while **users** can create accounts and manage their balances. The project demonstrates key programming concepts such as:

* File handling
* Data validation using regex
* Menu-driven functionality

## Features

### For Users:
* **Account Management:**
  * Create accounts with a unique ID (e.g., `USR0001`).
  * Secure accounts using password validation.
  * View and manage account balances.

* **Book Borrowing:**
  * View available books.
  * Borrow books (requires sufficient balance).

### For Admins:
* **Book Management:**
  * Add new books with unique ISBNs (e.g., `B0001`).
  * Modify book details (title and author).
  * Remove books from the system.

* **User Management:**
  * View all registered users.
  * Check individual user details.

* **System Information:**
  * List all available books.
  * Monitor user balances.

## Project Workflow

### User Operations:
1. **Create Account**: Users can register with a unique ID and initial deposit.
2. **Login**: Users can log in using their credentials to view or manage their accounts.
3. **Book Borrowing**: Users can borrow books if available and balance permits.

### Admin Operations:
1. **Login**: Admin logs in using predefined credentials (`user-admin/Password-Admin@123`).
2. **Manage Books**:
   * Add, edit, or remove books from the system.
3. **View Users**:
   * Display user details or a message if no users are registered.
4. **Monitor Books**:
   * List all books with their status (available or borrowed).

## Validation Rules
* **User ID**: Must match `USRXXXX` format (e.g., `USR0001`).
* **Password**: Minimum 8 characters, with at least:
  * One uppercase letter.
  * One lowercase letter.
  * One digit.
  * One special character.
* **ISBN**: Must follow `BXXXX` format (e.g., `B0001`).

## Sample Output
### Welcome Screen:
* Welcome! Choose an option:

1. * Create Account
2. * Login as User
3. * Login as Admin
0. * Exit
  
    
### Admin Menu:
### Welcome Admin!

1. * Add Book
2. * Modify Book Details
3. * Remove Book
4. * List All Books
5. * View All Users
0. * Logout

### User Menu:
### Welcome, User Name!

1. * View Balance
2. * Deposit Funds
3. * Borrow Book
0. * Logout

## System Requirements
* **Language**: C++ (Standard: C++11 or later).
* **Compiler**: Any C++ compiler (e.g., GCC, Visual Studio).
* **Operating System**: Cross-platform.

## How to Run
1. Clone the repository or copy the files to your local machine.
2. Compile the program using a C++ compiler.
3. Run the executable and follow on-screen instructions.
