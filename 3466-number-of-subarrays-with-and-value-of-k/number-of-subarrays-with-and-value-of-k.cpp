const int MOD = 1e9+7;
const int ALL_SET = INT_MAX;

class SegmentTree {
public:
    int len;
    vector<int> t;
    SegmentTree(int l) {
        len = l;
        t.resize(4 * len);
    }

    //  BUILD segment tree build(a, 1, 0, len - 1)
    void build(vector<int>& a, int v, int tl, int tr)
    // Add a declaration or statement here
    {
        if(tl == tr) {
            t[v] = a[tl];
            return; 
        }

        int tm = (tl + tr)/2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);

        t[v] = t[2 * v] & t[2 * v + 1];
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if(tl > r || tr < l) {  //  no overlap
            return ALL_SET;
        }

        if(tl >= l && tr <= r) {    //  full overlap
            return t[v];
        }

        int tm = (tl + tr)/2;
        int left = query(2 * v, tl, tm, l, r);
        int right = query(2 * v + 1, tm + 1, tr, l, r);

        return left & right;
    }

    //  over-ridden functions
    void build(vector<int>& a) {
        build(a, 1, 0, len - 1);
    }

    int query(int l, int r) {
        return query(1, 0, len - 1, l , r);
    }

    // void update(int l, int r, int val)
    // {
    //     update(1, 0, len - 1, l, r, val);
    // }
};

class Solution {
private:
    int solve(int val, int start, int end, SegmentTree &s)
    {
        int low = start, high = end - 1;
        while(low < high)
        {
            int mid = (low + high)/2;
            if(s.query(start, mid) > val)   low = mid + 1; 
            else 
                high = mid;
        }
        return (s.query(start, low) > val )?(low + 1) : low;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
                
        int n = nums.size();
        SegmentTree s(n);
        s.build(nums);

        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int first = solve(k-1, i, n, s);
            int last = solve(k, i, n, s);

            ans += (first - last);
        }
        return ans;
    }
};