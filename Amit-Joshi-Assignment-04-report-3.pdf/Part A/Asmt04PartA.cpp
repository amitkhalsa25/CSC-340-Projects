//PartA
using namespace std;
#include <iostream>

int main() {
	//PART A Question 1
	//First we create two  *ptr
	string* ptr5 = new string;
	string* ptr10 = ptr5;
		delete ptr5;
     	delete ptr10;
		//Line 12 will cause error because we ae deleting both pointers twice
	}
//PART A Question 2
void firstMethod() {
	//we are now declaring a unique smart pointer, so for the pointer it will go out the scope.
	//Line 19 ptr1 will be gone as followed
	unique_ptr<int>ptr1(new int);
	int *ptr2 = NULL;
	delete ptr2;
}
///PART A question 3
class newClass {
public:
	string* running;
	string* sports;
	void someRandomMethod() {
		running = sports;
	}
};
class myFirstClass {
public:
	unique_ptr<string>pizza;
	// will be deleted 
};

//Part A question 4
void conversionSPointer(){
	unique_ptr<string> firstSmartPointer(new string("smart pointer made"));
	//Shows unique pointer is converted into shared pointer!
	shared_ptr<string> secoundSmartPointer = move(firstSmartPointer);
}
//Part A question 5
void newDuoMake() {
	shared_ptr<string>sharedPtr(new string);
	weak_ptr<string>weakptr = sharedPtr;
	sharedPtr.reset();
}



