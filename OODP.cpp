#include <iostream>
#include <string>
#include <map>

using namespace std;

class AddressBook {
public:
    void addContact(string name, string phoneNumber, string email) {
        contacts[name] = make_pair(phoneNumber, email);
    }

    pair<string, string> getContact(string name) {
        if (contacts.count(name) == 0) {
            return make_pair("", "");
        }
        return contacts[name];
    }

private:
    map<string, pair<string, string>> contacts;
};

int main() {
    AddressBook book;

    book.addContact("Sailesh", "123-456-7890", "Sailesh@srmist.edu.in");
    book.addContact("Sarvanan", "555-555-5555", "Sarvanan@srmist.edu.in");

    pair<string, string> Sailesh = book.getContact("Sailesh");
    if (Sailesh.first.empty() && Sailesh.second.empty()) {
        cout << "Sailesh not found in address book." << endl;
    } else {
        cout << "Sailesh's phone number: " << Sailesh.first << endl;
        cout << "Sailesh's email address: " << Sailesh.second << endl;
    }

    pair<string, string> Raju = book.getContact("Raju");
    if (Raju.first.empty() && Raju.second.empty()) {
        cout << "Raju not found in address book." << endl;
    }

    return 0;
}


