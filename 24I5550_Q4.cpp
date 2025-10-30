#include <iostream>
#include <string>
using namespace std;

class Customer {
	public:
		int customerID;
    	string name;
    	int tickets;
    	Customer* next;

    Customer(int id, string n, int t) {
        customerID = id;
        name = n;
        tickets = t;
        next = NULL;
    }
};

class TicketQueue {
private:
    Customer* front;
    Customer* rear;

public:
    TicketQueue() {
        front = NULL;
        rear = NULL;
    }
    
    
    ~TicketQueue() {
        while (front != NULL) {
            Customer* temp = front;
            front = front->next;
            delete temp;
        }
        cout << "Queue memory freed.\n";
    }

    void enqueue(int id, string name, int tickets) {
        Customer* newCustomer = new Customer(id, name, tickets);

        if (rear == NULL) {
            front = rear = newCustomer;
        } else {
            rear->next = newCustomer;
            rear = newCustomer;
        }

        cout << "Customer " << name << " added to queue.\n";
    }

    void dequeue() {
        if (front == NULL) {
            cout << "No customers in queue.\n";
            return;
        }

        Customer* temp = front;
        cout << "Serving customer: " << temp->name 
             << " (ID: " << temp->customerID 
             << ", Tickets: " << temp->tickets << ")\n";

        front = front->next;

        delete temp;
        
        if (front == NULL)
            rear = NULL;

    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "\nCurrent Queue:\n";
        Customer* temp = front;
        while (temp != NULL) {
            cout << "ID: " << temp->customerID 
                 << ", Name: " << temp->name 
                 << ", Tickets: " << temp->tickets << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TicketQueue queue;

    queue.enqueue(101, "Ali", 2);
    queue.enqueue(102, "Sara", 4);
    queue.enqueue(103, "Hassan", 1);

    queue.display();

    queue.dequeue();
    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    return 0;
}
