{
    "targets": [
        {
            "target_name": "libloginsystem_jni",
            "type": "shared_library",
            "dependencies": [
              "deps/djinni/support-lib/support_lib.gyp:djinni_jni",
            ],
            "ldflags": [ "-llog", "-Wl,--build-id,--gc-sections,--exclude-libs,ALL","-D_GLIBCXX_USE_CXX11_ABI=0"],
            "sources": [
              "deps/djinni/support-lib/jni/djinni_main.cpp",
              "<!@(python glob.py generated-src/jni   '*.cpp' '*.hpp')",
              "<!@(python glob.py generated-src/cpp   '*.cpp' '*.hpp')",
              "<!@(python glob.py /usr/local/lib '*.a')",
              "<!@(python glob.py /usr/local/include '*.h', '*.c')",
              "<!@(python glob.py handwritten-src/cpp '*.cpp' '*.hpp', '*.c', '*.h')",
            ],
            "include_dirs": [
              "/usr/local/include",
              "/usr/local/lib"
              "generated-src/jni",
              "generated-src/cpp",
              "handwritten-src/jni",
              "handwritten-src/cpp",
            ],
        },
        {
            "target_name": "libloginsystem_objc",
            "type": 'static_library',
            "dependencies": [
              "deps/djinni/support-lib/support_lib.gyp:djinni_objc",
            ],
            "sources": [
              "<!@(python glob.py generated-src/objc  '*.cpp' '*.mm' '*.m' '*.h' '*.hpp')",
              "<!@(python glob.py generated-src/cpp   '*.cpp' '*.hpp')",
              "<!@(python glob.py /usr/local/lib '*.a')",
              "<!@(python glob.py /usr/local/include '*.h', '*.c')",
              "<!@(python glob.py handwritten-src/cpp '*.cpp' '*.hpp', '*.c', '*.h')",
            ],
            "include_dirs": [
              "generated-src/objc",
              "generated-src/cpp",
              "handwritten-src/objc",
              "handwritten-src/cpp",
            ],
        },
    ],
}
