#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include  "../src/person.h"



namespace {
    TEST(PersonTests, Person_AtributesTest) {
        char name[16]="Just";
        char lastname[16]="For";
        char email[51]="testing_purposes@biz.com";
        Person *f = Person(1, name, lastname, email);

        EXPECT_EQ(1, f.getID());
        EXPECT_EQ("Just", f.getName());
        EXPECT_EQ("For", f.getLastname());
        EXPECT_EQ("testing_purposes@biz.com", f.getEmail());

    }
}