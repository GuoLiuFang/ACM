#include <iostream>

using namespace std;

const int PRE_HEIGHT = 0xffff;
int row, column;

int method(int *pInt, int currentR, int currentC, int preHeight, int *pInt1);


int main() {
//    cout << "Hello, World!" << endl;
    int testNum;
    cin >> testNum;
    while (testNum--) {
        cin >> row >> column;
        int data[row][column];
        int result[row][column];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                cin >> data[i][j];
                result[i][j] = -1;//结果列表初始化为负一
            }
        }
//数据输入输出没有问题，现在开始处理数据
        int funResult;
        int maxLength = -0xffff;
        for (int k = 0; k < row; ++k) {
            for (int i = 0; i < column; ++i) {
                funResult = method(&data[0][0], k, i, PRE_HEIGHT, &result[0][0]);
                if (funResult > maxLength) {
                    maxLength = funResult;
                }
            }
        }
        cout << maxLength << endl;
//        for (int i = 0; i < row; ++i) {
//            for (int j = 0; j < column; ++j) {
//                cout << "--" << data[i][j];
//            }
//            cout << endl;
//        }
    }


    return 0;
}

int method(int *pArray, int currentR, int currentC, int preHeight, int *pTmpResult) {//参数分成了两部分前三个是当前的，，最后一个是前一个的。。
    int currentValue = pArray[currentR * column + currentC];
    if (currentR < 0 || currentR >= row || currentC < 0 || currentC >= column ||
        currentValue >= preHeight) {//当前位置比前一个位置高
        return 0;
    }
    if (pTmpResult[currentR * column + currentC] >= 0) {
        return pTmpResult[currentR * column + currentC];
    } else {
        pTmpResult[currentR * column + currentC] = 1 + max(max(method(pArray, currentR - 1, currentC, currentValue,
                                                                      pTmpResult),
                                                               method(pArray, currentR + 1, currentC, currentValue,
                                                                      pTmpResult)),
                                                           max(method(pArray, currentR, currentC - 1, currentValue,
                                                                      pTmpResult),
                                                               method(pArray, currentR, currentC + 1, currentValue,
                                                                      pTmpResult)));
        return pTmpResult[currentR * column + currentC];
    }
}