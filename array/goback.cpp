#include <iostream>
using namespace std;

int main() {
    int n = 10, w = 4;
 int i = 1;
 bool lostOnce = false;   
    while (i <= n) {
        cout << "Sending:\n";
        bool lost = false;
        for (int j = 0; j < w && (i + j) <= n; j++) {
        cout << i + j << "\n";
          if ((i + j) % 5 == 0 && !lostOnce) {
            cout << "frame " << i + j << " lost go back\n";
            i = i + j;
            lost = true;
                lostOnce = true;  
          break;
            }
        }
        if (!lost) {
            i += w;
        }
    }

    return 0;
}