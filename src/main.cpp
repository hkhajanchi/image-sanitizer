#include <iostream> 
#include <opencv2/opencv.hpp> 

using namespace cv; 
int main(int argc, char** argv)  {

    if (argc != 2)
    {
        printf( "usage: DisplayImage.out <Image_Path>\n"); 
        return -1; 
    }

    Mat image; 
    image = imread(argv[1], 1); 

    if ( !image.data) 
    {
        printf("No Image data \n" ); 
        return -1; 
    }

    else 
    {
        printf("%i \n", image.size().height);
        printf("%i \n", image.size().width);
        return 0; 
    }

    

}
