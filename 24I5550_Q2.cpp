#include <iostream>
using namespace std;

class Feature {
public:
    string Name;
    Feature(string n) { Name = n; }
    virtual void analyze() = 0;
    virtual ~Feature() {}
};

class LandFeature : public Feature {
public:
    LandFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Land Feature: " << Name << " detected.\n";
    }
};

class WaterFeature : public Feature {
public:
    WaterFeature(string n) : Feature(n) {}
    void analyze() override {
        cout << "Water Feature: " << Name << " detected.\n";
    }
};

class Node {
public:
    int FeatureID;
    Feature* f;
    Node* next;

    Node(int id, Feature* obj) {
        FeatureID = id;
        f = obj;
        next = NULL;
    }

    ~Node() {
        delete f;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insert_end(int featureID, Feature* f) {
        Node* newNode = new Node(featureID, f);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted ID " << featureID << endl;
    }

    void delete_id(int id) {
        if (head == NULL) return;

        if (head->FeatureID == id) {
            Node* t = head;
            head = head->next;
            delete t;
            cout << "Deleted ID " << id << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->FeatureID != id)
            temp = temp->next;

        if (temp->next == NULL) {
            cout << "ID not found!\n";
            return;
        }

        Node* t = temp->next;
        temp->next = temp->next->next;
        delete t;
        cout << "Deleted ID " << id << endl;
    }

    void displayall() {
        Node* temp = head;
        cout << "\n---- Feature List ----\n";
        while (temp != NULL) {
            temp->f->analyze();
            temp = temp->next;
        }
        cout << "----------------------\n";
    }

    void reverseList() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
        cout << "List Reversed!\n";
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != NULL) {
            Node* n = temp->next;
            delete temp;
            temp = n;
        }
    }
};

int main() {
    LinkedList list;

    list.insert_end(101, new LandFeature("Forest"));
    list.insert_end(102, new WaterFeature("Ocean"));
    list.insert_end(103, new LandFeature("Desert"));
    list.insert_end(104, new WaterFeature("River"));

    list.displayall();
    list.delete_id(102);
    list.displayall();
    list.reverseList();
    list.displayall();

    return 0;
}

