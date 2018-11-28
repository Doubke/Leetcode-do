/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} //结构体的构造函数，与类的构造函数相同，冒号后面的是初始化列表，也就是给成员val初始化为传入的参数x，next初始化为NULL 
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) { //声明一个返回类型为ListNode*的函数addTwoNumbers，参数为ListNode*L1，*L2
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h; //t是h指针的地址 *t是h的值 **t是h的值 
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);            
            sum = carry + x + y;           
            ListNode *node = new ListNode(sum%10);//开辟一个存放ListNode类型变量的空间，并指定变量未sum%10，返回一个指向该存储空间的地址，*node即值为sum%10的地址
            *t = node; //将node指针赋值给t
            t = (&node->next); //t变为node的下一个地址
            carry = sum/10;
        }        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next; //l指向下一个节点
        }
        return x;
    }
};