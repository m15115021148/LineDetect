#ifndef LINE_DETECT_H__
#define LINE_DETECT_H__

#include <iostream>
using namespace std;

//#define EXPORT

#ifdef __cplusplus
extern "C" {
#endif


    int get_line_with_alpha(void* yuv_img, void* binary_img, int width, int height);


	int get_need_value_and_location(void* yuv_img, int yuv_width, int yuv_height,
	                                void* alpha_img, int alpha_width, int alpha_height,
	                                double real_len, double* mean_value, double* min_array,
	                                double* max_array);

#ifdef __cplusplus
}
#endif

#endif // !LINE_DETECT_H__

