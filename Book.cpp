


#include <iostream>
#include <iomanip>
using namespace std;
#include "Book.h"
#include "Utils.h"
#include "Date.h"
namespace sdds {

	Book::Book() : PubRecord() { //My no arg construtor for book.
		sen_bookISBN = 0u;
		sen_memID = 0u;
	}

	Book::Book(const Book& copy1) : PubRecord(copy1), sen_memID(0) {  //copy construtor, copying everithing from the current object 
		*this = copy1;												 // to the variable sent. Also initalizing the memberID to 0, as well as copying everything from pubrecord (the member variables values
	}

	Book& Book::operator=(const Book& copy1) {		// Same as copy constructor, but its the copy assignement operator
													// Checking if the objects are same or not. If not ASSIGN it to the current obj.
		if (this != &copy1) {
			date = copy1.date;
			sen_bookISBN = copy1.sen_bookISBN;
			sen_memID = 0;
			name(copy1.name());
			mediaType(copy1.mediaType());
			shelfNo(copy1.shelfNo());
		}
		return *this;
	}

	Book::~Book() {			// Not need because we dont allocate any memory here
						
	}

	char Book::recID()const { //Juts returns B
		return 'B';
	}

	int Book::memberId()const {

		return sen_memID;
	}

	void Book::checkIn() {

		sen_memID = 0;
		write() << " checked in!" << endl;

	}

	void Book::checkOut() {
		int id;
		cout << "Enter Member id: ";
		readint(id, 10000, 99999, "Invalid Member ID, Enter again: ");
		sen_memID = id;
		Date today;
		do {
			do {
				do {
					cout << "Enter return date: ";
					date.read();
				} while (date.errCode() != 0 && cout << date.dateStatus() << "." << endl);
			} while (date <= today && cout << "Please enter a future date." << endl);
		} while (date - today > 30 && cout << "The return date must be earlier than 30 days away from today." << endl);
	}

	istream& Book::read(istream& is) {
		if (mediaType() == SDDS_CONSOLE) {
			sen_memID = 0;

			cout << "Book Name: ";
			char temp1[41] = "";
			readstr(temp1, 40, "Book name too long, Enter again: "); // From ws4 utils (Just edited the func a lil bit)
			name(temp1);

			cout << "ISBN: ";
			readLongint(sen_bookISBN, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: "); //This is new function added in utils for this particualr function for reading long long numbers.
			
			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			char tempo[41];
			int tempo2;

			is.getline(tempo, 40, '\t');  // Thought that getline has user interaction, but a friend told me that's not usually the case.
			name(tempo);					// Next time we meet, will ask you this question to be more clear.
			is >> sen_bookISBN;
			is.ignore();
			is >> tempo2;
			shelfNo(tempo2);
			is.ignore();
			is >> sen_memID;
			if (memberId() != 0) {
				is.ignore();
				is >> date;
			}
		}		
		return is;
	}

	ostream& Book::write(ostream& os)const { // Just basic prinitng out.
		if (mediaType() == SDDS_CONSOLE) {
			os << setw(41) << left;
			os << setfill(' ') << PubRecord::name() ;
			os  << sen_bookISBN << "  " << shelfNo();
			if (memberId() != 0) {
				os << " " << sen_memID << "   " << date;
			};
		}
		else if (mediaType() == SDDS_FILE) {
			os << setfill(' ') << recID() << PubRecord::name() << '\t' << sen_bookISBN << 
				'\t' << shelfNo() << '\t' << sen_memID;
			if (sen_memID != 0) {
				os << '\t' << date;
			}
			os << endl;
		}
		return os;
	}

}
