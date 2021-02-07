set TARGET_ARCH=x64

rem to get 'SDK_BUILD_NUMBER' run:
rem 
rem find /c/Program\ Files\ \(x86\)/Windows\ Kits/10/bin -type f -iname makepri.exe
rem
set SDK_BUILD_NUMBER=10.0.18362.0

set WINDOWS_KITS_PATH=C:\Program Files (x86)\Windows Kits\10\bin
set Path=%WINDOWS_KITS_PATH%\%SDK_BUILD_NUMBER%\%TARGET_ARCH%;%Path%

makepri createconfig /cf priconfig.xml /dq en-US /o /pv 10.0.0
del resources.pri
makepri new /pr "%CD%" /cf priconfig.xml
makeappx pack /m AppxManifest.xml /f filemap.txt /p UWPApp.msix /o

rem For creating the certificate open a PowerShell console and run the following command:
rem
rem New-SelfSignedCertificate -Type Custom -Subject "CN=MyCompany, O=MyCompany, L=MyCity, S=MyState, C=MyCountry" -KeyUsage DigitalSignature -FriendlyName "UWPApp Certificate" -CertStoreLocation "Cert:\CurrentUser\My" -TextExtension @("2.5.29.37={text}1.3.6.1.5.5.7.3.3", "2.5.29.19={text}")
rem
rem Then copy the certificate hash here: 
rem
set CERTIFICATE_SHA=0123456789ABCDEFFEDCBA987654321012345678

SignTool sign /v /a /sha1 %CERTIFICATE_SHA% /fd SHA256 UWPApp.msix
