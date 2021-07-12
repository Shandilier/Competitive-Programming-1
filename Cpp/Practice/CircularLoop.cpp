class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        for(int i=0;i<n;++i){
            if(visited[i]) continue;   //no need to consider visited index again, since this is not part of cycle.
            vector<bool> current_visited(n, false);
            if(has_cycle(nums, current_visited, i)){  //check if i can lead to cycle or not
                return true;
            }
            else{
                for(int j=0;j<n;++j){
                    if(current_visited[j]) visited[j] = current_visited[j];  //all index involved in this iteration do not involved in cycle
                }
            }
        }
        return false;
    }
    int get_next(vector<int> &nums, int current_index){
        int next_index = (current_index + nums[current_index] + nums.size())%nums.size();  // +n to make it positive.
        return next_index; 
    }

    bool has_cycle(vector<int> &nums, vector<bool> &visited, int i){
        int next = get_next(nums, i);
        
        visited[i] = true;
        
        if(next == i){ //single length loop, false by definition
            return false;
        }
        
        if(nums[next] > 0 != nums[i] > 0) //for single direction cycle, every element of cycle must be +ve or -ve.
            return false;
        if(visited[next]) //already visited, cycle detected
            return true; 

        return has_cycle(nums, visited, next);
    }
    
};