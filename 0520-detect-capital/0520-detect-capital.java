class Solution {
    public boolean detectCapitalUse(String word) {
        int capital = 0, small = 0;

        for(char c : word.toCharArray()){
            if(c < 'a')
                capital++;
            else
                small++;
        }

        if(capital == word.length() && small == 0)
            return true;
        if(small == word.length() && capital == 0)
            return true;
        if(capital == 1 && word.charAt(0) < 'a')
            return true;
        return false;
    }
}