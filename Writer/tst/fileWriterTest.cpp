#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../src/fileWriter.h"

namespace {
    TEST(fileWriterTests, fileWriter_OutputTest) {
        fileWriter *f = fileWriter();
        f->Write();

        bool written=false;
        std::ifstream ifs("Personas.dat", std::ifstream::in);
        if (ifs.is_open())
        {
            written=true;
        }
        //if file was written then bool "written" is TRUE

        EXPECT_TRUE(written);
    }
}