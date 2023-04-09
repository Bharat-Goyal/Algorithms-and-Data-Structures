//https://leetcode.com/problems/spiral-matrix-iv/description/
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
 #define pii pair<int, int>
 #define f first
 #define s second
 #define mp make_pair
class Solution {
public:
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> ret;
        for(int i=1;i<=n;i++) {
            vector<int> temp(m, -1);
            ret.push_back(temp);
        }
        int i1=0, i2=0;
        pii diff = {0, 1};
        int ind = 0;
        pii diffs[4];
        diffs[0] = mp(0, 1);
        diffs[1] = mp(1, 0);
        diffs[2] = mp(0, -1);
        diffs[3] = mp(-1, 0);
        int numDone=0;
        while(head != NULL && numDone<n*m) {
            ret[i1][i2] = head->val;
            head = head->next;
            numDone++;
            i1 += diff.f;i2 += diff.s;
            if(i1<0 || i1>=n || i2<0 || i2>=m || ret[i1][i2] != -1) {
                i1 -= diff.f;i2 -= diff.s;
                ind++;ind&=3;
                diff = diffs[ind];
                i1 += diff.f;i2 += diff.s;
            } 
        }
        return ret;
    }
};
