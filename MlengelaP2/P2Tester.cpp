/********************************************************************
* Program: Program 2
* Programmer: Daudi Mlengela (dmlengela@cnm.edu)
* Date: February 2nd 2022
* Purpose: Person Class
*********************************************************************/
#include <iostream>
#include "PersonGen.h"

void createPersons()
{
   PersonGen *pg = new PersonGen();

   if(!pg->IsTextFileRead())
   {
      std::cout << "\n\nWhoops! A text file was not read.\n";
   }
   else
   {
      bool bOk = pg->CreateFile("Persons15.txt", 15);

      if(bOk)
      {
         std::cout << "File created, all ok\n";
      }
      else
      {
         std::cout << "\n no file created\n";
      }
   }
}

int main()
{
   // createPersons();

   PersonGen *pg = new PersonGen();

   if(!pg->IsTextFileRead())
   {
      std::cout << "\n\nWhoops! A text file was not read.\n";
   }
   else
   {
      bool bOK = pg->UseFile("Persons15.txt");

      if(bOK)
      {
         cout << "\n file found, will use names from file first\n";
      }
      else
      {
         cout << "\n no file found, will create all Persons raondomly\n";
      }
      int index = 1;
      Person arrayOne[10];

      for(int i = 0; i < 10; i ++)
      {
         arrayOne[i] = pg->GetPerson();
         std::cout << "index: " << index++ << " " << arrayOne[i].GetFullDesc() << "\n";
      }

      Person arrayTwo[10];

      for(int i = 0; i < 10; i ++)
      {
         arrayTwo[i] = pg->GetPerson();
         std::cout << "index: " << index++ << " " << arrayTwo[i].GetFullDesc() << "\n";
      }

      Person *arrayThree[10];

      for(int i = 0; i < 10; i ++)
      {
         arrayThree[i] = pg->GetNewPerson();
         std::cout << "index: " << index++ << " " << arrayThree[i]->GetFullDesc() << "\n";
      }

      Person *arrayFour[10];
      for(int i = 0; i < 10; i ++)
      {
         arrayFour[i] = pg->GetNewPerson();
         std::cout << "index: " << index++ << " " << arrayFour[i]->GetFullDesc() << "\n";
      }
      for(int i = 0; i < 5; i ++)
      {
         Person p = pg->GetPerson();
         std::cout << "index: " << index++ << " " << p.GetFullDesc() << "\n";
      }
      for(int i = 0; i < 10; i ++)
      {
         delete(arrayThree[i]);
         delete(arrayFour[i]);
      }
   }
   if(pg)
   delete(pg);
}
