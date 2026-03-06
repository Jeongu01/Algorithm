#include <iostream>
using namespace std;

string k[4];
bool p[4][10];
int dr[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dc[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4; i++) {
        cin >> k[i];
    }

    string s;
    cin >> s;

    for (char ch : s) {
        for (int r = 0; r < 4; r++) {
            bool f = false;
            for (int c = 0; c < 10; c++) {
                if (k[r][c] == ch) {
                    p[r][c] = true;
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
    }

    for (int r = 1; r <= 2; r++) {
        for (int c = 1; c <= 8; c++) {
            bool ok = true;
            for (int k = 0; k < 9; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (!p[nr][nc]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cout << k[r][c] << '\n';
                return 0;
            }
        }
    }

    return 0;
}