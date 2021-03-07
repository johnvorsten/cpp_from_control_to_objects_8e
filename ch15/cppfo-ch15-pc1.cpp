#include <string>
#include <iostream>
#include <cstdio>

using namespace std;


class GradedActivity{
    protected:
        double score;
    
    public:
    GradedActivity()
        {score = 0.0;}
    GradedActivity(double s)
        {score = s;}
    void setScore(double s)
        {score = s;}
    double getScore() const
        {return score;}

    char getLetterGrade() const;

};

char GradedActivity::getLetterGrade() const{
    char letterGrade;

    if (score > 89) {
    letterGrade = 'A';
    } else if (score > 79) {
    letterGrade = 'B';
    } else if (score > 69) {
    letterGrade = 'C';
    } else if (score > 59) {
    letterGrade = 'D';
    } else {
    letterGrade = 'F';
    }

    return letterGrade;
}

class Essay : public GradedActivity {

    public:
    double grammar;
    double spelling;
    double correct_length;
    double content;

    double calculate_score() {
        score = grammar + spelling + correct_length + content;
        return score;
    }

    void print() {
        printf("Numeric Grade: %0.0f\n", calculate_score());
        printf("Letter Grade: %c\n", getLetterGrade());
        // std::cout << "Numeric Grade: " << calculate_score() << "\n";
        // std::cout << "Letter Grade: " << getLetterGrade() << "\n";
    }

    void user_input() {
        std::cout << "Enter points received for grammar:";
        std::cin >> grammar;
        std::cout << "Enter points received for spelling:";
        std::cin >> spelling;
        std::cout << "Enter points received for correct length:";
        std::cin >> correct_length;
        std::cout << "Enter points received for content:";
        std::cin >> content;
        calculate_score();
    }

    Essay() {
        user_input();
    }

    Essay(double a, double b, double c, double d) : 
        grammar(a), spelling(b), correct_length(c), content(d) {
        calculate_score();
    }

};

void test_essay() {
    Essay essay;
    essay.getLetterGrade();
    essay.print();
}

int main () {

    test_essay();

    return 0;
}
