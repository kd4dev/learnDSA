#include <iostream>
#include <iomanip> 
using namespace std;

class Book {
private:
    int bookid;
    string book_name;
    string author;
    float price;

public:
    void get_details() {
        cout << "Enter Book ID: ";
        cin >> bookid;
        cout << "Enter Book Name: ";
        cin >> book_name;
        cout << "Enter Author Name: ";
        cin >> author;
        cout << "Enter Price: ";
        cin >> price;
    }

    void print_details() {
        cout << setw(10) << bookid
             << setw(20) << book_name
             << setw(20) << author
             << setw(10) << fixed << setprecision(2) << price << endl;
    }

    float get_price() {
        return price;
    }
};

int main() {
    int n;
    float total = 0;

    cout << "How many books? ";
    cin >> n;

    Book books[n];

    for (int i = 0; i < n; ++i) {
        cout << "\n--- Enter details for Book " << i + 1 << " ---\n";
        books[i].get_details();
    }

    cout << "\n" << setw(10) << "Book ID"
         << setw(20) << "Book Name"
         << setw(20) << "Author"
         << setw(10) << "Price" << endl;
    cout << string(60, '-') << endl;

  
    for (int i = 0; i < n; ++i) {
        books[i].print_details();
        total += books[i].get_price();
    }

    cout << "\nTotal Price of All Books: ₹" << fixed << setprecision(2) << total << endl;

    return 0;
}