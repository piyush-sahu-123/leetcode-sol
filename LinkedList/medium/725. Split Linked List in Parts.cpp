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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count=0;
        vector<ListNode*> res;
        ListNode *rootcp=root, *rootcp2=root;
        while(rootcp!=NULL)
        {
            count++;
            rootcp=rootcp->next;
        }
        int quo=count/k;
        int rem=count%k;
        
        while(rootcp2!=NULL)
        {
            //if some remainder is there then element to be added in parts will be
            //quo else quo-1
            //this is algo, no questions
         
            int quocp1;
            if(rem>0)
                quocp1=quo;
            else
                quocp1=quo-1;
            
            res.push_back(rootcp2);
            
            //need to stop at null for node else error
            while(quocp1!=0 && rootcp2!=NULL)
            {
                rootcp2=rootcp2->next;
                quocp1--;
            }
            //making the last node of part as null so as to make it a whole part
            ListNode* cp=rootcp2;
            if(rootcp2!=NULL)
            {
                rootcp2=rootcp2->next;
                cp->next=NULL;
            }
            rem--;
            k--;
        }
        //inserting null parts in vector
        while(k>0)
        {
            
            res.push_back(NULL);
            k--;
        }
            
        return res;
    }
};
