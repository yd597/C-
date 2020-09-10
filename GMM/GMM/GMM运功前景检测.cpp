#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "No camera !\n" << endl;
		return -1;
	}
	Mat frame, mask, foreground_BW, mid_filer, gray_dilate1;
	//---------------------------------------------------------------------
	BackgroundSubtractorMOG bgSubtractor(5, 5, 0.5, false);
	//构造混合高斯模型 参数1：使用历史帧的数量 2：混合高斯个数，3：背景比例 4：:噪声权重

	while (1)
	{
		capture >> frame;
		imshow("frame_resize", frame);
		bgSubtractor(frame, mask, 0.7);
		imshow("gauss", mask);
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		threshold(mask, foreground_BW, 20, 255, 0);//二值化通常设置为50  255
		medianBlur(foreground_BW, mid_filer, 3);     //中值滤波法
		imshow("mid_filer", mid_filer);
		dilate(mid_filer, gray_dilate1, element);//膨胀
		imshow("gray_dilate1", gray_dilate1);
		char c = waitKey(33);
		if (c == 27) break;

	}
}
