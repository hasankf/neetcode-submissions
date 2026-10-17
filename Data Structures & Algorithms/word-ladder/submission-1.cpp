// in this solution, we will use a queue. 
// for every word, we will pick a charachter and change it to any char from a to z till we find it in the wordlist set. if we do, put it into queue and increase the number of steps ++ ;



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& list) {

        unordered_set<string> st( list.begin(), list.end() ) ;
        queue <pair<string, int> >q ;

        q.push({beginWord, 1}) ;
        st.erase(beginWord) ;
    
        while(!q.empty() ) {

            auto [word, steps] = q.front(); q.pop() ;

            if(word == endWord) return steps ;
        
            for(int i=0 ; i< word.size(); i++ ){

                char original = word[i] ;
                for(char ch= 'a'; ch <= 'z' ; ch++ ){
                    word[i] = ch ;

                    if( st.find(word) != st.end() ) {
                        st.erase(word) ;
                        q.push({word, steps+1}) ;
                    }
                }
                word[i] = original ;
            }

        }
        return 0 ;
        
    }
};
