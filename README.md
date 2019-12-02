## electron-nspanel
OSX [NSPanel](https://developer.apple.com/documentation/appkit/nspanel) wrapper for electron using [node addon api](https://github.com/nodejs/node-addon-api). The goal of this project is to enable NSPanel on [Electron](https://electronjs.org/) for showing a very elegant window style such as Spotlight or Alfred.

The extension inherit attribute and methods from [BrowserWindow](https://electronjs.org/docs/api/browser-window) class of Electron. Unfortunatley, some attributes and methods might be not working properly.

This project base on [electron-panel-window](https://github.com/goabstract/electron-panel-window)

### Installation

Install `electron-nspanel` using npm:

```shell
$ npm install electron-nspanel
```

### Usage
```javascript
import { PanelWindow } from 'electron-nspanel';

const panelWindow = new PanelWindow({
  width: 800,
  height: 600,
})

panelWindow.show();
```

### Build
```shell
$ npm run install
```

## License

This project is under MIT.
See [LICENSE](https://github.com/goabstract/electron-panel-window/blob/master/LICENSE)