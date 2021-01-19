// Specification file for the rectangle class
#ifndef RECTANGLE_H
#define RECTANGEL_H

// Rectangle class declaration
class Rectangle {

    private:
        double width;
        double height;

    public:
        void set_width(double);
        void set_length(double);
        double get_width() const; // const prevents the method from changing the class data
        double get_length() const;
        double get_area() const;

};

#endif