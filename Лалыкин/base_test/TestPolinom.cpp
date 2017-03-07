#include "Polinom.h"
#include<gtest.h>

TEST(Polinom, can_create_polinom)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom,  operator_Create_can_create_polinom_with_positive_coefficient)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(3,1,2,3));
}
TEST(Polinom,  operator_OfString_can_create_polinom_of_string_with_positive_coefficient)
{
	Polinom p;
	string s="3x1y2z3";

	ASSERT_NO_THROW(p.OfString(s));
}

TEST(Polinom,  operator_Create_can_create_polinom_with_negative_coefficient)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(-13,1,2,3));
}

TEST(Polinom,  operator_OfString_can_create_polinom_of_string_with_negative_coefficient)
{
	Polinom p;
	string s="-3x1y2z3";

	ASSERT_NO_THROW(p.OfString(s));
}

TEST(Polinom,  operator_Create_can_create_polinom_with_zero_coefficient)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(0,1,2,3));
}

TEST(Polinom,  operator_OfString_can_create_polinom_of_string_with_zero_coefficient)
{
	Polinom p;
	string s="0x1y2z3";

	ASSERT_NO_THROW(p.OfString(s));
}

TEST(Polinom,  operator_Create_can_create_polinom_with_zero_degree)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(5,0,2,3));
}

TEST(Polinom,  operator_OfString_can_create_polinom_of_string_with_zero_degree)
{
	Polinom p;
	string s="5x0y2z3";

	ASSERT_NO_THROW(p.OfString(s));
}

TEST(Polinom, operator_GetLength_can_get_length_for_polinom)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-5,2,0,5);
	p.Create(7,1,3,3);
	p.Create(5,0,3,4);
	EXPECT_EQ(p.GetLength(),4);
}

TEST(Polinom,  perator_GetLength_can_get_length_for_polinom_of_string)
{
	Polinom p;
	string s="50y2z3+4x4y2z3-6x30z3+2x2";
	p.OfString(s);

	EXPECT_EQ(p.GetLength(),4);
}

TEST(Polinom, operator_Create_can_create_polinom_and_delete_monom_with_zero_coefficient)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-5,2,3,5);
	p.Create(0,1,3,3);
	p.Create(5,2,3,4);

	EXPECT_EQ(p.GetLength(),3);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_and_delete_monom_with_zero_coefficient)
{
	Polinom p;
	string s="0x5y2z3+4x4y2z3-6x3z3+2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetLength(),3);
}

TEST(Polinom, operator_Create_can_create_polinom_and_fold_monom_with_equal_degrees)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-5,1,2,4);
	p.Create(0,1,3,3);
	p.Create(5,2,3,4);
	EXPECT_EQ(p.GetLength(),2);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_and_fold_monom_with_equal_degrees)
{
	Polinom p;
	string s="0x5y2z3+4x3y2z3-6x3y2z3+2x2y2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetLength(),2);
}

TEST(Polinom, operator_Create_can_create_polinom_and_fold_monom_with_equal_degrees_and_delete_monom_if_coefficient_is_zero)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-6,1,2,4);
	p.Create(0,1,3,3);
	p.Create(5,2,3,4);
	EXPECT_EQ(p.GetLength(),1);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_and_fold_monom_with_equal_degrees_and_delete_monom_if_coefficient_is_zero)
{
	Polinom p;
	string s="0x5y2z3+6x3y2z3-6x3y2z3+2x2";
	p.OfString(s);

	EXPECT_EQ(p.GetLength(),1);
}

TEST(Polinom, operator_Create_can_create_polinom_descending_rolled_degree_1)
{
	Polinom p;
	p.Create(6,1,2,3);
	p.Create(-5,2,3,4);
	p.Create(1,2,4,4);
	p.Create(5,8,8,8);
	EXPECT_EQ(p.GetData(0).coef,5);
}

TEST(Polinom, operator_Create_can_create_polinom_descending_rolled_degree_2)
{
	Polinom p;
	p.Create(6,1,2,3);
	p.Create(-5,2,3,4);
	p.Create(1,2,4,4);
	p.Create(5,8,8,8);
	EXPECT_EQ(p.GetData(1).coef,1);
}

TEST(Polinom, operator_Create_can_create_polinom_descending_rolled_degree_3)
{
	Polinom p;
	p.Create(6,1,2,3);
	p.Create(-5,2,3,4);
	p.Create(1,2,4,4);
	p.Create(5,8,8,8);
	EXPECT_EQ(p.GetData(2).coef,-5);
}

TEST(Polinom, operator_Create_can_create_polinom_descending_rolled_degree_4)
{
	Polinom p;
	p.Create(6,1,2,3);
	p.Create(-5,2,3,4);
	p.Create(1,2,4,4);
	p.Create(5,8,8,8);
	EXPECT_EQ(p.GetData(3).coef,6);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_descending_rolled_degree_1)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3+2x2y2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetData(0).coef,6);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_descending_rolled_degree_2)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3+2x2y2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetData(1).coef,-6);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_descending_rolled_degree_3)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3+2x2y2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetData(2).coef,2);
}

TEST(Polinom, operator_OfString_can_create_polinom_of_string_descending_rolled_degree_4)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3+2x2y2z3";
	p.OfString(s);

	EXPECT_EQ(p.GetData(3).coef,-7);
}

TEST(Polinom, operator_ToString_can_convert_the_list_to_string)
{
	Polinom p;
	p.Create(6,1,2,3);
	ASSERT_NO_THROW(p.ToString());
}

TEST(Polinom, operator_ToString_can_convert_the_list_of_string_to_string)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3+2x2y2z3";
	ASSERT_NO_THROW(p.ToString());
}


TEST(Polinom, operator_addition_can_fold_two_polinoms_1)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	Polinom d;
	d.Create(6,1,2,3);
	d.Create(8,2,3,4);
	p+=d;

	EXPECT_EQ(p.GetData(0).coef,13);
}

TEST(Polinom, operator_addition_can_fold_two_polinoms_2)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	Polinom d;
	d.Create(6,1,2,3);
	d.Create(8,2,3,4);
	p+=d;

	EXPECT_EQ(p.GetData(1).coef,10);
}

TEST(Polinom, operator_addition_can_fold_two_polinoms_of_string_1)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="4x5y2z3+2x3y2z3";
	d.OfString(k);
	p+=d;

	EXPECT_EQ(p.GetData(0).coef,10);
}

TEST(Polinom, operator_addition_can_fold_two_polinoms_of_string_2)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="4x5y2z3+2x3y2z3";
	d.OfString(k);
	p+=d;

	EXPECT_EQ(p.GetData(1).coef,-4);
}

TEST(Polinom, operator_addition_can_fold_two_polinoms_of_string_3)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="4x5y2z3+2x3y2z3";
	d.OfString(k);
	p+=d;

	EXPECT_EQ(p.GetData(2).coef,-7);
}


TEST(Polinom, operator_addition_can_fold_two_polinoms_and_delete_zero_monom)
{
	Polinom p;
	p.Create(4, 1, 2, 3);
	p.Create(5, 2, 3, 4);

	Polinom d;
	d.Create(-4, 1, 2, 3);
	d.Create(8, 2, 3, 4);
	p += d;

	EXPECT_EQ(p.GetLength(), 1);
}

TEST(Polinom, operator_addition_can_fold_two_polinoms_of_string_and_delete_zero_monom)
{
	Polinom p;
	string s="-7x1y2z3+6x5y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="6x3y2z3";
	d.OfString(k);
	p+=d;

	EXPECT_EQ(p.GetLength(), 2);
}


TEST(Polinom, operator_subtraction_can_subtract_two_polinoms_1)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	Polinom d;
	d.Create(6,1,2,3);
	d.Create(8,2,3,4);
	p-=d;

	EXPECT_EQ(p.GetData(0).coef,-3);
}


TEST(Polinom, operator_subtraction_can_subtract_two_polinoms_2)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	Polinom d;
	d.Create(6,1,2,3);
	d.Create(8,2,3,4);
	p-=d;

	EXPECT_EQ(p.GetData(1).coef,-2);
}

TEST(Polinom,operator_subtraction_can_subtract_two_polinoms_of_string_1)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="9x3y2z3+237x1y2z3";
	d.OfString(k);
	p-=d;

	EXPECT_EQ(p.GetData(0).coef,-15);
}

TEST(Polinom,operator_subtraction_can_subtract_two_polinoms_of_string_2)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="9x3y2z3-237x1y2z3";
	d.OfString(k);
	p-=d;

	EXPECT_EQ(p.GetData(1).coef,230);
}

TEST(Polinom, operator_subtraction_can_subtract_two_polinoms_and_delete_zero_monom)
{
	Polinom p;
	p.Create(4, 1, 2, 3);
	p.Create(5, 2, 3, 4);

	Polinom d;
	d.Create(6, 1, 2, 3);
	d.Create(5, 2, 3, 4);
	p-=d;

	EXPECT_EQ(p.GetLength(), 1);
}

TEST(Polinom,operator_subtraction_can_subtract_two_polinoms_of_string_and_delete_zero_monom)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);

	Polinom d;
	string k="9x3y2z3-7x1y2z3";
	d.OfString(k);
	p-=d;

	EXPECT_EQ(p.GetLength(), 1);
}


TEST(Polinom, operator_multiplication_multiply_polinom_and_positive_number)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	p*2;

	EXPECT_EQ(p.GetData(1).coef,8);
}

TEST(Polinom,operator_multiplication_multiply_polinom_of_string_and_positive_number)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);
	p*3;


	EXPECT_EQ(p.GetData(1).coef,-21);
}

TEST(Polinom, operator_multiplication_multiply_polinom_and_negative_number)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	p*(-2);

	EXPECT_EQ(p.GetData(0).coef,-10);
}

TEST(Polinom,operator_multiplication_multiply_polinom_of_string_and_negative_number)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);
	p*(-3);


	EXPECT_EQ(p.GetData(1).coef,21);
}

TEST(Polinom, operator_multiplication_multiply_polinom_and_zero_number)
{
	Polinom p;
	p.Create(4, 1, 2, 3);
	p.Create(5, 2, 3, 4);

	p*0;

	EXPECT_EQ(p.GetLength(), 0);
}

TEST(Polinom,operator_multiplication_multiply_polinom_of_string_and_zero_number)
{
	Polinom p;
	string s="-7x1y2z3-6x3y2z3";
	p.OfString(s);
	p*0;


	EXPECT_EQ(p.GetLength(), 0);
}

TEST(Polinom,operator_Calculate_can_calculate_value_of_polynomial_at_point)
{
	Polinom p;
	string s="-7x1y2z3";
	p.OfString(s);
	
	EXPECT_EQ(p.Calculate(5,1,2),-280);
}
