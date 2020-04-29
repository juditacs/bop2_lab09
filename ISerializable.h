#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <iostream>

// This class provides interface for saving/loading
class ISerializable
{
public:
	virtual void save(std::ostream &) const = 0;
	virtual void load(std::istream &) = 0;
};

#endif // SERIALIZABLE_H