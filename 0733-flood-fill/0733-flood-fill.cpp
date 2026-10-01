 class Solution {
private:
    void dfs(int row, int col,
             vector<vector<int>>& image,
             int newColor,
             int iniColor,
             int drow[],
             int dcol[]) {

        image[row][col] = newColor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor &&
                image[nrow][ncol] != newColor) {

                dfs(nrow, ncol, image, newColor,
                    iniColor, drow, dcol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc,
                                   int newColor) {

        int iniColor = image[sr][sc];

        // If the color is already the same, nothing to do
        if (iniColor == newColor)
            return image;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, newColor,
            iniColor, drow, dcol);

        return image;
    }
};