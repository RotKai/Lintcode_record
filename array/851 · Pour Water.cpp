class Solution {
public:
    /**
     * @param heights: the height of the terrain
     * @param v: the units of water
     * @param k: the index
     * @return: how much water is at each index
     */
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        // Write your code here
        for (int i = 0; i < V; i++)
        {
            int pos = K;
            while (pos > 0 && heights[pos - 1] <= heights[pos])
            {
                pos--;
            }
            while (pos < K && heights[pos + 1] == heights[pos])
            {
                pos++;
            }
            if (pos == K)
            {
                while (pos < heights.size() - 1 && heights[pos + 1] <= heights[pos])
                {
                    pos++;
                }
                while (pos > K && heights[pos - 1] == heights[pos])
                {
                    pos--;
                }
            }
            heights[pos]++;
        }
        return heights;
    }
};
