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

#ifdef BIGNUMBER_EXPORTS
#define BIGNUMBER_API __declspec(dllexport)  
#else   
#define BIGNUMBER_API __declspec(dllimport)    
#endif   

#include <vector>
#include <string>

namespace BigNumber

{
	class MyBigNumber

	{

	private:
		std::vector <int> digits;
		bool isNegative;
		void BIGNUMBER_API add(std::vector <int> & x, std::vector <int> & y, std::vector <int> & z);
		void BIGNUMBER_API subtract(std::vector <int> &x, std::vector <int> &y, std::vector <int> &z);
		std::vector<int> BIGNUMBER_API subtractReturnVector(std::vector <int> & x, std::vector <int> & y);
		bool BIGNUMBER_API maximum(std::vector <int> & x, std::vector <int> & y);
		void BIGNUMBER_API reverse(std::vector <int> & r);
		bool BIGNUMBER_API less(std::vector<int> leftOperand, std::vector<int> rightOperand);
		bool BIGNUMBER_API lessEqual(std::vector< int > leftOperand, std::vector< int > rightOperand);
		bool BIGNUMBER_API isASmallerString(std::string str1, std::string str2);
		MyBigNumber BIGNUMBER_API computeSignAndValue(MyBigNumber n1, MyBigNumber n2);
		std::string BIGNUMBER_API convertToString(std::vector<int> x);
		void BIGNUMBER_API setNegative(bool v);
		bool BIGNUMBER_API getNegative();

	public:
		BIGNUMBER_API MyBigNumber(std::string n);
		BIGNUMBER_API MyBigNumber();
		MyBigNumber BIGNUMBER_API operator +(MyBigNumber & x);
		MyBigNumber BIGNUMBER_API operator -(MyBigNumber & x);
		MyBigNumber BIGNUMBER_API operator *(MyBigNumber & x);
		MyBigNumber BIGNUMBER_API operator /(MyBigNumber & x);
		MyBigNumber BIGNUMBER_API operator ++();
		MyBigNumber BIGNUMBER_API operator %(MyBigNumber & x);
		int BIGNUMBER_API operator %(int a);
		void BIGNUMBER_API  print();

	};

}

