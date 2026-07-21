/*  
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:

    int getImportance(vector<Employee*> employees, int id) {
        int total = 0;

        std::unordered_map<int, Employee*> index_map;

        for(auto &Emp: employees){
           index_map[Emp->id] = Emp;
        }

        std::queue<Employee*> q;
        Employee* root = index_map[id];

        q.push(root);

        while(!q.empty()){
            
            int n = q.size();

            for(int i=0;i<n;i++) {
                Employee* node = q.front();
                q.pop();
                
                total += node->importance;

                if(node->subordinates.size()<1) continue;
                
                for(auto &child: node->subordinates){
                    q.push(index_map[child]);
                }
            }
        }

        return total;
    }
};