#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"

#include "bitset.hpp"

// THIS IS JUST AN EXAMPLE
// There should be at least one test per Bitset method

TEST_CASE( "Test bitset construction", "[bitset]" ) {

    Bitset b;  
    REQUIRE(b.size() == 8);
    REQUIRE(b.good());
}

TEST_CASE( "Test custom bitset construction", "[bitset]" ) {

    Bitset b(5);  
    REQUIRE(b.size() == 5);
    REQUIRE(b.good());
}

TEST_CASE( "Test good method ", "[bitset]" ) {

    Bitset b(-7);  
    REQUIRE(!b.good());
    Bitset c(5);
    REQUIRE(c.good());
}
TEST_CASE( "Test set and asString method ", "[bitset]" ) {

    Bitset b(5);
    b.set(3); 
    b.set(4);
    REQUIRE(b.good());
    REQUIRE(b.asString() == "11");
    b.reset(3);
    b.toggle(4);
    REQUIRE(b.asString() == "00000");
    b.toggle(0);
    REQUIRE(b.asString() == "10000");
}
TEST_CASE( "Test set,reset, and test method ", "[bitset]" ) {

    Bitset b(5);
    b.set(3); 
    b.set(4);
    REQUIRE(b.good());
    REQUIRE(b.test(3) == true);
    REQUIRE(b.test(4) == true);
    b.toggle(3);
    b.toggle(4);
    REQUIRE(b.test(3) == false);
    REQUIRE(b.test(4) == false);
    b.set(0);
    REQUIRE(b.test(0) == true);
}

TEST_CASE( "Test string constructor", "[bitset]" ) {
    Bitset b("1001010021");
    REQUIRE(b.good() == false);
    Bitset a("1001010001");
    REQUIRE(a.asString() == "1001010001");
}

