/*****************************************
* Instructions
*  - Replace 'uwuserid' with your uWaterloo User ID
*  - Select the current calendar term and enter the year
*  - List students with whom you had discussions and who helped you
*
* uWaterloo User ID:  l43cheng @uwaterloo.ca
* Submitted for ECE 250
* Department of Electrical and Computer Engineering
* University of Waterloo
* Calender Term of Submission:  (Fall) 2015
*
* By submitting this file, I affirm that
* I am the author of all modifications to
* the provided code.
*
* The following is a list of uWaterloo User IDs of those students
* I had discussions with in preparing this project:
*    -
*
* The following is a list of uWaterloo User IDs of those students
* who helped me with this project (describe their help; e.g., debugging):
*    -
*****************************************/
#include <stdexcpt.h>

#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#ifndef nullptr
#define nullptr 0
#endif


//#include "Exception.h"


template <typename Type>
class Dynamic_stack {
private:
	int entry_count;		//size of stack
	int initial_capacity;	//capacity of stack cannot be smaller than this
	int array_capacity;		//maximum number of items stack can store
	Type* array[10];			//use array to hold stack

public:
	Dynamic_stack(int = 10);
	Dynamic_stack(Dynamic_stack const &);
	~Dynamic_stack();

	Type top() const;		//return object at top of stack. Can throw underflow exception if stack is empty
	int size() const;		//return number of elements in stack
	bool empty() const;		//return true if stack is empty, false if non-empty
	int capacity() const;	//return maximum number of elements stack can store

	void swap(Dynamic_stack &);
	Dynamic_stack &operator=(Dynamic_stack const &);
	void push(Type const &);//push object to the top of the stack
	Type pop();				//pops the top element off the stack
	void clear();			//remove all elements from stack. Array is set to initial_capacity
};


template <typename Type>
Dynamic_stack<Type>::Dynamic_stack(int n) :
entry_count(0),
initial_capacity(n),
array_capacity(n) {
	//array = /*new Type[array_capacity];*/ array[array_capacity];
}

template <typename Type>
Dynamic_stack<Type>::Dynamic_stack(Dynamic_stack const &stack) :
entry_count(stack.entry_count),
initial_capacity(stack.initial_capacity),
array_capacity(stack.array_capacity),
array(new Type[array_capacity]) {
	// The above initializations copy the values of the appropriate
	// member variables and allocate memory for the data structure;
	// however, you must still copy the stored objects.

	// Enter your implementation here.
}

template <typename Type>
Dynamic_stack<Type>::~Dynamic_stack() {
	delete[] array;
}




/* Returns the top element of the stack. Can throw underflow error. */
template <typename  Type>
Type Dynamic_stack<Type>::top() const {
	if (entry_count == 0) throw std::exception("THERE ARE NO ELEMENTS IN THE STACK. NO ELEMENTS TO SHOW. MUHAHAHAHA!!!");
	return array[entry_count - 1];;
}

/* Returns the number of elements in the stack */
template <typename Type>
int Dynamic_stack<Type>::size() const {
	return entry_count;
}

/* Returns true if the stack is empty, false otherwise */
template <typename Type>
bool Dynamic_stack<Type>::empty() const {
	//(entry_count == 0) ? return true; : return false;
	if (entry_count == 0)
	{
		return true;
	}
	else { return false; }
}

/* Returns the current size of the stack */
template <typename Type>
int Dynamic_stack<Type>::capacity() const {
	return array_capacity;
}

template <typename Type>
void Dynamic_stack<Type>::swap(Dynamic_stack<Type> &stack) {
	std::swap(entry_count, stack.entry_count);
	std::swap(initial_capacity, stack.initial_capacity);
	std::swap(array_capacity, stack.array_capacity);
	std::swap(array, stack.array);
}

template <typename Type>
Dynamic_stack<Type> &Dynamic_stack<Type>::operator=(Dynamic_stack<Type> const &rhs) {
	Dynamic_stack<Type> copy(rhs);
	swap(copy);
	return *this;
}

/* Adds an element to the top of the stack. Size of array is doubled if the array is already full before adding */
template <typename Type>
void Dynamic_stack<Type>::push(Type const &obj) {

	//if array is already full, make a new one double in size, pointer points to it, 
	if (entry_count == array_capacity)
	{
		Type* new_array = new Type[2 * array_capacity];
		for (int i = 0; i < array_capacity; i++)
		{
			new_array[i] = array[i];
			delete[] array;
			array = new_array;
		}
	}

	entry_count++;
	array[entry_count] = obj;

}

/*  Removes the top element on the stack. Throws underflow exception if stack if empty. 
	If after popping the top element, the array is 1/4 or less the size of initial_capacity, then halve the array
	The array's size cannot be less than initial_capacity */
template <typename Type>
Type Dynamic_stack<Type>::pop() {
	if (entry_count == 0) throw std::exception("UNDERFLOW. ARRAY ALREADY HAS 0 ELEMENTS. MUHAHAHAHAHA!");

	Type top_element = array[entry_count - 1];
	array[entry_count - 1] = NULL;								//QUESITONABLE????????????????????????????????????????????????????????
	entry_count--;

	//resize array if necessary
	if (entry_count <= array_capacity / 4)
	{
		//if the new array would have less than initial_capacity elements, make it have initial_capacity
		if (array_capacity / 4 < 10) 
		{ 
			Type* new_array = new Type[initial_capacity];
			for (int i = 0; i < entry_count; i++)
			{
				new_array[i] = array[i];
				delete[] array;
				array = new_array;
			}
			array_capacity = initial_capacity; 
		}

		//if the new array would have more than initial_capacity, resize it to a quarter its size
		else
		{
			Type* new_array = new Type[array_capacity/4];
			for (int i = 0; i < entry_count; i++)
			{
				new_array[i] = array[i];
				delete[] array;
				array = new_array;
			}
			array_capacity = array_capacity / 4;
		}
	}

	return top_element;
}

//resize array refactor


template <typename Type>
void Dynamic_stack<Type>::clear() {
	delete[] array;
	array = new Type[initial_capacity];
	array_capacity = initial_capacity;
	entry_count = 0;
}

#endif