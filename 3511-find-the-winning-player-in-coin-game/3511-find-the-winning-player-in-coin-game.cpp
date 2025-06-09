class Solution {
public:
    string winningPlayer(int x, int y) 
    {
        int moves = min(x, y / 4);
        return moves % 2 == 0 ? "Bob" : "Alice";    
    }
};