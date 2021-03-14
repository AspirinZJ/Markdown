当我们用opencv自带的接口VideoCapture 打开设备自带的摄像头或者usb连接的摄像头时。对于一些高清的摄像头画面有的时候会出现帧率很低的情况(大概是6FPS).画面获取是出现处理的第一步，太低的数据能力会对算法的处理造成一定困扰。

一般的USB接口摄像头输出格式：H.264 、YUYV、MJPEG

三者的利弊可以查看博客：https://blog.csdn.net/yangdashi888/article/details/52289036

一般情况下,我们会用如下方式获取摄像头数据

```cpp
VideoCapture cap;
cap.open(0);
while(cap.isOpened()){
     Mat in;
    cap >> in;
    ......
}
```

绝大多数情况下我们能够实时获取数据。

用videocapture获取数据时默认情况下会以数据流的原始数据格式读入，当目前接入默认以YUYV格式编码的摄像头时，同样方式导入数据时，则帧率就会很低。对此我们可以==通过改变读取摄像头格式的方法来提高数据传输速度==，虽然会损失一点图像质量，但并不很影响。

```cpp
VideoCapture cap;
VideoWriter vw;
cap.open(0);
int fourcc = vw.fourcc('M','J','P','G');//设置摄像头编码方式
cap.set(CAP_PROP_FRAME_WIDTH, FRAME_WIDTH);//设置摄像头采集图像分辨率
cap.set(CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);
cap.set(CAP_PROP_FOURCC,fourcc);
```

我们可以通过set函数设置更多参数，例如博文https://blog.csdn.net/frosuccess/article/details/79589778

在linux下通过设置CAP_PROP_FPS改变帧率会不成功～