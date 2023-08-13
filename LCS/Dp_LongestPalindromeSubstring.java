class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int[] ans = new int[]{0,0};
        
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }
        
        for(int i=0; i<n-1; i++){
            if(s.charAt(i) == s.charAt(i+1)){
                dp[i][i+1] = true;
                ans[0] = i;
                ans[1] = i+1;
            }
        }
        
        for(int dif=2; dif<n; dif++){
            for(int i=0; i<n-dif; i++){
                int j = i+dif;
                if(s.charAt(i) == s.charAt(j) && dp[i+1][j-1]){
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        int k = ans[0];
        int l = ans[1];
        
        return s.substring(k,l+1);
        
    }
}
