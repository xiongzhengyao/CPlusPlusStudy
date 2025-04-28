LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

# 设置模块名称
LOCAL_MODULE := mathlib

# 设置源文件
LOCAL_SRC_FILES := \
    src/mathlib.cpp

# 设置头文件搜索路径
LOCAL_C_INCLUDES := \
    $(LOCAL_PATH)/include \
    $(LOCAL_PATH)/../include

# 设置编译标志
LOCAL_CFLAGS := -Wall -Werror

# 设置链接标志
LOCAL_LDFLAGS := -Wl,--no-warn-shared-textrel

# 设置要链接的库
LOCAL_LDLIBS := -llog

# 构建动态库
include $(BUILD_SHARED_LIBRARY) 