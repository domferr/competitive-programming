std::pair<Point, Point> upper_bridge(const std::vector<Point> &points, int med) {
    // handle simple and borderline cases
    if (points.size() == 2) return std::make_pair(points[0], points[1]);
    if (points.size() == 3) return upper_bridge_three_points(points, med);

    // compute the pairs and the avg slope
    int number_of_pairs = points.size() / 2;
    double slope_avg = 0;
    std::vector<std::pair<int, int>> pairs(points.size() / 2);
    for (int i = 0; i < points.size()-1; i += 2) {
        if (points[i].x < points[i+1].x) pairs[i/2] = std::make_pair(i, i+1);
        else pairs[i/2] = std::make_pair(i+1, i);
        slope_avg += SLOPE(points[pairs[i/2].first], points[pairs[i/2].second]);
    }
    std::vector<Point> remaining;
    if (points.size() % 2 == 1) {
        // one point is alone, count it but with a slope = 0
        number_of_pairs++;
        remaining.push_back(points.back());
    }
    slope_avg = slope_avg / number_of_pairs;

    // find max_c and top point
    double max_c = INT_MIN, c;
    Point top_point;
    for (auto pt: points) {
        // Given the point (xp, yp), y - yp = m(x - xp) => if x=0 then y = yp - m*xp
        c = pt.y - (slope_avg * pt.x);
        if (c > max_c) {
            max_c = c;
            top_point = pt;
        }
    }
    
    // prune phase
    for (auto pair: pairs) {
        bool prune = false;
        if (top_point.x < med) {
            if (SLOPE(points[pair.first], points[pair.second]) >= slope_avg) {
                remaining.push_back(points[pair.second]);
                prune = true;
            }
        } else {
            if (SLOPE(points[pair.first], points[pair.second]) < slope_avg) {
                remaining.push_back(points[pair.first]);
                prune = true;
            }
        }
        if (!prune) {
            remaining.push_back(points[pair.first]);
            remaining.push_back(points[pair.second]);
        }
    }

    return upper_bridge(remaining, med);
}