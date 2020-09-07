#include <iostream> 
#include <opencv2/opencv.hpp> 
#include <thread>

using namespace cv; 

void printImageShape (Mat image) {

    if ( !image.data) 
    {
        printf("No Image data \n" ); 
    }

    else 
    {
        printf("%i \n", image.size().height);
        printf("%i \n", image.size().width);
    }

}

void printTestMessage () {
    std::cout << "In a thread" << "\n";
}

int main(int argc, char** argv)  {

    if (argc != 2)
    {
        printf( "usage: DisplayImage.out <Image_Path>\n"); 
        return -1; 
    }

    Mat image; 
    image = imread(argv[1], 1); 

    std::thread test(printImageShape,image);
    std::thread test2(printTestMessage);

    test.join(); 
    test2.join(); 

    std::cout << "Threads completed" <<'\n'; 

  
    

}
