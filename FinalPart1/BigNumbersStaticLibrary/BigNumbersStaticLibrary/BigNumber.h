/**
* \class BigNumber
*
* \brief BigNumbers can be used in place of primitive data types
* to represent numbers that cannot normally be used in C++.
*
* \author $Author: bv Amir Sotoodeh
*
* \version $Revision: 1.0 $
*
* \date $Date: 6/1/18 $
*/
#pragma once
#include <vector>
#include <string>

namespace BigNumber

{
	class MyBigNumber

	{

	private:
		std::vector <int> digits;
		bool isNegative;  
		void add(std::vector <int> & x,  std::vector <int> & y, std::vector <int> & z);
		void subtract(std::vector <int> &x,  std::vector <int> &y, std::vector <int> &z);
		std::vector<int> subtractReturnVector(std::vector <int> & x, std::vector <int> & y);
		bool max(std::vector <int> & x,  std::vector <int> & y);
		void reverse(std::vector <int> & r);
		bool less(std::vector<int> l, std::vector<int> r);
		bool lessEqual(std::vector< int > l, std::vector< int > r);
		bool isASmallerString(std::string str1, std::string str2);
		MyBigNumber computeSignAndValue(MyBigNumber n1, MyBigNumber n2);
		std::string convertToString(std::vector<int> x);
		void setNegative(bool v);
		bool getNegative();


	public:
		MyBigNumber(std::string n);
		MyBigNumber();
		MyBigNumber operator +( MyBigNumber & x);
		MyBigNumber operator -( MyBigNumber & x);
		MyBigNumber operator *( MyBigNumber & x);
		MyBigNumber operator /( MyBigNumber & x);
		MyBigNumber operator ++();
		MyBigNumber operator %( MyBigNumber & x);
		int operator %(int a);
		void print();

	};

}