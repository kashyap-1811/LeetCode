/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* traverse(vector<vector<int>>& grid, int stRow, int stCol, int endRow, int endCol) {
        Node *root = new Node();
        bool ones = false;
        bool zeroes = false;

        for(int i=stRow; i<=endRow; i++) {
            for(int j=stCol; j<=endCol; j++) {
                if(grid[i][j] == 1)
                    ones = true;
                else
                    zeroes = true;
            }
        }

        if(!ones || !zeroes) {
            root->isLeaf = true;
            root->val = ones ? true : false;
            return root;
        }

        root->val = true;
        int middleRow = (endRow - stRow) / 2 + stRow;
        int middleCol = (endCol - stCol) / 2 + stCol;

        // top left
        root->topLeft = traverse(grid, stRow, stCol, middleRow, middleCol);

        // top right
        root->topRight = traverse(grid, stRow, middleCol+1, middleRow, endCol);

        // bottom left
        root->bottomLeft = traverse(grid, middleRow+1, stCol, endRow, middleCol);

        // bottom right
        root->bottomRight = traverse(grid, middleRow+1, middleCol+1, endRow, endCol);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return traverse(grid, 0, 0, grid.size()-1, grid[0].size()-1);
    }
};