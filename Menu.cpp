#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Menu.h"
using namespace std;
namespace sdds {
	MenuItem::MenuItem(const char* desc) {
		sen_description = new char[strlen(desc) + 1];
		strcpy(sen_description, desc);
	}
	MenuItem::~MenuItem() {
		delete[] sen_description;
	}

	MenuItem::operator bool()const {
		return (sen_description == nullptr);
	}
	MenuItem::operator const char*()const {
		return sen_description;
	}
	ostream& MenuItem::display(ostream& os)const {
		if (sen_description != nullptr) {
			os << sen_description;
		}
		return os;
	}
	Menu::Menu(): sen_title(nullptr){
		sen_allocated = 0;
	}

	Menu::Menu(const char* title) {
	
		sen_title = new MenuItem(title);
		
		for (int i = 0; i < MAX_MENU_ITEMS; i++) {
			sen_itemLists[i] = nullptr;
		}
		sen_allocated = 0;
	}


	Menu::~Menu() {
		for (int i = 0; i < sen_allocated; i++) {
			delete sen_itemLists[i];
		}
	}
	 
	ostream& Menu::displayTitle(ostream& os) const{
		sen_title->display(os);
		return os;
	}

	

	ostream& Menu::displayAllMenu(ostream& os) const {
		if (sen_title) {
			displayTitle(os) << ":" << endl;
			for (int i = 0; i < sen_allocated; i++) {
				os << " " << i + 1 << "- " << sen_itemLists[i]->sen_description << endl;
			}			
			os << " 0- Exit" << endl << "> ";
		}
		return os;
	}
	Menu& Menu::operator<<(const char* variable1) {		
		
		if (sen_allocated < MAX_MENU_ITEMS) {
			sen_itemLists[sen_allocated] = new MenuItem(variable1);
			sen_allocated++;
		}
		return *this;
	}
	unsigned int Menu::getSelection() {
		displayAllMenu();
		int userSelect;
		
		do {
			cin >> userSelect;
			cin.ignore();
			if (cin.fail()) {
				cout << "Invalid Selection, try Again: ";
				cin.clear();
			}
			
			if (userSelect < 0 || userSelect > MAX_MENU_ITEMS) {
				cout << "Invalid Selection, try Again: ";
			}
			
		} while (userSelect < 0 || userSelect >= MAX_MENU_ITEMS);
		return userSelect;
	}
	unsigned int Menu::operator~() {
		int i = getSelection();
		return i;
	}
	Menu::operator unsigned int()const {
		return sen_allocated;
	}
	Menu::operator bool()const {
		return sen_allocated > 0;
	}
	const char* Menu::operator[](int index)const {
		return (const char*)*sen_itemLists[index];
	}
	ostream& operator<<(ostream& os, const Menu& var1) {
		var1.displayTitle(os);
		return os;
	}
}