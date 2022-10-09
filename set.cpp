//---------------------------------------------------------------------
// Name: Robert Bennethum
// Email: rmb6287@psu.edu
// Class: CMPSC 122, Section 3
// Program 3.2
// Due Date: March 28, 2018, 11:59 PM
//
// Description: 
//A set is a collection of distinct (unique) items. Using a modified version of the Doubly Linked List we
//discussed in class, you will implement a Set class, and provide an interactive command loop to test the
//Set class.
//
// Acknowledgements:
//
//---------------------------------------------------------------------


//Err Union, intersection,


#include <iostream>
#include "list.h"

using namespace std;

class Set
{
private: 
	List* list;
	int set_size;
public:
	Set();
	~Set();

	bool contains(int value);
	bool add(int value);
	bool remove(int value);
	void clear();

	Set* set_union(Set&);
	Set* intersection(Set&);
	Set* difference(Set&);

    void print();
	int size() { return set_size; }
};

Set::Set() {
    set_size = 0;
    list = new List();
}

Set::~Set() {
    clear();
}

bool Set::contains(int value) {
    return list->contains(value);
}

bool Set::add(int value) {
    if (list->contains(value))
        return false;
    list->addToTail(value);
    set_size+=1;
    return true;
}

bool Set::remove(int value) {
    bool tf;
    tf = list->remove(value);
    if (tf)
        set_size-=1;
    return tf;
}

void Set::clear() {
for (int i = 0; i < set_size; i++) {
    list->removeHead();
}
set_size = 0;
}

Set *Set::set_union(Set &s) {
    Set *setTemp = new Set();
    for (int i = 0; i<set_size; i++)
        setTemp->add(list->at(i));
    for (int i = 0; i<s.set_size; i++)
        setTemp->add(s.list->at(i));
    return setTemp;
}

Set *Set::intersection(Set &s) {
    Set *setTemp = new Set();
    for (int i = 0; i<set_size; i++) {
        if (s.contains(list->at(i)))
            setTemp->add(list->at(i));
    }
    return setTemp;
}

Set *Set::difference(Set &s) {
    Set *setTemp = new Set();
    for (int i = 0; i<set_size; i++) {
        if (!s.contains(list->at(i))){
            setTemp->add(list->at(i));
        }
    }
    return setTemp;
}

void Set::print() {
cout << "set contents(" << set_size << "): ";
for (int i = 0; i<set_size; i++)
    cout << list->at(i) << " ";
cout << endl;
}

int main()
{
    auto set1 = new Set();
    auto set2 = new Set();
    int size1, size2;
    cout << "Enter the starting size of Set #1: ";
    cin >> size1;
    cout << "Enter the starting size of Set #2: ";
    cin >> size2;

    cout << "Enter " << size1 << " values for Set #1: ";
    for (int i = 0; i<size1; i++) {
        int value;
        cin >> value;
        set1->add(value);
    }
    cout << "Enter " << size2 << " values for Set #2: ";
    for (int i = 0; i<size2; i++) {
        int value;
        cin >> value;
        set2->add(value);
    }
    bool run = true;
    string input;
    cout << "Now accepting commands (quit to exit program): \n";
    while (run) {
        cin >> input;
        if (input == "contains") {
            int value, setNum;
            bool tf;
            cin >> value;
            cin >> setNum;
            if (setNum == 1) {
                tf = set1->contains(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else if (setNum == 2) {
                tf = set2->contains(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else
                cout << "error" << endl;
        }
        else if (input == "add") {
            int value, setNum;
            bool tf;
            cin >> value;
            cin >> setNum;
            if (setNum == 1) {
                tf = set1->add(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else if (setNum == 2) {
                tf = set2->add(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else
                cout << "error" << endl;
        }
        else if (input == "remove") {
            int value, setNum;
            bool tf;
            cin >> value;
            cin >> setNum;
            if (setNum == 1) {
                tf = set1->remove(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else if (setNum == 2) {
                tf = set2->remove(value);
                if (tf == 1)
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
            }
            else
                cout << "error" << endl;
        }
        else if (input == "print") {
            int setNum;
            cin >> setNum;
            if (setNum == 1)
                set1->print();
            else if (setNum == 2)
                set2->print();
        }
        else if (input == "union") {
            auto setUnion = set1->set_union(*set2);
            setUnion->print();
        }
        else if (input == "intersection") {
            auto set1int = set1->intersection(*set2);
            set1int->print();
        }
        else if (input == "difference") {
            auto set1dif = set1->difference(*set2);
            auto set2dif = set2->difference(*set1);
            cout << "First - Second" << endl;
            set1dif->print();
            cout << "Second - First" << endl;
            set2dif->print();
        }
        else if (input == "quit") {
            run = false;
            cout << "Exiting Program" << endl;
        }
        else
            cout << "Error, try again" << endl;
    }
}
