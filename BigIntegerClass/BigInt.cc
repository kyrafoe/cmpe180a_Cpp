#include "BigInt.h"
#include <math.h>

#define SIZE 3 // maximum size for cin >> operator overload


// Define constructors
BigInt::BigInt(const std::vector<int> & vec)
{
    vInt = vec; 
}

BigInt::BigInt(const std::vector<char> & vec)
{
    for(int i = 0; i< vec.size(); i++)
    {
        vInt.push_back(vec.at(i) -'0');
    }
}

BigInt::BigInt(char *array, int size)
{
    for(int i = 0; i< size; i++)
    {
        vInt.push_back(array[i] -'0');
    }
}


// Function to calculate min and maximum input vector sizes
void BigInt::minmax(const BigInt & other, int & min, int & max) const
{
    min = std::min(this->vInt.size(),other.vInt.size());
    max = std::max(this->vInt.size(),other.vInt.size());
}


// Function to reverse a vector
void BigInt::reverseVec(std::vector<int> & toBereversed, std::vector<int> & reversed) const
{
    // clear vector
    reversed.clear();

    auto it = toBereversed.rbegin();
    for (int i = 0; i< toBereversed.size();i++)
    {
        reversed.push_back(*it);
        it++;
    }
}

// Function to fill the smaller input vector with 0's in front
void BigInt::fillZerosFront(const BigInt & other, std::vector<int> & helpVec,int min, int max) const
{
    // If both input vectors have not the same size, fill smaller with 0 in front
    if(this->vInt.size()!=other.vInt.size())
    {
        // Find smaller vector
        std::vector<int>  smallerVec;

        if (min == this->vInt.size())
            smallerVec = this->vInt;
        else
            smallerVec = other.vInt;
        
        // Fill non existing elements with 0 in helpVec        
        std::fill (helpVec.begin(),helpVec.begin()+(max-min),0); 

        for(int i = 0; i<smallerVec.size();i++)
        {
            helpVec.push_back(smallerVec.at(i));
        }    
    }
    else  // if both vectors have the same size
        helpVec = other.vInt;

}


// Functions to fill a vectors with 0's at back
void BigInt::fillZerosBack(int start,const BigInt & other, std::vector<int> & reversedPlusZeros  , std::vector<int> & filled ) const
{
    filled.clear();
    filled = reversedPlusZeros;
    int i = start;
    while(i<other.vInt.size()-1)
    {
        filled.push_back(0);
        i = i+1;      
    }     
}

// Function to caluclate the sum of two input vectors
void BigInt::sum(const BigInt& other, BigInt &result, std::vector<int>::const_reverse_iterator it1,
std::vector<int>::const_reverse_iterator it2 ) const
{
    std::vector<int> temp; // temporary vector
    int element ;// result of sum of individual values in vectors
    int carry{0}, carryEl; 

    // Get min and max of input vectors
    int sizeVecMax, sizeVecMin ;
    minmax(other, sizeVecMin, sizeVecMax);

    // Define max loop iterations based on input vector sizes: determines result vector length
    // if sum of first two elements of inputs vectors >10 --> add  vector size +1 for generating the sum
    if ((this->vInt.front()+other.vInt.front())>10 && this->vInt.size() == other.vInt.size()) 
        sizeVecMax = sizeVecMax + 1;  

    // Sum individual elements and calculate carray if needed
    for (int i = 0; i< sizeVecMax;i++) 
    { 
        element = *it1 + *it2 + carry;

        if(element>=10 )
            carryEl = element -10;
        else
            carryEl = element;

        temp.push_back( carryEl); // fill temporary vector with sum
        it1++;
        it2++;
  
        if (element >=10 )
            carry = 1;
        else    
            carry = 0; 
    }  

    // Reverse temporray vector elements to save results in readable format
    reverseVec(temp, result.vInt);

    temp.clear();  
}


// Operatot + overload
BigInt BigInt::operator+( const BigInt& other)
{   
    // Define result bigInt
    std::vector<int> vector;  
    BigInt result(vector);

    // Calculate min and max input vector sizes
    int min, max;
    minmax(other, min, max);
    
    // Fill zeros at front in smaller vector: get same lengths of vectors for addition
    // the result is saved in helpVec (same size as other input vector)
    std::vector<int> helpVec((max-min));
    fillZerosFront(other, helpVec, min, max);


    // Define iterators depending on input sizes and helper vector (helpVec) that is the smaller vector filled with 0's at front
    if(this->vInt.size()<other.vInt.size()) // 1st vector < 2nd vector: fill 2nd vector with 0's in front
    {
        auto it1 = helpVec.rbegin();
        auto it2 = other.vInt.rbegin();
        sum(other, result, it1, it2);
    }
    else if (this->vInt.size()>other.vInt.size()) // 1st vector > 2nd vector: fill 1st vector with 0's in front
    {
        auto it1 = this->vInt.rbegin();
        auto it2 = helpVec.rbegin();  
        sum(other, result, it1, it2); 
    }
    else // same size, use original input vectors
    {
        auto it1 = this->vInt.rbegin();
        auto it2 = other.vInt.rbegin();
        sum(other, result, it1, it2);       
    }    
    return result;
} 

// - operator needs to be reviewed, not fully functional yet
// Function to subtract 
void BigInt::sub(const BigInt& other, BigInt &result, std::vector<int>::const_reverse_iterator it1,
std::vector<int>::const_reverse_iterator it2 ) const
{
    std::vector<int> temp; // temporary vector
    int element ;// result of sum of individual values in vectors
    int carry{0}, carryEl; 

    // Get min and max of input vectors
    int sizeVecMax, sizeVecMin ;
    minmax(other, sizeVecMin, sizeVecMax);

    // Define max loop iterations based on input vector sizes: determines result vector length
    // if sum of first two elements of inputs vectors >10 --> add  vector size +1 for generating the sum
    if ((this->vInt.front()+other.vInt.front())>10 && this->vInt.size() == other.vInt.size()) 
        sizeVecMax = sizeVecMax + 1;  

    // Sum individual elements and calculate carray if needed
    for (int i = 0; i< sizeVecMax;i++) 
    { 
        int upper;
    
        if(*it1 < (*it2+ carry ) ) // if upper element < lower element define carry, carry lives outside this function
        { 
                upper = *it1 + 10;
                element = upper - *it2 - carry; 

                temp.push_back( element); // fill temporary vector with sum
                it1++;
                it2++;
        
                if (upper >=10 )
                {
                    carry = 1;
                }
                else    
                    carry = 0; 
        }
        else if(*it1 > (*it2 + carry ) || *it1 == (*it2 + carry)) // if carry from previous element subtraction, use it here
        {
            element = *it1-(*it2 +carry); // lower element +carry in case the previous elemnt subtraction had a carry, then set to 0
            carry = 0;  
            temp.push_back( element); // fill temporary vector with sum
            it1++;
            it2++;  
        } 
    }  

    // Reverse temporray vector elements to save results in readable format
    // if first vector< second vector *-1 for the result

    if (temp.back() == 0) // remove last element if 0
        temp.pop_back();
   
    if(this->vInt.size()<other.vInt.size() || (this->vInt.size() == other.vInt.size() && this->vInt.front()<other.vInt.front()))
    {
        auto it3 = temp.rbegin();
        result.vInt.push_back(*it3*-1) ; 
        it3++; 

        for(int i = 0; i < sizeVecMax-1 ;i++) // reverse temporary vector elements to save results in readable format
        {
            result.vInt.push_back(*it3);
            it3++;
        }

        if (result.vInt.back() == 0) // remove last element if 0
            result.vInt.pop_back();
    }
    else
        reverseVec(temp, result.vInt); 

    temp.clear();  
}


// - operator needs to be reviewed, not fully functional yet
// Operator overload -
BigInt BigInt::operator-(const BigInt& other)
{
    // Define result Bigint
    std::vector<int> vector;  
    BigInt result(vector);
     
    /*Define iterators and always ensure that the bigger number is on top
    Distinguish 4 cases:
         1. 1st vector < 2nd vector
         2. 1st vector > 2nd vector
         3. equal size, but compare front value to get larger vector (1st < 2nd vector)
         4. equal size, but compare front value to get larger vector (1st > 2nd vector)
         */

    // Calculate min and max input vector sizes
    int min, max;
    minmax(other, min, max);
    
    // Fill zeros at front in smaller vector: get same lengths of vectors for addition
    // the result is saved in helpVec (same size as other input vector)
    std::vector<int> helpVec((max-min));
    fillZerosFront(other, helpVec, min, max);


    // Define iterators depending on input sizes and helper vector (helpVec) that is the smaller vector filled with 0's at front
    if(this->vInt.size()<other.vInt.size()) // 1st vector < 2nd vector: fill 2nd vector with 0's in front
    {
        auto it2 = helpVec.rbegin();
        auto it1 = other.vInt.rbegin();
        sub(other, result, it1, it2);
        
    }
    else if (this->vInt.size()>other.vInt.size()) // 1st vector > 2nd vector: fill 1st vector with 0's in front
    {
        auto it1 = this->vInt.rbegin();
        auto it2 = helpVec.rbegin();  
        sub(other, result, it1, it2); 
    } 
    else if (this->vInt.size()==other.vInt.size()  && *this >= other)
    {
        auto it2 = this->vInt.rbegin();
        auto it1 = other.vInt.rbegin();
        sub(other, result, it1, it2); 
    } 
    else if (this->vInt.size()==other.vInt.size() && *this <= other) // same size, use original input vectors
    {
        auto it1 = this->vInt.rbegin();
        auto it2 = other.vInt.rbegin();
        sub(other, result, it1, it2);       
    }    
    return result;  
}


// Function to sum elements of vectors created in operator overload * (vector of vectors)
void BigInt::addSubVectors(std::vector<int> & filled, const BigInt & other, BigInt & interm, BigInt & result) const
{
    std::vector<int> vec1={0};
    std::vector<int> vec2;
    
    // Sum intermediate vector with new vector (filled): filled vectors all have the same size (0's added to the end)
    if (!interm.vInt.empty())
    {
        BigInt First(interm.vInt);
        BigInt Second(filled);
        interm = First+Second;
    }
    else // if intermediate vector is empty (on the first loop iteration), use the provided vector with 0
    {
        BigInt First(vec1);
        BigInt Second(filled);
        interm = Second;
    }
}


// Operator overload * 
BigInt BigInt::operator*(const BigInt& other)
{
    std::vector<int> vector;  // Define result bigint
    BigInt result(vector);

    // Define intermediate BigInt
    std::vector<int> vector6;  
    BigInt interm(vector6);

    //Check if one of both inputs is 0, return 0
    if (this->vInt.size() == 0 || other.vInt.size()==0 )
    {
        vector={0};
        BigInt result(vector);
        return result;
    }
    
    // Stores elements of individual digit multiplication
    std::vector<int> temp;

    // Stores temp vectors 
    std::vector<std::vector<int>> temp2;
    

    int element = 0;
    int carry = 0;

    // Reverse this vector
    std::vector<int> reverse;
    auto it1 = this->vInt.rbegin();
    for(int i = 0; i< this->vInt.size(); i++)
    {
        reverse.push_back(*it1);
        it1++;
    }


    // Loop over this vector(inner loop) and other vector (outer loop)
    // Calculate individual multiplication result and store in vector temp
    for(int i =0; i< other.vInt.size();i++) 
    {
        temp.clear();
        carry = 0;

        for(int j = 0; j < this->vInt.size();j++) 
        {
            // element stores the individual multiplication result and adds a carry if needed
            element = other.vInt.at(i) * reverse.at(j) + carry;

            // Calculate carry and add rest to the temp vector
            if(element >= 10)
            {
                carry = floor(element/10);
                temp.push_back(element % 10);
            }
            else // otherwise add element to temp
            {
                carry = 0;
                temp.push_back(element);

            }         
            
            if(carry != 0 && j == this->vInt.size()-1) //push the last carry to temp vector, if last loop
                temp.push_back(carry);           
        }

        temp2.push_back(temp); // oush temp to temp2 (vector of vectors)
    }

    // Define helper vectors
    std::vector<int> vector3, filled;

    // Loop over each vector temp in temp2 
    // Reverse the temp vector
    // fillZerosBack: Fill the remaining elements per vector with 0's: each vector should have the same size
    // addSubVectors: 
    for(int k = 0; k< temp2.size();k++)
    {   
        reverseVec(temp2[k], vector3);
        fillZerosBack(k ,other, vector3, filled );
        addSubVectors( filled, other, interm, result); 

        filled.clear();

        if (k == temp2.size()-1) // if loop is completed assign interm to result
            result = interm;
    }
    return result;
}


bool BigInt::operator!()
{
    if (this->vInt.front() == 0)
        return true;
    return false;
}


bool BigInt::operator== (const BigInt& other)
{
    for(int i = 0; i < this->vInt.size();i++)
    {
        if(this->vInt.at(i)== other.vInt.at(i))
            return true;
        else
            return false;
    }
    return false;
}

bool BigInt::operator>= (const BigInt& other)
{
    for(int i = 0; i < this->vInt.size();i++)
    {
        if(this->vInt.at(i)== other.vInt.at(i) || this->vInt.at(i) > other.vInt.at(i))
            return true;
        else if (this->vInt.size()>other.vInt.size())
            return true;
        else
            return false;
    }
    return false;
}

bool BigInt::operator> (const BigInt& other)
{
    for(int i = 0; i < this->vInt.size();i++)
    {
        if(this->vInt.at(i) > other.vInt.at(i))
            return true;
        else if (this->vInt.size()>other.vInt.size())
            return true;
        else
            return false;
    }
    return false;
}


bool BigInt::operator<= (const BigInt& other)
{
    for(int i = 0; i < this->vInt.size();i++)
    {
        if(this->vInt.at(i)== other.vInt.at(i))
            return true;
        else if (this->vInt.at(i) < other.vInt.at(i))
            return true;
        else if (this->vInt.size()<other.vInt.size())
            return true;
        else
            return false;
    }
    return false;
}


bool BigInt::operator< (const BigInt& other)
{
    for(int i = 0; i < this->vInt.size();i++)
    {
        if(this->vInt.at(i) < other.vInt.at(i))
            return true;
        else if (this->vInt.size()<other.vInt.size())
            return true;
        else
            return false;
    }
    return false;
}

// Pre increment operator is used to increment variable value by 1 before assigning the value to the variable.
// Post increment operator is used to increment variable value by 1 after assigning the value to the variable.

// Postfix
BigInt BigInt::operator++(int) {
  BigInt tmp(*this);
  operator++();
  return tmp;
}

// Prefix return *this
BigInt BigInt::operator++()
{
    int lastEl = this->vInt.back()+1;
    this->vInt[this->vInt.size()-1] = lastEl;

    return *this;
}

// Postfix 
BigInt BigInt::operator--(int) {
  BigInt tmp(*this);
  operator--();
  return tmp;
}

// Prefix
BigInt BigInt::operator--()
{
    int lastEl = this->vInt.back()-1;
    this->vInt[this->vInt.size()-1] = lastEl;

    return *this;
}

std::ostream& operator<<(std::ostream& output,const BigInt & bigint)
{
    for(int i = 0; i < bigint.vInt.size();i++)
    {
        output << bigint.vInt.at(i);
    }
    return output;
}

std::istream& operator >>(std::istream& input, BigInt& bigint)
{
    int vec; 
    for(int i = 0; i<SIZE;i++)
    {
        input >> vec;
        bigint.vInt.push_back(vec);
    }
    return input;
} 

 
