class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m, n) / 2;

        for (int layer = 0; layer < layers; layer++) {

            vector<int> v;

            int top = layer;
            int bottom = m - layer - 1;
            int left = layer;
            int right = n - layer - 1;

            // Top row: left -> right
            for (int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            // Right column: top+1 -> bottom
            for (int i = top + 1; i <= bottom; i++)
                v.push_back(grid[i][right]);

            // Bottom row: right-1 -> left
            for (int j = right - 1; j >= left; j--)
                v.push_back(grid[bottom][j]);

            // Left column: bottom-1 -> top+1
            for (int i = bottom - 1; i > top; i--)
                v.push_back(grid[i][left]);

            // Number of elements in this layer
            int len = v.size();

            // Counter-clockwise rotation by k
            int shift = k % len;

            // Put rotated values back

            int idx = shift;

            // Top row
            for (int j = left; j <= right; j++) {
                grid[top][j] = v[idx];
                idx = (idx + 1) % len;
            }

            // Right column
            for (int i = top + 1; i <= bottom; i++) {
                grid[i][right] = v[idx];
                idx = (idx + 1) % len;
            }

            // Bottom row
            for (int j = right - 1; j >= left; j--) {
                grid[bottom][j] = v[idx];
                idx = (idx + 1) % len;
            }

            // Left column
            for (int i = bottom - 1; i > top; i--) {
                grid[i][left] = v[idx];
                idx = (idx + 1) % len;
            }
        }

        return grid;
    }
};
