#include "llrec.h"
#include <iostream>
//*********************************************
// Provide your implementation of llpivot below
//*********************************************


using namespace std; 

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if(head == nullptr)
  {
    return;
  }
  
  //checks if value in head is larger than pivot. If it is, passes into larger list
  else if(head->val > pivot)
  {
    larger->next = head;
    larger = larger->next;
    larger->next = nullptr; 

  }

  //checks if value in head is smaller or equal to pivot. If it is, passes into smaller list
  else if(head->val <= pivot)
  {
    smaller->next = head;
    smaller = smaller->next;
    smaller->next = nullptr;
  }

//recursive function that calls itself to pivot Linked List
  llpivot(head->next, smaller, larger, pivot);

  head = nullptr; 
  
}




