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
    smaller = nullptr;
    larger = nullptr;
    return;
  }
  
  //checks if value in head is larger than pivot. If it is, passes into larger list
  else if(head->val > pivot)
  {
    larger = head;
    // larger->next = nullptr;
    head = head->next;
    llpivot(head, smaller, larger->next, pivot);
  }

  //checks if value in head is smaller or equal to pivot. If it is, passes into smaller list
  else if(head->val <= pivot)
  {
    smaller = head;
    // smaller->next = nullptr;
    head = head->next;
    llpivot(head, smaller->next, larger, pivot);
  }
 
}




