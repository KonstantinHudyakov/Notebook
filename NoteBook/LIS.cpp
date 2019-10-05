// LIS O(n^2)
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // dp[i] - длина LIS, заканчивающейся на элементе v[i]
    vector<int> dp(n);
    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // ищем максимальную длину LIS
    int m = 1;
    for(auto &it : dp) {
        m = max(m, it);
    }
    cout << m << endl;

    return 0;
}