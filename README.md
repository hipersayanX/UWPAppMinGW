# UWP application example using MinGW and MSYS2

This is the simplest working application you can build using MinGW and MSYS2.  
You can build and test you app before packaging as it were a normal Windows program, but take in mind that your application will be running in a box and won't be able to interact with anything else outside the box, for example you won't be able to launch programs or use any kind of IPC mechanism outside the box, also you won't be able to get any console output or pass any argument or environment variable to the app, also MinGW does not implements [C++/WinRT API](https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/intro-to-using-cpp-with-winrt). You will have to adhere to the strictly available [Win32 APIs in UWP apps](https://docs.microsoft.com/en-us/uwp/win32-and-com/win32-and-com-for-uwp-apps).  
Things that you can do with UWP apps and limitations are long to explain, if you have any question just check out [Microsoft documentation](https://docs.microsoft.com/en-us/windows/uwp/get-started/universal-application-platform-guide).
For signing the package and running the app in your system you will need to [create a self-signed certificate](https://docs.microsoft.com/en-us/windows/msix/package/create-certificate-package-signing) and pass the sha1 hash to **CERTIFICATE_SHA** in package.bat. If you have any question about packaging and signing  just check out [Microsoft documentation](://docs.microsoft.com/en-us/windows/msix/package/manual-packaging-root).

# Required dependencies

* [Windows SDK for UWP Managed Apps](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/), read [here](https://docs.microsoft.com/en-us/windows/uwp/app-resources/makepri-exe-command-options).
* [MSYS2](https://www.msys2.org/)

# Building and running

Once you have everything prepared, run:

```
make
make package
```

and then double-click the UWPApp.msix package to install and run the app.
