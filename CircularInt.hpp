#pragma once
#include<iostream>
#include<string>
using namespace std;
using std::ostream;
using std::to_string;

class CircularInt
{

public:
	int start, end;
    int current;
	CircularInt(int, int);
	CircularInt( const CircularInt& );
	~CircularInt();

	CircularInt& operator+=(int);
	CircularInt &operator*=(const int);
	CircularInt&  operator++();
	CircularInt  operator++(int);

	CircularInt operator+( int);
	CircularInt operator+(const CircularInt&);
	CircularInt operator--();
	CircularInt& operator-=(int);
	friend CircularInt operator/(const CircularInt&, const int );

	friend CircularInt operator- (const CircularInt& other);
	friend  CircularInt operator-(const int, const CircularInt&);

	CircularInt operator=(int);
	CircularInt operator/=(const int);
	friend ostream& operator<<(ostream&, const CircularInt);

};
inline CircularInt operator- (const int num, const CircularInt& other )
{
	CircularInt temp(other);
	 temp.current=num -temp.current  ;
	 while(temp.current<temp.start)
		 temp.current+=12;
	return temp;
}
inline CircularInt operator- (const CircularInt& other)
{
	CircularInt temp(other);
	temp.current = (temp.end - temp.current);
	return temp;

}
