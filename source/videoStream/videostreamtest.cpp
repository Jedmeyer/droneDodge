

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>


#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/videoio.hpp>


using namespace std;
using namespace cv;

void vidDisplay(VideoCapture source){
	Mat vidFrame;
	
	while(1){
		source >> vidFrame;
		imshow("Drone Stream:", vidFrame);
		waitKey(1);
		char c = (char)waitKey(25);
		if(27==c)
			break;

	}
}


int main(int argc, char** argv){
	string droneIP = "tcp://192.168.1.1:5555";
	string testvid = "testvid.mp4";
	VideoCapture captReference(droneIP, CAP_FFMPEG);
	//VideoCapture captReference(testvid);



	if ( !captReference.isOpened() )
	{
		int a =0;
		cout << "\nStream not found, please modify settings.\n";
		cin >> a;
		return -1;
	}
	vidDisplay(captReference);

	captReference.release();
	destroyAllWindows();
	return(0);
}