//
// Created by Domenico on 02/11/2021.
//

#ifndef COMPETITIVE_PROGRAMMING_MAXSEGMENTINTERSECTIONS_H
#define COMPETITIVE_PROGRAMMING_MAXSEGMENTINTERSECTIONS_H

#include <vector>

struct segment {
    int start;
    int end;
};

typedef struct segment segment;

int max_segment_intersections(const std::vector<segment> &segments);

#endif //COMPETITIVE_PROGRAMMING_MAXSEGMENTINTERSECTIONS_H
