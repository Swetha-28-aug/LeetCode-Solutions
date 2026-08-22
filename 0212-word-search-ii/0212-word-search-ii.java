class Trie{
    String word;
    Trie[] chars=new Trie[26];
}

class Solution{
    int diff[]={0,1,0,-1,0};

    void dfs(int R,int C,int row,int col,char board[][],boolean vis[][],Trie t,List<String> ans){
        int chidx=board[row][col]-'a';
        if(t.chars[chidx]==null) return;

        Trie curr=t.chars[chidx];

        if(curr.word!=null){
            ans.add(curr.word);
            curr.word=null;
        }

        vis[row][col]=true;

        for(int i=0;i<4;i++){
            int ar=row+diff[i];
            int ac=col+diff[i+1];

            if(ar>=0&&ar<R&&ac>=0&&ac<C&&!vis[ar][ac]){
                dfs(R,C,ar,ac,board,vis,curr,ans);
            }
        }

        vis[row][col]=false;
    }

    void buildTrie(Trie p,String word,int idx){
        int chidx=word.charAt(idx)-'a';

        if(p.chars[chidx]==null)
            p.chars[chidx]=new Trie();

        Trie curr=p.chars[chidx];

        if(idx==word.length()-1){
            curr.word=word;
            return;
        }

        buildTrie(curr,word,idx+1);
    }

    public List<String> findWords(char[][] board,String[] words){
        Trie root=new Trie();

        for(String word:words){
            if(word.length()>0)
                buildTrie(root,word,0);
        }

        List<String> ans=new ArrayList<>();
        int R=board.length;
        int C=board[0].length;
        boolean vis[][]=new boolean[R][C];

        for(int row=0;row<R;row++){
            for(int col=0;col<C;col++){
                dfs(R,C,row,col,board,vis,root,ans);
            }
        }

        return ans;
    }
}