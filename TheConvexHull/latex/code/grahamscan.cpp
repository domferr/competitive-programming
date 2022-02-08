std::vector<Point> grahamscan(std::vector<Point> &points) {
    std::vector<Point> ch;
    int leftmostIndex = leftmost_point_index(points);
    Point leftmost = points[leftmostIndex];
    std::swap(points[leftmostIndex], points[0]);

    // Sort points in ccw order from the leftmost
    std::sort(points.begin()+1, points.end(), [&leftmost](Point &p1, Point &p2) {
        int orien = orientation(leftmost, p1, p2);
        if (orien == COL) // Points are colinear. Compare by distance
            return dist_sq(leftmost, p2) >= dist_sq(leftmost, p1);

        return orien == CCW;
    });

    ch.push_back(leftmost);
    ch.push_back(points[1]);
    ch.push_back(points[2]);
    for (int i = 3; i < points.size(); ++i) {
        while(ch.size() > 1 && orientation(ch[ch.size() - 2], ch.back(), points[i]) != CCW)
            ch.pop_back();
        ch.push_back(points[i]);
    }

    return ch;
}