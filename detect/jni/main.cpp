#include <jni.h>
#include <android/log.h>
#include "line_detect.h"
#include "main.h"
#include <string>

#ifndef LOG_TAG
#define LOG_TAG "line_detect"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#endif

#ifndef _Included_com_geek_linedetcet_util_LineDetectUtils
#define _Included_com_geek_linedetcet_util_LineDetectUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_geek_linedetcet_util_LineDetectUtils
 * Method:    stringFromJNI
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_geek_linedetcet_util_LineDetectUtils_stringFromJNI
  (JNIEnv *env, jobject clazz){
      const char* hello = "Hello from C++";
      return env->NewStringUTF(hello);
}

/*
 * Class:     com_geek_linedetcet_util_LineDetectUtils
 * Method:    getAlphaLine
 * Signature: ([B[BII)I
 */
JNIEXPORT jint JNICALL Java_com_geek_linedetcet_util_LineDetectUtils_getAlphaLine
  (JNIEnv *env, jobject clazz, jbyteArray yuv_img, jbyteArray binary_img, jint width, jint height){
      LOGE("get alpha line");
      int ret = -1;
      jbyte* yuv = env->GetByteArrayElements(yuv_img, JNI_FALSE);
      jbyte* binary = env->GetByteArrayElements(binary_img, JNI_FALSE);

      ret = get_line_with_alpha(yuv, binary, (int)width, (int)height);

      env->ReleaseByteArrayElements(yuv_img,yuv,JNI_FALSE);
      env->ReleaseByteArrayElements(binary_img,binary,JNI_FALSE);

      return ret;
}

/*
 * Class:     com_geek_linedetcet_util_LineDetectUtils
 * Method:    getAlphaValueAndLocation
 * Signature: ([BII[BIID[D[D[D)I
 */
JNIEXPORT jint JNICALL Java_com_geek_linedetcet_util_LineDetectUtils_getAlphaValueAndLocation
  (JNIEnv *env, jobject clazz, jbyteArray yuv_img, jint width, jint height,
  jbyteArray alpha_img, jint alpha_width, jint alpha_height,
  jdouble real_len, jdoubleArray mean_value, jdoubleArray min_array, jdoubleArray max_array){

      LOGE("get alpha value");
      int ret = -1;
      jbyte* yuv = env->GetByteArrayElements(yuv_img, JNI_FALSE);
      jbyte* alpha = env->GetByteArrayElements(alpha_img, JNI_FALSE);
      jdouble* mean = env->GetDoubleArrayElements(mean_value, JNI_FALSE);
      jdouble* min = env->GetDoubleArrayElements(min_array, JNI_FALSE);
      jdouble* max = env->GetDoubleArrayElements(max_array, JNI_FALSE);

      ret = get_need_value_and_location(yuv, (int)width, (int)height,
                                        alpha, (int)alpha_width, (int)alpha_height,
                                        (double)real_len, (double*)mean, (double*)min, (double*)max);

      env->ReleaseByteArrayElements(yuv_img,yuv,JNI_FALSE);
      env->ReleaseByteArrayElements(alpha_img,alpha,JNI_FALSE);
      env->ReleaseDoubleArrayElements(mean_value,mean,JNI_FALSE);
      env->ReleaseDoubleArrayElements(min_array,min,JNI_FALSE);
      env->ReleaseDoubleArrayElements(max_array,max,JNI_FALSE);

      return ret;

}

#ifdef __cplusplus
}
#endif
#endif