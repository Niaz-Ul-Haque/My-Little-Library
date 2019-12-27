#ifndef SDDS_MARK_H
#define SDDS_MARK_H

namespace sdds {

	const int MAX_MENU_ITEMS = 20;
	const unsigned int DESC_LEN = 20;

	class Menu;

	class MenuItem {
		
		char* sen_description;

		MenuItem(const char* desc = nullptr);
		~MenuItem();
		MenuItem(const MenuItem& copy1) = delete;
		MenuItem& operator=(const MenuItem& copy1) = delete;		
		operator bool()const;
		operator const char*()const;
		std::ostream& display(std::ostream& os)const;

		friend Menu;

	};

	class Menu {

		MenuItem* sen_title;
		MenuItem* sen_itemLists[MAX_MENU_ITEMS];
		int sen_allocated;

	public:
		
		Menu();
		Menu(const char* title="");
		virtual ~Menu();
		std::ostream& displayTitle(std::ostream& os = std::cout)const;
		std::ostream& displayAllMenu(std::ostream& os = std::cout)const;
		Menu& operator<<(const char* variable1);
		unsigned int getSelection();
		unsigned int operator~();
		operator unsigned int()const;
		operator bool()const;
		const char* operator[](int index)const;


	};

	std::ostream& operator<<(std::ostream& os, const Menu& var1);

}

#endif