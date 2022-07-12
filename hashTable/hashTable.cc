#include <unordered_map> // use hashes if want to search quickly (find, delete, insert is O(1))/ slowly use trees
#include <vector>
#include <iostream>


/*Find whether an array is subset of another array*/
bool isSubset(const std::vector<int> & input , const std::vector<int> & large)
{
    std::unordered_map<int, int> myMap;
    // Build hash table for bigger vector
    for(int i = 0; i <large.size(); i++)
    {       
        myMap[large[i]] = i;
    }

    int count = 0;
    for (int i = 0; i< input.size();i++)
    {
        if (myMap.find(input[i]) != myMap.end())
            count++;
        else
            return false;
    }

    if (count == input.size())
        return true;
    else    
        return false;
}



