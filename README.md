# Library-management-system-C-Project
Library management system C++ OOP Project

# 📚 Library Management System

A console-based **Library Management System** implemented in **C++** (`main.cpp`). Built around Object-Oriented Programming (OOP) principles, C++ Standard Template Library (`std::vector`), and automated RAII file persistence, the system manages book catalogs, member registrations, and borrowing/returning transactions.

---

## ✨ Features

### 📖 Book Catalog Management (`Library` Class)
* **Add New Books:** Register titles with genre/type, author name, stock quantity, and auto-incremented Book IDs.
* **Display All Books:** View a formatted table of all available books with their IDs, stock quantities, and titles.
* **Search Books by ID:** Retrieve detailed book records (Title, Type, Author, and Available Quantity).

### 👥 Member & Circulation Management (`Person` Class)
* **Member Account Registration:** Create member profiles storing full name, occupation/job, and unique Member ID.
* **Borrow Books:** Validates member ID and book stock availability before issuing a book, decrementing inventory, and updating the member's borrowed book list.
* **Return Books:** Verifies that the member currently holds the specified book ID, restores stock quantity, and updates the member's active borrow list.
* **View Borrowed Books:** Displays all books currently checked out by a specific member.
* **Directory & Search:** List all registered members or look up individual member profiles and borrowed book counts by ID.

### 💾 Automated File Persistence (RAII)
* **Automatic Loading on Startup:** The `Library()` constructor reads existing book and member records from `datafile.txt` and `PersonData.txt` upon launch[cite: 2].
* **Automatic Saving on Exit:** The `~Library()` destructor automatically serializes and writes all updated book and member records back to disk when the program terminates[cite: 2].

---

## 🛠️ Tech Stack & Concepts Used

* **Language:** C++ (`<iostream>`, `<fstream>`, `<vector>`, `<string>`, `<iomanip>`, `<algorithm>`)[cite: 2]
* **Core Concepts:**
  * **Object-Oriented Programming:** `Library` and `Person` classes with encapsulation (`private` member attributes) and `friend` functions/classes[cite: 2]
  * **RAII Resource Management:** Constructor-based file loading and destructor-based file saving[cite: 2]
  * **Data Structures:** `struct Book` and dynamic `std::vector` containers (`listOfBooks`, `listOfPersons`, `listOfBorrowedBook`)[cite: 2]
  * **Custom Delimited Parsing:** Slash-delimited (`/`) storage for books and pipe/comma-delimited (`|` and `,`) storage for member records[cite: 2]

---

## 📂 Project Structure

```text
Library-Management-System/
├── main.cpp           # Complete source code (Book struct, Person & Library classes, main menu)
├── datafile.txt       # Auto-generated flat-file database for book records (slash-delimited)
├── PersonData.txt     # Auto-generated flat-file database for member records (pipe-delimited)
└── README.md          # Project documentation
```
## 🚀 Getting Started
Prerequisites
A C++ compiler supporting C++11 or later (G++ / MinGW, Clang, or MSVC) or an IDE such as Code::Blocks, Dev-C++, or VS Code.

Platform Note: The source code uses system("cls") for clearing the console screen on Windows. (If compiling on Linux or macOS, replace system("cls") with system("clear")).

## 📖 Usage Guide
* Upon launching the program, choose from the 10-option interactive console menu[cite: 2]:

* Display all books — View the entire library catalog[cite: 2]

* Display all Persons — View all registered library members[cite: 2]

* Search of a book — Look up book details by Book ID[cite: 2]

* Search of a person — Look up member details by Member ID[cite: 2]

* Add a book — Add a new book title and quantity to the catalog[cite: 2]

* Display person list of Books — Check which books a specific member has borrowed[cite: 2]

* Borrow a book — Check out a book using Book ID and Member ID[cite: 2]

* Return a book — Return a borrowed book and restore catalog stock[cite: 2]

* Create a new account — Register a new library member[cite: 2]

* Exit — Enter X or x to exit and trigger automatic file saving[cite: 2]

# 👤 Author
Mohammed Lutfi Mahfoodh Basseif

GitHub: @Mohammed-Lutfi144
