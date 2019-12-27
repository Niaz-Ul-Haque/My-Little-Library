#ifndef SDDS_PUBRECORD_H
#define SDDS_PUBRECORD_H 

#include "ReadWriteable.h"

namespace sdds {

	const int SDDS_FILE = 1;
	const int SDDS_CONSOLE = 0;

	class PubRecord : public ReadWriteable {

		char* sen_publicationName;
		int sen_shelfNo;
		int sen_media;

	protected:

		void name(const char* name1);
		const char* name()const;
		void shelfNo(int value);

	public:

		virtual char recID()const = 0;
		virtual void checkIn() = 0;
		virtual void checkOut() = 0;

		PubRecord();
		PubRecord(const PubRecord& copy1);
		virtual ~PubRecord();
		PubRecord& operator=(const PubRecord& copy1);
		void mediaType(int media);
		int mediaType()const;
		int shelfNo()const;

		void readShelfNo();
		bool operator==(const char equals);
		bool operator==(const char* equals);
		operator bool()const;

		// Dont worry sir, wanted to put it in header file because it feels good  (to me atleast) when I try putting setEmpty/isEmpty in header files. (Out of the way of my main files)
		void setEmpty() {
			sen_media = 0;
			sen_shelfNo = 0;
			sen_publicationName = nullptr;
		}

	};

}

#endif
