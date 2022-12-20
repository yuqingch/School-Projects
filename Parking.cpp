#pragma once

#include "Parking.h"
#include "Vehicle.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Motorcycle.h"
#include "Car.h"

using namespace std;

namespace sdds {
   Parking::Parking() {
   }
   Parking::Parking(const char* datafile, int noOfSpots) {
      if (noOfSpots >= 10 && noOfSpots <= MAX_NO_OF_PARKING_SPOTS) {
         m_numSpots = noOfSpots;
         for (int i = 0; i < MAX_NO_OF_PARKING_SPOTS; i++) {
            m_parkingSpots[i] = nullptr;
         }
         if (datafile && datafile[0]) {
            int len = ut.strlen(datafile);
            m_datafile = new char[len + 1];
            ut.strcpy(m_datafile, datafile, len);
         }
      }
      else {
         m_numSpots = -1;
      }

   }
   Parking::~Parking() {
      delete[] m_datafile;
   }

   bool Parking::isEmpty() const {
      return (m_numSpots >= 10 && m_numSpots <= MAX_NO_OF_PARKING_SPOTS && m_datafile && m_datafile[0]);
   }
   void Parking::parkingStatus() const {
      cout << "****** Valet Parking ******" << endl;
      cout << "***** Available spots: ";
      cout << left << setw(4) << m_numSpots - m_numParked << endl;
   }
   bool Parking::loadDataFile() {
      if (!isEmpty()) {
         ifstream file;
         file.open(m_datafile);
         if (!file) {
            return true;
         }
         else {
            char input;
            input = getchar();
            file.ignore();
            if (input) {
               if (input == 'M') {
                  m_parkingSpots[m_numParked] = new Motorcycle();
                  m_numParked ++;
                  m_parkingSpots[m_numParked]->setCsv(true);
                  Motorcycle::read(file);
               }
               else if (input == 'C') {
                  m_parkingSpots[m_numParked] = new Car();
                  m_numParked++;
                  m_parkingSpots[m_numParked]->setCsv(true);
               }
               else {
                  m_parkingSpots[m_numParked] = nullptr;
               }
            }
            else {
               file.close();
            }
         }

      }
   }
   void Parking::saveDataFile() {
   }
   void Parking::listParkedVehicles() const {
      for (int i = 0; i < m_numParked; i++) {
         display
      }
   }
   void Parking::findVehicle() const {

   }
   void Parking::parkVehicle() {
   }
   void Parking::returnVehicle() const {
   }
   void Parking::closeParking() const {
   }

}
