#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> v;
  int m;
  PComparator c;

};

// Add implementation of member functions here
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c ){
  this->m = m;
  this->c = c;
  v.push_back(T());
}

template <typename T, typename Comparator>
Heap<T,Comparator>::~Heap(){
}

template <typename T, typename Comparator>
bool Heap<T,Comparator>::empty() const{
  return size() == 0;
}

template <typename T, typename Comparator>
size_t Heap<T,Comparator>::size() const{
 return v.size()-1;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    throw std::underflow_error("Heap is Empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
    return v[1]; 

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("Heap is Empty");

  }
  else
  {
    v[1] = v[v.size()-1];
    v.pop_back(); 
    int parentIndex = 1; 
    int leftChildIndex = 2;
    int rightChildIndex = 3; 

    while(leftChildIndex < (int)v.size())
    {
      if(rightChildIndex>=(int)v.size() || c(v[leftChildIndex], v[rightChildIndex]))
      {
        if(c(v[leftChildIndex], v[parentIndex]))
        {
          T temp = v[parentIndex]; 
          v[parentIndex] = v[leftChildIndex]; 
          v[leftChildIndex] = temp;

          parentIndex = leftChildIndex; 
          leftChildIndex = parentIndex*2;
          rightChildIndex = leftChildIndex+1;  
        }
        else{
          break;
        }
      }
      else
      {
        if(c(v[rightChildIndex], v[parentIndex]))
        {
          T temp = v[parentIndex]; 
          v[parentIndex] = v[rightChildIndex]; 
          v[rightChildIndex] = temp; 

          parentIndex = rightChildIndex; 
          leftChildIndex = parentIndex*2;
          rightChildIndex = leftChildIndex+1;
        }
        else{
          break;
        }
      } 
    }
  }

}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  v.push_back(item);
  int currInd = v.size()-1;
  int parentInd = currInd/2;
  while(parentInd>0){
    if(c(v[currInd], v[parentInd])){
      T temp = v[parentInd];
      v[parentInd] = v[currInd];
      v[currInd] = temp;
      currInd = parentInd;
      parentInd /= 2;
    }
    else{
      break;
    }
  }

}



#endif

