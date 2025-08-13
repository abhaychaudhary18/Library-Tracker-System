#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int _id, const string& _title, const string& _author)
        : id(_id), title(_title), author(_author), isBorrowed(false) {}
};

class Library {
private:
    vector<Book> books;
    int nextId = 1;
    const string adminPassword = "admin123";

    static void clearStdinLine() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    Library() {
        // Pre-load famous books
        books.emplace_back(nextId++, "The Great Gatsby", "F. Scott Fitzgerald");
        books.emplace_back(nextId++, "To Kill a Mockingbird", "Harper Lee");
        books.emplace_back(nextId++, "1984", "George Orwell");
        books.emplace_back(nextId++, "Pride and Prejudice", "Jane Austen");
        books.emplace_back(nextId++, "The Hobbit", "J.R.R. Tolkien");
    }

    void addBook() {
        string password;
        cout << "Enter admin password: ";
        cin >> password;
        if (password != adminPassword) {
            cout << "Incorrect password.\n";
            return;
        }
        clearStdinLine();

        string title, author;
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);

        if (title.empty() || author.empty()) {
            cout << "Title/Author cannot be empty.\n";
            return;
        }

        books.emplace_back(nextId++, title, author);
        cout << "Book added successfully.\n";
    }

    void showAllBooks() const {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "\n=== All Books ===\n";
        for (const auto& b : books) {
            cout << "ID: " << b.id
                 << " | Title: " << b.title
                 << " | Author: " << b.author
                 << " | Status: " << (b.isBorrowed ? "Borrowed" : "Available") << '\n';
        }
    }

    void borrowBook() {
        int id;
        cout << "Enter book ID to borrow: ";
        if (!(cin >> id)) {
            handleInvalidNumber();
            return;
        }

        for (auto& b : books) {
            if (b.id == id) {
                if (b.isBorrowed) {
                    cout << "Book already borrowed.\n";
                } else {
                    b.isBorrowed = true;
                    cout << "You borrowed: " << b.title << '\n';
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter book ID to return: ";
        if (!(cin >> id)) {
            handleInvalidNumber();
            return;
        }

        for (auto& b : books) {
            if (b.id == id) {
                if (!b.isBorrowed) {
                    cout << "This book was not borrowed.\n";
                } else {
                    b.isBorrowed = false;
                    cout << "You returned: " << b.title << '\n';
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void showBorrowedBooks() const {
        bool any = false;
        cout << "\n=== Borrowed Books ===\n";
        for (const auto& b : books) {
            if (b.isBorrowed) {
                cout << "ID: " << b.id
                     << " | Title: " << b.title
                     << " | Author: " << b.author << '\n';
                any = true;
            }
        }
        if (!any) cout << "No borrowed books.\n";
    }

    static void handleInvalidNumber() {
        cout << "Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Tracker System ===\n";
        cout << "1. Add Book (Admin only)\n";
        cout << "2. Show All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Show Borrowed Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            Library::handleInvalidNumber();
            continue;
        }

        switch (choice) {
            case 1: lib.addBook(); break;
            case 2: lib.showAllBooks(); break;
            case 3: lib.borrowBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.showBorrowedBooks(); break;
            case 6: cout << "Exiting system.\n"; break;
            default: cout << "Invalid choice.\n"; break;
        }
    } while (choice != 6);

    return 0;
}
