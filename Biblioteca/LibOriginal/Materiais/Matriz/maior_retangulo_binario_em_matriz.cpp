// Description: Encontra o maior retângulo binário em uma matriz.
// Time: O(n*m)
// Space: O(n*m)
tuple<int, int, int> maximalRectangle(vector<vector<int>>& mat) {
    int r = mat.size();
    if(r == 0) return {0, 0, 0};
    int c = mat[0].size();

    vector<vector<int>> dp(r+1, vector<int>(c));

    int mx = 0;
    int area = 0, height = 0, length = 0;
    for(int i=1; i<r; ++i) {
        int leftBound = -1;
        stack<int> st;
        vector<int> left(c);

        for(int j=0; j<c; ++j) {
            if(mat[i][j] == 1) {
                mat[i][j] = 1+mat[i-1][j];
                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = leftBound;
                if(!st.empty())
                    val = max(val, st.top());

                left[j] = val;
            } else {
                leftBound = j;
                left[j] = 0;
            }
            st.push(j);
        }
        while(!st.empty()) st.pop();

        int rightBound = c;
        for(int j=c-1; j>=0; j--) {
            if(mat[i][j] != 0) {

                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = rightBound;
                if(!st.empty())
                    val = min(val, st.top());

                dp[i][j] = (mat[i][j]) * (((val-1)-(left[j]+1)+1));
                if (dp[i][j] > mx) {
                    mx = dp[i][j];
                    area = mx;
                    height = mat[i][j];
                    length = (val-1)-(left[j]+1)+1;
                }
                st.push(j);
            } else {
                dp[i][j] = 0;
                rightBound = j;
            }
        }
    }

    return {area, height, length};
}
    int r = mat.size();
    if(r == 0) return make_tuple(0, 0, 0);
    int c = mat[0].size();

    vector<vector<int>> dp(r+1, vector<int>(c));

    int mx = 0;
    int area = 0, height = 0, length = 0;
    for(int i=1; i<r; ++i) {
        int leftBound = -1;
        stack<int> st;
        vector<int> left(c);

        for(int j=0; j<c; ++j) {
            if(mat[i][j] == 1) {
                mat[i][j] = 1+mat[i-1][j];
                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = leftBound;
                if(!st.empty())
                    val = max(val, st.top());

                left[j] = val;
            } else {
                leftBound = j;
                left[j] = 0;
            }
            st.push(j);
        }
        while(!st.empty()) st.pop();

        int rightBound = c;
        for(int j=c-1; j>=0; j--) {
            if(mat[i][j] != 0) {

                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = rightBound;
                if(!st.empty())
                    val = min(val, st.top());

                dp[i][j] = (mat[i][j]+1) * (((val-1)-(left[j]+1)+1)+1);
                if (dp[i][j] > mx) {
                    mx = dp[i][j];
                    area = mx;
                    height = mat[i][j];
                    length = (val-1)-(left[j]+1)+1;
                }
                st.push(j);
            } else {
                dp[i][j] = 0;
                rightBound = j;
            }
        }
    }

    return make_tuple(area, height, length);
}