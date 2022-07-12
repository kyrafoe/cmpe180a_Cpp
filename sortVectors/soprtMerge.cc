#include "soprtMerge.h"
#include<cmath>

/*Three functions are defined:
1.) compareElements which is overloaded (different iterators as input)
2.) oneEmpty to check for one empty vector and return appropriate result
3.) soprtMerge that calls 1 and 2
*/


// Overload the compareElements function: depends on increasing or decreasing vector and corresponding iterators or reverse iterators being passed
void compareElements(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result, 
std::vector<int>::const_reverse_iterator it1, std::vector<int>::const_reverse_iterator it2)
{ 
    int size1= in1.size();
    int size2 = in2.size();

    /*Use of iterators to define the starting point for vector element comparison.
    The defined iterators can not be used for a comparison with > or <.
    Therefore, an additional i and j are defined for the while loop.
    As long as i is smaller than the size of vector in1 and j is smaller than the size of 
    in2, the while loop is executed.*/

    int i = 0;
    int j = 0;

    while((i< size1 && j<size2))
    {
        if(*it1<*it2)
        {   
            result.push_back(*it1);
            i++;
            it1++;      
        }
        else
        {           
            result.push_back(*it2);
            j++;   
            it2++;        
        }
    }

    /*The previous while loop may not fill the result vector until the sum of both 
    input vector sizes. E.g. if i or j equals its vector size.
    Therefore, the following two while loops fill
    the remaining elements from in1, if i < in1 size, and 
    elements from in2, if j < in2 size.*/

    while (i < size1)
    {
        result.push_back(*it1);
        i++;
        it1++;
    }
 
    while (j < size2)
    {
        result.push_back(*it2);
        j++;
        it2++;
    }
}


void compareElements(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result, 
std::vector<int>::const_iterator it1, std::vector<int>::const_iterator it2)
{ 
    int size1= in1.size();
    int size2 = in2.size();
    int i = 0;
    int j = 0;

    while((i< size1 && j<size2))
    {
        if(*it1<*it2)
        {   
            result.push_back(*it1);
            i++;
            it1++;      
        }
        else
        {           
            result.push_back(*it2);
            j++;   
            it2++;        
        }
    }
    while (i < size1)
    {
        result.push_back(*it1);
        i++;
        it1++;
    } 
    while (j < size2)
    {
        result.push_back(*it2);
        j++;
        it2++;
    }
}


void compareElements(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result, 
std::vector<int>::const_reverse_iterator it1, std::vector<int>::const_iterator it2)
{ 
    int size1= in1.size();
    int size2 = in2.size();
    int i = 0;
    int j = 0;

    while((i< size1 && j<size2))
    {
        if(*it1<*it2)
        {   
            result.push_back(*it1);
            i++;
            it1++;      
        }
        else
        {           
            result.push_back(*it2);
            j++;   
            it2++;        
        }
    }
    while (i < size1)
    {
        result.push_back(*it1);
        i++;
        it1++;
    } 
    while (j < size2)
    {
        result.push_back(*it2);
        j++;
        it2++;
    }
}


void compareElements(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result, 
std::vector<int>::const_iterator it1, std::vector<int>::const_reverse_iterator it2)
{ 
    int size1= in1.size();
    int size2 = in2.size();
    int i = 0;
    int j = 0;

    while((i< size1 && j<size2))
    {
        if(*it1<*it2)
        {   
            result.push_back(*it1);
            i++;
            it1++;      
        }
        else
        {           
            result.push_back(*it2);
            j++;   
            it2++;        
        }
    }
    while (i < size1)
    {
        result.push_back(*it1);
        i++;
        it1++;
    } 
    while (j < size2)
    {
        result.push_back(*it2);
        j++;
        it2++;
    }
}


/* oneEmpty checks if in1 or in2 are empty and return directly the result (when vector is increasing) or 
fill result with value from reverse iterator*/ 
void oneEmpty(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result)
{
    if(in1.empty()) //If in1 is empty, return in2 if increasing, else fill result with reverse elements of in2
    {
        int vec2Front = in2.front();
        int vec2Back = in2.back();
        int maximum2 = std::max(vec2Front, vec2Back);  
      
        if(maximum2 == vec2Back)
            result = in2;
        else
        {      
            int i = 0;
            auto it1 = in2.rbegin();
            while (i<in2.size())
            {            
                result.push_back(*it1);
                it1++;
                i++;
            }
        }       
    } 
    else if(in2.empty()) //If in2 is empty, return in1 if increasing, else fill result with reverse elements of in1
    {
        int vec1Front= in1.front();    
        int vec1Back= in1.back();
        int maximum1 = std::max(vec1Front, vec1Back);

        if(maximum1 == vec1Back)
            result = in1;
        else
        {
            int i = 0;
            auto it1 = in1.rbegin();
            while (i<in1.size())
            {            
                result.push_back(*it1);
                it1++;
                i++;
            }           
        }
    }
}


void soprtMerge(const std::vector<int> &in1, const std::vector<int> &in2,  std::vector<int> &result)
{
    //Empty the result vector
    result.clear();

    if(in1.empty() && in2.empty()) //If both input vectors are empty, return empty   
        result.clear();

    //If one of two vectors is empty 
    if(in1.empty() || in2.empty())
        oneEmpty(in1, in2, result);
    
    // Following only, if both input vectors are not empty. 
    // Check for increasing or decreasing input vectors by calculating maximum of the first and last element.
    if(!in1.empty() && !in2.empty())
    { 
        int vec1Front= in1.front();    
        int vec1Back= in1.back();
        int maximum1 = std::max(vec1Front, vec1Back); 
        int vec2Front = in2.front();
        int vec2Back = in2.back();
        int maximum2 = std::max(vec2Front, vec2Back); 
    
        //Set iterators depending on sorted increased or decreased, compare elements with compareElements()
        // which is an overloaded function due to passing different iterator types
        if(maximum1 == vec1Front && maximum2 == vec2Front) // both decreasing
        {
            auto it1 = in1.rbegin();
            auto it2 = in2.rbegin();
            compareElements(in1, in2, result, it1 ,it2);       
        }
        else if(maximum1 == vec1Front && maximum2 == vec2Back) // in1 decresing, in2 increasing
        {
            auto it1 = in1.rbegin();
            auto it2 = in2.begin();
            compareElements(in1, in2, result, it1 ,it2);
        }
        else if(maximum1 == vec1Back && maximum2 == vec2Back) // both increasing
        {
            auto it1 = in1.begin();
            auto it2 = in2.begin();
            compareElements(in1, in2, result, it1 ,it2);
        }
        else if(maximum1 == vec1Back && maximum2 == vec2Front) // in1 increasing, in2 decreasing
        {
            auto it1 = in1.begin();
            auto it2 = in2.rbegin();
            compareElements(in1, in2, result, it1 ,it2);
        }  
    }   
}




















