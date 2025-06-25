#include <iostream>
using namespace std;

//ok function
bool ok (int cross[], int cap){
    static int checklist[8][5] = {
        {-1},
        {0,-1},
        {1,-1},
        {0,1,2,-1},
        {1,2,3,-1},
        {2,4,-1},
        {0,3,4,-1},
        {3,4,5,6,-1},
    };
    for(int i=0; i<cap; i++){ 
        if(cross[i]==cross[cap])
        return false;
    }
    for(int i=0; checklist[cap][i]!=-1; i++){ 
       if(abs(cross[cap]-cross[checklist[cap][i]])==1) return false;
    }
    return true;
};
 
//print function
void print(int cross[], int cap){
    static int count=1; 
    cout << endl;
    cout << "Solution number: " << count++ <<endl;
    cout << endl;
    cout << "  " << cross[1] << " " << cross[2] << endl;
    cout << cross[0] << " " << cross[3] << " " << cross[4] << " " << cross[7] << endl;
    cout << "  " << cross[5] << " " << cross[6] << endl;
}

// eigthNumbers function
void eightNumbers(int cross[], int cap) {
   if (cap == 8)
      print(cross, cap); 
   else 
   	for (cross[cap] = 1; cross[cap] <= 8; cross[cap]++) 
      if (ok(cross, cap))
         eightNumbers(cross, cap+1);
}

//main function 
int main() {
   int cross[8];
   eightNumbers(cross, 0);
   return 0;
}
