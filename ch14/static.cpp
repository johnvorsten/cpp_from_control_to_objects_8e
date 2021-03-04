
using namespace std;


class Counter {
	public:
	int counter;
	int limit;
	static int nCounters;
	
	Counter(int a, int b) : counter(a), limit(b) {
		nCounters += 1;}
	
	void increment() {
		if (counter < limit) {
			counter += 1;
		}
	}
	
	void decrement() {
		if (counter > 0)
			counter -=1;
	}
	
	int getValue() {
		return counter;
	}
	
	static int getNCounters() {
		return nCounters;
	}
	
};

int Counter::nCounters = 0;

int main () {}

