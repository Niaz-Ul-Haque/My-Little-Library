#ifndef SDDS_READWRITEABLE_H
#define SDDS_READWRITEABLE_H

#include <iostream>

namespace sdds {

	class ReadWriteable {

	public: 

	virtual std::ostream& write(std::ostream& os = std::cout)const = 0;
	virtual std::istream& read(std::istream& is = std::cin) = 0;

	};

	std::ostream& operator<<(std::ostream& os, const ReadWriteable& print);
	std::istream& operator>>(std::istream& is, ReadWriteable& input);
}


#endif