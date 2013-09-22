#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
/* Head ends here */
int flag[40][40];
typedef pair<int, int> node_t;
node_t last_node[40][40];
int min_len[40][40];
stack< node_t > nodes;

void update(int max_r, int max_c, int r, int c, int from_r, int from_c, vector <string> &grid, int len) {
    if (r >= 0 && r < max_r && c < max_c && c >= 0 && grid[r][c] != '%') {
        if (len < min_len[r][c]) {
            min_len[r][c] = len;
            last_node[r][c] = make_pair(from_r, from_c);
            flag[r][c] = 0;
        }
        if (flag[r][c] == 0) {
            nodes.push(make_pair(r, c));
            flag[r][c] = 1;
        }
    }
}

void dfs( int r, int c, int pacman_r, int pacman_c, int food_r, int food_c, vector <string> grid){
    //your logic here
    //deque< node_t > path;
    node_t node;
    //flag[pacman_r][pacman_c] = 1;

    node = make_pair(pacman_r, pacman_c);
    nodes.push(node);
    min_len[pacman_r][pacman_c] = 0;
    flag[pacman_r][pacman_c] = 1;

    //int length = 0;
    while (!nodes.empty()) {
        node = nodes.top();
        nodes.pop();
        //cout << node.first << " " << node.second << endl;
        //path.push_back(node);
        //length++;

        int row = node.first;
        int col = node.second;
        //flag[row][col] = 1;
        int len = min_len[row][col] + 1;

        //cout << "to update\n";
        update(r, c, row - 1, col, row, col, grid, len);
        update(r, c, row, col - 1, row, col, grid, len);
        update(r, c, row, col + 1, row, col, grid, len);
        update(r, c, row + 1, col, row, col, grid, len);
        //cout << row << " " << col << " " << min_len[row][col] << " " << nodes.size() << endl;

        // if (row == food_r && col == food_c) {
        //     // found
        //     break;
        // }

        // int cnt = 0;
        // if (row > 0 && flag[row - 1][col] == 0 && grid[row - 1][col] != '%') {
        //     //cout << "push up " << row - 1 << ":" << col << endl;

        //     nodes.push(make_pair(row - 1, col));
        //     cnt++;
        // }
        // if (col > 0 && flag[row][col - 1] == 0 && grid[row][col - 1] != '%') {
        //     nodes.push(make_pair(row, col - 1));
        //     cnt++;
        //     //cout << "push left " << row << ":" << col - 1 << endl;
        // }
        // if (col < c - 1 && flag[row][col + 1] == 0 && grid[row][col + 1] != '%') {
        //     nodes.push(make_pair(row, col + 1));
        //     cnt++;
        //     //cout << "push right " << row << ":" << col + 1 << endl;
        // }
        // if (row < r - 1 && flag[row + 1][col] == 0 && grid[row + 1][col] != '%') {
        //     nodes.push(make_pair(row + 1, col));
        //     cnt++;
        //     //cout << "push down " << row + 1 << ":" << col << endl;
        // }

        // if (cnt == 0) {
        //     //cout << "cnt=0 " << row << " " << col << endl;
        //     path.pop_back();
        //     length--;
        // }
    }
    
    stack< node_t > paths;
    stack< node_t > paths_bk;
    int row = food_r, col = food_c;
    while (row != pacman_r || col != pacman_c) {
        //cout << row << " " << col << endl;
        paths.push(make_pair(row, col));
        paths_bk.push(make_pair(row, col));
        node = last_node[row][col];
        row = node.first;
        col = node.second;
    }
    paths.push(make_pair(pacman_r, pacman_c));
    paths_bk.push(make_pair(pacman_r, pacman_c));

    /*
    cout << min_len[food_r][food_c] + 1 << endl;
    while (!paths.empty()) {
        node = paths.top();
        cout << node.first << " " << node.second << endl;
        paths.pop();
    }
    */

    cout << min_len[food_r][food_c] << endl;
    while (!paths_bk.empty()) {
        node = paths_bk.top();
        cout << node.first << " " << node.second << endl;
        paths_bk.pop();
    }
    //cout << length << endl;
    // for (int i = 0; i < path.size(); ++i)
    // {
    //     cout << path[i].first << " " << path[i].second << endl;
    // }
    //cout << length - 1 << endl;
    // for (int i = 0; i < path.size(); ++i)
    // {
    //     cout << path[i].first << " " << path[i].second << endl;
    // }
}
/* Tail starts here */
int main(void) {

    int r,c, pacman_r, pacman_c, food_r, food_c;
    
    cin >> pacman_r >> pacman_c;
    cin >> food_r >> food_c;
    cin >> r >> c;
    
    vector <string> grid;

    for(int i=0; i<r; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    for (int j = 0; j < r; ++j)
    {
        for (int k = 0; k < c; ++k)
        {
            flag[j][k] = 0;
            min_len[j][k] = 100000;
        }
    }

    dfs( r, c, pacman_r, pacman_c, food_r, food_c, grid);

    return 0;
}