#include <iostream>
#include <string>

using namespace std;

class PersonData {
    public:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;


};

class CustomerData : public PersonData {
    public:
    string customerNumber;
    bool mailingList;



};

void test_() {

    std::string input;
    CustomerData customer1;


    std::cout << "Creating derived class or subclass CustomerData from base class PersonData with: 'CustomerData customer1;'" << std::endl;

    std::cout << "Enter customer's last name:";
    std::cin >> input;
    std::cout << "customer1.setLastName(\"" << input << "\");" << std::endl;
    customer1.lastName = input;

    std::cout << "Enter customer's first name:";
    std::cin >> input;
    std::cout << "customer1.setFirstName(\"" << input << "\");" << std::endl;
    customer1.firstName = input;
    
    std::cout << "Enter customer's address:";
    std::getline(std::cin, input);
    std::getline(std::cin, input);
    std::cout << "customer1.setAddress(\"" << input << "\");" << std::endl;
    customer1.address = input;
    
    std::cout << "Enter customer's City:";
    std::getline(std::cin, input);
    std::cout << "customer1.setCity(\"" << input << "\");" << std::endl;
    customer1.city = input;
    
    std::cout << "Enter customer's State:";
    std::getline(std::cin, input);
    std::cout << "customer1.setState(\"" << input << "\");" << std::endl;
    customer1.state = input;
    
    std::cout << "Enter customer's Zip:";
    std::getline(std::cin, input);
    std::cout << "customer1.setZip(" << input << ");" << std::endl;
    customer1.zip = input;
    
    std::cout << "Enter customer's Phone number:";
    std::getline(std::cin, input);
    std::cout << "customer1.setPhone(" << input << ");" << std::endl;
    customer1.phone = input;
    
    std::cout << "Enter customer's Customer Number:";
    std::getline(std::cin, input);
    std::cout << "customer1.setCustomerNumber(" << input << ");" << std::endl;
    customer1.customerNumber = input;
    
    char input2;
    std::cout << "Enter 'y' if customer is on mailing listing list or 'n' if not.";
    std::cin >> input2;
    
    if (input2 == 'y') {
        customer1.mailingList = true;
    }
    else {
        customer1.mailingList = false;
    }
    std::cout << "customer1.setMailingList(" << customer1.mailingList << ");" << "\n\n\n";
    


    std::cout << "Using all the get functions from both the base and derived class to show state of CustomerData object:" << "\n";

    std::cout << "customer1.getLastName()= " << customer1.lastName << std::endl;
    std::cout << "customer1.getFirstName()= " << customer1.firstName << std::endl;
    std::cout << "customer1.getAddress()= " << customer1.address << std::endl;
    std::cout << "customer1.getCity()= " << customer1.city << std::endl;
    std::cout << "customer1.getState()= " << customer1.state << std::endl;
    std::cout << "customer1.getZip()= " << customer1.zip << std::endl;
    std::cout << "customer1.getPhone()= " << customer1.phone << std::endl;
    std::cout << "customer1.getCustomerNumber()= " << customer1.customerNumber << std::endl;
    std::cout << std::boolalpha;
    std::cout << "customer1.getMailingList()= " << customer1.mailingList << "." << std::endl;

}


int main () {

    test_();

    return 0;
}