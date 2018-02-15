#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::stringstream;

int add(const string &addable){
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

TEST_CASE( "add null str [add]" ) {
    REQUIRE( add("") == 0 );
    REQUIRE( add("1") == 1);
    REQUIRE( add("2") == 2);
    REQUIRE( add("1,2") == 3);
    REQUIRE( add("1,2,3") == 6);

}
