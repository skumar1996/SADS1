#include <iostream>
#include "gtest/gtest.h"
#include <cstdlib>
using namespace std;

// Please run executable independentaly if the following error is shown:
// "cannot open output file bin\debug\SADS1.exe Permission denied
// error: ld returned 1 exit status

int error_function(int);
static int test(int,int,int);

int main(){

    // all eight unit test combinations
    EXPECT_EQ(1, test(1,1,1));
    EXPECT_EQ(1, test(1,1,0));
    EXPECT_EQ(1, test(1,0,1));
    EXPECT_EQ(1, test(1,0,0));
    EXPECT_EQ(0, test(0,1,1));
    EXPECT_EQ(0, test(0,1,0));
    EXPECT_EQ(0, test(0,0,1));
    EXPECT_EQ(0, test(0,0,0));

    return 0;
}


int error_function(int input){
    return input;
}

static int test(int if_1, int if_2, int if_3){
    int err;

	if((err = error_function(if_1)) != 0)
        goto fail;
	if((err = error_function(if_2)) != 0)
        goto fail;
        goto fail;
	if((err = error_function(if_3)) != 0)
        goto fail;

    cout << "All if cases failed..." << endl;
    return 1;

fail:
	cout << "goto fail reached..." << endl;
	return err;
}