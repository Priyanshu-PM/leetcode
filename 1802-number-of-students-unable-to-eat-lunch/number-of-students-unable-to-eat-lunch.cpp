class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        queue<int> q;
        for(int stud: students) q.push(stud);
        for(int index = 0; index < sandwiches.size(); index++)
        {
            bool take = false;
            int counter = q.size();
            while(counter--)
            {
                int stud = q.front();
                if(stud == sandwiches[index])
                {
                    take = true;
                    q.pop();
                    break;
                }
                else
                {
                    q.pop();
                    q.push(stud);
                }
            }

            if(!take) {
                return q.size();
            }
        }   
        return 0;
    }
};