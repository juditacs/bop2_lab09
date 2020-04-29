#ifndef PERSON_H
#define PERSON_H

#include "IComparable.h"
#include "ISerializable.h"

class Person: public IComparable, public ISerializable
{
	 double height;
	 double weight;
	 int age;
public:
	// Constructor
	Person(int age, double height, double weight): age(age), height(height), weight(weight) {}

	// Getters and setters
	void setHeight(double height);
	double getHeight() const;
	void setWeight(double weight);
	double getWeight() const;
	// negative age should not be allowed
	void setAge(int age) const;
	int getAge() const;

	// Comparing with another Person object (equal?)
	bool operator==(const IComparable& theOther) const;
	// Comparing with another Person object (less?)
	bool operator>(const IComparable& theOther) const;

	// Saving to file
	void save(std::ostream &) const;
	// Loading from file
	void load(std::istream &);
};
#endif