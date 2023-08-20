/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *t,*t2,*last,*f=l1,*s=l2;
      last = NULL;      
     int x,flag=0,n=0;
      while(f &&s){
            if(flag==1){
             x = f->val +s->val+n;
            }
            else{
                  x = f->val +s->val;
            }
            if(!f->next && !s->next ){
                  if(last==NULL){
                        t=new ListNode;
                        t2=t;
                        last=t2;
                  }
                  else{
                        t = new ListNode;
                  }
                  // x+=n;
                   if(x<=9){
                        t->val=x;
                        t->next=NULL;
                        if(last!=t2){
                        last->next=t;}
                        return t2;
                  }
                  else{
                  t->val = x%10;
                  last->next=t;
                  last=t;
                  t=new ListNode;
                  t->val=x/10;
                  t->next=NULL;
                  last->next=t;
                  return t2;}

            }
            if(x<=9){
                  t = new ListNode;
                  // flag==1?t->val= n+x: t->val=x;
                  t->val=x;
                  t->next=NULL;
                  if(last==NULL){
                        t2 = t;
                        last=t;
                  }
                  else{
                        last->next=t;
                        last=t;}
             flag=0;
             n=0;      
            }
            else{
                  t = new ListNode;                      
                  if(!f->next && !s->next){
                        // flag==0?t->val = x:t->val=n+x;
                        t->val=x;
                  }
                  else{
                  // flag==0?t->val = x%10:t->val=n+x%10;}
                  t->val=x%10;}
                  t->next=NULL;
                  flag=1;
                  n=x/10;
                  if(last==NULL){
                        t2 = t;
                        last=t;
                  }
                  else{
                        last->next=t;
                        last=t;
                  }         
            }
            f=f->next;
            s =s->next;
      }
        if(f!=NULL || s!=NULL){
          flag=1;
      }
      else{
          flag=0;
      }
      if(flag){
      ListNode *p;
      if(f) p=f;
      else p=s;
    
      while(p){
            
           t = new ListNode;
           x=p->val+n;
          
           if(x>9){
            t->val=x%10;
            n=x/10;
             }
             else{
                  t->val=x;
                  n=0;
             }
           t->next=NULL;
           last->next=t;
           last=t;
           if(!p->next && n!=0){
            t=new ListNode;
            t->val =n;
            t->next=NULL;
            last->next=t;
            last=t;
           }
           p=p->next;
      }}

    
      
      return t2;
        
    }
};
