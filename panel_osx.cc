#import <CoreServices/CoreServices.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <objc/objc-runtime.h>

#include <napi.h>

using namespace Napi;

@interface PROPanel : NSPanel
@end

@implementation PROPanel
- (BOOL)needsPanelToBecomeKey {
  return YES;
}
- (BOOL)acceptsFirstResponder {
  return YES;
}
@end

// Buffer<char> to_buffer(napi_env env, Object& data) {
//   return Buffer::Data() data
// }

void MakePanel(const CallbackInfo& info) {
  char* handleBuffer = info[0].As<Napi::Buffer<char >>().Data();
  NSView* mainContentView = *reinterpret_cast<NSView**>(handleBuffer);
  object_setClass(mainContentView.window, [PROPanel class]);
  mainContentView.window.styleMask |= NSWindowStyleMaskNonactivatingPanel;
  [mainContentView.window setCollectionBehavior: NSWindowCollectionBehaviorTransient | NSWindowCollectionBehaviorMoveToActiveSpace | NSWindowCollectionBehaviorFullScreenAuxiliary ];
  [mainContentView.window setLevel:NSFloatingWindowLevel];
  [mainContentView.window setFloatingPanel:YES];
}

void MakeKeyWindow(const Napi::CallbackInfo& info) {
  char* handleBuffer = info[0].As<Napi::Buffer<char >>().Data();
  NSView* mainContentView = *reinterpret_cast<NSView**>(handleBuffer);
  [mainContentView.window makeKeyWindow];
}

Napi::Object Init(Napi::Env env, Napi::Obejct exports) {
  exports.Set(Napi::Object(env, "makePanel"), Napi::Function::New(env, MakePanel));
  exports.Set(Napi::Object(env, "makeKeyWindow"), Napi::Function::New(env, MakeKeyWindow));
  return exports;
}
