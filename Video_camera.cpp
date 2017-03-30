#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main()
{
	Mat edges;
	VideoCapture capture(0);
	while(1)
	{
		Mat frame;
		capture>>frame;

		cvtColor(frame,edges,CV_BGR2GRAY);

		blur(edges,edges,Size(7,7));
		Canny(edges,edges,0,30,3);
		imshow("video",edges);
		if (waitKey(30) >= 0)
		{
			break;
		}
		//waitKey(30);
	}

	return(0);
}
