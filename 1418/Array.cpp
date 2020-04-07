#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

// 面试题 01.07. 旋转矩阵
// 给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。不占用额外内存空间能否做到？

// 示例 1:
// 给定 matrix = 
// [
//   [1,2,3],
//   [4,5,6],
//   [7,8,9]
// ],
// 原地旋转输入矩阵，使其变为:
// [
//   [7,4,1],
//   [8,5,2],
//   [9,6,3]
// ]

// 示例 2:
// 给定 matrix =
// [
//   [ 5, 1, 9,11],
//   [ 2, 4, 8,10],
//   [13, 3, 6, 7],
//   [15,14,12,16]
// ], 
// 原地旋转输入矩阵，使其变为:
// [
//   [15,13, 2, 5],
//   [14, 3, 4, 1],
//   [12, 6, 8, 9],
//   [16, 7,10,11]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //上下翻转
        for(int i=n/2-1;i>=0;--i){
            for(int j=n-1;j>=0;--j){
                swap(matrix[i][j],matrix[n-i-1][j]);
            }
        }
        //主对角线翻转
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(int argc, char *argv[])
{
	vector<vector<int>> data = { 
          {1,2,3},
          {4,5,6},
          {7,8,9}
    };
	Solution s;
	s.rotate(data);

	for(auto it:data){
        for(auto d:it){
            cout<<d<<" ";
        }
        cout<<endl;
    }
	cout << endl;
	return 0;
}