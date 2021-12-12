#include <gtest/gtest.h>
#include <string>

#include "../src/fileReader.h"

namespace {
    TEST(fileReaderTests, fileReader_Test) {
        string result= " ";
        EXPECT_EQ(" ", result);
    }
}