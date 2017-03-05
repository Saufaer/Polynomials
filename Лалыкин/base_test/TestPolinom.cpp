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

TEST(Polinom,  operator_Create_can_create_polinom_with_negative_coefficient)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(-13,1,2,3));
}

TEST(Polinom,  operator_Create_can_create_polinom_with_zero_coefficient)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(0,1,2,3));
}

TEST(Polinom,  operator_Create_can_create_polinom_with_zero_degree)
{
	Polinom p;
	ASSERT_NO_THROW(p.Create(5,0,2,3));
}

TEST(Polinom, operator_GetLength_can_get_length_for_polinom)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-5,2,3,5);
	p.Create(7,1,3,3);
	p.Create(5,2,3,4);
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

TEST(Polinom, operator_Create_can_create_polinom_and_fold_monom_with_equal_degrees)
{
	Polinom p;
	p.Create(6,1,2,4);
	p.Create(-5,1,2,4);
	p.Create(0,1,3,3);
	p.Create(5,2,3,4);
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

TEST(Polinom, operator_ToString_can_convert_the_list_to_string)
{
	Polinom p;
	p.Create(6,1,2,3);
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

TEST(Polinom, operator_subtraction_can_subtract_two_polinoms_1)
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

TEST(Polinom, operator_subtraction_can_subtract_two_polinoms_2)
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
TEST(Polinom, operator_multiplication_multiply_polinom_and_number_1)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	p*(2);

	EXPECT_EQ(p.GetData(1).coef,8);
}

TEST(Polinom, operator_multiplication_multiply_polinom_and_number_2)
{
	Polinom p;
	p.Create(4,1,2,3);
	p.Create(5,2,3,4);

	p*(-2);

	EXPECT_EQ(p.GetData(0).coef,-10);
}
