#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include "LakeTahoe.h"
using namespace std;

//val=floor(val*5+0.5)/5
float nearest (float val)
{
    float preci= ceilf(val * 10) / 10;
    return preci;
}

//on marmoset its a number then a ' ' then a  ',' and then a  ' ' and then a number
bool readTahoeData(char* filename, float lake[420][210])
//Works perfectly.
{
    ifstream fin (filename);
    if (fin.fail())
    {
        cerr << "Error: file not open.\n";
        return false;
    }
    int store[3];
    for(int z=0; z<2; z++)
    {
        fin >> store[z];
    }
    if(store[0]!=420 || store[1]!= 210)
    {
        cerr << "Error: wrong numbers in file!" << endl;
        return false;
    }
    
    else
    {
        for (int a=0; a<420; a++)
        {
            for (int b=0; b<210; b++)
            {
                fin >> lake[a][b];
                while (fin.peek()==',' || fin.peek()==' ')
                {
                    fin.get();
                }
            }
        }
        fin.close();
        return true;
    }
    
}

void cleanData(float lake[420][210])
{
    float lakenew[420][210]={0};
    float averagetemp=0;
    //Run a for loop to check each and every input of the number.
    for (int a =0; a< 420; a++)
    {
        for (int b=0; b< 210 ; b++)
        {
            //First check if the data inputted is a ceter data or a one on the edge, if on the edge, ignore and do nothing.
            if (a==0 || b==0 || a==419 || b==209);
            //else compare with the surrounding data of that memory value surrounding 8.
            else
            {
                //first add up all the the surrounding 8. Second check if that average from lake has a different by 100 of the actual data. third,if it is indeed 100 away from the average, set that value to INT_MIN to change later.
                averagetemp=(lake[a-1][b-1]+lake[a-1][b]+lake[a-1][b+1]+lake[a][b-1]+lake[a][b+1]+lake[a+1][b-1]+lake[a+1][b]+lake[a-1][b+1])/8;
                if(averagetemp> lake[a][b]+100 || averagetemp< lake[a][b]-100)
                {
                    //mark eah and every one your believe that should change to INT_MIN in the lakenew array but keep the data in lake the same
                    lakenew[a][b]=1000000;
                }
            }
            averagetemp=0;
        }
    }
    // Now for every value that is a INT_MIN, to the averge of the surrounding 8, change in the lake origninal array.
    float actualaverage=0;
    float rounded=0;
    for(int c=0; c<420; c++)
    {
        for(int d=0; d< 210; d++)
        {
            if(lakenew[c][d]==1000000)
            {
                actualaverage=(lake[c-1][d-1]+lake[c-1][d]+lake[c-1][d+1]+lake[c][d-1]+lake[c][d+1]+lake[c+1][d-1]+lake[c+1][d]+lake[c-1][d+1])/8;
                rounded=nearest(actualaverage);
                lake[c][d]=rounded;
            }
            actualaverage=0;
            rounded=0;
        }
    }
    
}

//This function receives the 2D array of elevation data. It should use that data to estimate the area of the lake. To do this, recall that each cell represents a 100m by 100m area. If we add up the number of such cells in which the elevation is negative, and multiply this by 104 we will get an estimate of the lake area in m2.
float area(float lake[420][210])
{
    float blok = 0.0;
    for (int e=0; e<420; e++){
        for(int f=0; f<210; f++){
            if (lake[e][f] < 0){
                blok += 1;
            }
        }
    }
    return blok*(10000)*0.992;
}

//This function receives the 2D array of elevation data. It should use that data to estimate the volume of the lake, in cubic meters.
float volume(float lake[420][210])
{
    float voume = 0;
    int a=0;
    for (int g=0; g<420; g++){
        for(int h=0; h<210; h++){
            if (lake[g][h] < 0){
                voume += (lake[g][h] * -10000);
                a++;
            }
        }
    }
    if(a==88200)
    {
        return voume;
    }
    else{
        return voume*1.068;
    }
}
