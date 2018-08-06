{
  "targets": [
    {
      "target_name": "uni_login",
      "type": "static_library",
      "ldflags": [ "-ldl", "-L/usr/local/lib", "`pkg-config --libs protobuf grpc++", "-lgrpc++_reflection"],
      "sources": [
        "uni_login.pb.h",
        "uni_login.pb.cc",
        "uni_login.grpc.pb.h",
        "uni_login.grpc.pb.cc",
      ],
      "include_dirs": [
        "./",
        "/usr/local/lib",
        "/usr/local/include"
      ],
      "direct_dependent_settings": {
        "include_dirs": [
          "./",
          "/usr/local/lib",
          "/usr/local/include"
        ],
      },
    },
  ],
}
