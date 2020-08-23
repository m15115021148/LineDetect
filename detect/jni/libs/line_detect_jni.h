
#ifndef LINE_DETECT_JNI_H__
#define LINE_DETECT_JNI_H__
#include "jni.h"
#include "jni_md.h"
#include "line_detect.h"

#include <android/log.h>  

#ifndef LOG_TAG  
#define LOG_TAG "line_detect"  
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)  
#endif 

#ifdef __cplusplus
extern "C" {
#endif

/*

The function get a binary image by pass a color image.

src_img: input YUV format.
binary_img: output binary image .
width: src_img width.
height: src_img height.

return value:
	0: success.
	-1: src_img is empty.
	-2: binary_img new memory fail.
*/
JNIEXPORT jint JNICALL get_alpha_line(JNIEnv* _env, jobject obj, jbyte* yuv_img, jbyte* binary_img, jint width, jint height)
{
	LOGE("enter_get_alpha_line");
	return get_line_with_alpha(yuv_img, binary_img, (int)width, (int)height);
}

/*
The function get image line mean, min, max width and min and max location.

yuv_img: input YUV format.
yuv_width: yuv img width.
yuv_height: yuv img height.

alpha_img: alpha image.
real_lenth: real lenth of the src_img line.
alpha_width: alpha img width.
alpha_height: alpha img height.
real_len: real length of the line.

mean_value: mean value.
min_array: is array, first value is min value, second is x location, third is y location.
max_array: is array, first value is max value, second is x location, third is y location.

return value:
	0: success.
	-1: src_img is empty.
	-2: binary_img new memory fail.
*/
JNIEXPORT jint JNICALL get_line_value(JNIEnv* _env, jobject obj, jbyte* yuv_img, jint yuv_width, jint yuv_height, jbyte* alpha_img, jint alpha_width, jint alpha_height,
	jdouble real_len, jdouble* mean_value, jdouble* min_array, jdouble* max_array)
{
	LOGE("enter_get_line_value");
	return get_need_value_and_location(yuv_img, (int)yuv_width, (int)yuv_height, alpha_img, (int)alpha_width, (int)alpha_height,
		(double)real_len, (double)mean_value, (double)min_array, (double)max_array);
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif // ! LINE_DETECT_JNI_H__
