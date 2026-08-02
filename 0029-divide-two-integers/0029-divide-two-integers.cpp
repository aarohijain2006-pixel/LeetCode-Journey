class Solution {
public:
    int divide(int dividend, int divisor) {
       if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
       if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {
            dvd -= dvs;
            ans++;
        }
        if(ans>INT_MAX)
            return INT_MAX;
        if(ans<INT_MIN)
            return INT_MIN;

        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return ans;
    }
};