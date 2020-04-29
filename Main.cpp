#include <fstream>
#include <exception>
#include "Person.h"
#include "IComparable.h"
// uncomment for Task 2
//#include "Sorter.h"

using namespace std;

//Test the implemented classes here
int main() 
{
	// Creating the array of Persons
	const unsigned maxPeople = 4;	
	Person* people[maxPeople];

	people[0] = new Person(12, 100, 50);
	people[1] = new Person(30, 180, 85);
	people[2] = new Person(40, 182, 90);
	people[3] = new Person(40, 182, 90);

	
	// Modify if necessary
	const char* fname = "data.txt";
	
	// Save the array of Persons to external file
	ofstream os(fname);
	if(!os) {
		cerr << "Error opening output file: " << fname << endl;
		return -1;
	}
	// Testing attributes and getters/setters of Person class
	// setAge should throw an invalid_argument exception when its argument is negative
	try {
		cout << "Trying to set a negative value for age: " << endl;
		people[0]->setAge(-25);
	}
	catch (const invalid_argument& e) {
		cerr << "setAge got an invalid argument " << e.what() << endl;
	}

	for(unsigned int i=0; i < maxPeople; i++) {
		// Testing save function
		people[i]->save(os);
		people[i]->setAge(25);
		people[i]->setHeight(20);
		people[i]->setWeight(10);
	}

	os.close();
	if(!os) {
		cerr << "Error closing output file: " << fname << endl;
		return -1;
	}

	// load the array of Persons from external file
	ifstream is(fname);
	if(!is) {
		cerr << "Error opening input file: " << fname << endl;
		return -1;
	}

	for(int j=0; j<maxPeople; j++) {
		// Testing load function
		people[j]->load(is);
	}

	is.close();
	if(!is) {
		cerr << "Error closing input file: " << fname << endl;
		return -1;
	}

	// Test the 'equal' comparison (operator==)
	if(!(*people[2] == *people[3]))
		return -1;

	// Test the 'greater than' comparison (operator>)
	if(*people[1] > *people[2])
		return -1;

	// Put a breakpoint here. If execution reaches this point without errors, the mandatory Task 1 is done successfully.
	
	// TASK 2 (optional): Sorting
	
	// Writing original Persons
	cout << "Original 'Person' objects:" << endl;
    for (int i = 0; i < maxPeople; i++)
		cout << people[i] << endl;

	// Uncomment for Task2
	// Sorting the array
	// Sorter::BubbleSort((IComparable**)people, maxPeople);

	// Writing sorted Persons
	cout << endl << endl << "Sorted 'Person' objects:" << endl;
    for (int i = 0; i < maxPeople; i++)
		cout << people[i] << endl;
    
//	 Releasing memory
	for(int i=0; i < maxPeople; i++)
		delete people[i];

	// Put a breakpoint here.
	// Check the output on the screen. If 'Person' objects are sorted in descending order, the Task 2 is done successfully.
	return 0;
}