std::vector<Point> chan(const std::vector<Point> &points, int m, int h) {
    unsigned int subset_size = std::round((double) points.size() / m);
    std::vector<std::vector<Point>> pts(m);
    std::vector<std::vector<Point>> ch(m);
    // subdivide points into m subsets
    int j = 0;
    for (int i = 1; i <= points.size(); ++i) {
        pts[j].push_back(points[i-1]);
        if (i % subset_size == 0 && j + 1 < m)
            j++;
    }

    // graham scan for each subhull
    for (int i = 0; i < m; ++i) ch[i] = grahamscan(pts[i]);

    std::vector<Point> finalhull { rightmost_point(points) };
    for (int k = 0; k < h; ++k) {
        Point best{ INT_MIN, INT_MIN };
        // jarvis march phase
        for (int i = 0; i < m; ++i) {
            // do not compare last point with itself when the set has only the last point
            if (ch[i].size() == 1 && ch[i][0] == finalhull.back()) continue;
            // find the next candidate via binary search and compare with the best found
            Point next = next_candidate(ch[i], finalhull.back());
            if (best == Point{ INT_MIN, INT_MIN } ||
                orientation(finalhull.back(), best, next) == CW)
                best = next;
        }

        if (best == finalhull[0]) return finalhull;
        finalhull.push_back(best);
    }

    return {};
}