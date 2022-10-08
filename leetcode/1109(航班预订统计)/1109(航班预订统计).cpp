class Solution {

public:
long long sum[4*20000+10];
long long add[4*20000+10];

void up(int rt){
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void down(int rt, int len){
    if(add[rt]){
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * static_cast<long long>(len - (len>>1));
        sum[rt<<1|1] += add[rt] * static_cast<long long>(len>>1);
        add[rt] = 0;
    }
}

void update(int rt, int l, int r, int x, int y, int v){
    if(x<=l && r<=y){
        sum[rt] += static_cast<long long>(v) * static_cast<long long>(r-l+1);
        add[rt] += v;
    }
    else{
        down(rt, r-l+1);
        int mid = (l+r)>>1;
        if(x<=mid) update(rt<<1, l, mid, x, y, v);
        if(mid<y) update(rt<<1|1, mid+1, r, x, y, v);
        up(rt);
    }
}

long long query(int rt, int l, int r, int x, int y){
    if(x<=l && r<=y){
        return sum[rt];
    }
    else{
        int mid = (l+r)>>1;
        long long retval = 0;
        down(rt, r-l+1);
        if(x<=mid) retval = query(rt<<1, l, mid, x, y);
        if(mid<y) retval += query(rt<<1|1, mid+1, r, x, y);
        up(rt);
        return retval;
    }
}


public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        memset(sum, 0, size(sum));
        memset(add, 0, size(add));
        for(auto &x : bookings){
            int l = x[0];
            int r = x[1];
            int v = x[2];
            update(1, 1, n, l, r, v);
        }

        vector<int> ans;
        for(int i=1; i<=n; ++i){
            long long retval = query(1, 1, n, i, i);
            ans.push_back(static_cast<int>(retval));
        }
        return ans;

    }
};