#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w,h;
        cin >> w >> h;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w2, h2;
        cin >> w2 >> h2;
        int w1 = abs(x1 - x2), h1 = abs(y1- y2);
        int ans = -1;
        if (x1 > x2) swap(x1,x2);
        if (y1 > y2) swap(y1, y2);
        if (w1 + w2 <= w)
        {
            ans = w2 - max(x1, w - x2);
            if (ans < 0) ans = 0;
        }
        if (h1 + h2 <= h)
        {
            if (ans == -1)
                ans = max(y1, h - y2);
            ans = min(ans, h2 - max(y1, h - y2));
            if(ans < 0) ans = 0;
        }
        cout << ans << endl;
    }
}