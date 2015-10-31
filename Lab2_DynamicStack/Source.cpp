
#include "Dynamic_stack.h"


using namespace std;

int main()
{

	Dynamic_stack<int> dynamic_stack;

	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	 dynamic_stack.push(45);
	 dynamic_stack.push(46);
	 dynamic_stack.push(47);
	dynamic_stack.push(48);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(45);
	dynamic_stack.push(46);
	dynamic_stack.push(47);
	auto a = dynamic_stack.pop();
	dynamic_stack.push(48);
	dynamic_stack.clear();
	dynamic_stack.push(25);
	//auto j =


	return 0;
}