# 733. Flood Fill
[Flood Fill - LeetCode](https://leetcode.com/problems/flood-fill/)

An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

## BFS
- original
    - Time: O(m*n)
    - Space: O(m*n)
    
    ```cpp    
    class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            if (image.size() == 0) return image;
            
            int rows = image.size();
            int cols = image[0].size();
            vector<vector<bool>> visted(rows, vector<bool>(cols, false));
            int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            int original_color = image[sr][sc];
            queue<pair<int, int>> q;
            q.push(make_pair(sr, sc));
            visted[sr][sc] = true;
            
            while(!q.empty()) {
                int cur_r = q.front().first;
                int cur_c = q.front().second;
                image[cur_r][cur_c] = color;
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int next_r = cur_r + dir[d][0];
                    int next_c = cur_c + dir[d][1];
                    if (next_r < 0 || next_r >= rows 
                        || next_c < 0 || next_c >= cols 
                        || visted[next_r][next_c] 
                        || image[next_r][next_c] != original_color) {
                        
                        continue;
                    }
                    
                    q.push(make_pair(next_r, next_c));
                    visted[next_r][next_c] = true;   
                }
            }
            
            return image;
        }
    };
    ```
    
- Optimized
    - The vector for recording visited cell is not needed. We determine if the colors of the neighbors are the same with the color in initial cell. However, when the original color is same with the new color, we need to return the original image right away, otherwise, the program will not be ended.
    
    ```cpp
    class Solution {
    public:    
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            if (image.size() == 0) return image;
            
            int rows = image.size();
            int cols = image[0].size();
            int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            
            int original_color = image[sr][sc];
            if (original_color == color) return image;
            
            queue<pair<int, int>> q;
            q.push(make_pair(sr, sc));
            image[sr][sc] = color;
            
            while(!q.empty()) {
                int cur_r = q.front().first;
                int cur_c = q.front().second;
                q.pop();
                
                for (int d = 0; d < 4; d++) {
                    int next_r = cur_r + dir[d][0];
                    int next_c = cur_c + dir[d][1];
                    if (next_r < 0 || next_r >= rows 
                        || next_c < 0 || next_c >= cols) {
                        continue;
                    }
                    if (image[next_r][next_c] == original_color) {
                        q.push(make_pair(next_r, next_c));
                        image[next_r][next_c] = color;
                    }
                }
            }
            
            return image;
        }
    };
    ```