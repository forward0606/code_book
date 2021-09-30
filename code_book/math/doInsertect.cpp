// consider two segment is collision or not
// O(1)
// use the concept of vector in math
// there are also some special case too

struct Point{
	int x, y;
};

// checks if point q lies on line segment p-r
bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
			q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
		return true;

	return false;
}

// To find orientation of ordered triplet (p, q, r).
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
	// reference from http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
	int val = (q.y - p.y) * (r.x - q.x)-(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;  // colinear

	return (val > 0)? 1: 2; // clock or counterclock wise
}

// line segment p1-q1 and line segent p2-q2 have intersection point or not.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	//Find four orientations needed for general and special case
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	// General case- line segment A crosses  line segment B, looks like shape X.
	if (o1 != o2 && o3 != o4)
		return true;

	// Special Cases-one end point of line segment A(p1-q1 or p2-q2) lie s on line segment B(p2-q2 or p1-q1), looks like shape T.
	if (o1 == 0 && onSegment(p1, p2, q1)) return true;

	if (o2 == 0 && onSegment(p1, q2, q1)) return true;

	if (o3 == 0 && onSegment(p2, p1, q2)) return true;

	if (o4 == 0 && onSegment(p2, q1, q2)) return true;

	return false;
}
