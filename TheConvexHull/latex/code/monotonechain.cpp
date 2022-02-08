std::vector<Point> monotonechain(std::vector<Point> &points) {
    // Sort points by x-coordinate or by y-coordinate if there is a tie
    std::sort(points.begin(), points.end(), [](Point &p1, Point &p2) {
        return p1.x == p2.x ? p1.y < p2.y : p1.x < p2.x;
    });

    std::vector<Point> ch { points[0] };
    // build lower hull
    int i = 1;
    while (i < points.size()) {
        if (ch.size() >= 2 && orientation(ch[ch.size() - 2], ch.back(), points[i]) == CW) {
            ch.pop_back();
        } else {
            ch.push_back(points[i]);
            i++;
        }
    }

    // build upper hull
    i = points.size() - 2;
    while (i >= 0) {
        if (ch.size() >= 2 && orientation(ch[ch.size() - 2], ch.back(), points[i]) == CW) {
            ch.pop_back();
        } else {
            ch.push_back(points[i]);
            i--;
        }
    }

    if (ch[0] == ch.back())
        ch.pop_back();

    return ch;
}