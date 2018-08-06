{
  "includes": [
        "../../common.gypi"
  ],
  "targets": [
    {
      "target_name": "uni_login",
      "product_name": "uni_login",
      "type": "static_library",
      "ldflags": [ "-ldl",
                    "-I/usr/local/include", 
                    "-L/usr/local/lib", 
                    "`pkg-config --cflags --libs protobuf grpc++", 
                    "-lgrpc++_reflection", 
                    "-D_GLIBCXX_USE_CXX11_ABI=0"
                    "-lpthread","-lrt "
                    ],
      "sources": [
        "uni_login.pb.cc",
        "uni_login.pb.h",
        "uni_login.grpc.pb.cc",
        "uni_login.grpc.pb.h",
      ],
      "include_dirs": [
        "..",
        "/usr/local/lib",
        "/usr/local/include"
      ],
      "direct_dependent_settings": {
        "include_dirs": [
          "./",
          "/usr/local/lib/",
          "/usr/local/include/"
        ],
      },
    },
  ],
}
