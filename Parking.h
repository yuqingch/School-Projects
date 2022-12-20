/*
Final Project Milestone 1
Module: Parking
Filename: Parking.h
Version 1.0
Author	Yuqing Chen
Revision History
-----------------------------------------------------------
Date      Reason
2022/11/23
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#pragma once
#define MAX_NO_OF_PARKING_SPOTS 100
#include "Vehicle.h"

namespace sdds {

   class Parking {
      int m_maxParkNum = MAX_NO_OF_PARKING_SPOTS;
      int m_numSpots{};
      Vehicle* m_parkingSpots[MAX_NO_OF_PARKING_SPOTS + 1]{};
      char* m_datafile;
      int m_numParked{};

   public:
      Parking();
      Parking(const char* datafile, int noOfSpots);
      ~Parking();
      bool isEmpty() const;
      void parkingStatus() const;
      bool loadDataFile() ;
      void saveDataFile();
      void listParkedVehicles() const;
      void findVehicle() const;
      void parkVehicle();
      void returnVehicle() const;
      void closeParking() const;
   };
}

