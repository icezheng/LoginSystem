# LoginSystem

## 本项目主要采用grpc框架实现了前后端通讯，主要实现了注册，登陆，检查重复登录的能力。

### Android端代码主要有以下几块：
#### 1、protobuf和grpc相关：
/grpc目录，uni_login.proto为协议文件，通过以下protoc命令将之编译到/grpc/cpp目录下，得到相关.cc和.h，包含了message和相关req struct，后续使用grpc的channel直接发送请求与后台进行交互。

$ protoc -I ./ --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./uni_login.proto
$ protoc -I ./ --cpp_out=. ./uni_login.proto

另外，为了解决查找头文件等问题，有人提到可以使用pkg-config来解决查找问题。一般来说，标准安装方式安装好grpc，其文件和依赖库分别存放在/usr/local/include和/usr/local/lib下，如果不是，则需要进行一些配置。

#### 2、djinni相关：
djinni是一套解决跨平台的方案，通过.djinni协议编译编译出多平台接口代码，相关实现可以通过多种语言实现，更可以利用各平台特性，提供相关接口代理，将具体实现下放到各平台方，以此解决平台兼容性问题。

通过下载djinni和编译安装后，拟定loginsystem.djinni协议，通过参考源码example的run_djinni.sh脚本，修改其路径和相关输出目录，运行编译后将会输出到/generated-src目录下，根据各平台所需，引入相关目录文件即可。

##### 下载djinni：
https://github.com/dropbox/djinni.git

##### 编译安装djinni：
$ cd [djinni_root]/
$ src/build

##### 编译.djinni协议：
$ sh ./run_djinni.sh

#### 3.makefile相关：

本项目采用了google的gyp构建框架来实现makefile相关编写（主要是受到djinni项目影响），gyp是通过实现了.gyp脚本及.gypi基础脚本来编译得到各平台的makeFile文件。

###### gyp源码：
https://chromium.googlesource.com/external/gyp/

注意:
1、gprc需要使用std::c++11来进行编译，不然会出现很多引用丢失的问题，因此cflags需要配置好，具体可以参考本项目的common.gypi文件。
2、为了避免依赖库查找问题，include_dirs里可以设置好相关依赖目录

### Server端代码：

#### 本项目服务器端采用Go语言实现，主要是grpc用go实现起来比较方便，而且go语言实现起来比C++优雅，因此决定采用go。

server相关代码都放在了/server目录下，server端同样需要解析.proto协议，例如本项目解析后得到uni_login.pb.go，其主要也是提供了一些struct和function以提供调用，在main方法入口里，痛过grpc.newServer我们将获得grpc的相关服务，再通过RegisterUniLoginServer以绑定服务。

server具体实现了两张表，table_user存储了用户的业务数据，table_user_session则存储了用户的关键唯一性数据。

#### 关于多端登陆问题：

本项目要求，同一个用户只能在一端登陆，因此当发现多端登陆时，需要旧的一方踢下线，这里的方案是：

登陆后返回sessionId，客户端需要将sessionId存储在内存，每次发任何请求时都需要带上，后台每次处理请求前，都将对sessionId的可用性进行检查，如果发现sessionId不可用，则返回错误码，客户端处理错误码进行退出登录处理。




