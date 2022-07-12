#ifndef _BIG_INT_H_
#define _BIG_INT_H_

#include <vector>
#include <iostream>

class BigInt{

public:
    // Constructors
    BigInt(const std::vector<int> & vec);
    BigInt(const std::vector<char> & vec);
    BigInt(char *array, int size);

    // Helper functions for + and - and *
    void minmax(const BigInt & other, int & min, int & max) const;

    void sum(const BigInt& other, BigInt & result, std::vector<int>::const_reverse_iterator it1, 
    std::vector<int>::const_reverse_iterator it2) const;

    void sub(const BigInt& other, BigInt &result, std::vector<int>::const_reverse_iterator it1,
    std::vector<int>::const_reverse_iterator it2 ) const;

    void fillZerosFront( const BigInt & other, std::vector<int> & helpVec,int min, int max) const;
    void reverseVec(std::vector<int> & toBereversed, std::vector<int> & reversed) const;
    void fillZerosBack(int start,const BigInt & other, std::vector<int> & reversed , std::vector<int> & filled ) const;
    void addSubVectors(std::vector<int> & filled, const BigInt & other, BigInt & interm, BigInt & result) const;

    // Operator overloading
    BigInt operator+(const BigInt& other);
    BigInt operator-(const BigInt& other);
    BigInt operator*(const BigInt& other);

    bool operator!();
    bool operator== (const BigInt& other);
    bool operator>= (const BigInt& other);
    bool operator> (const BigInt& other);
    bool operator<= (const BigInt& other);
    bool operator< (const BigInt& other);

    BigInt operator++(int);
    BigInt operator++();
    BigInt operator--(int);
    BigInt operator--();

    friend std::ostream& operator<<(std::ostream& output,const BigInt & bigint);
    friend std::istream& operator>>(std::istream& input, BigInt & bigint);

private:
    std::vector<int> vInt;
};

#endif

