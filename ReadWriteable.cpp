#include <iostream>
using namespace std;
#include "ReadWriteable.h"

namespace sdds {
	   
	ostream& operator<<(ostream& os, const ReadWriteable& output) {
		return output.write(os);
	}

	istream& operator>>(istream& is, ReadWriteable& input) {
		return input.read(is);
	}

}