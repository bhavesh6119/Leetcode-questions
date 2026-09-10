class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    int r;
    int c;
    bool valid(int i,int j){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void DFS(vector<vector<int>>&image,int original,int i ,int j,int color){
        for(int k=0;k<4;k++){
            int newi=i+row[k];
            int newj=j+col[k];
            if(valid(newi,newj) && image[newi][newj]==original){
                image[i+row[k]][j+col[k]]=color;
                DFS(image,original,newi,newj,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        r=image.size();
        c=image[0].size();
        int original=image[sr][sc];
        if(original==color){
            return image;
        }
        image[sr][sc]=color;
        DFS(image,original,sr,sc,color);
        return image;
    }
};