void findhull(std::vector<Point> &ch, const std::vector<Point> &points, 
                const Point &left, const Point &right) {
    int farPointIndex = -1;
    int maxDistance = 0;

    // Find the farthest point from the line left-right
    for (int i = 0; i < points.size(); ++i) {
        // distance from the point to the line left-right
        int distance = abs((points[i].y - left.y) * (right.x - left.x) -
                           (right.y - left.y) * (points[i].x - left.x));
        if (distance > maxDistance) {
            farPointIndex = i;
            maxDistance = distance;
        }
    }

    // there are no remaining points
    if (farPointIndex == -1) {
        ch.push_back(left);
        return;
    }

    // Divide the set of points into two subsets
    std::vector<Point> rightside; // points to the right of the line right-max
    std::vector<Point> leftside;  // points to the left of the line left-max
    for (int i = 0; i < points.size(); ++i) {
        if (i == farPointIndex) continue; // avoid checking the max again

        int orienWithLeft = orientation(left, points[farPointIndex], points[i]);
        if (orienWithLeft == CW) {
            // the point lies to the right of the line left-far
            rightside.push_back(points[i]);
        } else if (orientation(right, points[farPointIndex], points[i]) == CCW) {
            // the point lies to the left of the line right-far
            leftside.push_back(points[i]);
        }
    }

    findhull(ch, rightside, left, points[farPointIndex]);
    findhull(ch, leftside, points[farPointIndex], right);
}