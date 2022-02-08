Point next_candidate(const std::vector<Point> &subhull, const Point &last) {
    unsigned int curr = 0, inc = subhull.size()/2, next, prev;
    Point next_point = subhull[0];
    bool found = false;
    while(!found) {
        next = (curr + 1) % subhull.size();
        prev = (curr - 1) % subhull.size();
        if (orientation(last, subhull[curr], subhull[next]) == CW) {
            curr = (curr + inc) % subhull.size();
        } else if (orientation(last, subhull[curr], subhull[prev]) == CW) {
            curr = (curr - inc) % subhull.size();
        } else {
            next_point = subhull[curr];
            found = true;
        }
        if (inc > 2) inc /= 2;
    }

    return next_point;
}