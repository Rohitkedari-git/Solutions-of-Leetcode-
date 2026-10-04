class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            // Reached a zero
            if (arr[i] == 0)
                return true;

            // Jump right
            int right = i + arr[i];

            if (right < n && !visited[right]) {
                visited[right] = true;
                q.push(right);
            }

            // Jump left
            int left = i - arr[i];

            if (left >= 0 && !visited[left]) {
                visited[left] = true;
                q.push(left);
            }
        }

        return false;
    }
};
