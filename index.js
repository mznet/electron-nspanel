var BrowserWindow = require("electron").BrowserWindow;
var PanelMac = require("bindings")("PanelMac");

class PanelWindow extends BrowserWindow {
  constructor(options) {
    super(options);
    PanelMac.MakePanel(this.getNativeWindowHandle());
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
