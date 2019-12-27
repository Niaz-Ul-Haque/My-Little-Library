#ifndef SDDS_MAGAZINE_H
#define SDDS_MAGAZINE_H

#include "PubRecord.h"

namespace sdds
{

	class Magazine : public PubRecord
	{

		int sen_magVol;
		int sen_magIssue;
	public:
		Magazine();
		Magazine(const Magazine& copy1);
		Magazine& operator=(const Magazine& copy1);

		virtual ~Magazine();

		char recID()const;

		void checkIn();
		void checkOut();

		std::istream& read(std::istream& is);
		std::ostream& write(std::ostream& os)const;
	};

}
#endif