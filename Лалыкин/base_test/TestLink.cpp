#include"Link.h"
#include<gtest.h>

TEST(Link, can_create_link)
{
	ASSERT_NO_THROW(Link<double> link);
}

