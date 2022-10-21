#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : public std::vector<T> 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private:
    int sizeOfStack;
};

//Last in First Out (LIFO)
//Top variable
//push = adds to the top
//Create a vector that stores all variables 

//Constructor 
template<typename T>
Stack<T>::Stack() {

    sizeOfStack = 0; 

}

//Size
template<typename T>
size_t Stack<T>::size() const {

	return sizeOfStack;

}

//top 
template<typename T> 
const T& Stack<T>::top() const
{
    if (sizeOfStack == 0)
    {
        throw std::underflow_error("Stack is Empty"); 
    }
		
	else
    {
        return this[sizeOfStack-1]; 
    }
}

//Push
template<typename T>
void Stack<T>::push(const T& item) {

    if(sizeOfStack == std::vector<T>::size())
    {
        std::vector<T>::push_back(item);
    }
    else
    {
        this[sizeOfStack] = item;
        
    }

    sizeOfStack++;  
}


//Pop
template<typename T>
void Stack<T>::pop() {
	if (sizeOfStack == 0)
    {
        throw std::underflow_error("Stack is Empty"); 
    }
		
	else
    {
        sizeOfStack--; 
    }
		
}

//Empty
template<typename T>
bool Stack<T>::empty() const {
    if(sizeOfStack == 0)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}








#endif