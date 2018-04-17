
#include "CircularInt.hpp"


CircularInt::CircularInt(int _start, int _end)
{
	this->start = _start;
	this->end = _end;
	this->current = _start;
}

CircularInt::CircularInt(const CircularInt& other) :start(other.start), end(other.end), current(other.current)
{}

CircularInt::~CircularInt()//destructor
{
}

CircularInt& CircularInt::operator+=(int a)
{

	a %= (end - start + 1);
	if (current + a > end) {
		current = (current + a) % end;
	}
	else {
		this->current += a;
	}
	return(*this);
}
CircularInt & CircularInt::operator++() {
	this->current += 1;
	return (*this);
}

CircularInt CircularInt::operator++(int ) {
	CircularInt temp(*this);
	++(*this);
	return *this;
}





CircularInt& CircularInt::operator-=(int b)
{
	b %= (end - start + 1);

	if (current - b < start) {
		b -= current;
		current = end - b;

	}
	else {
		current -= b;
	}

	return CircularInt(*this);
}



CircularInt& CircularInt::operator*=(const int c)
{
		this->current = current*c % (end - start + 1);
		return CircularInt(*this);
}


CircularInt CircularInt::operator+( int a)
{

	a %= (end - start + 1);
	if (current + a > end) {
		current = (current + a) % end;

	}
	else {
		current += a;
	}

	return CircularInt(*this);
}

CircularInt CircularInt::operator+(const CircularInt& other)
{
	CircularInt temp(other);
	if (other.current + temp.current >temp.end)
		temp.current = (other.current + temp.current) % (end - start +1);
	else temp.current += other.current;

	return temp;
}

CircularInt CircularInt::operator--()
{
	if (this->current == this->start)
		this->current = this->end;
	else this->current -= 1;
	return CircularInt(*this);
}


CircularInt CircularInt::operator/=(const int a) 
{

	int temp = 0;
	temp = current%a;

	if (temp != 0)

		throw string("There is no number x in {1,12} such that x*" + to_string(a) + "=" + to_string(this->current));
	else
		current = current / a;

	return CircularInt(*this);
}


CircularInt  CircularInt::operator=(int a)
{

	if (a - current < start) {
		current = end - (current - a);
	}
	else {
		current = a - current;
	}
	return (*this);
}

ostream & operator<<(ostream & o, const CircularInt c)
{
	o << c.current;
	return o;
}

CircularInt operator/(const CircularInt& other, const int a)
{
	CircularInt temp(other);
	temp /= a;
	return temp;
}

