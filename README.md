
# **Library Tracker System – C++ Console Application**

## **Project Overview**

The **Library Tracker System** is a simple yet efficient console-based application written in C++ that helps manage a small library's inventory.
It allows an administrator to add new books and lets users view available books, borrow them, return them, and see which books are currently borrowed.
The system uses **object-oriented programming (OOP)** principles like **classes**, **encapsulation**, and **data abstraction** to manage books efficiently.

This project is ideal for **beginners** to understand OOP concepts in C++ and for **college projects** where library management is the problem statement.

---

## **Features**

1. **Add Book (Admin only)** –
   The admin can securely add new books to the library by entering a password (`admin123`). Each book is assigned a unique ID.

2. **View All Books** –
   Displays the complete list of books with their IDs, titles, authors, and availability status.

3. **Borrow Book** –
   A user can borrow a book by entering its ID, provided it’s available.

4. **Return Book** –
   A user can return a borrowed book by entering its ID.

5. **Show Borrowed Books** –
   Displays all the books currently borrowed from the library.

6. **Error Handling** –
   Handles invalid inputs, such as entering text instead of numbers, and prevents empty title/author names.

---

## **Preloaded Books**

When the application starts, it comes preloaded with a few famous books so the library is not empty:

* *The Great Gatsby* – F. Scott Fitzgerald
* *To Kill a Mockingbird* – Harper Lee
* *1984* – George Orwell
* *Pride and Prejudice* – Jane Austen
* *The Hobbit* – J.R.R. Tolkien

---

## **Technology Stack**

* **Language:** C++
* **Paradigm:** Object-Oriented Programming (OOP)
* **Compiler:** Works with GCC, Clang, or MSVC
* **Platform:** Any OS (Windows, Linux, MacOS) with a C++17 or later compiler

---

## **Class Structure**

### **Class: `Book`**

* **Attributes:** `id`, `title`, `author`, `isBorrowed`
* **Purpose:** Represents a single book and its details.

### **Class: `Library`**

* **Attributes:** `vector<Book> books`, `nextId`, `adminPassword`
* **Functions:**

  * `addBook()` – Adds a book after admin password check
  * `showAllBooks()` – Displays all books
  * `borrowBook()` – Marks a book as borrowed
  * `returnBook()` – Marks a book as returned
  * `showBorrowedBooks()` – Lists all borrowed books
  * `handleInvalidNumber()` – Handles invalid numeric inputs

---

## **How It Works**

1. When the program starts, it shows a **menu** with options from adding books to viewing borrowed ones.
2. The user selects an option by entering the menu number.
3. The system performs the action (with input validation) and returns to the menu.
4. The program continues until the user selects **Exit**.

---

## **Example Run**

```
=== Library Tracker System ===
1. Add Book (Admin only)
2. Show All Books
3. Borrow Book
4. Return Book
5. Show Borrowed Books
6. Exit
Enter your choice: 2

=== All Books ===
ID: 1 | Title: The Great Gatsby | Author: F. Scott Fitzgerald | Status: Available
ID: 2 | Title: To Kill a Mockingbird | Author: Harper Lee | Status: Available
...
```

---

## **Installation & Execution**

**Step 1:** Save the code as `library.cpp`
**Step 2:** Open terminal/command prompt and compile:

```
g++ -std=c++17 library.cpp -o library
```

**Step 3:** Run the program:

```
./library
```

---

## **Advantages of This System**

* Simple and beginner-friendly
* Password-protected admin actions
* Handles invalid inputs gracefully
* Easily extendable (can add database integration later)

---

## **Possible Future Improvements**

* Store books in a **file/database** so data persists after closing the program
* Add **user login system** for different members
* Implement **search and filter** for books by title/author
* Add **due dates & fines** for late returns
* Create a **GUI version** using Qt or other frameworks

---

If you want, I can now also prepare a **beautiful formatted README.md file** with sections, code blocks, and screenshots so it looks like a professional GitHub project page.
This will make it ready for **submission or portfolio upload**.
