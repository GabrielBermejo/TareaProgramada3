#include <gtest/gtest.h>
#include <string>

#include "../src/fileWriter.h"

namespace {
    TEST(fileWriterTests, fileWriter_Test) {
        string result= " ";
        EXPECT_EQ(" ", result);
    }
}