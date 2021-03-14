opencv中通过VideoCaptrue类==对视频进行读取操作以及调用摄像头==，下面是该类的API。



# VideoCapture类的构造函数

```c++
// C++
VideoCapture::VideoCapture();
VideoCapture::VideoCapture(const string& filename);
VideoCapture::VideoCapture(int device);
VideoCapture::VideoCapture (const String &filename, int apiPreference);
VideoCapture::VideoCapture (int index, int apiPreference);
```

功能：创建一个VideoCapture类的实例，如果传入对应的参数，可以直接打开视频文件或者要调用的摄像头。

参数:
filename – 打开的视频文件名。

device – 打开的视频捕获设备id ，如果只有一个摄像头可以填0，表示打开默认的摄像头。 



# VideoCapture::open

功能：打开一个视频文件或者打开一个捕获视频的设备（也就是摄像头）

```cpp
bool VideoCapture::open(const string& filename)
bool VideoCapture::open(int device)
```

参数: 
filename – 打开的视频文件名。

device – 打开的视频捕获设备id ，如果只有一个摄像头可以填0，表示打开默认的摄像头。



通过对VideoCapture类的构造函数和open函数分析，可以发现opencv读入视频的方法一般有如下两种。比如读取当前目录下名为"dog.avi"的视频文件，那么这两种写法分别如下。

1. 先实例化再初始化：

   ```cpp
   VideoCapture capture;
   capture.open("dog.avi");
   ```

2. 在实例化的同时进行初始化：

   ```cpp
   VideoCapture("dog.avi");
   ```

# VideoCapture::isOpened

`bool VideoCapture::isOpened()`
功能：判断视频读取或者摄像头调用是否成功，成功则返回true。

# VideoCapture::release

`void VideoCapture::release()`
功能：关闭视频文件或者摄像头。

# VideoCapture::grab

`bool VideoCapture::grab()`
功能：从视频文件或捕获设备中抓取下一个帧，假如调用成功返回true。

# VideoCapture::read

`bool VideoCapture::read(Mat& image)`

`VideoCapture& VideoCapture::operator>>(Mat& image)`

功能：该函数结合VideoCapture::grab()和VideoCapture::retrieve()其中之一被调用，用于捕获、解码和返回下一个视频帧。这是一个最方便的函数对于读取视频文件或者捕获数据从解码和返回刚刚捕获的帧，假如没有视频帧被捕获（相机没有连接或者视频文件中没有更多的帧）将返回false。

8.

 **从上面的API中我们会发现获取视频帧可以有多种方法 ：**

```cpp
// 方法一 
capture.read(frame); 

// 方法二 
capture.grab(); 

// 方法三
capture.retrieve(frame); 

// 方法四
capture >> frame;
```

# VideoCapture::retrieve

`bool VideoCapture::retrieve(Mat& image, int channel=0)`
功能：解码并且返回刚刚抓取的视频帧，假如没有视频帧被捕获（相机没有连接或者视频文件中没有更多的帧）将返回false。

# VideoCapture::get

`double VideoCapture::get(int propId)`

功能：一个视频有很多属性，比如：帧率、总帧数、尺寸、格式等，VideoCapture的get方法可以获取这些属性。

参数：属性的ID。

属性的ID可以是下面的之一：

```python
CV_CAP_PROP_POS_MSEC Current position of the video file in milliseconds or video capture timestamp.
CV_CAP_PROP_POS_FRAMES 0-based index of the frame to be decoded/captured next.
CV_CAP_PROP_POS_AVI_RATIO Relative position of the video file: 0 - start of the film, 1 - end of the film.
CV_CAP_PROP_FRAME_WIDTH Width of the frames in the video stream.
CV_CAP_PROP_FRAME_HEIGHT Height of the frames in the video stream.
CV_CAP_PROP_FPS Frame rate.
CV_CAP_PROP_FOURCC 4-character code of codec.
CV_CAP_PROP_FRAME_COUNT Number of frames in the video file.
CV_CAP_PROP_FORMAT Format of the Mat objects returned by retrieve() .
CV_CAP_PROP_MODE Backend-specific value indicating the current capture mode.
CV_CAP_PROP_BRIGHTNESS Brightness of the image (only for cameras).
CV_CAP_PROP_CONTRAST Contrast of the image (only for cameras).
CV_CAP_PROP_SATURATION Saturation of the image (only for cameras).
CV_CAP_PROP_HUE Hue of the image (only for cameras).
CV_CAP_PROP_GAIN Gain of the image (only for cameras).
CV_CAP_PROP_EXPOSURE Exposure (only for cameras).
CV_CAP_PROP_CONVERT_RGB Boolean flags indicating whether images should be converted to RGB.
CV_CAP_PROP_WHITE_BALANCE Currently not supported
CV_CAP_PROP_RECTIFICATION Rectification flag for stereo cameras (note: only supported by DC1394 v 2.x backend currently)
```

Note: 如果查询的视频属性是VideoCapture类不支持的，将会返回0。

# VideoCapture::set

`bool VideoCapture::set(int propertyId, double value)`

功能：设置VideoCapture类的属性，设置成功返回ture,失败返回false。

参数：第一个是属性ID，第二个是该属性要设置的值。
属性ID如下：

```python
CV_CAP_PROP_POS_MSEC Current position of the video file in milliseconds.
CV_CAP_PROP_POS_FRAMES 0-based index of the frame to be decoded/captured next.
CV_CAP_PROP_POS_AVI_RATIO Relative position of the video file: 0 - start of the film, 1 - end of the film.
CV_CAP_PROP_FRAME_WIDTH Width of the frames in the video stream.
CV_CAP_PROP_FRAME_HEIGHT Height of the frames in the video stream.
CV_CAP_PROP_FPS Frame rate.
CV_CAP_PROP_FOURCC 4-character code of codec.
CV_CAP_PROP_FRAME_COUNT Number of frames in the video file.
CV_CAP_PROP_FORMAT Format of the Mat objects returned by retrieve() .
CV_CAP_PROP_MODE Backend-specific value indicating the current capture mode.
CV_CAP_PROP_BRIGHTNESS Brightness of the image (only for cameras).
CV_CAP_PROP_CONTRAST Contrast of the image (only for cameras).
CV_CAP_PROP_SATURATION Saturation of the image (only for cameras).
CV_CAP_PROP_HUE Hue of the image (only for cameras).
CV_CAP_PROP_GAIN Gain of the image (only for cameras).
CV_CAP_PROP_EXPOSURE Exposure (only for cameras).
CV_CAP_PROP_CONVERT_RGB Boolean flags indicating whether images should be converted to RGB.
CV_CAP_PROP_WHITE_BALANCE Currently unsupported
CV_CAP_PROP_RECTIFICATION Rectification flag for stereo cameras (note: only supported by DC1394 v 2.x backend currently)
```

至此，视频捕获类VideoCapture的API介绍完了，下面是一个应用示例：

```cpp
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
	cv::VideoCapture capture(argv[1]);
	if (!capture.isOpened())
	{
		std::cout << "video not open." << std::endl;
		return 1;
	}
	//获取当前视频帧率
	double rate = capture.get(CV_CAP_PROP_FPS);
	//当前视频帧
	cv::Mat frame;
	//每一帧之间的延时
	//与视频的帧率相对应
	int delay = 1000 / rate;
	bool stop(false);
	while (!stop)
	{
		if (!capture.read(frame))
		{
			std::cout << "no video frame" << std::endl;
			break;
		}

		//此处为添加对视频的每一帧的操作方法
		int frame_num = capture.get(CV_CAP_PROP_POS_FRAMES);
		std::cout << "Frame Num : " << frame_num << std::endl;
		if (frame_num == 20)
		{
			capture.set(CV_CAP_PROP_POS_FRAMES, 10);
		}

		cv::imshow("video", frame);
		//引入延时
		//也可通过按键停止
		if (cv::waitKey(delay) > 0)
			stop = true;
	}

	//关闭视频，手动调用析构函数（非必须）
	capture.release();
	return 0;
}
```

