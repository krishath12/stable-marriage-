#include <iostream>
using namespace std;
// Function to check if the current assignment is stable
bool ok(int q[], int c, int mp[3][3], int wp[3][3]){
for (int i=0; i<c; i++){
      int cm = i;  // current man
	  int cw = q[i]; // current woman
	  int nm = c;  // new man
	  int nw = q[c];  // new woman
	  
// Check if the new woman has already been assigned to some man
        for (int j = 0; j < c; j++) {
            if (q[j] == nw) {
                return false;
            }
        }
//check if current man prefers new woman and the new woman preferes the current man  or the new man prefers the current woman and the current woman prefers the new man over their current partners 		
	  if((mp[cm][nw]<mp[cm][cw] && wp[nw][cm]<wp[nw][nm]) || 
	  (mp[nm][cw]< mp[nm][nw] && wp[cw][nm]<wp[cw][cm])){
	  return false;
	  }
	 }
	 return true;	 		
}
//Function to print the current stable assignment
void print(int q[], int solutionNumber){
	cout << "Solution #" << solutionNumber << ": " << endl;
	cout << "Man    Woman" << endl;
	for (int i = 0; i < 3; i++) {
	        cout <<  i << "      " << q[i] << endl;
	    }
	    cout << endl;
	}
	
	int main() {
	    int q[3] = {};
	    int c = 0;
	    q[c] = 0;
	
	int mp[3][3]={{0,2,1},//man 0's preference
				 {0,2,1}, //man 1's preference
				 {1,2,0}}; //man 2's preference
	int wp[3][3]={{2,1,0}, // woman 0's preference
				 {0,1,2}, // woman 1's preference
				 {2,0,1}}; // woman 2's preference
	
	int solutionNumber = 0; //keep the solution count
    
	while (c >= 0) {
           c++;
           if (c == 3) {
			   solutionNumber++;   // complete solution is found
               print(q, solutionNumber);
               c--;
           } else {
               q[c] = -1;
           }

           while (c >= 0) {
               q[c]++;
               if (q[c] == 3) {
                   c--;
               } else if (ok(q, c, mp, wp)) {
                   break;
               }
           }
       }

       return 0;
   }