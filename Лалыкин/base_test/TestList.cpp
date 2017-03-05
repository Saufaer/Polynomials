#include"List.h"

#include<gtest.h>

TEST(List, can_create_null_link_of_list)
{
	ASSERT_NO_THROW(List<double> list);
}

TEST(List,operator_Push_can_push_multiple_links_with_positive_val)
{
	List<double> list;

	ASSERT_NO_THROW(list.Push(3));	
}

TEST(List,operator_Push_can_push_multiple_links_with_zero_val)
{
	List<double> list;

	ASSERT_NO_THROW(list.Push(0));	
}

TEST(List,operator_GetData_can_return_the_value_of_links_1)
{
	List<double> list;
	list.Push(88);
	list.Push(32);

	EXPECT_EQ(list.GetData(0),88);
}

TEST(List,operator_GetData_can_return_the_value_of_links_2)
{
	List<double> list;
	list.Push(88);
	list.Push(32);

	EXPECT_EQ(list.GetData(1),32);
}

TEST(List,operator_Push_can_place_links_on_the_values_descending_1)
{
	List<double> list;
	list.Push(23);
	list.Push(4);
	list.Push(17);

	EXPECT_EQ(list.GetData(0),23);
}

TEST(List,operator_Push_can_place_links_on_the_values_descending_2)
{
	List<double> list;
	list.Push(23);
	list.Push(4);
	list.Push(17);

	EXPECT_EQ(list.GetData(1),17);
}

TEST(List,operator_Push_can_place_links_on_the_values_descending_3)
{
	List<double> list;
	list.Push(23);
	list.Push(4);
	list.Push(17);

	EXPECT_EQ(list.GetData(2),4);
}


TEST(List,operator_IsEmpty_indicates_that_stack_is_empty)
{
	List<double> list;

	EXPECT_EQ(list.IsEmpty(),true);
}

TEST(List,operator_IsEmpty_indicates_that_stack_is_not_empty)
{
	List<double> list;
	list.Push(4);
	list.Push(11);

	EXPECT_EQ(list.IsEmpty(),false);
}

TEST(List,operator_GetLength_can_return_list_of_length )
{
	List<int> list;
	list.Push(3);
	list.Push(2);
	list.Push(1);
	list.Push(4);

	EXPECT_EQ(list.GetLength(),4);
}

TEST(List,operator_DeleteList_can_delete_all_links_of_list)
{
	List<int> list;
	list.Push(44);
	list.Push(21);
	list.Push(1);
	list.Push(0);
	list.DeleteList();

	EXPECT_EQ(list.GetLength(),0);
}

