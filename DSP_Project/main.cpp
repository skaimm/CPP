#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using std::cout;
using std::cin;
using std::endl;

using namespace cv;

void im_histogram(Mat image, int histogram[])
{

    // initialize all intensity values to 0
    for(int i = 0; i < 256; i++)
    {
        histogram[i] = 0;
    }

    // calculate the no of pixels for each intensity values
    for(int y = 0; y < image.rows; y++)
        for(int x = 0; x < image.cols; x++)
            histogram[(int)image.at<uchar>(y,x)]++;

}

void cum_histogram(int histogram[], int cumhistogram[])
{
    cumhistogram[0] = histogram[0];

    for(int i = 1; i < 256; i++)
    {
        cumhistogram[i] = histogram[i] + cumhistogram[i-1];
    }
}

void histogram_Display(int histogram[], const char* name)
{
    int hist[256];
    for(int i = 0; i < 256; i++)
    {
        hist[i]=histogram[i];
    }
    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double) hist_w/256);

    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

    // find the maximum intensity element from histogram
    int max = hist[0];
    for(int i = 1; i < 256; i++){
        if(max < hist[i]){
            max = hist[i];
        }
    }

    // normalize the histogram between 0 and histImage.rows

    for(int i = 0; i < 256; i++){
        hist[i] = ((double)hist[i]/max)*histImage.rows;
    }


    // draw the intensity line for histogram
    for(int i = 0; i < 256; i++)
    {
        line(histImage, Point(bin_w*(i), hist_h),
                              Point(bin_w*(i), hist_h - hist[i]),
             Scalar(0,0,0), 1, 8, 0);
    }

    // display histogram
    namedWindow(name, CV_WINDOW_AUTOSIZE);
    imshow(name, histImage);
}



int main()
{
    // Load the image
    Mat image = imread("image.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    int rows=image.rows;
    int cols=image.cols;

    if (image.empty())
    {
      cout << "Cannot load image!" << endl;
      return -1;
    }

    // Generate the histogram
    int histogram[256];
    im_histogram(image, histogram);

    // Caluculate the size of image
    int size = rows * cols;
    float alpha = 255.0/size;

    // Calculate the probability of each intensity
    float PrRk[256];
    for(int i = 0; i < 256; i++)
    {
        PrRk[i] = (double)histogram[i] / size;
    }

    // Generate cumulative frequency histogram
    int cumhistogram[256];
    cum_histogram(histogram,cumhistogram );

    // Scale the histogram
    int Sk[256];
    for(int i = 0; i < 256; i++)
    {
        Sk[i] = cvRound((double)cumhistogram[i] * alpha);
    }


    // Generate the equlized histogram
    float PsSk[256];
    for(int i = 0; i < 256; i++)
    {
        PsSk[i] = 0;
    }

    for(int i = 0; i < 256; i++)
    {
        PsSk[Sk[i]] += PrRk[i];
    }

    int final[256];
    for(int i = 0; i < 256; i++)
        final[i] = cvRound(PsSk[i]*255);


    // Generate the equlized image
    Mat new_image = image.clone();

    for(int y = 0; y < rows; y++)
        for(int x = 0; x < cols; x++)
            new_image.at<uchar>(y,x) = saturate_cast<uchar>(Sk[image.at<uchar>(y,x)]);


    cout<<"the output for matrix of pixels";

    //code to access pixel values of an image
    cout<<"\nbefore blur";
    for (int i = 0; i <rows; i++)
    {
        Vec3b *ptr = image.ptr<Vec3b>(i);

        for (int j = 0; j < cols; j++)
        {
        Vec3b pixel = ptr[j];
        //cout<<pixel<<"\t";
        }
        cout<<"\n";
    }
    Mat image1=image.clone();//cloning image

    GaussianBlur( image, image1, Size( 7, 7), 0, 0 );//applying Gaussian filter


    cout<<"\nafter blur";

    //code to access pixel values of an image
    for (int i = 0; i < rows; i++)
    {
        Vec3b *ptr = image1.ptr<Vec3b>(i);

        for (int j = 0; j < cols; j++)
        {
        Vec3b pixel = ptr[j];
        }
        cout<<"\n";
    }

    namedWindow("Blur Image");
    imshow("Image with Blur:",image1);//displaying image1
    imwrite("C:/Users/ultrAslan/Desktop/project-dsp/blur.jpg", image1);



    // Display the original Histogram
    histogram_Display(histogram, "Blur Image");

   // Display the original Image
    namedWindow("Original Image");
    imshow("Original Image", image);


    // Display the original Histogram
    histogram_Display(histogram, "Original Histogram");

    // Display equilized image
    namedWindow("Equilized Image");
    imshow("Equilized Image",new_image);
    imwrite("C:/Users/ultrAslan/Desktop/project-dsp/equilized.jpg", new_image);

    // Display the equilzed histogram
    histogram_Display(final, "Equilized Histogram");

    waitKey();
    return 0;
}
