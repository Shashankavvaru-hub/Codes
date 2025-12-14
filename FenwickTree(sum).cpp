class Fenwick {
private:
    int n;
    vector<long long> bit;   // internal tree (private)

public:
    Fenwick(int _n) {
        n = _n;
        bit.assign(n + 1, 0);  // 1-indexed
    }

    // add delta to index i
    void update(int i, long long delta) {
        for (; i <= n; i += (i & -i))
            bit[i] += delta;
    }

    // prefix sum 1..i
    long long prefix_sum(int i) {
        long long s = 0;
        for (; i > 0; i -= (i & -i))
            s += bit[i];
        return s;
    }

    // sum on [l, r]
    long long range_sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    // optional: build from array arr[1..n]
    void build_from_array(vector<long long> &arr) {
        for (int i = 1; i <= n; ++i) bit[i] += arr[i];
        for (int i = 1; i <= n; ++i) {
            int j = i + (i & -i);
            if (j <= n) bit[j] += bit[i];
        }
    }

    long long lowerBound(long long k) {
        long long total = prefix_sum(n);
        if (k > total) return 0;      // not found
        int curr = 0;
        long long prevsum = 0;        // must be long long
        for (int i = log2(n); i >= 0; i--) {
            int next = curr + (1 << i);
            // bounds check
            if (next <= n) {
                // if taking this step still keeps prefix sum < k
                if (prevsum + bit[next] < k) {
                    prevsum += bit[next];
                    curr = next;
                }
            }
        }
        return curr + 1;
    }

};

