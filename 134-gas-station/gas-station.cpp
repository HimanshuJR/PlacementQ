#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int currentGas = 0;
        int start = 0;

        // Calculate the total gas and total cost
        for (int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];
            
            // If current gas is less than 0, reset the starting point
            if (currentGas < 0) {
                start = i + 1;
                currentGas = 0;
            }
        }

        // If the total gas is less than the total cost, it's not possible to complete the circuit
        if (totalGas < totalCost) {
            return -1;
        }

        return start;
    }
};
