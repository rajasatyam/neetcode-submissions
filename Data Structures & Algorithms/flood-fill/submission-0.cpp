class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        int curr = image[sr][sc];
        int dx[4] = {1 , 0 , -1 , 0};
        int dy[4] = {0 , 1 , 0 , -1};
        int m = image.size() , n = image[0].size();
        queue<pair<int , int>> pq;
        image[sr][sc] = color;
        pq.push({sr , sc});

        while(!pq.empty()){
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == curr){
                    image[nx][ny] = color;
                    pq.push({nx , ny});
                }
            }
        }
        return image;
    }
};