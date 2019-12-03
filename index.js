var BrowserWindow = require("electron").BrowserWindow;
var PanelMac = require("bindings")("PanelMac");

class PanelWindow extends BrowserWindow {
  constructor(options) {
    const o = { ...options };
    o.frame = true;
    super(o);
    PanelMac.MakePanel(this.getNativeWindowHandle(), options.frame ? options.frame : true);
  }

  show() {
    super.showInactive();
    PanelMac.MakeKeyWindow(this.getNativeWindowHandle());
  }
}

module.exports = {
  PanelWindow,
  makeKeyWindow: function(window) {
    return PanelMac.MakeKeyWindow(window.getNativeWindowHandle());
  },
  makePanel: function(window) {
    return PanelMac.MakePanel(window.getNativeWindowHandle());
  }
};
