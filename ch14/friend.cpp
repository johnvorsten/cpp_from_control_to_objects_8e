#include <iostream>
#include <string>

using namespace std;

namespace project {

// Class with friend member function
class Window {
	int width;
	int height;
	
	public:
	Window(int a, int b) : width(a), height(b) {}
	
	friend bool areSameSize(const Window& a, const Window& b);

    friend std::ostream& operator<<(std::ostream& os, const Window& window);

    friend std::istream& operator>>(std::istream& is, Window& window);
};

bool areSameSize(const Window& a, const Window& b) {
	if (a.width == b.width && a.height == b.height)
		return true;
	return false;
}

std::ostream& operator<<(ostream& os, const Window& window) {
    
    os << "Window<";
    os << window.width << ",";
    os << window.height << ",";
    os << ">" << std :: endl;

    return os;
}


std::istream& operator>>(std::istream& is, Window& window) {
	is >> window.width;
	is >> window.height;
	return is;
}

}; // End namespace project

int main () {}
