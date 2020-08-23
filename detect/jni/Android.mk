LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := libdetect_line
LOCAL_SRC_FILES := $(LOCAL_PATH)/libs/$(TARGET_ARCH_ABI)/libdetect_line.so

include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE    := native-lib

LOCAL_SRC_FILES := main.cpp

LOCAL_LDLIBS := -llog

LOCAL_CPPFLAGS += -std=c++11

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE_TAGS :=optional

LOCAL_SHARED_LIBRARIES := libdetect_line

include $(BUILD_SHARED_LIBRARY)
