//Method 1
//Sorting Method used
//TC : n*KlongK

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();

        unordered_map<string,vector<string>> mp;
        vector<vector<string>>res;

        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(begin(temp),end(temp));

            mp[temp].push_back(strs[i]);  ///{temp->{strs}}
        }

        for(auto it : mp){
            res.push_back(it.second);
        }

        return res;
        
    }
};



//Method 2
//As the constraint, word will only consist of lower case english letters, we can use array of size 26.
//TC : n*(k+26) = n*k



class Solution {
public:

   string generate(string& word){
       int arr[26] = {0};  //Creating and initializaing an array of size 26 with zeros

       for(char &ch : word){
           arr[ch - 'a']++;  //For ch "a" it would be arr[0]
       }

       string new_word = "";
       for(int i=0;i<26;i++){
           int freq = arr[i];
           if(freq > 0){
               new_word += string(freq, i + 'a'); //This adds the character equal to its presense to the new_word
           }
       }

       return new_word;
   }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>>res;

        for(int i=0;i<n;i++){
            string word = strs[i];
            string new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for(auto it : mp){
            res.push_back(it.second);
        }

        return res;

        
    }
};

