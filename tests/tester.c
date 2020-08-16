#include <stdio.h>

#include <unity.h>

#include "commands.h"

void setUp(){}
void tearDown(){}

void test_commands() {
	TEST_ASSERT_EQUAL(2, commands());
}

int main(void) {
	UNITY_BEGIN();

	RUN_TEST(test_commands);

	return UNITY_END();
}
