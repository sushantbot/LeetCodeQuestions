class Solution {
public:
    int UniqueCharacterIndex(string&s){
        int size=s.length();
        //we will store the frequency of each character in frq array
        //the character having frequency == 1 will be unique
        int freq[26]={0};
        for(int i=0;i<size;i++){
            char ch=s[i];
            //updating frequency of curr character
            freq[ch-'a']++;
        }

        //Now out frequency array is processed
        //Now checking unique character
        for(int i=0;i<size;i++){
            char ch = s[i];
            if(freq[ch-'a'] == 1){
                //this is unique character
                //this is our requeired character
                //so we will return its index
                return i;
            }
        }
        //if nothing has been returned yet
        //this means there is no unique characters in the string
        //in this case we have to return 0
        return -1;
    }
    int firstUniqChar(string s) {
        return UniqueCharacterIndex(s);
    }
};