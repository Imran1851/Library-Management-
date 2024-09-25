#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int bookID;
    string title;
    string author;
    bool isIssued;

    Book(int id, string t, string a) : bookID(id), title(t), author(a), isIssued(false) {}

    void displayBook() {
        cout << "Book ID: " << bookID << ", Title: " << title << ", Author: " << author 
             << ", " << (isIssued ? "Issued" : "Available") << endl;
    }
};

class Member {
public:
    int memberID;
    string name;

    Member(int id, string n) : memberID(id), name(n) {}

    void displayMember() {
        cout << "Member ID: " << memberID << ", Name: " << name << endl;
    }
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
    }

    void addMember(int id, string name) {
        members.push_back(Member(id, name));
    }

    void displayBooks() {
        cout << "Library Books:" << endl;
        for (Book &book : books) {
            book.displayBook();
        }
    }

    void displayMembers() {
        cout << "Library Members:" << endl;
        for (Member &member : members) {
            member.displayMember();
        }
    }

    void issueBook(int bookID, int memberID) {
        for (Book &book : books) {
            if (book.bookID == bookID && !book.isIssued) {
                book.isIssued = true;
                cout << "Book issued to Member ID: " << memberID << endl;
                return;
            }
        }
        cout << "Book is not available or doesn't exist." << endl;
    }

    void returnBook(int bookID) {
        for (Book &book : books) {
            if (book.bookID == bookID && book.isIssued) {
                book.isIssued = false;
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "This book was not issued." << endl;
    }
};

int main() {
    Library library;

    library.addBook(1, "C++ Programming", "Bjarne Stroustrup");
    library.addBook(2, "Introduction to Algorithms", "Thomas H. Cormen");

    library.addMember(1, "John Doe");
    library.addMember(2, "Jane Smith");

    library.displayBooks();
    library.displayMembers();

    library.issueBook(1, 1); 
    library.displayBooks();   

    library.returnBook(1);   
    library.displayBooks();   

    return 0;
}