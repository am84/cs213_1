
//-----Include required headers here-----
#include <iostream>
#include <cmath>

using namespace std;
//-----End of headers-----

//-----Don't change/delete classes -----
class Point {
	public:
		int x,y; 
};

class LineSeg {
	public:
		Point p1,p2;
};
//----- Classes end here

//-----Add new functions here(if any)-----

int pval(Point p1, class LineSeg l1){
	int y = p1.y;
	int x = p1.x;

	int x1 = l1.p1.x;
	int x2 = l1.p2.x;

	int y1 = l1.p1.y;
	int y2 = l1.p2.y;

	int pval = (y - y1) * (x2 - x1) - (y2 - y1) * (x - x1);
	return pval;

}

bool collinear(class LineSeg l1, class LineSeg l2){
	// function returns true if segments intersect else false
	// assumption is that the lines are collinear already
	// check slope 
	// it is the same across both
	// function computes the distance of the x coordinate between
	// from the other two points. product is negative if the
	// point lies in between the other two points

	int slope_num = l1.p2.y - l1.p1.y;
	int slope_den = l1.p2.x - l1.p1.x;

	int prod1, prod2, prod3, prod4;
	if (slope_den == 0){
		// it is a vertical line
		prod1 = (l1.p1.y - l2.p1.y) * (l1.p1.y - l2.p2.y);
		prod2 = (l1.p2.y - l2.p1.y) * (l1.p2.y - l2.p2.y);
		prod3 = (l2.p1.y - l1.p1.y) * (l2.p1.y - l1.p2.y);
		prod4 = (l2.p2.y - l1.p1.y) * (l2.p2.y - l1.p2.y);

	}
	else {
		prod1 = (l1.p1.x - l2.p1.x) * (l1.p1.x - l2.p2.x);
		prod2 = (l1.p2.x - l2.p1.x) * (l1.p2.x - l2.p2.x);
		prod3 = (l2.p1.x - l1.p1.x) * (l2.p1.x - l1.p2.x);
		prod4 = (l2.p2.x - l1.p1.x) * (l2.p2.x - l1.p2.x);
	}
	if ((prod1 <= 0) || (prod2 <= 0) || (prod3 <= 0) || (prod4 <= 0)) {
		return true;
	}
	return false;
}

bool compare_pvals(class LineSeg l1, class LineSeg l2, int p1_val, int p2_val){

	if ((p1_val == 0) && (p2_val == 0)){
		return collinear(l1, l2);
	}
	else {
		int product = p1_val * p2_val;
		if (product <= 0){
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool opp_sides(class LineSeg l1, class LineSeg l2){

	Point l1p1 = l1.p1;
	Point l1p2 = l1.p2;

	Point l2p1 = l2.p1;
	Point l2p2 = l2.p2;

	int l1_slope_den = l1p2.x - l1p1.x;
	int l1_slope_num = l1p2.y - l1p1.y;

	int p1_val, p2_val;
	if (l1_slope_den != 0){
		p1_val = pval(l2.p1, l1);
		p2_val = pval(l2.p2, l1);

		return compare_pvals(l1, l2, p1_val, p2_val);
	}
	else {
		// it is vertical line
		p1_val = l2p1.x - l1p1.x;
		p2_val = l2p2.x - l1p1.x;

		return compare_pvals(l1, l2, p1_val, p2_val);
	}
}



//-----New functions end here-----

/* Question: You need to write the function SegIntersect which takes two line segments as input and returns true if the two line segments
   intersect each other and false if not .You may write any additional helper functions you want in the specified region only.
   Do not change the signature of the functions or classes already given.  
   LineSeg l1 : First line segment with its end-points given
   LineSeg l2 : Second line segment with its end-points given
 */

bool SegIntersect(class LineSeg l1,class LineSeg l2) {
	// write your code below this line
	bool opp_side_l1_l2 = opp_sides(l1, l2);
	bool opp_side_l2_l1 = opp_sides(l2, l1);

	cout << opp_side_l1_l2 << opp_side_l2_l1 << endl;


	return (opp_side_l1_l2 && opp_side_l2_l1);

}
int main(int argc, char** argv){

	LineSeg l1, l2;
	l1.p1.x = 17;
	l1.p1.y = 5;
	l1.p2.x = 15;
	l1.p2.y = 5;

	l2.p1.x = 30;
	l2.p1.y = 7;
	l2.p2.x = 2;
	l2.p2.y = 14; 

	cout << SegIntersect(l1, l2) << endl;
	
	return 0;
}
