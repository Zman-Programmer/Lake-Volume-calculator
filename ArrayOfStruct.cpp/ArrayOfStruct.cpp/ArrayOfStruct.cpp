#include <iostream>
#include "ArrayOfStruct.h"
using namespace std;

int stringcompare(char people[], char people2[]);

void peopleSwap(Person &people1, Person &people2)
{
    Person temp = people1;
    people1 = people2;
    people2 = temp;
}



int stringcompare(char people[], char people2[])
{
    bool bye=true;
    int x=0;
    while (bye){
        if (people[x] > '@' && people[x] < '['){
            people[x]= people[x] +32;
        }
        if (people2[x] > '@' && people2[x] < '['){
            people2[x]= people2[x]+32;
        }
        if(people[x] != '\0' && people2[x]!= '\0'){
            if (people[x] < people2[x]){
                bye=false;
                return 1;
            }
            else if (people[x] > people2[x]){
                bye=false;
                return -1;
            }
        }
        else if (people[x]=='\0' && people2[x]=='\0'){
            bye = false;
            return 0;
        }
        else if (people[x]=='\0'){
            bye = false;
            return 1;

        }
        else if (people2[x]=='\0'){
            
            bye = false;
            return -1;
        }
        x++;
    }
}


//bubble sort
void bubbleSort(int numPeople, Person people[])
{
    for(int x=0; x< (numPeople-1); x++)
    {
        for(int y=0; y < ((numPeople-1)-x); y++)
        {
            int swap = stringcompare(people[y].lastName, people[y+1].lastName);
            if(swap== -1)
            {
                peopleSwap(people[y], people[y+1]);
            }
            else if(swap==0)
            {
                int swap2= stringcompare(people[y].firstName, people[y+1].firstName);
                if (swap2== -1)
                {
                    peopleSwap(people[y], people[y+1]);
                }
            }
        }
    }
}

//display names

void displayNames(int numPeople, Person people[])
{
    for (int i=0; i<numPeople; i++)
    {
        cout << people[i].firstName << " " << people[i].lastName <<  " " << people[i].age << endl;
    }
}


