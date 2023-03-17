/*
Question link: https://leetcode.com/problems/falling-squares/
The maximium height can be maintained by querying the segment tree for the 
max height h in the range of the new square, and updating the entire range's 
value to h + side_length. 
Lazy propagation maintains the O(N) complexity. 
*/
#include<bits/stdc++.h> 
struct Node {
  Node *l, *r;
    int ans, lazy;//lazy is accounted for in answer, also needs to be propagated.
};
class Solution {
    Node* root;
    public:
    Node* updvals(Node *cur, int lazyProp) {
        if(cur==NULL) {
            cur=new Node();
        }
        cur->ans=lazyProp;
        cur->lazy = lazyProp;
        return cur;
    }
    void prop(Node *cur) {
        if(cur->lazy ==0) return;
        cur->l = updvals(cur->l, cur->lazy);
        cur->r = updvals(cur->r, cur->lazy);
        cur->lazy =0;
    }
    Node* update(Node *cur, int l, int r, int ql, int qr, int val) {
        if(cur == NULL) {
            cur=new Node();
            cur->lazy = cur->ans = 0;
        }
        if(l>qr||r<ql) return cur;
        if(l>=ql &&r<=qr) {
            cur->ans=val;
            cur->lazy = val;
            return cur;
        }
        prop(cur);
        int mid=(l+r)>>1; 
        cur->l = update(cur->l, l, mid, ql, qr, val);
        cur->r = update(cur->r, mid+1, r, ql, qr, val);
        cur->ans = max(cur->l->ans, cur->r->ans);
        return cur;
    }
    int query(Node *cur, int l, int r, int ql, int qr) {
        if(l>qr||r<ql || cur==NULL) return 0;
        if(l>=ql &&r<=qr) {
            return cur->ans;
        }
        prop(cur);
        int mid=(l+r)>>1; 
        return max(query(cur->l, l, mid, ql, qr), query(cur->r, mid+1, r, ql, qr));
    }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        for(auto i:positions) {
            int height =query(root, 1, 1e8, i[0], i[0] + i[1] -1);
            root=update(root, 1, 1e8, i[0], i[0] + i[1] -1, height+i[1]);
         //   printf("ql=%d, qr=%d, val=%d height =%d \n", i[0], i[0] + i[1] -1, i[1], height);
            ans.push_back(root->ans);
        }
        return ans;
    }
};
