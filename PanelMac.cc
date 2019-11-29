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

Value MakePanel(const CallbackInfo& info) {
  Env env = info.Env();
  char* handleBuffer = info[0].As<Napi::Buffer<char >>().Data();

  NSView* mainContentView = *reinterpret_cast<NSView**>(handleBuffer);

  if (!mainContentView)
    return Napi::Boolean::New(env, false);

  object_setClass(mainContentView.window, [PROPanel class]);

  mainContentView.window.styleMask |= NSWindowStyleMaskNonactivatingPanel;
  [mainContentView.window setCollectionBehavior: NSWindowCollectionBehaviorTransient | NSWindowCollectionBehaviorMoveToActiveSpace | NSWindowCollectionBehaviorFullScreenAuxiliary ];
  [mainContentView.window setLevel:NSFloatingWindowLevel];
  [mainContentView.window setFloatingPanel:YES];

  return Napi::Boolean::New(env, true);
  
}

Value MakeKeyWindow(const Napi::CallbackInfo& info) {
  Env env = info.Env();
  char* handleBuffer = info[0].As<Napi::Buffer<char >>().Data();
  NSView* mainContentView = *reinterpret_cast<NSView**>(handleBuffer);

  if (!mainContentView)
    return Napi::Boolean::New(env, false);

  [mainContentView.window makeKeyWindow];
  return Napi::Boolean::New(env, true);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::Boolean::New(env, "makePanel"), Napi::Function::New(env, MakePanel));
  exports.Set(Napi::Boolean::New(env, "makeKeyWindow"), Napi::Function::New(env, MakeKeyWindow));
  return exports;
}

// Napi::Object Init(Napi::Env env, Napi::Object exports) {
//   return Napi::Function::New(env, MakePanel);
// }

// Object Init(Napi::Env env, Napi::Object exports) {
//   exports.Set(Napi::Object(env, "makePanel"), Function::New(env, Make));
//   // exports.Set(Napi::Object(env, "makekeywindow"), Napi::Function::New(env, MakeKeyWindow));
//   return exports;
// }

NODE_API_MODULE(addon, Init)