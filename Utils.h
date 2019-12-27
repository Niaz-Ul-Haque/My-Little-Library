#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{

	/*
	A set function that generically works with cstring pointer copying w/ dynamic memory
	A src and dest are given as parameters where the latter is a pointer reference. Where
  the dynamic allocation would take place.
	If the src isn't nullptr, normal processing occurs otherwise dest is set to nullptr.
	Assumes dest is allocated or has been set to a safe empty state / nullptr.
  The max_len dicates how much memory is to be allocated to the dest at maximum
  for the copying / the max number of characters to copy. It is nullbyte non inclusive.
	*/

	void copystr(char*& dest, const char* src, unsigned int max_len);

	// reads an integer from console the integer referenced by "val"
	// argument.
	// if the user enters an invalid integer or values outside of the 
	// boundries set by "min" or "max" , this function flushes the 
	//keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable integer

	void readint(int& val, int min, int max, const char* errorMessage = "");

	// reads a C style string from console up to "len" characters into the
	// the string pointed by the "str" pointer
	// if the user enters more than "len" characters, this function
	// flushes the keyboard, prints the "errorMessage and reads again
	// untill user enters an acceptable string


	void readstr(char* str, int len, const char* errorMessage = "");

	void readLongint(long long& val, long long  min, long long max, const char* ErrorMess);
}
#endif