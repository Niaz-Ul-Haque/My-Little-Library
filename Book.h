#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "PubRecord.h"
#include "Date.h"
namespace sdds
{
	class Book : public PubRecord
	{
		long long sen_bookISBN;
		int sen_memID;
		Date date;
	public:
		Book();
		Book(const Book& copy1);
		Book& operator=(const Book& copy1);

		virtual ~Book();

		char recID()const;

		int memberId() const;
		void checkIn();
		void checkOut();

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os = std::cout)const;
	};

}
#endif