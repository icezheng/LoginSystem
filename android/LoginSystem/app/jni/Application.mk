# Android makefile for textsort shared lib, jni wrapper around libtextsort C API

APP_ABI := all
APP_OPTIM := release
APP_PLATFORM := android-15
# GCC 4.9 Toolchain - requires NDK r16
# NDK_TOOLCHAIN_VERSION = 4.9
# GNU libc++ is the only Android STL which supports C++11 features
# APP_STL := gnustl_static
APP_STL := c++_static
NDK_TOOLCHAIN_VERSION = clang
APP_BUILD_SCRIPT := jni/Android.mk
APP_MODULES := libloginsystem_jni
LOCAL_CFLAGS := -std=c++11
APP_CPPFLAGS := -std=c++11