//!
//! @file 		FpTest-Fp64sDifferentQArithmetic.cpp
//! @author 	Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @edited 	n/a
//! @date 		2013/07/24
//! @brief 		Performs unit tests on the slow 64-bit fixed point compound arithmetic with variables that have
//!				a different Q .
//! @details
//!				See README.rst in root fir for more info.

// Slow 64-bit fixed-point library
#include "../src/include/FixedPoint-Fp64s.hpp"

#include "./UnitTest++/src/UnitTest++.h"

using namespace Fp;

SUITE(Fp64sDiffQArithmeticTests)
{
	TEST(DiffQCompoundAdditionNoChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 8);
		Fp64s fp2 = Fp64s(0.6, 12);
		
		fp1 += fp2;

		CHECK_CLOSE(3.8, (double)fp1, 0.1);
		CHECK_EQUAL(8, fp1.q);
		CHECK_EQUAL(12, fp2.q);
	}
	
	TEST(DiffQCompoundAdditionChangeTest)
	{
		Fp64s fp1 = Fp64s(0.4, 16);
		Fp64s fp2 = Fp64s(8.2, 5);
		
		// This should change the Q of fp1 to 5
		fp1 += fp2;

		CHECK_CLOSE(8.6, (double)fp1, 0.1);
		CHECK_EQUAL(5, fp1.q);
		CHECK_EQUAL(5, fp2.q);
	}
	
	TEST(DiffQCompoundSubtractionNoChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 7);
		Fp64s fp2 = Fp64s(0.6, 22);
		
		fp1 -= fp2;

		CHECK_CLOSE(2.6, (double)fp1, 0.1);
		CHECK_EQUAL(7, fp1.q);
		CHECK_EQUAL(22, fp2.q);
	}
	
	TEST(DiffQCompoundSubtractionChangeTest)
	{
		Fp64s fp1 = Fp64s(2.3, 24);
		Fp64s fp2 = Fp64s(13.0, 12);
		
		fp1 -= fp2;

		CHECK_CLOSE(-10.7, (double)fp1, 0.1);
		CHECK_EQUAL(12, fp1.q);
		CHECK_EQUAL(12, fp2.q);
	}
	
	TEST(DiffQCompoundMultiplicationNoChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 6);
		Fp64s fp2 = Fp64s(0.6, 12);
		
		fp1 *= fp2;

		CHECK_CLOSE(1.92, (double)fp1, 0.1);
		CHECK_EQUAL(6, fp1.q);
		CHECK_EQUAL(12, fp2.q);
	}
	
	TEST(DiffQCompoundMultiplicationChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 12);
		Fp64s fp2 = Fp64s(0.6, 6);
		
		fp1 *= fp2;

		CHECK_CLOSE(1.92, (double)fp1, 0.1);
		CHECK_EQUAL(6, fp1.q);
		CHECK_EQUAL(6, fp2.q);
	}

	TEST(DiffQCompoundDivisionNoChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 12);
		Fp64s fp2 = Fp64s(0.6, 18);
		
		fp1 /= fp2;

		CHECK_CLOSE(5.33, (double)fp1, 0.1);
		CHECK_EQUAL(12, fp1.q);
		CHECK_EQUAL(18, fp2.q);
	}
	
	TEST(DiffQCompoundDivisionChangeTest)
	{
		Fp64s fp1 = Fp64s(3.2, 18);
		Fp64s fp2 = Fp64s(0.6, 12);
		
		fp1 /= fp2;

		CHECK_CLOSE(5.33, (double)fp1, 0.1);
		CHECK_EQUAL(12, fp1.q);
		CHECK_EQUAL(12, fp2.q);
	}
	
	TEST(DiffQCompoundModuloNoChangeTest)
	{
		Fp64s fp1 = Fp64s(20.2, 12);
		Fp64s fp2 = Fp64s(1.5, 19);
		
		fp1 %= fp2;
		//20.2 % 1.5 = 0.7
		
		CHECK_CLOSE(0.7, (double)fp1, 0.1);
		CHECK_EQUAL(12, fp1.q);
		CHECK_EQUAL(19, fp2.q);
	}
	
	TEST(DiffQCompoundModuloChangeTest)
	{
		Fp64s fp1 = Fp64s(20.2, 19);
		Fp64s fp2 = Fp64s(1.5, 12);
		
		fp1 %= fp2;
		//20.2 % 1.5 = 0.7
		
		CHECK_CLOSE(0.7, (double)fp1, 0.1);
		CHECK_EQUAL(12, fp1.q);
		CHECK_EQUAL(12, fp2.q);
	}
	
}