/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} //�ṹ��Ĺ��캯��������Ĺ��캯����ͬ��ð�ź�����ǳ�ʼ���б�Ҳ���Ǹ���Աval��ʼ��Ϊ����Ĳ���x��next��ʼ��ΪNULL 
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) { //����һ����������ΪListNode*�ĺ���addTwoNumbers������ΪListNode*L1��*L2
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h; //t��hָ��ĵ�ַ *t��h��ֵ **t��h��ֵ 
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);            
            sum = carry + x + y;           
            ListNode *node = new ListNode(sum%10);//����һ�����ListNode���ͱ����Ŀռ䣬��ָ������δsum%10������һ��ָ��ô洢�ռ�ĵ�ַ��*node��ֵΪsum%10�ĵ�ַ
            *t = node; //��nodeָ�븳ֵ��t
            t = (&node->next); //t��Ϊnode����һ����ַ
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
            l = l->next; //lָ����һ���ڵ�
        }
        return x;
    }
};