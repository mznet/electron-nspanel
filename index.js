var BrowserWindow = require("electron").BrowserWindow;
var PanelMac = require("bindings")("PanelMac");

class PanelWindow extends BrowserWindow {
  constructor(options) {
    const o = { ...options };
    o.frame = true;
    super(o);
    if (!options.frame === undefined) options.frame = true
    PanelMac.MakePanel(this.getNativeWindowHandle(), options.frame);
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
