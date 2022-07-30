// link to question - https://leetcode.com/problems/design-a-food-rating-system/

class FoodRatings {
public:
    unordered_map<string, multiset<int>> m;
    map<pair<string, int>, set<string>> food;
    unordered_map<string, int> fi;
    vector<int> rating;
    vector<string> cuisine;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        rating = ratings;
        cuisine = cuisines;
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            fi[foods[i]] = i;
            m[cuisines[i]].insert(ratings[i]);
            food[{cuisines[i], ratings[i]}].insert(foods[i]);
        }
    }
    
    void changeRating(string foodItem, int newRating) {
        int i = fi[foodItem];
        if (rating[i] == newRating) return;
        
        food[{cuisine[i], rating[i]}].erase(foodItem);
        m[cuisine[i]].erase(m[cuisine[i]].find(rating[i]));
        food[{cuisine[i], newRating}].insert(foodItem);
        rating[i] = newRating;
        m[cuisine[i]].insert(newRating);
    }
    
    string highestRated(string cuisine) {
        int r = *m[cuisine].rbegin();
        string ans = *food[{cuisine, r}].begin();
        return ans;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */