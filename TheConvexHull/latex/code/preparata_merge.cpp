std::vector<Point> merge(const std::vector<Point> &ch1, const std::vector<Point> &ch2) {
    int ch1_rightmost = rightmost_point_index(ch1);
    int ch2_leftmost = leftmost_point_index(ch2);
    
    // compute upper bridge
    std::pair<int, int> up_bridge = upper_bridge(ch1, ch1_rightmost, ch2, ch2_leftmost);
    
    // compute lower bridge
    std::pair<int, int> lo_bridge = lower_bridge(ch1, ch1_rightmost, ch2, ch2_leftmost);
    
    // merge the subhulls
    std::vector<Point> ch_merged;
    ch_merged.push_back(ch1[up_bridge.first]);
    int i = up_bridge.first;
    while (i != lo_bridge.first) {
        i = (i+1) % ch1.size();
        ch_merged.push_back(ch1[i]);
    }

    ch_merged.push_back(ch2[lo_bridge.second]);
    i = lo_bridge.second;
    while (i != up_bridge.second) {
        i = (i+1) % ch2.size();
        ch_merged.push_back(ch2[i]);
    }

    return ch_merged;
}