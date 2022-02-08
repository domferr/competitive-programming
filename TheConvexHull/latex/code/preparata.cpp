std::vector<Point> preparata(std::vector<Point> &points, int l, int r) {
    if (r - l == 1) return { points[l] };
    if (r - l == 2) return { points[l], points[l+1] };
    if (r - l == 3) return ch_three_points(points[l], points[l+1], points[l+2]);

    int m = (l+r) / 2;
    std::vector<Point> ch1 = preparata(points, l, m);
    std::vector<Point> ch2 = preparata(points, m, r);

    return merge(ch1, ch2);
}