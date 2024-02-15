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

    while (true) {
        cout << "Enter a name (or 'quit' to exit): ";
        string name;
        getline(cin, name);

        if (name == "quit") {
            break;
        }

        cout << "Enter " << name << "'s phone number: ";
        string phoneNumber;
        getline(cin, phoneNumber);

        cout << "Enter " << name << "'s email address: ";
        string email;
        getline(cin, email);

        book.addContact(name, phoneNumber, email);
    }

    
    while (true) {
        cout << "Enter a name to retrieve contact information (or 'quit' to exit): ";
        string name;
        getline(cin, name);

        if (name == "quit") {
            break;
        }

        pair<string, string> contact = book.getContact(name);
        if (contact.first.empty() && contact.second.empty()) {
            cout << name << " not found in address book." << endl;
        } else {
            cout << name << "'s phone number: " << contact.first << endl;
            cout << name << "'s email address: " << contact.second << endl;
        }
    }

    return 0;
}
