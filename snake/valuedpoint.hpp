#include "mytools.hpp"
class ValuedPoint
{
private:
    float score;
    pair<int, int> point;

public:
    ValuedPoint(const float &score, const pair<int, int> &point) : score(score), point(point){};
    inline bool operator<(const ValuedPoint &other) const
    {
        return score < other.score;
    }
    inline pair<int, int> get_point() const
    {
        return point;
    }
};