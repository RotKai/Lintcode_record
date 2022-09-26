class Solution {
public:
    bool find_prime(int n){
        for (int i = 2; i * i <= n; ++i ){
            if (n % i == 0){
                return false;       
            }
        }
        return true;
    }

    int kthPrime(int n) {
        int ans = 0;
        for (int i=2; i <= n; ++i){
            if (find_prime(i))
                ans ++;
            if (i == n)
                return ans;
        }
        return -1;
    }

};
