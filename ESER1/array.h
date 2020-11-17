#ifndef ARRAY_H
#define ARRAY_H
#endif

#include <vector>
#include <string>
using namespace std;

class Array
{
private:
    int arraySize;

public:
    Array(int size)
    {
        arraySize = size;
    }

    ~Array()
    {
    }
    int greatherThan(int array[], int k)
    {
        int i = 0;
        for (int j = 0; j < arraySize; j++)
        {
            if (array[j] > k)
                i++;
        }
        return i;
    }
    bool member(int array[], int k)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (array[j] == k)
                return true;
        }
        return false;
    }

    vector<int> largest(int array[])
    {
        vector<int> result = {array[0], 0};

        for (int j = 0; j < arraySize - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                result[0] = array[j + 1];
                result[1] = j + 1;
            }
        }
        return result;
    }
    void remove(int array[], int k)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (array[j] == k)
            {
                for (int l = j; l < arraySize - 1; l++)
                    array[l] = array[l + 1];
                array[arraySize-1] = 0;
            }
        }
    }

    string ordering(int array[])
    {
        for (int j = 0; j < arraySize - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                for (int i = j + 1; i < arraySize - 1; i++)
                {
                    if (array[i] > array[i + 1])
                        return "not sorted";
                }
                return "increasing";
            }
            else if (array[j] > array[j + 1])
            {
                for (int i = j + 1; i < arraySize - 1; i++)
                {
                    if (array[i] < array[i + 1])
                        return "not sorted";
                }
                return "decreasing";
            }
        }
        return "cant define order";
    }
    void reverse(int array[])
    {
        int tmp;
        int j = 0;
        for (int i = arraySize-1; i > arraySize / 2; i--)
        {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            j++;
        }
    }
};
