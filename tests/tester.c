#include <unity/unity.h>

#include <stdio.h>

#include <common/commands.h>

void setUp(){}
void tearDown(){}

void test_commands() {
	TEST_ASSERT_EQUAL(3, commands());
}

void test_commands2() {
	TEST_ASSERT_EQUAL(2, commands());
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_commands);
	RUN_TEST(test_commands2);

	return UNITY_END();
}
