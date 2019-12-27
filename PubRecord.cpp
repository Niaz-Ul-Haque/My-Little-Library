#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "colors.h"
#include "PubRecord.h"
#include "ReadWriteable.h"
#include "Date.h"
#include "Menu.h"
#include "Utils.h"
#include "Magazine.h"

namespace sdds {

	void PubRecord::name(const char* name) {
		if (name != nullptr) {
			sen_publicationName = new char[strlen(name) + 1]; 
			strcpy(sen_publicationName, name);
		}
		else {
			sen_publicationName = nullptr;
		}
	}

	const char* PubRecord::name()const {
		return sen_publicationName;
	}

	PubRecord::PubRecord() {
		sen_media = SDDS_CONSOLE;
		sen_shelfNo = 0;
		sen_publicationName = nullptr;
	}

	PubRecord::PubRecord(const PubRecord& copy1): sen_publicationName(nullptr) {
		name(copy1.sen_publicationName);
		sen_shelfNo = copy1.sen_shelfNo;
		sen_media = copy1.sen_media;	
	}

	PubRecord::~PubRecord() {
		delete[] sen_publicationName;
	}

	PubRecord& PubRecord::operator=(const PubRecord& copy1) {
		if (this != &copy1) {
			name(copy1.sen_publicationName);

			sen_shelfNo = copy1.sen_shelfNo;
			sen_media = copy1.sen_media;
		}
		return *this;
	}

	void PubRecord::mediaType(int media) {
		sen_media = media;
	}

	int PubRecord::mediaType()const {
		return sen_media;
	}

	int PubRecord::shelfNo()const {
		return sen_shelfNo;
	}

	void PubRecord::shelfNo(int value) {
		sen_shelfNo = value;
	}
	   	
	void PubRecord::readShelfNo() {
		int userSelect;
		readint(userSelect, 100, 999, "Invalid Shelf Number, Enter again: ");
		sen_shelfNo = userSelect;
	}	

	bool PubRecord::operator==(const char equals) {
		return recID() == equals;
	}

	bool PubRecord::operator==(const char* equals) {
		return strstr(sen_publicationName, equals);
	}

	PubRecord::operator bool()const {
		return (sen_publicationName != nullptr);
	}

}