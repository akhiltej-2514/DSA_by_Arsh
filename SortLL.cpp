class Solution{
  public:
    Node * merge(Node * l1,Node * l2){
         Node *ptr = new Node(0);
        Node *curr = ptr;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->data <= l2->data)
            {
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                curr -> next = l2;
                l2 = l2 -> next;
            }
        curr = curr ->next;
        }
        if(l1 != NULL)
        {
            curr -> next = l1;
        }
        if(l2 != NULL)
        {
            curr -> next = l2;
        }
        return ptr->next;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node * fast=head;
        Node *prevmid=NULL;
        Node * slow=head;
        while(fast && fast->next){
            prevmid=slow;                   // important step store prev of slow
            slow=slow->next;
            fast=fast->next->next;
        }
        prevmid->next=NULL; // dividing into two parts first part ends here
       Node* l1=mergeSort(head);    // sort first part
        Node* l2=mergeSort(slow);  // sort second part
        return merge(l1,l2);        // merge both parts
    }
    
};

// Merge Sort on  Linked List

// intution:
// 1. find mid
// 2. divide into two parts --> important step prevmid->next=NULL; 
// 3. sort both parts
// 4. merge both parts
// 5. return head
// Time Complexity: O(nLogn) where n is the number of nodes in Linked List.
// Auxiliary Space: O(n) for linked list.