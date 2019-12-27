/***********************************************************************
// OOP244 Project Milestone 4
// File	ms4.cpp
// Version 1.0
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019/11/24      intial release
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <fstream>
#include "Book.h"
#include "Magazine.h"
#include "colors.h"
using namespace std;
using namespace sdds;
const char outputs[6][400] = {
"This Magazine is not set yet!\n"
"This Book is not set yet!\n"
"This Book is not set yet!\n",
"Title                                    ISBN or V(I)  Shlf Lent to Ret Date\n"
"---------------------------------------- -------------  --- -----   ----------\n"
"C++ Journal                                     02(03)  111\n"
"C 144                                    1234567890987  222\n"
"C++ 244                                  9876543212345  333\n",
"Magazines cannot be checked in or out!\n"
"Magazines cannot be checked in or out!\n",
"Title                                    ISBN or V(I)  Shlf Lent to Ret Date\n"
"---------------------------------------- -------------  --- -----   ----------\n"
"C++ Journal                                     02(03)  111\n"
"C 144                                    1234567890987  222 12345   2019/12/24\n"
"C++ 244                                  9876543212345  333\n",
"MC++ Journal\t2\t3\t111\n"
"BC 144\t1234567890987\t222\t12345\t2019/12/24\n"
"BC++ 244\t9876543212345\t333\t0\n",
"C++ Journal                                     02(03)  111\n"
"C++ Journal                                     02(03)  111\n"
"C 144                                    1234567890987  222\n"
"C 144                                    1234567890987  222\n"
};
const char prompts[3][40] = {
   "C++ Journal\n2\n3\n111\n",
   "C 144\n1234567890987\n222\n",
   "C++ 244\n9876543212345\n333\n"
};

const char fname[] = "data.txt";

void output(const char* title, const char* outp);
void print(PubRecord* prptr[], int num = 3);
void fileOut(PubRecord* prptr[]);
void fileIn(PubRecord* prptr[]);
void output(const char* value);
void dumpFile(void);
void message(const char* value);
void title(void);
void line(int i);
int main() {
   cout << col_red << "Magazine and Book Tester...." << col_end << endl;
   Magazine M;
   Book B[2];
   PubRecord* p[3] = { &M, &B[0], &B[1] };
   PubRecord* p4read[3];
   int i;
   output("Tester output and your output should match:", outputs[0]);
   print(p);
   for (i = 0; i < 3; i++) {
      line(i);
      cin >> *p[i];
   }
   output("Tester output and your output should match:", outputs[1]);
   title();
   print(p);
   output("Tester output and your output should match:", outputs[2]);
   p[0]->checkOut();
   p[0]->checkIn();
   cout << col_yellow << "Enter the following:" << endl << "12345" << endl << "2019/12/25" << col_end << endl;
   p[1]->checkOut();
   output("Tester output and your output should match:", outputs[3]);
   title();
   print(p);
   fileOut(p);
   output("File output test, Tester output and your output should match:", outputs[4]);
   dumpFile();
   fileIn(p4read);
   output("File input test,Tester output and your output should match:", outputs[3]);
   title();
   print(p4read);
   for (i = 0; i < 3; i++) {
      delete p4read[i];
   }
   Magazine MC = M, MA;
   MA = M;
   Book BC = B[0], BA;
   BA = B[0];
   PubRecord* copies[4] = {&MC, &MA, &BC, &BA};
   output("Copy constructor and assignment test\nTester output and your output should match:", outputs[5]);
   print(copies, 4);
   return 0;
}

void line(int n) {
   cout << col_yellow;
   for (int i = 0; i < 10; i++, cout << (n+1) << " ");
   cout << endl << "----------------------------------------" << endl;
   cout << "Enter the following:" << endl << prompts[n];
   cout << col_end;
}
void title(void) {
   cout << col_cyan << "Title                                    ISBN or V(I)  Shlf Lent to Ret Date" << endl <<
      col_cyan << "---------------------------------------- -------------  --- -----   ----------" << col_end<< endl;
}
void dumpFile(void) {
   ifstream testFile(fname);
   char ch;
   while (testFile.get(ch)) {
      cout << ch;
   }
}
void fileOut(PubRecord* prptr[]) {
   ofstream testFile(fname);
   for (int i = 0; i < 3; i++) {
      if (*prptr[i]) {
         prptr[i]->mediaType(SDDS_FILE);
         testFile << *prptr[i];
      }
   }
}
PubRecord* readPubRecrod(ifstream& f) {
   PubRecord* p = nullptr;
   char id = f.get();
   if (id == 'B')
      p = new Book();
   else if (id == 'M')
      p = new Magazine;
   if (p) {
      p->mediaType(SDDS_FILE);
      f >> *p;
   }
   return p;
}
void fileIn(PubRecord* prptr[]) {
   ifstream testFile(fname);
   for (int i = 0; i < 3; i++) {      
      prptr[i] = readPubRecrod(testFile);
   }
}

void print(PubRecord* prptr[], int num) {
   cout << col_green;
   for (int i = 0; i < num; i++) {
      prptr[i]->mediaType(SDDS_CONSOLE);
      if (prptr[i] && *prptr[i]) {
         cout << *prptr[i] << endl;
      }
      else if(prptr[i]){
         cout << "This " << (prptr[i]->recID() == 'B' ? "Book" : "Magazine") << " is not set yet!" << endl;
      }
      else {
         cout << "PubRecord pointer is null!" << endl;
      }
   }
   cout << col_end;
}


void output(const char* value) {
   cout << endl << col_green << value << col_green << endl;
}
void message(const char* value) {
   cout << endl << col_yellow << value << col_end << endl;
}


void output(const char* title, const char* outp){
   cout << col_white << title << endl;
   cout << "Tester ouput------------------------------------------" << endl;
   cout << outp << col_end;
   cout << col_green << "Your ouput ------------------------------------------" << endl;
}
