package com.geek.linedetcet.util;

/**
 * Created by  on 2020/8/22.
 */
public class LineDetectUtils {

    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("detect_line");
    }

    public static native String stringFromJNI();

    public static native int getAlphaLine(byte[] yuv_img, byte[] binary_img, int width, int height);

    public static native int getAlphaValueAndLocation(
            byte[] yuv_img, int width, int height,
            byte[] alpha_img, int alpha_width, int alpha_height,
            double real_len, double[] mean_value, double[] min_array, double[] max_array
    );

}
