// Include
#include <string>
#include <vector>
#include <iostream>
#include <random>

// Namespace
using namespace std;

// Local declarations
struct tag {
    int member_name;
    // Additional declarations..
} tag_object1;

vector<string> eye_colors = {"Blue","Green","Brown","Hazel"};
vector<string> moods = {"Happy",
                        "Sad",
                        "Angry",
                        "Frustrated",
                        "Hungry",
                        "Elated",
                        "Unsure",};

struct sheebah {
    int age;
    string name;
    string eye_color;
    vector<string> mood_log;
    double salary;

    sheebah& operator=(const sheebah& other) {
        /*This allows me to use the = operator on an object to 
        fill in its data members*/
        age = other.age;
        eye_color = other.eye_color;
        mood_log = other.mood_log;
        return *this;
    }

    sheebah& operator+(const sheebah& other) {
        /*This allows me to add two sheebah objects together
        Double trouble*/
        age = (age + other.age) / 2; // Average age
        eye_color = eye_color + other.eye_color; // Append
        // Concatenate
        mood_log.reserve(mood_log.size() + other.mood_log.size()); 
        mood_log.insert(mood_log.end(), other.mood_log.begin(), other.mood_log.end());
        return *this;
    }

    void set_random_attributes() {
        /*Set the member attributes to random values*/
        std::random_device r;
        std::
        std::default_random_engine engine(r());
        std::uniform_int_distribution<int> age_dist(0,100);
        std::uniform_int_distribution<int> eye_dist(0,eye_colors.size());
        std::uniform_int_distribution<int> mood_dist(0,moods.size());
        std::uniform_int_distribution<int> name_length_dist(0, 20);
        std::uniform_int_distribution<int> lowercase_char_dist(97,122);
        std::uniform_real_distribution<double> uniform_dist_double(30000,500000);

        // Set age
        age = age_dist(engine);

        // Set name
        for (int i=0; i < name_length_dist(engine); i++) {
            name += lowercase_char_dist(engine);
        }

        // Set eye_color
        eye_color = eye_colors[eye_dist(engine)];

        // Set mood
        mood_log.push_back(moods[mood_dist(engine)]);

        // Set salary
        salary = uniform_dist_double(engine);

    }


};

// Function declarations
void print_sheebah(sheebah& sheebs) {
    std::cout << "The one named " << sheebs.name << " ";
    std::cout << "makes " << sheebs.salary << " dollars/year, ";
    std::cout << "has " << sheebs.eye_color << " eyes, ";
    std::cout << "is currently " << sheebs.mood_log.back() << " mood, ";
    std::cout << "and is " << sheebs.age << " years old." << endl;
}



int main () {

    // Accessing and assigning structures
    sheebah my_girl, side_biss;
    my_girl.age = 25;
    my_girl.name = "Fiance";
    my_girl.eye_color = "brown";
    my_girl.mood_log.push_back(string("Hungry"));
    my_girl.salary = 80000.00;

    // Initialize side_biss with the contents of my_girl
    side_biss = my_girl;
    // Change the eye color and salary of side_biss
    side_biss.name = "Other girl";
    side_biss.salary = 45000;
    side_biss.eye_color = string("Green");
    side_biss.mood_log.push_back(string("Happy"));

    // Print the attributes of my_girl and side_biss
    std::cout << "I have two girlfriends. The main one ";
    std::cout << "makes " << my_girl.salary << " dollars/year, ";
    std::cout << "has " << my_girl.eye_color << " eyes, ";
    std::cout << "is currently " << my_girl.mood_log.back() << " mood, ";
    std::cout << "and is " << my_girl.age << " years old." << endl;

    std::cout << "The second one ";
    std::cout << "makes " << side_biss.salary << " dollars/year, ";
    std::cout << "has " << side_biss.eye_color << " eyes, ";
    std::cout << "is currently " << side_biss.mood_log.back() << " mood, ";
    std::cout << "and is " << side_biss.age << " years old." << endl;

    // Initialize the members of a structure
    vector<string> vec {string("Upset"), string("Happy")};
    sheebah side_biss3 {28, "Third girl", string{"Hazel"}, vector<string> {string("Upset"), string("Happy")}, 75000.0};
    print_sheebah(side_biss3);

    // Create your own girl
    sheebah sheebs;
    char mood[256];
    std::cout << "Create your own girl" << endl;
    std::cout << "Enter her age : ";
    std::cin >> sheebs.age;
    std::cout << "Enter her name : ";
    std::cin >> sheebs.name;
    std::cout << "Enter her current mood : ";
    std::cin >> mood;
    sheebs.mood_log.push_back(mood);
    std::cout << "Enter her salary : ";
    std::cin >> sheebs.salary;


    // An array of sheebs
    {
        sheebah sheebs[3];
        for (int i=0;i<3;i++) {
            sheebs[i].set_random_attributes();
        }

    }


    return 0;
}