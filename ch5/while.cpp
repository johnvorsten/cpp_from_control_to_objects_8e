#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool _yes_regex_search(string response) {
    /*Perform regex target matching for a user input. Return true
    if the input sequence contains Y, Yes, True (case insensitive)
    inputs
    -------
    response : (string) regex target sequence
    outputs
    -------
    accepted : (bool)
    */
    bool accepted;

    string accept_pattern = "(yes|^y$|true)"; // Regex pattern
    string reject_pattern = "(no|^n$|false)"; // Regex pattern

    std::regex accept_reg(accept_pattern, 
        std::regex_constants::ECMAScript | std::regex_constants::icase);
    std::regex reject_reg(reject_pattern, 
        std::regex_constants::ECMAScript | std::regex_constants::icase);

    if (std::regex_search(response, accept_reg)) {
        // Perform regex search for accepted resposne in the string
        // Includes [Y, Yes, True] case-insensitive
        accepted = true;
    }
    else if (std::regex_search(response, reject_reg)) {
        // else the response is false
        accepted = false;
    }
    else {
        throw std::logic_error("The user neither accepted or rejected the TOS");
    }

    return accepted;
}


void user_input () {

    string response;
    bool response_valid = false;
    bool accepted;

    cout << "Please carefully read the terms of service agreement : " << endl;
    cout << "By using this product you're signing your life away" << endl;

    while (!(response_valid)) {
        // Gather user input data
        cout << "Do you accept the terms of the service agreement [Y/N]? : " << endl;
        std::getline(cin, response); // Read a whole line and consume e-o-l

        try {
            accepted = _yes_regex_search(response);
            response_valid = true;
        } catch (const std::logic_error& e) {
            cout << e.what();
            cout << "Please enter \"Y\" if you accept the TOS, or \"N\" if you reject" << endl;
            response_valid = false;
        }

    }

    if (accepted) {
        cout << "The user terms of service were accepted" << endl;
    }
    else {
        cout << "The user rejected the terms of service" << endl;
    }

}


int main () {
    user_input();
    return 0;
}