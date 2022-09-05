#include "constraints.hpp"
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerTestlibCmd(argc, argv);

	int j_a = ans.readInt();
	int p_a = ouf.readInt();
	if(p_a < MIN_ANS_A || MAX_ANS_A < p_a) {
		quitf(_wa, "a = %d does not meet the condition", p_a);
	}

	int j_b = ans.readInt();
	int p_b = ouf.readInt();
	if(p_b < MIN_ANS_B || MAX_ANS_B < p_b) {
		quitf(_wa, "b = %d does not meet the condition", p_b);
	}

	if(p_a + p_b == j_a + j_b) {
		quitf(_ok, "all conditions are met");
	} else {
		quitf(_wa, "a+b = %d is not equal to N = %d", p_a + p_b, j_a + j_b);
	}
}
