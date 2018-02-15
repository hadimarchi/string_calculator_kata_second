#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

int Add(const string &addable){
    vector<int> nums{};
    if(addable.size()==0){
        return 0;
    }
		unsigned int total = 0;
    stringstream ss(addable);
		int i = 0;
		while (ss >> i) {
      if (i<0){
        raise;
      }
			total += i;
			if (ss.peek() == ',' || ss.peek() == '\n') {
				ss.ignore();
			}
		}
		return total;
}

TEST_CASE("empty string returns 0") {
	REQUIRE(Add("") == 0);
}

TEST_CASE("single number returns value") {
	REQUIRE(Add("7") == 7);
}

TEST_CASE("two numbers (comma delimited) returns sum") {
	REQUIRE(Add("7, 5") == 12);
}

TEST_CASE("two numbers (newline delimited) returns sum") {
	REQUIRE(Add("3\n8") == 11);
}

TEST_CASE("three numbers, whatever delimiter, returns sum") {
	REQUIRE(Add("4,5,6") == 15);
	REQUIRE(Add("4\n5\n6") == 15);
	REQUIRE(Add("4,5\n6") == 15);
	REQUIRE(Add("4\n5,6") == 15);
}

TEST_CASE("negative numbers throw") {
	REQUIRE_THROWS(Add("-5"));
}

TEST_CASE("numbers > 1000 are ignored") {
	REQUIRE(Add("10,10000") == 10);
	REQUIRE(Add("1000,1001") == 1000);
}
