#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
using std::vector;
#include <string>
using std::string;

string delimiter = ",";
int add(const string &addable){
    vector<int> nums{};
    if(addable.size()==0){
        return 0;
    }

    size_t numnums = std::count(addable.begin(), addable.end(), ',');

    for(unsigned int i = 0; i < numnums * 2; i+=2){
      nums.push_back(stoi(addable.substr(i, addable.find(delimiter))));
    }
    auto num1 = stoi(addable.substr(0, addable.find(delimiter)));
    int num2 = 0;
    try{
      auto num2 = stoi(addable.substr(2, addable.find(delimiter)));
      return num1 + num2;
    }
    catch(...){
      return num1;
    }
}

TEST_CASE( "add null str [add]" ) {
    REQUIRE( add("") == 0 );
    REQUIRE( add("1") == 1);
    REQUIRE( add("2") == 2);
    REQUIRE( add("1,2") == 3);
    REQUIRE( add("1,2,3") == 6);

}
