#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

bool customSort(Segment i, Segment j){
    return i.end < j.end;
}

vector<int> optimal_points(vector<Segment> segments) {
  vector<int> points;
  // Sort increasing order according to End points
  sort(segments.begin(), segments.end(), customSort);
  
//   for(int i=0; i<segments.size(); i++)
//     cout<<segments[i].start<<" "<<segments[i].end<<endl;
//   cout<<endl;
  
  int currentPoint = segments[0].end;
  points.push_back(currentPoint);
  
  for (long long i=1; i<segments.size(); i++){
      if (segments[i].start>currentPoint || segments[i].end<currentPoint){
          currentPoint = segments[i].end;
          points.push_back(currentPoint);
      }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
