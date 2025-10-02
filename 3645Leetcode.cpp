class Solution {
public:
    static bool cmp(vector<long long>&a,vector<long long>&b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        vector<vector<long long>>v;
        for(int i=0;i<value.size();i++){
            v.push_back({limit[i],value[i]});
        }sort(v.begin(),v.end(),cmp);
        int i=0;
        multiset<int>st;
        int curcnt=0;
        long long ans=0;
        while(i<v.size()){
            if(st.empty()){
                ans+=v[i][1];
                st.insert(v[i][0]);
                i++;
            }
            else{
                while(i<v.size()&&v[i][0]<=st.size())i++;
                auto x=st.size();
                st.erase(x);
                if(i<v.size()){ans+=v[i][1];
                st.insert(v[i][0]);i++;}
            }
         
        }return ans;
    }
};
