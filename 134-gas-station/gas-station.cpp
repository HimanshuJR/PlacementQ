class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
       long long int totalgas =0; long long int totalcost = 0;
       for( int i =0 ;i< n;i++){
        totalgas+= gas[i]; totalcost+= cost[i];
       }
       if( totalcost > totalgas ) return -1;
       int start = 0;
       int remaining_gas = 0;

       for(int i = 0;i< n;i++){
        remaining_gas += (gas[i] - cost[i]);
        if( remaining_gas < 0){
            start = i+1;
            remaining_gas = 0;


        }

       }
       return start;
    }
};