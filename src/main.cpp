#include <iostream> 
#include <opencv2/opencv.hpp> 
#include <opencv2/core/utility.hpp> 
#include <thread>
#include "time.h" 

using namespace cv; 

void imageProcessLambda(Mat image) { 

    std::cout << image.size().height << '\n'; 
    std::cout << image.size().width  << '\n'; 
    std::cout << "Image Processing completed" << '\n';
} 

void runThreaded (std::vector<Mat> images) {
    std::vector<std::thread> threadPool; 
    for (size_t i = 0; i < images.size(); i++)
    {
        threadPool.push_back(std::thread(imageProcessLambda, images[i]));
    }
    for (auto& thread: threadPool) {
        thread.join(); 
    }
}

void runNonThreaded(std::vector<Mat> images) {
    for (size_t i = 0; i < images.size(); i++)
    {
        imageProcessLambda(images[i]);
    }
}

void processPaths (std::vector<cv::String> paths, int i) {
    std::vector<Mat> image_batch; 

      for (int j = i; j < i + 3200; j++) {
          image_batch.push_back(imread(paths[j])); 
      }
}
int main(int argc, char** argv)  {

    // Load all images in GrassClover dataset 
    std::vector<cv::String> paths; 
    glob("/images/all_images/*.jpg", paths, false); 
    std::cout << paths.size() << "\n"; 

    auto cnt = paths.size(); 
    int data_chunk = 3200; // load in 3200 images at any given iteration 
  /* 
  We have 32000 images, which obviously can't be loaded all into RAM without crashing the computer 
  Therefore, i'm loading 3200 images at a time, and dividing it to 32 threads 
  */

  for (int i = 0; i < cnt; i+=data_chunk)   
  {
      processPaths(paths, i);
      std::cout << "Chunk " << i << "Processed." << "\n";

  } 

}
