class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>visited(n,0);
        visited[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()) {
            int idx=q.front();
            q.pop();
            if(arr[idx]==0) return true;
            int leftIndex=idx-arr[idx];
            int rightIndex=idx+arr[idx];
            if(leftIndex>=0 && !visited[leftIndex]) {
                visited[leftIndex]=1;
                q.push(leftIndex);
            }
            if(rightIndex<n && !visited[rightIndex]) {
                visited[rightIndex]=1;
                q.push(rightIndex);
            }
        }
        return false;
    }
};