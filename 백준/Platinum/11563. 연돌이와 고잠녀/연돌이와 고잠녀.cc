#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n, m;
double yon[2000][4];
double xs, ys, xe, ye, answer = -1;
double distance(double x1, double y1, double x2, double y2){
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
double dot(double x1, double y1, double x2, double y2){
	return (x1 * x2) + (y1 * y2);
}
bool perpendicular(double x1, double y1, double x2, double y2, double x3, double y3){
	double L = dot(x2 - x1, y2 - y1, x3 - x1, y3 - y1);
	double R = dot(x1 - x2, y1 - y2, x3 - x2, y3 - y2);
	if (L >= 0 && R >= 0) return true;
	return false;
}
double triangleHeight(double x1, double y1, double x2, double y2, double x3, double y3){
	double area = abs((x1 * y2) + (x2 * y3) + (x3 * y1) - (x1 * y3) - (x3 * y2) - (x2 * y1));
	return area / distance(x1, y1, x2, y2);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			cin >> yon[i][j];
	for (int i = 0; i < m; i++){
		cin >> xs >> ys >> xe >> ye; 
		for (int j = 0; j < n; j++){
			double x3 = yon[j][0], y3 = yon[j][1];
			double x4 = yon[j][2], y4 = yon[j][3];
			double tmp = distance(xs, ys, x3, y3);
			tmp = min(tmp, distance(xe, ye, x3, y3));
			tmp = min(tmp, distance(xs, ys, x4, y4));
			tmp = min(tmp, distance(xe, ye, x4, y4));
			if (perpendicular(xs, ys, xe, ye, x3, y3)) tmp = min(tmp, triangleHeight(xs, ys, xe, ye, x3, y3));
			if (perpendicular(xs, ys, xe, ye, x4, y4)) tmp = min(tmp, triangleHeight(xs, ys, xe, ye, x4, y4));
			if (perpendicular(x3, y3, x4, y4, xs, ys)) tmp = min(tmp, triangleHeight(x3, y3, x4, y4, xs, ys));
			if (perpendicular(x3, y3, x4, y4, xe, ye)) tmp = min(tmp, triangleHeight(x3, y3, x4, y4, xe, ye));
			if (answer == -1) answer = tmp;
			else answer = min(answer, tmp);
		}
	}
	printf("%.16lf", answer);
}