/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    /**
     * @param employees: 
     * @param id: 
     * @return: the total importance value 
     */
    unordered_map<int, Employee *> mp;

    int dfs(int id) {
        Employee *employee = mp[id];
        int total = employee->importance;
        if (employee->subordinates.empty()) return total;
        for (int subId : employee->subordinates) {
            total += dfs(subId);
        }
        return total;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        // Write your code here.
        for (auto &employee : employees) {
            mp[employee->id] = employee;
        }
        return dfs(id);
    }
}; 
