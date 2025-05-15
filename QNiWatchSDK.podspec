#
# Be sure to run `pod lib lint QNWatchSDK.podspec --allow-warnings' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
s.name             = 'QNiWatchSDK'
s.version          = '2.0.3'
s.summary          = '轻牛旗下设备通讯类'

s.description      = '支持智能体脂秤'

s.homepage         = 'https://github.com/YolandaQingniu/sdk-watchOS-demo'
s.license          = { :type => 'MIT', :file => 'LICENSE' }
s.author           = { 'service@qnniu.com' => 'service@qnniu.com' }
s.source           = { :git => 'https://github.com/YolandaQingniu/sdk-watchOS-demo.git', :tag => s.version.to_s}
s.watchos.deployment_target = "4.0"
s.vendored_frameworks = 'QNDeviceSDKWatch WatchKit Extension/QNDeviceSDK_watchos.framework'
s.source_files = 'QNDeviceSDKWatch WatchKit Extension/QNDeviceSDK_watchos.framework/Headers/*.h'
s.public_header_files = 'QNDeviceSDKWatch WatchKit Extension/QNDeviceSDK_watchos.framework/Headers/*.h'
s.static_framework = true
s.frameworks = 'CoreBluetooth'
s.pod_target_xcconfig = {
  'VALID_ARCHS' => 'arm64 arm64_32 armv7k', # 声明 SDK 支持的架构（真机）
  'EXCLUDED_ARCHS[sdk=watchsimulator*]' => 'arm64 arm64_32 armv7k x86_64',  # 排除模拟器架构（避免编译冲突）
  'OTHER_LDFLAGS' => '-ObjC -all_load'  # 确保分类方法被加载
}

end
