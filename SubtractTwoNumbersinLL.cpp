Node *reverse(Node * cur){
    Node *prev=NULL,*nxt=NULL;
    while(cur){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
    
}

Node* subLinkedList(Node* l1, Node* l2){

if(l1==NULL) return l2;
if(l2==NULL) return l1;
while(l1!=NULL){
        if(l1->data!=0){
            break;
        }
        else
        l1=l1->next;
    }
    while(l2!=NULL){
        if(l2->data!=0){
            break;
        }
        else
        l2=l2->next;
    }
int length1=0,length2=0;
Node *cur1=l1,*cur2=l2;
while(cur1){
    length1++;
    cur1=cur1->next;
}
while(cur2){
    length2++;
    cur2=cur2->next;
}
 Node *large,*small;
if(length1>length2){
    large=l1;
    small=l2;
}
else if(length2>length1){
    large=l2;
    small=l1;
}
else if(length1==length2){
    int larger =0;  // =1 means 1 is larger ,2 means 2 is larger
    cur1=l1; cur2=l2; 
    while(cur1){
        if(cur1->data > cur2->data){
            larger=1;
            break;
        }
        else if(cur2->data>cur1->data){
            larger=2;
            break;
        }
        cur1=cur1->next; cur2=cur2->next;
    }
    if(larger==1){
        large=l1; small=l2;
    }
    if(larger==2){
        large=l2; small=l1;
    }
    if(larger==0){  /// if both lists are same  returning 0 node but chk what should be returned
        Node * head= new Node(0);
        return head;
    }
}
// adding extra 0s in front of smaller one

    int dif=abs(length1-length2); 
if(dif!=0){
    Node * zerohead=new Node(0);
    Node* zerotail=zerohead;
    while(dif>1){
        Node * zeroadd=new Node(0);
        zerotail->next=zeroadd;
        zerotail=zerotail->next;
        dif--;
    }
    zerotail->next=small;
    small=zerohead;
}
// now we reverse both the lists;
cur1= reverse(large);    cur2=reverse(small);
int carry=0;
Node* l3head =new Node(-1);
Node *l3=l3head;
while(cur1!=NULL && cur2!=NULL){
    int a=cur1->data,b=cur2->data;
    if(a-carry<b){
        Node *temp = new Node((a+10-carry)-b);   /// + here (not multipy 6*10=60 not 16)
        carry=1;
         l3->next=temp;
    }
    else{
        Node *temp =new Node(a-carry-b);
        carry=0;
        l3->next=temp;
    }
    cur1=cur1->next;
    cur2=cur2->next;
    l3=l3->next;
}
    l3=reverse(l3head->next);
    while(l3!=NULL){
        if(l3->data!=0){
            break;
        }
        else
        l3=l3->next;
    }
    return l3;
}

/* find length of both Linked lists, then  added zeroes in front of smaller sized LL.

2. now find the larger number in LL, if length is not same , we get the larger LL but if size is same, we see which has a greater integer initally .

3. Now reverse both LLs and make a new LL l3 to store the differnce, used a carry integer to chk if we need borrow from the next integer or not . example:

L1=0->5->1 , L2=1->5->0   (after reversing)

 int a=l1->data,b=l2->data;
    if(a-carry<b){
        Node *temp = new Node((a+10-carry)-b);   /// + here (not multipy 6*10=60 not 16)
        carry=1;
         l3->next=temp;
    }
    else{
        Node *temp =new Node(a-carry-b);
        carry=0;
        l3->next=temp;
    }
    l1=l1->next;
    l2=l2->next;
    l3=l3->next;

reverse the l3 to get the answer */