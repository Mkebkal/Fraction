#include<iostream>
using namespace std;

class Fraction
{
	int integer; 	
	int numerator;	
	int denominator;
public:
	const int get_integer()const
	{
		return integer;
	}
	const int get_numerator()const
	{
		return numerator;
	}
	const int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//		Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//		Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}

	//		Methods:
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "+";
			//if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			//if (integer)cout << ")";
		}
		else if (integer == 0)
			cout << 0;
		cout << endl;
	}
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		
	}
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		
	}

	void reduce()	
	{
		int more, less, reminder = 0;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			reminder = more % less;
			more = less;
			less = reminder;
		} while (reminder);
		int GCD = more; // Greatest Common Divider 
		numerator /= GCD;
		denominator /= GCD;
		
	}

};

//#define CONSTRUCTORS_CHECK
#define Methods_CHECK

void main()
{
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(4, 5);
	C.print();
	Fraction D(5, 4, 7);
	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;		//DefaultConstructor
	F = E;
	F.print();
#endif // CONSTRUCTORS_CHECK

	/*Fraction A(1, 2);
	A.print();
	Fraction B;
	B.print();
	cout << "\n-------------------------------------------\n";
	B = A;
	cout << "\n-------------------------------------------\n";*/

	/*int a, b, c;
	a = b = c = 0;
	Fraction D(1, 2);

	Fraction A, B, C;
	A = B = C = D;*/

#ifdef Methods_CHECK
	Fraction A(7, 5);
	cout << "\t" << "Fraction print:" << endl;
	A.print();
	cout << "\t" << "Fraction to_proper:" << endl;
	A.to_proper();
	A.print();
	
	Fraction B(1,2,5);
	cout << "\t"<<"Fraction print:" << endl;
	B.print();
	cout << "\t" << "Fraction to_improper:" << endl;
	B.to_improper();
	B.print();


	Fraction C(222,888);
	cout << "\t" << "Fraction print:" << endl;
	C.print();
	cout << "\t" << "Fraction reduce:" << endl;
	C.reduce();
	C.print();
#endif // Methods_CHECK

	
}