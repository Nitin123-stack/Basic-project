#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class representing a book with title and author
class Book {
private:
    string title;
    string author;

public:
    // Constructor to initialize book details
    Book(string t, string a) : title(t), author(a) {}

    // Accessor methods to get book details
    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    // Method to display book details
    void display() const {
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

// Library class to manage the collection of books
class Library {
private:
    vector<Book> books; // Vector to store the list of books

public:
    // Method to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added: ";
        book.display();
    }

    // Method to remove a book from the library
    void removeBook(const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                cout << "Removing book: ";
                it->display();
                books.erase(it);
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    // Method to search for a book by title
    void searchBook(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << "Book found: ";
                book.display();
                return;
            }
        }
        cout << "Book not found: " << title << endl;
    }

    // Method to display all books in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        cout << "Books in the library:" << endl;
        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    Library library;

    // Add some books to the library
    library.addBook(Book("1984", "George Orwell"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee"));

    // Display all books
    library.displayAllBooks();

    // Search for a book
    library.searchBook("1984");

    // Remove a book
    library.removeBook("1984");

    // Display all books after removal
    library.displayAllBooks();

    return 0;
}
