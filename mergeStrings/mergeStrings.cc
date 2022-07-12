#include "mergeStrings.h"
using namespace std;

void mergeStrings(const string &a, const string &b, string &result)
{
    //Clear result to ensure empty result string to the beginning
    result.clear();

    //Check for empty strings
    if(a.empty()){
        result = b;
    }else if(b.empty()){
        result = a;
    }else if (a.empty() and b.empty()){
        result.clear();
    }else{
        /*If both strings are not empty:
        Check for lengths of both strings.
        1.Get length */
        int lengthA = a.length(), lengthB = b.length();   
        int smallerLength{}, biggerLength{};
        string biggerString;

        //2. Check which string is smaller (smallerLength)
        if (lengthA < lengthB){
            smallerLength = lengthA;
            biggerLength = lengthB;
            biggerString = b;
        }else if (lengthA > lengthB){
            smallerLength = lengthB;
            biggerLength = lengthA;
            biggerString = a;
        }else{
            smallerLength = lengthA;
            biggerLength = lengthB;      
        }

        /*The merging of the two strings is accomplished by two loops. The first loops over
        both strings until < length of the smaller string and
        fill the result string on each second index with a and b.*/

        for (int i = 0; i< smallerLength ; i ++)
        {
            result.push_back(a[i]);
            result.push_back(b[i]);        
        }

        /*The second loop fills result with the rest of the chars of the longer string 
        if both strings are not the same size. Otherwise the first loop already merges the two strings.*/
        if(lengthA != lengthB){
            for (int i = smallerLength; i <  biggerLength ; i ++)
            {           
                result.push_back(biggerString[i]);
            }   
        }
    }
}

