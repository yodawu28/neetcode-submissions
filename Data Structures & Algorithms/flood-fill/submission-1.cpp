class Solution {
public:
    vector<vector<int>> visited;
    int m = 0;
    int n = 0;

    bool check(vector<vector<int>>& image, int r, int c, int originalColor) {
        if (r < 0 || r > m - 1) {
            return false;
        }
        
        if (c < 0 || c > n - 1) {
            return false;
        }
        
        if (visited[r][c]) {
            return false;
        }
        
        if (image[r][c] != originalColor) {
            return false;
        }
        
        return true;
    }

    void run(vector<vector<int>>& image, int r, int c, int color, int originalColor) {
        image[r][c] = color;
        visited[r][c] = true;
        
        if (check(image, r + 1, c, originalColor)) {
            run(image, r + 1, c, color, originalColor);
        }
        
        if (check(image, r - 1, c, originalColor)) {
            run(image, r - 1, c, color, originalColor);
        }
        
        if (check(image, r, c + 1, originalColor)) {
            run(image, r, c + 1, color, originalColor);
        }
        
        if (check(image, r, c - 1, originalColor)) {
            run(image, r, c - 1, color, originalColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        
        for (int i = 0; i < m; i++) {
            visited.push_back({});
            for (int j = 0; j < n; j++) {
                visited[i].push_back(false);
            }
        }
        
        run(image, sr, sc, color, image[sr][sc]);
        
        return image;
    }
};