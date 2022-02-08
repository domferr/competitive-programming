std::vector<Point> quickhull(const std::vector<Point> &points) {
    Point leftmost = leftmost_point(points);
    Point rightmost = rightmost_point(points);
    std::vector<Point> ch;
    std::vector<Point> rightside;
    std::vector<Point> leftside;

    // Split the points by the line from the leftmost to the rightmost
    for (Point point: points) {
        int orien = orientation(leftmost, rightmost, point);
        if (orien == CCW) { // this point is on the right of the line
            leftside.push_back(point);
        } else if (orien == CW) { // this point is on the left of the line
            rightside.push_back(point);
        }
    }

    findhull(ch, rightside, leftmost, rightmost);
    findhull(ch, leftside, rightmost, leftmost);

    return ch;
}