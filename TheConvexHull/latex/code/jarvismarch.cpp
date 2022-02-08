std::vector<Point> jarvismarch(const std::vector<Point> &points) {
    std::vector<Point> ch;
    int leftmostPointIndex = leftmost_point_index(points);
    int hullPointIndex = leftmostPointIndex;
    Point hullPoint = points[hullPointIndex];
    do {
        ch.push_back(hullPoint);
        int endPointIndex = (hullPointIndex + 1) % points.size();
        for (int i = 0; i < points.size(); ++i) {
            if (orientation(hullPoint, points[i], points[endPointIndex]) == CCW)
                endPointIndex = i;
        }
        hullPoint = points[endPointIndex];
        hullPointIndex = endPointIndex;
    } while(hullPointIndex != leftmostPointIndex);

    return ch;
}