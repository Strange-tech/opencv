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
		cout << "�ֱ��������1��2��������������" << endl;
		cin >> m1 >> n1 >> m2 >> n2;
		if (m1 != m2 || n1 != n2)
		{
			cout << "������ľ���û����ѽ���ٸ���һ�λ��ᣡ" << endl;
			continue;
		}
		else
		{
			m = m1; n = n1;
		}
		cout << "�������1��" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> a[r][c];
			}
		}
		cout << "�������2��" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> b[r][c];
			}
		}
		cout << "��������֮��Ϊ��" << endl;
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
	cout << "��������������������" << endl;
	cin >> m >> n;
	cout << "����þ���" << endl;
	for (r = 0; r < m; r++)
	{
		for (c = 0; c < n; c++)
		{
			cin >> a[r][c];
		}
	}
	cout << "�������Ҫ�˵�����" << endl;
	cin >> k;
	cout << "�������˵Ľ��Ϊ��" << endl;
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
	cout << "��������������������" << endl;
	cin >> m >> n;
	cout << "����Ҫת�õľ���" << endl;
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
	cout << "ת�ú�ľ���Ϊ��" << endl;
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
		cout << "�ֱ��������1��2�����������������ĸ�������" << endl;
		cin >> m >> n >> p >> q;
		if (n == p)
		{
			cout << "�������1��" << endl;
			for (r = 0; r < m; r++)
			{
				for (c = 0; c < n; c++)
				{
					cin >> a[r][c];
				}
			}
			cout << "�������2��" << endl;
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
			cout << "��������֮��Ϊ��" << endl;
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
			cout << "������ľ���û���˰����ٸ���һ�λ��ᣡ" << endl;
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
		cout << "�ֱ��������1��2��������������" << endl;
		cin >> m1 >> n1 >> m2 >> n2;
		if (m1 != m2 || n1 != n2)
		{
			cout << "������ľ���û����ѽ���ٸ���һ�λ��ᣡ" << endl;
			continue;
		}
		else
		{
			m = m1; n = n1;
		}
		cout << "�������1��" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> a[r][c];
			}
		}
		cout << "�������2��" << endl;
		for (r = 0; r < m; r++)
		{
			for (c = 0; c < n; c++)
			{
				cin >> b[r][c];
			}
		}
		cout << "���������Hadamard�˻�Ϊ��" << endl;
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
	cout << "�������A�Ľ�����" << endl;
	cin >> n;
	cout << "������������ֵ��" << endl;
	cin >> padding;
	n += (padding * 2);
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			A[r][c] = 0;
		}
	}
	cout << "�������A������������ʱ��n�ױ���һ�£���" << endl;
	for (r = padding; r < n - padding; r++)
	{
		for (c = padding; c < n - padding; c++)
		{
			cin >> A[r][c];
		}
	}
	cout << "��ʾһ������ľ���" << endl;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < n; c++)
		{
			cout << A[r][c] << " ";
		}
		cout << endl;
	}
	cout << "�������B(�涨����3��)��" << endl;
	for (r = 0; r < 3; r++)
	{
		for (c = 0; c < 3; c++)
		{
			cin >> B[r][c];
		}
	}
	cout << "�������Ϊ��" << endl;
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
	//��vs2019+opencv��ȷ���ú󷽿�ʹ�ã��˴�ֻ����һ�ζ�ȡ����ʾͼ��Ĳο����룬���๦������������ƺͲ�������
	Mat image = imread("C:\\Users\\93954\\Pictures\\Saved Pictures\\demolena.jpg", 0);//ͼ��ĻҶ�ֵ����ڸ�ʽΪMat�ı���image��
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
	//��ʾ��Mat��ʽ���������໥ת��
	return;
}
int find_yuzhi(IplImage* image)
{
	//���ø��Ͻ��ķ�ʽ���ڴ˿��Լ��϶���ͼ��Ϊ�����䡣
	int width = image->width;//���ַ��ʵó��Ŀ���൱��row��������ͨ��ָ����ʵġ�
	int height = image->height;//�൱��col,ͬ�ϡ�
	int x = 0, y = 0;
	int pixelCount[256];
	float pixelPro[256];
	int i, j, pixelSum = width * height, threshold = 0;
	uchar* data = (uchar*)image->imageData;
	//uchar���޷����ַ����ͣ��ܽ���8λ�������������ö�ӦС��255��ʮ��������
	//��ʼ��  
	for (i = 0; i < 256; i++)
	{
		pixelCount[i] = 0;
		pixelPro[i] = 0;
	}
	//ͳ�ƻҶȼ���ÿ������������ͼ���еĸ���  
	for (i = y; i < height; i++)
	{
		for (j = x; j < width; j++)
		{
			pixelCount[data[i * image->widthStep + j]]++;
		}
	}
	//����ÿ������������ͼ���еı���  
	for (i = 0; i < 256; i++)
	{
		pixelPro[i] = (float)(pixelCount[i]) / (float)(pixelSum);
	}
	//����ostu�㷨,�õ�ǰ���ͱ����ķָ�  
	//�����Ҷȼ�[0,255],������������ĻҶ�ֵ,Ϊ�����ֵ  
	float w0, w1, u0tmp, u1tmp, u0, u1, u, deltaTmp, deltaMax = 0;
	for (i = 0; i < 256; i++)
	{                   //i������ֵ��
		w0 = w1 = u0tmp = u1tmp = u0 = u1 = u = deltaTmp = 0;
		for (j = 0; j < 256; j++)
		{
			if (j <= i) //ǰ������  
			{
				//��iΪ��ֵ���࣬��һ���ܵĸ���  
				w0 += pixelPro[j];
				u0tmp += j * pixelPro[j];
			}
			else       //��������  
			{
				//��iΪ��ֵ���࣬�ڶ����ܵĸ���  
				w1 += pixelPro[j];
				u1tmp += j * pixelPro[j];
			}
		}
		u0 = u0tmp / w0;        //ǰ�����ƽ���Ҷ�  
		u1 = u1tmp / w1;        //�������ƽ���Ҷ�  
		u = u0tmp + u1tmp;      //����ͼ���ƽ���Ҷ�  
		//������䷽��  
		deltaTmp = w0 * (u0 - u) * (u0 - u) + w1 * (u1 - u) * (u1 - u);
		//�ҳ������䷽���Լ���Ӧ����ֵ  
		if (deltaTmp > deltaMax)
		{
			deltaMax = deltaTmp;
			threshold = i;
		}
	}
	//���������ֵ;  
	return threshold;
}
void ostu()
{
	//cvLoadImage��������Ĳ���Ϊ0ʱ��ǿ��ת����ȡͼ��Ϊ�Ҷ�ͼ������Ϊ1ʱ����ȡ��ɫͼ��
	IplImage* srcImage1 = cvLoadImage("C:\\Users\\93954\\Pictures\\Saved Pictures\\demolena.jpg", 0);
	//���Ͻ����Լ���assert(NULL != srcImage);
	cvShowImage("1", srcImage1);
	//ʹ��cvCreateImage��������ͼ���׵�ַ��������洢�ռ䡣
	IplImage* biImage1 = cvCreateImage(cvGetSize(srcImage1), 8, 1);
	int threshold1 = find_yuzhi(srcImage1);//���������ֵ
	cvThreshold(srcImage1, biImage1, threshold1, 255, THRESH_BINARY);//��ͼ���ֵ��  
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
	cout << endl << "����ʼ���밴�س�������";
	if (_getch() == '\r')
	{
		true;
	}
}
void menu()
{
	cout << "********************************************************";
	cout << endl;
	cout << "*" << "      " << "1 ����ӷ�" << "      "
		<< "2 ��������" << "      " << "3 ����ת��" << "      " << "*" << endl;
	cout << "*" << "      " << "4 ����˷�" << "      "
		<< "5 hadamard�˻�" << "  " << "6 ������" << "      " << "*" << endl;
	cout << "*" << "      " << "7 ���Ӧ��" << "      "
		<< "8 OTSU�㷨" << "      " << "0 �˳�����" << "      " << "*" << endl;
	cout << "********************************************************";
	cout << endl;
	cout << "ѡ��˵���<0~8>:";
}
int main()
{
	char choice;// ������ر���
	char ch;

	wait_for_enter();
	while (true) //ע���ѭ���˳�������
	{
		system("cls"); //��������

		menu(); //���ò˵���ʾ����

		choice = _getch();// ��Ҫ������˵�ѡ����choice

		if (choice == '0') //ѡ���˳�
		{
			cout << "\n ȷ���˳���?(��Ҫ�˳�����y��Y����)" << endl;
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
		default:cout << "\n �����������������" << endl;
			wait_for_enter();
		}
		if (choice >= '1' && choice <= '8')
		{
			cout << "\n�밴��������¿�ʼ" << endl;
			int input = _getch();
		}
	}
	return 0;
}