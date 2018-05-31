/** @file BigNumber.h
* @author Amir Sotoodeh
* @date 5/30/18
* @brief BigNumber.h headerfile that outlines functions used.
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
		bool BIGNUMBER_API maximum(std::vector <int> & x, std::vector <int> & y);
		void BIGNUMBER_API reverse(std::vector <int> & r);
		bool BIGNUMBER_API less(std::vector<int> leftOperand, std::vector<int> rightOperand);
		bool BIGNUMBER_API lessEqual(std::vector< int > leftOperand, std::vector< int > rightOperand);

	public:
		BIGNUMBER_API MyBigNumber(std::string n);
		BIGNUMBER_API MyBigNumber();
		BIGNUMBER_API MyBigNumber operator +(MyBigNumber & r);
		BIGNUMBER_API MyBigNumber operator -(MyBigNumber & r);
		BIGNUMBER_API MyBigNumber operator *(MyBigNumber & r);
		BIGNUMBER_API MyBigNumber operator /(MyBigNumber & r);
		BIGNUMBER_API MyBigNumber operator ++();
		BIGNUMBER_API MyBigNumber operator %(MyBigNumber & r);
		BIGNUMBER_API int operator %(int a);

		BIGNUMBER_API void print();

	};

}