/***********************************************************************
// OOP244 Project Milestone 4
// File	PubApp.h
// Version 1.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Fardad          2019/12/01      intial release
// Fardad          2019/12/03      fixed the mutiple read function error 
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_PUBAPP_H__
#define SDDS_PUBAPP_H__
#include <iostream>
#include <fstream>
#include "PubRecord.h"
#include "Menu.h"
namespace sdds {
   const int MaxNoOfPubs = 1000;
   class PubApp {
      std::fstream m_file;
      Menu m_mainMenu;
      Menu m_sureMenu;
      Menu m_pubType;
      PubRecord* m_pubs[MaxNoOfPubs];
      int m_noOfPubs;
      char m_filename[256];
      bool load(void);
      void save(void);
      void addPub(void);
      void checkOut(void);
      void checkIn(void);
      void title(void);
      bool search(int& index, char recID = '\0');
   public:
      PubApp(const char* filename);
      int run();
      virtual ~PubApp();
   };

}

#endif
