class NumArray 
{
    public:
    bool _ = []{ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);return false;}();  
    #define ll long long 
    struct segtree 
    {
          int size;
          vector < ll > sums; 
          void intial(int n)
          {
              size = 1;
              while(size < n) size *= 2;
              sums.assign(2 * size, 0ll);
          }
        void build(vector < int >& nums, int x, int lx, int rx)
        {
            if(lx >= nums.size()) return;
            if(rx == lx) sums[x] = nums[lx];
            else 
            {
                int m = (rx + lx) / 2;
                build(nums, 2 * x + 1, lx, m);
                build(nums, 2 * x + 2, m + 1, rx);
                sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
            }
        }
        void build(vector < int >& nums)
        {
            build(nums, 0, 0, size - 1);
        }
        void set(int i, int v, int x, int lx, int rx)
        {
            if(rx == lx) sums[x] = v;
            else 
            {
                int m = (rx + lx) / 2;
                if(i <= m) set(i, v, 2 * x + 1, lx, m);
                else set(i, v, 2 * x + 2, m + 1, rx);
                sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
            }
        }
        void set(int i, int v)
        {
            set(i, v, 0, 0, size - 1);
        }
        ll query(int l, int r, int x, int lx, int rx)
        {
            if(lx > r || l > rx) return 0;
            if(lx >= l && rx <= r) return sums[x];
            int m = (lx + rx) / 2;
            return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m + 1, rx);
        }
          ll query(int l, int r)
          {
              return query(l, r - 1, 0, 0, size - 1);
          }
   };
    segtree st;
    
    NumArray(vector<int>& nums)
    {
        st.intial(nums.size());
        st.build(nums);
    }
    
    void update(int index, int val) 
    {
        st.set(index, val);
    }
    
    int sumRange(int left, int right) 
    {
        return st.query(left, right + 1);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
