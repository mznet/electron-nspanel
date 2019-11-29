{
    "targets": [
        {
            "target_name": "NativeExtension",
            "sources": ["NativeExtension.cc"],
            "include_dirs": ["<!@(node -p \"require('node-addon-api').include\")"],
            "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")"],
            "link_settings": {
                "conditions": [
                    ['OS=="mac"', {
                        "sources": [
                            "panel_osx.cc"
                        ],
                        "libraries": [
                            'Foundation.framework',
                            'AppKit.framework',
                            'ScriptingBridge.framework'
                        ],
                    }
                    ]]
            },
            "xcode_settings": {
                'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
                'CLANG_CXX_LIBRARY': 'libc++',
                'MACOSX_DEPLOYMENT_TARGET': '10.14.4',
                "OTHER_CFLAGS": [
                    "-x objective-c++ -stdlib=libc++"
                ]
            },
            'cflags!': ['-fno-exceptions'],
            'cflags_cc!': ['-fno-exceptions'],
            'msvs_settings': {
                'VCCLCompilerTool': {'ExceptionHandling': 1},
            },
        }
    ],
}
