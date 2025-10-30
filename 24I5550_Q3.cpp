#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int bookid;
    string title;
    string author;
    Node* next;
    Node* prev;

    Node(int id, string t, string a) {
        bookid = id;
        title = t;
        author = a;
        next = prev = NULL;
    }
};

class library {
private:
    Node* head;
    Node* tail;
public:
    library() {
        head = tail = NULL;
    }

    void add_begin(int id, string t, string a) {
        Node* newnode = new Node(id, t, a);
        if (head == NULL && tail == NULL) {
            head = tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        cout << "Book Added at Beginning\n";
    }

    void add_end(int id, string t, string a) {
        Node* newnode = new Node(id, t, a);
        if (head == NULL && tail == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        cout << "Book Added at End\n";
    }

    void addAtPosition(int pos, int id, string title, string author) {

        if (pos <= 1) {
            add_begin(id, title, author);
            return;
        }

        Node* temp = head;
        int i = 1;

        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
            add_end(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;

        cout << "Book added at position " << pos << ".\n";
    }

    void deleteByID(int id) {
        if (head == NULL) {
            cout << "Library empty.\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL && temp->bookid != id)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Book not found.\n";
            return;
        }

        if (temp == head && temp == tail) {
            head = tail = NULL;
        }
        else if (temp == head) {
            head = head->next;
            head->prev = NULL;
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;

        cout << "Book with ID " << id << " deleted.\n";
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Library empty.\n";
            return;
        }

        cout << "\nLibrary (Forward):\n";
        Node* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->bookid
                << ", Title: " << temp->title
                << ", Author: " << temp->author << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (tail == NULL) {
            cout << "Library empty.\n";
            return;
        }

        cout << "\nLibrary (Backward):\n";
        Node* temp = tail;
        while (temp != NULL) {
            cout << "ID: " << temp->bookid
                << ", Title: " << temp->title
                << ", Author: " << temp->author << endl;
            temp = temp->prev;
        }
    }
};

int main() {
    library lib;

    lib.add_begin(101, "The Alchemist", "Paulo Coelho");
    lib.add_end(102, "1984", "George Orwell");
    lib.add_end(103, "To Kill a Mockingbird", "Harper Lee");
    lib.addAtPosition(2, 104, "Pride and Prejudice", "Jane Austen");

    lib.displayForward();
    lib.displayBackward();

    lib.deleteByID(104);
    lib.deleteByID(101);

    lib.displayForward();
    lib.displayBackward();

    return 0;
}

