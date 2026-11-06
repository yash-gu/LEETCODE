class Solution {
public:
    std::vector<int> constructRectangle(int area) {
        if (area <= 0) return {-1, -1};
        int w =sqrt(area);
        
        while (area % w != 0) {
            w--;
        }
        return {area / w, w};
    }
};
