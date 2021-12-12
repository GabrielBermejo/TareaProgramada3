#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include  "../src/person.h"
#include "../src/fileReader.h"
#include "../src/OutOfBoundsException.h"



namespace {
    TEST(fileReaderTests, fileReader_OutputTest) {
        fileReader *f = fileReader();
        f->Read();

        Person alice=f->personFinder(1);
        EXPECT_EQ(1, alice.getID());
        EXPECT_EQ("Just", alice.getName());
        EXPECT_EQ("For", alice.getLastname());
        EXPECT_EQ("testing_purposes@biz.com", alice.getEmail());
    }
}

namespace {
    TEST(fileReaderTests, fileReader_OutOfBoundsException)
    {
        fileReader *f = fileReader();
        f->Read();
        EXPECT_THROW({
            try
            {
                f->personFinder(13);
            }
            catch( const OutOfBoundsException& e )
            {
                EXPECT_STREQ( "There's no person with the ID that you typed", e.what() );
                throw;
            }
        }, OutOfBoundsException );
    }

}