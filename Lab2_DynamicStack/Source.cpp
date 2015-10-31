
#include "Dynamic_stack.h"


using namespace std;

int main()
{
	int qwe = 123;
	int wer = 234;


	int* m = new int[5];
	m[0] = 987;
	m[1] = 598;

	auto tt = m[1];


	Dynamic_stack<int> dynamic_stack;
	auto a = dynamic_stack.capacity();
	auto b = dynamic_stack.size();
	auto c = dynamic_stack.empty();
	
	 dynamic_stack.push(45);
	 dynamic_stack.push(46);
	 dynamic_stack.push(47);
	dynamic_stack.push(48);
	auto h = dynamic_stack.pop();
	auto i = dynamic_stack.pop();
	//auto j =


	return 0;
}