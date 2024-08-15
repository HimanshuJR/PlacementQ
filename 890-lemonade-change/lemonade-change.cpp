class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        bool ans ;
        int five = 0; int ten = 0; int twenty = 0;
        for(int i = 0;i<n;i++){
        if(bills[i] == 5){
            five++;
        }
       
            else if( bills[i] == 10){
                 if( five == 0){
            return false;
        }
        ten++;
        five--;
            }

        if(bills[i] == 20){
            if( five > 0 && ten > 0){
            ten--;
            five--;
            }
            else if(five >= 3){
                five = five-3;
            }
           else {
            return  false;
           }
        }
     }
        return true ;
    }
};