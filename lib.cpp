#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int bookId, string bookTitle, string bookAuthor)
    {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

class Member
{
public:
    int memberId;
    string name;

    Member(int id, string memberName)
    {
        memberId = id;
        name = memberName;
    }
};

vector<Book> books;
vector<Member> members;

void addBook()
{
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "Book Added Successfully!\n";
}

void addMember()
{
    int id;
    string name;

    cout << "\nEnter Member ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "Member Added Successfully!\n";
}

void displayBooks()
{
    if (books.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n===== BOOK LIST =====\n";

    for (int i = 0; i < books.size(); i++)
    {
        cout << "\nBook ID: " << books[i].id;
        cout << "\nTitle: " << books[i].title;
        cout << "\nAuthor: " << books[i].author;

        if (books[i].isIssued)
            cout << "\nStatus: Issued\n";
        else
            cout << "\nStatus: Available\n";
    }
}

void issueBook()
{
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            found = true;

            if (books[i].isIssued)
            {
                cout << "Book is already issued!\n";
            }
            else
            {
                books[i].isIssued = true;
                cout << "Book Issued Successfully!\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "Book Not Found!\n";
    }
}

void returnBook()
{
    int id;
    bool found = false;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].id == id)
        {
            found = true;

            if (!books[i].isIssued)
            {
                cout << "Book was not issued!\n";
            }
            else
            {
                books[i].isIssued = false;
                cout << "Book Returned Successfully!\n";
            }

            break;
        }
    }

    if (!found)
    {
        cout << "Book Not Found!\n";
    }
}

void searchBook()
{
    int choice;
    string keyword;
    bool found = false;

    cout << "\nSearch By:";
    cout << "\n1. Title";
    cout << "\n2. Author";
    cout << "\nEnter Choice: ";
    cin >> choice;

    cin.ignore();

    cout << "Enter Search Keyword: ";
    getline(cin, keyword);

    for (int i = 0; i < books.size(); i++)
    {
        if ((choice == 1 && books[i].title == keyword) ||
            (choice == 2 && books[i].author == keyword))
        {
            found = true;

            cout << "\nBook Found!";
            cout << "\nBook ID: " << books[i].id;
            cout << "\nTitle: " << books[i].title;
            cout << "\nAuthor: " << books[i].author;

            if (books[i].isIssued)
                cout << "\nStatus: Issued\n";
            else
                cout << "\nStatus: Available\n";
        }
    }

    if (!found)
    {
        cout << "No Matching Book Found!\n";
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n LIBRARY MANAGEMENT SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Add Book";
        cout << "\n2. Add Member";
        cout << "\n3. Display Books";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Search Book";
        cout << "\n7. Exit";
        cout << "\nEnter Your Choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            addMember();
            break;

        case 3:
            displayBooks();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            searchBook();
            break;

        case 7:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}