#include <unity/unity.h>

#include <stdio.h>

#include <common/commands.h>

void setUp(){}
void tearDown(){}

void test_commands() {
	TEST_ASSERT_EQUAL(3, commands());
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_commands);

	return UNITY_END();
}
