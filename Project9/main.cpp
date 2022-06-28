#include <iostream>
#include <cmath>
#include <conio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int a[256][256], b[256][256], d[256][256], ply[256][256],
A[256][256], multi[256][256];
int C1[256][256],
C2[256][256],
C3[256][256],
C4[256][256],
C5[256][256],
C6[256][256];
int matriplus()
{
	int r, c, m1, n1, m2, n2, m, n;
	while (true)
	{
		cout << "分别输入矩阵1和2的行数与列数：" << endl;
		cin >> m1 >> n1 >> m2 >> n2;
		if (m1 != m2 || n1 != n2)
		{
			cout << "你输入的矩阵没法加呀，再给你一次机会！" << endl;
			continue;
		}
		else
		{
			m = m1; n = n1;
		}
		cout << "输入矩阵1：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> a[r][c];
			}
		}
		cout << "输入矩阵2：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> b[r][c];
			}
		}
		cout << "两个矩阵之和为：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				d[r][c] = a[r][c] + b[r][c];
				cout << d[r][c] << " ";
			}
			cout << endl;
		}
		break;
	}
	return 0;
}
int nummulti()
{
	int r, c, m, n, k;
	cout << "输入矩阵的行数与列数：" << endl;
	cin >> m >> n;
	cout << "输入该矩阵：" << endl;
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			cin >> a[r][c];
		}
	}
	cout << "输入矩阵要乘的数：" << endl;
	cin >> k;
	cout << "矩阵数乘的结果为：" << endl;
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			a[r][c] = k * a[r][c];
			cout << a[r][c] << " ";
		}
		cout << endl;
	}
	return 0;
}
int matritrans()
{
	int r, c, m, n;
	cout << "输入矩阵的行数与列数：" << endl;
	cin >> m >> n;
	cout << "输入要转置的矩阵：" << endl;
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			cin >> a[r][c];
		}
	}
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			b[c][r] = a[r][c];
		}
	}
	cout << "转置后的矩阵为：" << endl;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < m; c++)
		{
			cout << b[r][c] << " ";
		}
		cout << endl;
	}
	return 0;
}
int matrimulti()
{
	int r, c, m, n, p, q, k;
	while (true)
	{
		cout << "分别输入矩阵1和2的行数与列数（共四个数）：" << endl;
		cin >> m >> n >> p >> q;
		if (n == p)
		{
			cout << "输入矩阵1：" << endl;
			for (r = 0; r < m; r++)
			{
				for (c = 0; c < n; c++)
				{
					cin >> a[r][c];
				}
			}
			cout << "输入矩阵2：" << endl;
			for (r = 0; r < p; r++)
			{
				for (c = 0; c < q; c++)
				{
					cin >> b[r][c];
				}
			}
			for (r = 0; r < p; r++)
			{
				for (c = 0; c < q; c++)
				{
					multi[r][c] = 0;
				}
			}
			cout << "两个矩阵之积为：" << endl;
			for (r = 0; r < m; r++)
			{
				for (c = 0; c < q; c++)
				{
					for (k = 0; k < n; k++)
					{
						multi[r][c] += a[r][k] * b[k][c];
					}
					cout << multi[r][c] << " ";
				}
				cout << endl;
			}
			break;
		}
		else
		{
			cout << "你输入的矩阵没法乘啊，再给你一次机会！" << endl;
			continue;
		}
	}
	return 0;
}
int hadamulti()
{
	int r, c, m, n, m1, n1, m2, n2;
	while (true)
	{
		cout << "分别输入矩阵1和2的行数与列数：" << endl;
		cin >> m1 >> n1 >> m2 >> n2;
		if (m1 != m2 || n1 != n2)
		{
			cout << "你输入的矩阵没法哈呀，再给你一次机会！" << endl;
			continue;
		}
		else
		{
			m = m1; n = n1;
		}
		cout << "输入矩阵1：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> a[r][c];
			}
		}
		cout << "输入矩阵2：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> b[r][c];
			}
		}
		cout << "两个矩阵的Hadamard乘积为：" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				ply[r][c] = a[r][c] * b[r][c];
				cout << ply[r][c] << " ";
			}
			cout << endl;
		}
		break;
	}
	return 0;
}
int conv()
{
	int n, r, c, padding, B[3][3], innersum = 0;
	cout << "输入矩阵A的阶数：" << endl;
	cin >> n;
	cout << "输入增加填充的值：" << endl;
	cin >> padding;
	n += (padding * 2);
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			A[r][c] = 0;
		}
	}
	cout << "输入矩阵A（阶数与输入时的n阶保持一致）：" << endl;
	for (r = padding; r < n - padding; r++)
	{
		for (c = padding; c < n - padding; c++)
		{
			cin >> A[r][c];
		}
	}
	cout << "显示一下填充后的矩阵：" << endl;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			cout << A[r][c] << " ";
		}
		cout << endl;
	}
	cout << "输入矩阵B(规定输入3阶)：" << endl;
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			cin >> B[r][c];
		}
	}
	cout << "卷积矩阵为：" << endl;
	for (int p = 0; p < n - 2; p++)
	{
		for (int k = 0; k < n - 2; k++)
		{
			for (r = 0; r < 3; r++)
			{
				for (c = 0; c < 3; c++)
				{
					innersum += A[r + p][c + k] * B[r][c];
				}
			}
			cout << innersum << " ";
			innersum = 0;
		}
		cout << endl;
	}
	return 0;
}
void tran_scretch(int a[256][256])
{
	int pixmax = 0; int pixmin = 255;
	int i, j;
	Mat image = imread("C:\\Users\\93954\\Pictures\\Saved Pictures\\demolena.jpg", 0);
	int row = image.rows;
	int col = image.cols;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (a[i][j] > pixmax)
			{
				pixmax = a[i][j];
			}
			if (a[i][j] < pixmin)
			{
				pixmin = a[i][j];
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			a[i][j] = (a[i][j] - pixmin) * 255 / (pixmax - pixmin);
		}
	}
}
void demo()
{
	int innersum = 0;
	int B1[3][3] = { {1,1,1},{1,1,1},{1,1,1} },
		B2[3][3] = { {-1,-2,-1},{0,0,0},{1,2,1} },
		B3[3][3] = { {-1,0,1},{-2,0,2},{-1,0,1} },
		B4[3][3] = { {-1,-1,-1},{-1,9,-1},{-1,-1,-1} },
		B5[3][3] = { {-1,-1,0},{-1,0,1},{0,1,1} },
		B6[3][3] = { {1,2,1},{2,4,2},{1,2,1} };
	//对vs2019+opencv正确配置后方可使用，此处只给出一段读取并显示图像的参考代码，其余功能流程自行设计和查阅文献
	Mat image = imread("C:\\Users\\93954\\Pictures\\Saved Pictures\\demolena.jpg", 0);//图像的灰度值存放在格式为Mat的变量image中
	imshow("Image-original", image);
	int row = image.rows;
	int col = image.cols;
	int** La = new int* [row];
	for (int i = 0; i < row; i++)
	{
		La[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			La[i][j] = image.at<uchar>(i, j);
		}
	}
	int p, k;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B1[r][c];
				}
			}
			C1[p][k] = innersum;
			innersum = 0;
		}
	}
	innersum = 0;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B2[r][c];
				}
			}
			C2[p][k] = innersum;
			innersum = 0;
		}
	}
	innersum = 0;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B3[r][c];
				}
			}
			C3[p][k] = innersum;
			innersum = 0;
		}
	}
	innersum = 0;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B4[r][c];
				}
			}
			C4[p][k] = innersum;
			innersum = 0;
		}
	}
	innersum = 0;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B5[r][c];
				}
			}
			C5[p][k] = innersum;
			innersum = 0;
		}
	}
	innersum = 0;
	for (p = 0; p < row - 2; p++)
	{
		for (k = 0; k < col - 2; k++)
		{
			for (int r = 0; r < 3; r++)
			{
				for (int c = 0; c < 3; c++)
				{
					innersum += La[r + p][c + k] * B6[r][c];
				}
			}
			C6[p][k] = innersum;
			innersum = 0;
		}
	}
	Mat temp1 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C1);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			/*temp1.at<uchar>(i, j) = C1[i][j] / 9;*/
			temp1.at<uchar>(i, j) = C1[i][j];
		}
	}
	imshow("Image-result1", temp1);
	waitKey(0);
	Mat temp2 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C2);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp2.at<uchar>(i, j) = C2[i][j];
		}
	}
	imshow("Image-result2", temp2);
	waitKey(0);
	Mat temp3 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C3);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp3.at<uchar>(i, j) = C3[i][j];
		}
	}
	imshow("Image-result3", temp3);
	waitKey(0);
	Mat temp4 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C4);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp4.at<uchar>(i, j) = C4[i][j];
		}
	}
	imshow("Image-result4", temp4);
	waitKey(0);
	Mat temp5 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C5);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			temp5.at<uchar>(i, j) = C5[i][j];
		}
	}
	imshow("Image-result5", temp5);
	waitKey(0);
	Mat temp6 = Mat(row, col, CV_8U, Scalar::all(0));
	tran_scretch(C6);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			/*temp6.at<uchar>(i, j) = C6[i][j] / 16;*/
			temp6.at<uchar>(i, j) = C6[i][j];
		}
	}
	imshow("Image-result6", temp6);
	waitKey(0);
	destroyAllWindows();
	//提示：Mat格式可与数组相互转换
	return;
}
int find_yuzhi(IplImage* image)
{
	//若用更严谨的方式，在此可以加上断言图像不为零的语句。
	int width = image->width;//这种访问得出的宽度相当于row，但是是通过指针访问的。
	int height = image->height;//相当于col,同上。
	int x = 0, y = 0;
	int pixelCount[256];
	float pixelPro[256];
	int i, j, pixelSum = width * height, threshold = 0;
	uchar* data = (uchar*)image->imageData;
	//uchar是无符号字符类型，能接受8位二进制数，正好对应小于255的十进制数。
	//初始化  
	for (i = 0; i < 256; i++)
	{
		pixelCount[i] = 0;
		pixelPro[i] = 0;
	}
	//统计灰度级中每个像素在整幅图像中的个数  
	for (i = y; i < height; i++)
	{
		for (j = x; j < width; j++)
		{
			pixelCount[data[i * image->widthStep + j]]++;
		}
	}
	//计算每个像素在整幅图像中的比例  
	for (i = 0; i < 256; i++)
	{
		pixelPro[i] = (float)(pixelCount[i]) / (float)(pixelSum);
	}
	//经典ostu算法,得到前景和背景的分割  
	//遍历灰度级[0,255],计算出方差最大的灰度值,为最佳阈值  
	float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
	for (i = 0; i < 256; i++)
	{                   //i就是阈值。
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (j = 0; j < 256; j++)
		{
			if (j <= i) //前景部分  
			{
				//以i为阈值分类，第一类总的概率  
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else       //背景部分  
			{
				//以i为阈值分类，第二类总的概率  
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;        //前景点的平均灰度  
		u1 = u1tmp / w1;        //背景点的平均灰度  
		u = u0tmp + u1tmp;      //整幅图像的平均灰度  
		//计算类间方差  
		deltaTmp = w0 * (u0 - u) * (u0 - u) + w1 * (u1 - u) * (u1 - u);
		//找出最大类间方差以及对应的阈值  
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	//返回最佳阈值;  
	return threshold;
}
void ostu()
{
	//cvLoadImage函数后面的参数为0时，强制转化读取图像为灰度图；参数为1时，读取彩色图。
	IplImage* srcImage1 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\demolena.jpg", 0);
	//更严谨可以加上assert(NULL != srcImage);
	cvShowImage("1", srcImage1);
	//使用cvCreateImage函数创建图像首地址，并分配存储空间。
	IplImage* biImage1 = cvCreateImage(cvGetSize(srcImage1), 8, 1);
	int threshold1 = find_yuzhi(srcImage1);//计算最佳阈值
	cvThreshold(srcImage1, biImage1, threshold1, 255, THRESH_BINARY);//对图像二值化  
	cvShowImage("1now", biImage1);
	cvWaitKey(0);

	IplImage* srcImage2 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\snowball.jpg", 1);
	cvShowImage("2", srcImage2);
	IplImage* biImage2 = cvCreateImage(cvGetSize(srcImage2), 8, 3);
	int threshold2 = find_yuzhi(srcImage2);
	cvThreshold(srcImage2, biImage2, threshold2, 255, THRESH_TOZERO);
	cvShowImage("2now", biImage2);
	cvWaitKey(0);

	IplImage* srcImage3 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\polyhedrosis.jpg", 0);
	cvShowImage("3", srcImage3);
	IplImage* biImage3 = cvCreateImage(cvGetSize(srcImage3), 8, 1);
	int threshold3 = find_yuzhi(srcImage3);
	cvThreshold(srcImage3, biImage3, threshold3, 255, THRESH_BINARY);
	cvShowImage("3now", biImage3);
	cvWaitKey(0);

	IplImage* srcImage4 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\ship.jpg", 0);
	cvShowImage("4", srcImage4);
	IplImage* biImage4 = cvCreateImage(cvGetSize(srcImage4), 8, 1);
	int threshold4 = find_yuzhi(srcImage4);
	cvThreshold(srcImage4, biImage4, threshold4, 255, THRESH_BINARY);
	cvShowImage("4now", biImage4);
	cvWaitKey(0);

	IplImage* srcImage5 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\brain.jpg", 0);
	cvShowImage("5", srcImage5);
	IplImage* biImage5 = cvCreateImage(cvGetSize(srcImage5), 8, 1);
	int threshold5 = find_yuzhi(srcImage5);
	cvThreshold(srcImage5, biImage5, threshold5, 255, THRESH_BINARY);
	cvShowImage("5now", biImage5);
	cvWaitKey(0);
	destroyAllWindows();
}
void wait_for_enter()
{
	cout << endl << "程序开始，请按回车键继续";
	if (_getch() == '\r')
	{
		true;
	}
}
void menu()
{
	cout << "********************************************************";
	cout << endl;
	cout << "*" << "      " << "1 矩阵加法" << "      "
		<< "2 矩阵数乘" << "      " << "3 矩阵转置" << "      " << "*" << endl;
	cout << "*" << "      " << "4 矩阵乘法" << "      "
		<< "5 hadamard乘积" << "  " << "6 矩阵卷积" << "      " << "*" << endl;
	cout << "*" << "      " << "7 卷积应用" << "      "
		<< "8 OTSU算法" << "      " << "0 退出程序" << "      " << "*" << endl;
	cout << "********************************************************";
	cout << endl;
	cout << "选择菜单项<0~8>:";
}
int main()
{
	char choice;// 定义相关变量
	char ch;

	wait_for_enter();
	while (true) //注意该循环退出的条件
	{
		system("cls"); //清屏函数

		menu(); //调用菜单显示函数

		choice = _getch();// 按要求输入菜单选择项choice

		if (choice == '0') //选择退出
		{
			cout << "\n 确定退出吗?(如要退出输入y或Y即可)" << endl;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
				break;
			else
				continue;
		}
		switch (choice)
		{

		case '1':cout << endl; matriplus(); break;
		case '2':cout << endl; nummulti(); break;
		case '3':cout << endl; matritrans(); break;
		case '4':cout << endl; matrimulti(); break;
		case '5':cout << endl; hadamulti(); break;
		case '6':cout << endl; conv(); break;
		case '7':cout << endl; demo(); break;
		case '8':cout << endl; ostu(); break;
		default:cout << "\n 输入错误，请重新输入" << endl;
			wait_for_enter();
		}
		if (choice >= '1' && choice <= '8')
		{
			cout << "\n请按任意键重新开始" << endl;
			int input = _getch();
		}
	}
	return 0;
}