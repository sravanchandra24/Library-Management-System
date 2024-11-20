#include <iostream>
#include <cstring>
#include <iomanip>
#include <regex>

using namespace std;

// Constants
const int MAX_USERS = 20;
const int MAX_BOOKS = 15;
const int MAX_STRING_LENGTH = 50;

// Global variables
int user_count = 0;
int book_count = 0;
double account_balances[MAX_USERS];
string user_ids[MAX_USERS];
char user_names[MAX_USERS][MAX_STRING_LENGTH];
char book_titles[MAX_BOOKS][MAX_STRING_LENGTH];
char book_authors[MAX_BOOKS][MAX_STRING_LENGTH];
string book_isbns[MAX_BOOKS];
bool book_availability[MAX_BOOKS];

// Function prototypes
void create_user_account();
void login_user();
void admin_login();
void add_book();
void remove_book();  // New function for removing a book
void modify_book_details();
void list_all_books();
void view_all_users();
void view_user_details(string user_id);
int find_user_index(string user_id);
bool validate_user_id(const string &user_id);
bool validate_password(const string &password);
bool validate_book_isbn(const string &isbn);
int find_book_index(string isbn);  // Make sure this line is present

int main() {
    // Initialize default books with simplified ISBNs
    for (int i = 0; i < MAX_BOOKS; i++) {
        strcpy(book_titles[i], "Default Title");
        strcpy(book_authors[i], "Default Author");
        book_isbns[i] = "B" + to_string(i + 1).insert(0, 4 - to_string(i + 1).length(), '0'); // e.g., B0001, B0002
        book_availability[i] = true;
    }
    book_count = MAX_BOOKS;

    int choice;

    while (true) {
        cout << "\nWelcome! Choose an option:\n1. Create Account\n2. Login as User\n3. Login as Admin\n0. Exit\n";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                create_user_account();
                break;
            case 2:
                login_user();
                break;
            case 3:
                admin_login();
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

void create_user_account() {
    if (user_count >= MAX_USERS) {
        cout << "User limit reached. Cannot create more accounts.\n";
        return;
    }

    string user_id;
    cout << "Enter a unique user ID (format: USRXXXX): ";
    cin >> user_id;

    if (!validate_user_id(user_id)) {
        cout << "Invalid User ID format. It should be 'USRXXXX' (e.g., USR0001).\n";
        return;
    }

    if (find_user_index(user_id) != -1) {
        cout << "Account already exists for this User ID.\n";
        return;
    }

    user_ids[user_count] = user_id;
    cout << "Enter your name: ";
    cin.ignore();
    cin.getline(user_names[user_count], MAX_STRING_LENGTH);

    string password;
    cout << "Set a password (minimum 8 characters, including uppercase, lowercase, number, and special character): ";
    cin >> password;

    if (!validate_password(password)) {
        cout << "Invalid password. It must have at least 8 characters, including uppercase, lowercase, a number, and a special character.\n";
        return;
    }

    double initial_deposit;
    cout << "Enter initial deposit amount ($50 minimum): ";
    cin >> initial_deposit;

    if (initial_deposit < 50) {
        cout << "Initial deposit must be at least $50.\n";
        return;
    }

    account_balances[user_count] = initial_deposit - 50; // Deduct account setup fee
    user_count++;
    cout << "Account created successfully. Your User ID is " << user_id << ".\n";
}

void login_user() {
    string user_id;
    cout << "Enter your User ID: ";
    cin >> user_id;

    int index = find_user_index(user_id);
    if (index == -1) {
        cout << "User not found. Please create an account first.\n";
        return;
    }

    int choice;
    cout << "Welcome, " << user_names[index] << "!\n";
    while (true) {
        cout << "User Menu:\n1. View Balance\n2. Deposit Funds\n3. Borrow Book\n0. Logout\n";
        cin >> choice;

        if (choice == 0) {
            cout << "Logged out successfully.\n";
            break;
        }

        switch (choice) {
            case 1:
                view_user_details(user_id);
                break;
            case 2: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account_balances[index] += amount;
                cout << "New balance: $" << fixed << setprecision(2) << account_balances[index] << endl;
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

void admin_login() {
    string username, password;
    cout << "Enter Admin Username: ";
    cin >> username;
    cout << "Enter Admin Password: ";
    cin >> password;

    if (username == "admin" && password == "Admin@123") {
        int choice;
        cout << "Welcome Admin!\n";
        while (true) {
            cout << "Admin Menu:\n1. Add Book\n2. Remove Book\n3. Modify Book Details\n4. List All Books\n5. View All Users\n0. Logout\n";
            cin >> choice;

            if (choice == 0) {
                cout << "Logged out successfully.\n";
                break;
            }

            switch (choice) {
                case 1:
                    add_book();
                    break;
                case 2:
                    remove_book();  // Adding the remove book feature
                    break;
                case 3:
                    modify_book_details();
                    break;
                case 4:
                    list_all_books();
                    break;
                case 5:
                    view_all_users();
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    } else {
        cout << "Invalid Admin credentials. Access denied.\n";
    }
}

void add_book() {
    if (book_count >= MAX_BOOKS) {
        cout << "Book limit reached. Cannot add more books.\n";
        return;
    }

    cout << "Enter book title: ";
    cin.ignore();
    cin.getline(book_titles[book_count], MAX_STRING_LENGTH);

    cout << "Enter book author: ";
    cin.getline(book_authors[book_count], MAX_STRING_LENGTH);

    string isbn;
    cout << "Enter book ISBN (format: BXXXXX): ";
    cin >> isbn;

    if (!validate_book_isbn(isbn)) {
        cout << "Invalid ISBN format. It should be 'BXXXXX' (e.g., B0001).\n";
        return;
    }

    book_isbns[book_count] = isbn;
    book_availability[book_count] = true;
    book_count++;
    cout << "Book added successfully.\n";
}

void remove_book() {
    string isbn;
    cout << "Enter the ISBN of the book to remove: ";
    cin >> isbn;

    int index = find_book_index(isbn);
    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    // Shift books to remove the book from the list
    for (int i = index; i < book_count - 1; i++) {
        strcpy(book_titles[i], book_titles[i + 1]);
        strcpy(book_authors[i], book_authors[i + 1]);
        book_isbns[i] = book_isbns[i + 1];
        book_availability[i] = book_availability[i + 1];
    }

    book_count--;
    cout << "Book with ISBN " << isbn << " removed successfully.\n";
}

void modify_book_details() {
    string isbn;
    cout << "Enter the ISBN of the book to modify: ";
    cin >> isbn;

    int index = find_book_index(isbn);
    if (index == -1) {
        cout << "Book not found.\n";
        return;
    }

    cout << "Current Title: " << book_titles[index] << "\nNew Title: ";
    cin.ignore();
    cin.getline(book_titles[index], MAX_STRING_LENGTH);

    cout << "Current Author: " << book_authors[index] << "\nNew Author: ";
    cin.getline(book_authors[index], MAX_STRING_LENGTH);

    cout << "Book details updated successfully.\n";
}

void list_all_books() {
    for (int i = 0; i < book_count; i++) {
        cout << "ISBN: " << book_isbns[i] << ", Title: " << book_titles[i] << ", Author: " << book_authors[i] 
             << ", Available: " << (book_availability[i] ? "Yes" : "No") << "\n";
    }
}

void view_all_users() {
    if (user_count == 0) {
        cout << "No users available.\n";
        return;
    }

    for (int i = 0; i < user_count; i++) {
        cout << "User ID: " << user_ids[i] << ", Name: " << user_names[i] << ", Balance: $" 
             << fixed << setprecision(2) << account_balances[i] << "\n";
    }
}

void view_user_details(string user_id) {
    int index = find_user_index(user_id);
    if (index == -1) {
        cout << "User not found.\n";
        return;
    }
    cout << "User ID: " << user_ids[index] << ", Name: " << user_names[index] << ", Balance: $" 
         << fixed << setprecision(2) << account_balances[index] << "\n";
}

int find_user_index(string user_id) {
    for (int i = 0; i < user_count; i++) {
        if (user_ids[i] == user_id) {
            return i;
        }
    }
    return -1;
}

bool validate_user_id(const string &user_id) {
    return regex_match(user_id, regex("USR[0-9]{4}"));
}

bool validate_password(const string &password) {
    return password.length() >= 8 && regex_search(password, regex("[A-Z]")) && 
           regex_search(password, regex("[a-z]")) && regex_search(password, regex("[0-9]")) &&
           regex_search(password, regex("[^A-Za-z0-9]"));
}

bool validate_book_isbn(const string &isbn) {
    return regex_match(isbn, regex("B[0-9]{4}"));
}

int find_book_index(string isbn) {
    for (int i = 0; i < book_count; i++) {
        if (book_isbns[i] == isbn) {
            return i;
        }
    }
    return -1;
}
