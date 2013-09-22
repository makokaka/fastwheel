#include <iostream>
#include <vector>
//#include <cmath>
using namespace std;
/* Head ends here */
int distance(int r1, int c1, int r2, int c2) {
    return (r1-r2) * (r1-r2) + (c1-c2) * (c1-c2);
}

void displayPathtoPrincess(int n, vector <string> grid){
    //your logic here
    int m_row = -1, m_col = -1;
    int p_row = -1, p_col = -1;

    for (int i = 0; i < grid.size(); ++i)
    {
        string row = grid[i];
        for (int j = 0; j < row.size(); ++j)
        {
            if (row[j] == 'm') {
                m_row = i;
                m_col = j;
            } else if (row[j] == 'p') {
                p_row = i;
                p_col = j;
            }
        }
    }
    //cout << m_row << " " << m_col << " " << p_row << " " << p_col << endl;
    int curr_dist = distance(m_row, m_col, p_row, p_col);
    vector <string> result;
    while (1) {
        if (m_row == p_row && m_col == p_col)
            break;
        int min_dist = 2147483647;
        string direction;
        int new_row, new_col;
        if (m_row > 0) {
            int dist = distance(m_row - 1, m_col, p_row, p_col);
            if (min_dist > dist) {
                direction = "UP";
                min_dist = dist;
                new_row = m_row - 1;
                new_col = m_col;
            }
        }
        if (m_row < n-1) {
            int dist = distance(m_row + 1, m_col, p_row, p_col);
            if (min_dist > dist) {
                direction = "DOWN";
                min_dist = dist;
                new_row = m_row + 1;
                new_col = m_col;
            }
        }
        if (m_col > 0) {
            int dist = distance(m_row, m_col - 1, p_row, p_col);
            if (min_dist > dist) {
                direction = "LEFT";
                min_dist = dist;
                new_row = m_row;
                new_col = m_col - 1;
            }
        }
        if (m_col < n-1) {
            int dist = distance(m_row, m_col + 1, p_row, p_col);
            if (min_dist > dist) {
                direction = "RIGHT";
                min_dist = dist;
                new_row = m_row;
                new_col = m_col + 1;
            }
        }
        //cout << min_dist << " " << direction << endl;
        result.push_back(direction);
        m_row = new_row;
        m_col = new_col;
    }
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }
}
/* Tail starts here */
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}