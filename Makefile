#
# Environment variables for overriding default behavior.
#

ifndef ANDROID_NDK_HOME
ANDROID_NDK_HOME = $(abspath $(dir $(realpath $(shell which ndk-build))))
endif

SCALA_VERSION=2.11
DJINNI_VERSION=0.1-SNAPSHOT
OUTPUT_JAR=src/target/scala-$(SCALA_VERSION)/djinni-assembly-$(DJINNI_VERSION).jar

#
# Global targets.
#

all: djinni android test

clean: 
	-ndk-build -C android/LoginSystem/app clean
	-rm -rf libs/
	-rm -rf obj/
	-rm -rf build/
	-rm -rf build_ios/
	-rm -rf GypAndroid.mk/

# rule to lazily clone gyp
# freeze gyp at the last version with android support
./deps/gyp:
	git clone https://chromium.googlesource.com/external/gyp.git ./deps/gyp
	cd deps/gyp && git checkout -q 0bb67471bca068996e15b56738fa4824dfa19de0

djinni:
	cd deps/djinni/src && ./build

$(OUTPUT_JAR):
	cd deps/djinni/src && sbt assembly

djinni_jar: $(OUTPUT_JAR)

djinni_jar_clean:
	cd deps/djinni/src && sbt clean

# we specify a root target for android to prevent all of the targets from spidering out
GypAndroid.mk: ./deps/gyp ./libloginsystem.gyp ./deps/djinni/support-lib/support_lib.gyp ./loginsystem.djinni
	./run_djinni.sh
	ANDROID_BUILD_TOP=$(ANDROID_NDK_HOME) deps/gyp/gyp --depth=. -f android -DOS=android -Icommon.gypi ./libloginsystem.gyp --root-target=libloginsystem_jni


# this target implicitly depends on GypAndroid.mk since gradle will try to make it
android: GypAndroid.mk
	cd android/LoginSystem/ && ./gradlew app:assembleDebug
	@echo "Apks produced at:"
	@python ./glob.py ./android '*.apk'

test: ./deps/java
	make -C test-suite

.PHONY: android ios test djinni clean all dinni_jar
