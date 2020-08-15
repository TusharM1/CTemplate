// #include <gtest/gtest.h>

extern "C" {
	#include "commands.h"
}

// TEST(COMMANDS_TEST, RUN_COMMAND) {
// 	ASSERT_EQ(commands(), 3);
// }

// TEST(COMMANDS_TEST, RUN_WRONG_COMMAND) {
// 	ASSERT_EQ(commands(), 4);
// }

// int main(int argc, char** argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }

int main() {
	return commands();
}
