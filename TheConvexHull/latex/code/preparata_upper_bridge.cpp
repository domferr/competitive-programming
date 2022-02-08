std::pair<int, int> upper_bridge(const std::vector<Point> &ch1, int ind_ch1, 
                                 const std::vector<Point> &ch2, int ind_ch2) {
    bool done = false;
    int next_ind2 = (ch2.size() + ind_ch2 - 1) % ch2.size();
    int next_ind1 = (ind_ch1 + 1) % ch1.size();
    while(!done) {
        done = true;
        while(orientation(ch2[ind_ch2], ch1[ind_ch1], ch1[next_ind1]) == CW) {
            ind_ch1 = next_ind1;
            next_ind1 = (next_ind1 + 1) % ch1.size();
        }

        while(orientation(ch1[ind_ch1], ch2[ind_ch2], ch2[next_ind2]) == CCW) {
            ind_ch2 = next_ind2;
            next_ind2 = (ch2.size() + next_ind2 - 1) % ch2.size();
            done = false;
        }
    }

    return std::make_pair(ind_ch1, ind_ch2);
}