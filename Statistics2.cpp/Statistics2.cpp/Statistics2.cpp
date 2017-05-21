#include <iostream>
#include <cmath>
#include <climits>
using namespace std;



int convertToIntArray(int argc, char* argv[], int array[])
{
    
    // if there are too many inputs or too little return -21 if this is true then the rest of the funtion will stop running.
    if (argc > 21 || argc < 2)
    {
        return -21;
    }
    
       for (int i = 1; i < argc; i++)
    {
        bool positive = false;
        bool negative =false;
        int value = 0;
        int length = 0;
        
        while (*(argv[i] + length) != '\0')
        {
            length++;
        }
        
        for (int k = length; k > 0; k--)
        {
            int previousNumber = value;
            int newNumber = 0;
            switch(*(argv[i] + (length-k)))
            {
                case '+':
                    if (k-length == 0)
                        positive = true;
                    else
                        return i*-1;
                case '-':
                    if (k-length ==0)
                        negative = true;
                    else
                        return i*-1;
                case '0':
                    break;
                case '1':
                    newNumber += 1 * (pow(10, k-1));
                    break;
                case '2':
                    newNumber += 2 * (pow(10, k-1));
                    break;
                case '3':
                    newNumber += 3 * (pow(10, k-1));
                    break;
                case '4':
                    newNumber += 4 * (pow(10, k-1));
                    break;
                case '5':
                    newNumber += 5 * (pow(10, k-1));
                    break;
                case '6':
                    newNumber += 6 * (pow(10, k-1));
                    break;
                case '7':
                    newNumber += 7 * (pow(10, k-1));
                    break;
                case '8':
                    newNumber += 8 * (pow(10, k-1));
                    break;
                case '9':
                    newNumber += 9 * (pow(10, k-1));
                    break;
                default:
                    cerr << "Error. for argv[" << i << "] at character slot " << (length-k+1) << endl;
                    return i*-1;
            }
            
            // Error checking if the number is too large.
            if (previousNumber > INT_MAX - newNumber)
            {
                cerr << "Error. for argv[" << i << "]: number input is too large" << endl;
                return i*-1;
            }
            // Else finish the job.
            else
            {
                value += newNumber;
            }
        }
        //If the number inputted was negative, add it back here.
        if (positive)
        {
            array[i-1] = value *1;
        }
        else if (negative)
        {
            array [i-1] = value *-1;
        }
        //If not just keep going.
        else
        {
            array[i-1] = value;
        }
    }
    
    return 0;
}






bool findMaxMinAvg(int array[], int numElements, int& max, int& min, float& avg)
{
    if (numElements < 1)
    {
        return false;
    }
    
    else
    {
        int value = -200;
        int value2 = 200;
        float sum = 0;
        for(int i = 0; i < numElements; i++)
        {
            sum+=array[i];
            if (array[i] > value)
            {
                value = array[i];
            }
            else if (array[i] < value2)
            {
                value2 = array[i];

            }
        }
        max= value;
        min= value2;
        avg= (sum/numElements);
        
        return true;
    }
}









int main(int argc, char* argv[])
{
    int array[20];
    
    
   
    
    if (argc == 1)
    {
        return 0;
    }
    else if (argc > 21)
    {
        cerr << "Error: Too many inputs." << endl;
        return 0;
    }
    
    int numElements = argc - 1;
    
    int max=0;
    int min=0;
    float avg=0;
    
    convertToIntArray( argc, argv, array);
    
    for (int x=0; x< numElements; x++)
    {
        cout << array[x] << endl;
    }
    
    cout << endl;
    
    
    if (findMaxMinAvg (array, numElements,  max, min, avg))
    {
    // findMaxMinAvg()
   
        cout << "Maximum: " << max << endl;
        cout << "Minimum: " << min << endl;
        cout << "Average: " << avg << endl;
    }
    
    
    
    return 0;
}









