#include "PubApp.h"
int main(void) {
   sdds::PubApp library("libdata.dat");
   return library.run();
}