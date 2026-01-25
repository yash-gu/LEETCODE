class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = (ans << 1) + head->val;  // ans*2 + bit
            head = head->next;
        }
        return ans;
    }
};
