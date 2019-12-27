
#include <iostream>
#include <iomanip>
using namespace std;
#include "Magazine.h"
#include "Utils.h"
namespace sdds {
	Magazine::Magazine() {    // Basic constructor and I also asssign a media type, cause if i didn't, the compiler breaks down (crash is the word?)
		sen_magIssue = 0;
		sen_magVol = 0;
		//mediaType(SDDS_FILE);
	}

	Magazine::Magazine(const Magazine& copy1) : PubRecord(copy1) { // Literally copy everything (and also the variables from pubrecord)
		*this = copy1;
	}

	Magazine& Magazine::operator=(const Magazine& copy1) { // check if it is the same object, dont do anyithng. If not, ASSGIN the sent varable to the current object.
		if (this != &copy1) {			
			sen_magIssue = copy1.sen_magIssue;
			sen_magVol = copy1.sen_magVol;
			name(copy1.name());
			mediaType(copy1.mediaType());
			shelfNo(copy1.shelfNo());
		}
		return *this;
	}

	Magazine::~Magazine() {
	}

	char Magazine::recID()const {
		return 'M';
	}

	void Magazine::checkIn() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	void Magazine::checkOut() {
		cout << "Magazines cannot be checked in or out!" << endl;
	}

	istream& Magazine::read(istream& is) {
		if (mediaType() == SDDS_CONSOLE) {
			cout << "Magazine Name: ";
			char temp1[41] = "";
			readstr(temp1, 40, "Magazine name too long, Enter again: ");
			name(temp1);

			cout << "Volume: ";
			int temp2;
			readint(temp2, 1, 99, "Invalid Volume number, Enter again: ");
			sen_magVol = temp2;

			cout << "Issue: ";
			int temp3;
			readint(temp3, 1, 99, "Invalid Issue number, Enter again: ");
			sen_magIssue = temp3;

			cout << "Shelf Number: ";
			readShelfNo();
		}
		else if (mediaType() == SDDS_FILE) {
			char tempo[41];
			int tempo2;

			is.getline(tempo, 40, '\t');
			name(tempo);
			is >> sen_magVol;
			is.ignore();
			is >> sen_magIssue;
			is.ignore();
			is >> tempo2;
			shelfNo(tempo2);
			is.ignore();
		}
		return is;
	}

	ostream& Magazine::write(ostream& os) const{ // Just basic write func.
		if (mediaType() == SDDS_CONSOLE) {   // Next time we meet, wanted to ask this question (will probably do a google search now, still writing the ques. ios::left, and left, these two are the same thing right? 
						     // I used left.
			os << setw(41) << left;		
			os << name();
			os << "       " << right;
			os << setw(2) << setfill('0') << sen_magVol << setfill(' ') <<  "(";
			os << setw(2) << setfill('0') << sen_magIssue << setfill(' ') << ")" << left;
			os << "  " << shelfNo();
			
		}
		else if (mediaType() == SDDS_FILE) {
			os << recID() <<
				name() << '\t' << sen_magVol <<
				'\t' << sen_magIssue << '\t' <<
				shelfNo() << endl;
		}
		return os;
	}
}
