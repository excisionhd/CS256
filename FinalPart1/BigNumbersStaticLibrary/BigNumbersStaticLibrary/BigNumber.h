/** @file BigNumber.h
* @author Amir Sotoodeh
* @date 5/30/18
* @brief BigNumber.h headerfile that outlines functions used.
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
		void add( std::vector <int> & x,  std::vector <int> & y, std::vector <int> & z);
		void subtract( std::vector <int> &x,  std::vector <int> &y, std::vector <int> &z);
		bool max( std::vector <int> & x,  std::vector <int> & y);
		void reverse(std::vector <int> & r);
		bool less(std::vector<int> leftOperand, std::vector<int> rightOperand);
		bool lessEqual(std::vector< int > leftOperand, std::vector< int > rightOperand);

	public:
		MyBigNumber(std::string n);
		MyBigNumber();
		MyBigNumber operator +( MyBigNumber & r);
		MyBigNumber operator -( MyBigNumber & r);
		MyBigNumber operator *( MyBigNumber & r);
		MyBigNumber operator /( MyBigNumber & r);
		MyBigNumber operator ++();
		MyBigNumber operator %( MyBigNumber & r);
		int operator %(int a);

		void print();

	};

}