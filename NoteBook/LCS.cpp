//заполняем массивы s1 и s2 индексами LCS из соответствующих строк (результат надо реверсировать)
void getLcsInd(vector<vector<char>> &path, vector<int> &s1, vector<int> &s2, int i, int j) {
    if(i == 0 || j == 0)
        return;
    if(path[i][j] == 'D') {
        s1.pb(i);
        s2.pb(j);
        getLcsInd(path, s1, s2, i - 1, j - 1);
    }
    else if(path[i][j] == 'L') {
        getLcsInd(path, s1, s2, i, j - 1);
    }
    else {
        getLcsInd(path, s1, s2, i - 1, j);
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<char>> path(n + 1, vector<char>(m + 1, ' '));

    // проходим по всей матрице и заполняем массив dp
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                path[i][j] = 'D';
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 'U';
            }
            else {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = 'L';
            }
        }
    }

    // получаем вектора индексов, соответствующих LCS в обоих строках
    vector<int> ind1, ind2;
    getLcsInd(path, ind1, ind2, n, m);

    cout << ind1.size() << endl;

    for(auto it = ind1.rbegin(); it != ind1.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = ind2.rbegin(); it != ind2.rend(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}