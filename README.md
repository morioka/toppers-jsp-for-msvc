# toppers-jsp-msvc
# TOPPERS/JSP 1.4.4 を Visual Studio Community 2015 でビルドする

## 目的

TOPPERS/JSP 1.4.4 Windowsシミュレータを Visual Studio Community 2015 でビルドする.
Visual C++ 6.0 を対象に開発されたがメンテされていない.

## 環境

* OS : Windows 10 (64bit)
* 開発環境 : Visual Studio Community 2015

## 修正内容

### cfg (checker, configurator)

#### プロジェクトの変換

* \jsp\cfg\vc_project\configurator.dsw を開いて、VC6ワークスペースをVSソリューションに変換する。
* 途中の問いにはすべて "yes" を選択する。
* VC6ワークスペース中の各VC6プロジェクトは、VSプロジェクトに変換される。
* 変換後のソリューションファイルは configurator.sln
* プロジェクトファイルは、checker.vcxproj, configurator.vcxproj 

#### コマンドラインオプションの衝突

ビルド時の現象：

    cl : Command line error D8016: '/ZI' and '/Gy-' command-line options are incompatible

対策:

  [Project] > [Properties]

  checker Property Pages

    [Configuration Properties] > [C/C++] > [All Options] > [Enable Function-Level Linking]
      "No (/Gy-)" --> "Yes (/Gy)"

    [Configuration Properties] > [C/C++] > [All Options] > [Debug Information Format]
      "Program Database for Edit And Continue (/ZI)"

　※他のプロジェクトでも同様に対応すること


####  sprintf のセキュリティ警告(C4996)

ビルド時の現象：

    1>c:\temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\cfg\base\directorymap.h(295): warning C4996: 'sprintf': This function or variable may be unsafe. Consider using sprintf_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
    1>  c:\program files (x86)\windows kits\10\include\10.0.10240.0\ucrt\stdio.h(1769): note: see declaration of 'sprintf'

対策:

    [Configuration Properties] > [C/C++] > [Command Line] > [Additional Options]
      /D_CRT_SECURE_NO_WARNINGS 

　※他のプロジェクトでも同様に対応すること

####  toppersプロジェクトのビルド時に cfg が終了しない。

ビルド時の現象：

toppersプロジェクトのビルドの最初に cfg を実行するが終了しない。

    1>------ Rebuild All started: Project: Toppers, Configuration: Debug Win32 ------
    1>  Performing Custom Build Tools
    1>  Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23918 for x86
    1>  Copyright (C) Microsoft Corporation.  All rights reserved.
    1>
    1>  sample1.cfg
    1>  === TOPPERS/JSP Kernel Configurator ver.9.4 (for JSP rel 1.4) ===

強制終了させるしかない。

    1>------ Rebuild All started: Project: Toppers, Configuration: Debug Win32 ------
    1>  Performing Custom Build Tools
    1>  Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23918 for x86
    1>  Copyright (C) Microsoft Corporation.  All rights reserved.
    1>
    1>  sample1.cfg
    1>  === TOPPERS/JSP Kernel Configurator ver.9.4 (for JSP rel 1.4) ===
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(171,5): error MSB6006: "cmd.exe" exited with code 1.
    ========== Rebuild All: 0 succeeded, 1 failed, 0 skipped ==========


対策:

\jsp\cfg\base\parser.cpp

修正前

            //ストリームから切り出す
        if(current == NULL || current->stream == NULL || current->stream->bad())
        {
            token.assign("<End of stream>");
            return (token.type = Token::EOS);
        }

            //カレントのストリームが空になった
        if(current->stream->eof())
        {
                //ファイルスタックから次のストリームを取る
            if(!fileStack.empty())
            {
                if(current->stream != &cin)
                    delete current->stream;
                delete current;

修正後


            //ストリームから切り出す
        if(current == NULL || current->stream == NULL || current->stream->bad())
        {
            token.assign("<End of stream>");
            return (token.type = Token::EOS);
        }

            //カレントのストリームが空になった
        if(!current->stream->good())
        {
                //ファイルスタックから次のストリームを取る
            if(!fileStack.empty())
            {
                if(current->stream != &cin)
                    delete current->stream;
                delete current;

###  toppers

#### プロジェクトの変換

* \jsp\tools\WINDOWS\vc_project\toppers.dsw を開いてVC6ワークスペースをVSソリューションに変換する。
* 途中の問いにはすべて "yes" を選択する。
* VC6ワークスペース中の各VC6プロジェクトは、VSプロジェクトに変換される。
* 変換後のソリューションファイルは toppers.sln 

#### コマンドラインオプションの衝突 なし

上述のとおり。

#### sprintf のセキュリティ警告(C4996)  なし

上述のとおり。

#### wNULLの未定義

ビルド時の現象:

    1>C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\corecrt_memcpy_s.h(47): error C2065: 'wNULL': undeclared identifier
    1>C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\corecrt_memcpy_s.h(47): warning C4047: '!=': 'void *const ' differs in levels of indirection from 'int'

対策:

	\jsp\config\windows\vwindows.h
	
	#ifndef __VWINDOWS_H
    #define __VWINDOWS_H
    /*
     * Windowsヘッダ 衝突回避用インクルードファイル
     */

    #ifdef NULL
    #define ALREADYDEFINED_NULL
    #endif
    #undef NULL

    #define SIZE wSIZE
    #define BOOL wBOOL
    /*#define NULL wNULL*/ ← この部分をコメントアウト
    #include <windows.h>
    #undef NULL
    #undef SIZE
    #undef BOOL

    #ifdef ALREADYDEFINED_NULL
    #define NULL (0)
    #undef ALREADYDEFINED_NULL
    #endif

    #endif

または

	#ifndef __VWINDOWS_H
    #define __VWINDOWS_H
    /*
     * Windowsヘッダ 衝突回避用インクルードファイル
     */

    #ifdef NULL
    #define ALREADYDEFINED_NULL
    #endif
    #undef NULL

    #define SIZE wSIZE
    #define BOOL wBOOL
    #define NULL wNULL
    #define wNULL (0)  //  ← wNULLの定義を与える
    #include <windows.h>
    #undef NULL
    #undef SIZE
    #undef BOOL

    #ifdef ALREADYDEFINED_NULL
    #define NULL (0)
    #undef ALREADYDEFINED_NULL
    #endif

    #endif

どちらでもよかったが、後者を選択。


#### ビルド最後でのチェッカ実行に失敗

ビルド時の現象:

    1>  --- TOPPERS/JSP Configuration Checker (ver 2.4) ---
    1>    ターゲットアーキテクチャ : Windows (Win32)
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(133,5): error MSB3073: The command "cd ..
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(133,5): error MSB3073: ..\..\cfg\chk.exe -m toppers.exe -cs windows.chk -obj -v -lj
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(133,5): error MSB3073: :VCEnd" exited with code 255.

対策:

cfg -pass3 相当の動作であり、ビルド後の検証工程なので、実行しなくてもよい。

    [Configuration Properties] > [Build Events] > [Post-Build Event]
    [Command Line] cd ..
                   ..\..\cfg\chk.exe -m toppers.exe -cs windows.chk -obj -v -lj
    [Description]
    [Use In Buid]
      "Yes" -> "No"

### tools/Command Watch

#### プロジェクトの変換

上述のとおり。

#### コマンドラインオプションの衝突

上述のとおり。

#### sprintf のセキュリティ警告(C4996)

上述のとおり。

#### Character Setの不正

ビルド時の現象:

    1>c:\temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\cmdwatch\cmdwatch.cpp(367): error C2664: 'int wsprintfW(LPWSTR,LPCWSTR,...)': cannot convert argument 1 from 'char [256]' to 'LPWSTR'
    1>  c:\temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\cmdwatch\cmdwatch.cpp(367): note: Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or function-style cast

対策:

    [Configuration Properties] > [General] > [Project Defaults] > [Character Set]
      "Use Unicode Character Set" -> "Use Multi-Byte Character Set"

### device_control 

#### プロジェクトの変換

上述のとおり。

#### コマンドラインオプションの衝突

上述のとおり。

#### atlimpl.cpp がない

ビルド時の現象:

    1>c:\temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\devicecontrol\stdafx.cpp(46): fatal error C1083: Cannot open include file: 'atlimpl.cpp': No such file or directory

対策:

stdafx.cpp

    //#include <atlimpl.cpp>

#### HMONITORが未定義

ビルド時の現象:

    1>c:\program files (x86)\microsoft visual studio 14.0\vc\atlmfc\include\atlwinverapi.h(710): error C3861: 'LCMapStringEx': identifier not found
    1>c:\program files (x86)\microsoft visual studio 14.0\vc\atlmfc\include\atlwin.h(2084): error C2065: 'HMONITOR': undeclared identifier
    1>c:\program files (x86)\microsoft visual studio 14.0\vc\atlmfc\include\atlwin.h(2084): error C2146: syntax error: missing ';' before identifier 'hMonitor'
    1>c:\program files (x86)\microsoft visual studio 14.0\vc\atlmfc\include\atlwin.h(2084): error C2065: 'hMonitor': undeclared identifier


対策:

http://stackoverflow.com/questions/23640791/compile-errors-upgrading-atl-project-from-vs2010-to-vs2013

stdafx.h

修正前

    #ifndef WINVER  
    #define WINVER 0x0400   
    #endif

修正後

    #ifndef WINVER  
    #define WINVER 0x0500
    #define _WIN32_WINNT 0x0500
    #endif

#### regsvr32エラー

ビルド時の現象:

regsvr32の実行権限が不足

    1>device.obj : warning LNK4075: ignoring '/EDITANDCONTINUE' due to '/SAFESEH' specification
    1>.\device.def : warning LNK4222: exported symbol 'DllCanUnloadNow' should not be assigned an ordinal
    1>.\device.def : warning LNK4222: exported symbol 'DllGetClassObject' should not be assigned an ordinal
    1>.\device.def : warning LNK4222: exported symbol 'DllRegisterServer' should not be assigned an ordinal
    1>.\device.def : warning LNK4222: exported symbol 'DllUnregisterServer' should not be assigned an ordinal
    1>     Creating library .\Debug\device.lib and object .\Debug\device.exp
    1>  device.vcxproj -> C:\Temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\devicecontrol\.\Debug\device.dll
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: The command "regsvr32 /s /c "C:\Temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\devicecontrol\.\Debug\device.dll"
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: echo regsvr32 exec. time > ".\Debug\regsvr32.trg"
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: :VCEnd" exited with code 5. Please verify that you have sufficient rights to run this command.

対策:

別途、コマンドプロント上で実行。

### tools/device_manager

#### プロジェクトの変換

上述のとおり。

#### コマンドラインオプションの衝突

上述のとおり。

#### atlimpl.cpp がない

ビルド時の現象:

    1>c:\temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\devicemanager\stdafx.cpp(53): fatal error C1083: Cannot open include file: 'atlimpl.cpp': No such file or directory

対策:

stdafx.cpp

    //#include <atlimpl.cpp>

### tools/watcher

#### プロジェクトの変換

上述のとおり。

#### コマンドラインオプションの衝突

上述のとおり。

#### regsvr32エラー

ビルド時の現象:

regsvr32の実行権限が不足

    1>kernellogcontrol.obj : warning LNK4075: ignoring '/EDITANDCONTINUE' due to '/SAFESEH' specification
    1>.\watcher.def : warning LNK4222: exported symbol 'DllCanUnloadNow' should not be assigned an ordinal
    1>.\watcher.def : warning LNK4222: exported symbol 'DllGetClassObject' should not be assigned an ordinal
    1>.\watcher.def : warning LNK4222: exported symbol 'DllRegisterServer' should not be assigned an ordinal
    1>.\watcher.def : warning LNK4222: exported symbol 'DllUnregisterServer' should not be assigned an ordinal
    1>     Creating library .\Debug\watcher.lib and object .\Debug\watcher.exp
    1>  watcher.vcxproj -> C:\Temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\watcher\.\Debug\watcher.dll
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: The command "regsvr32 /s /c "C:\Temp\jsp-1.4.4.1_full\jsp-1.4.4.1-full\windev\watcher\.\Debug\watcher.dll"
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: echo regsvr32 exec. time > ".\Debug\regsvr32.trg"
    1>C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\V140\Microsoft.CppCommon.targets(203,5): error MSB3075: :VCEnd" exited with code 5. Please verify that you have sufficient rights to run this command.

対策:

別途、コマンドプロント上で実行。

## 参考

* TOPPERS　JSP 1.4.3 VC++ 2008でのビルド方法 - utiyama
 - Last-modified: 2010-04-27 (火) 22:37:33
 - http://www.wikihouse.com/utiyamat/index.php?TOPPERS%A1%A1JSP%201.4.3%20VC%2B%2B%202008%A4%C7%A4%CE%A5%D3%A5%EB%A5%C9%CA%FD%CB%A1
* Toppers/JSP 1.4.3をVC++2005 Expressでビルドするまでの手順 - shikaku's blog
 - 2007-10-10
 - http://blog.systemjp.net/entry/20071010/p1
* [TOPPERS] JSPカーネルのWindowsシミュレータをVisual C++ 2008で使うには | 株式会社きじねこ
 - 投稿日時：2008-11-18 (火) 16:33 
 - http://www.kijineko.co.jp/tech/toppers/jsp-on-vc2008.html
* (toppers-users 3987) Re: JSP1.4.4の不具合 (原因究明？)
 - 2012年 6月 13日 (水) 16:07:52 JST
 - https://www.toppers.jp/TOPPERS-USERS/2012-June/003810.html
* c++ - Compile Errors upgrading ATL project from vs2010 to vs2013 - Stack Overflow
 - asked May 13 '14 at 20:16
 - http://stackoverflow.com/questions/23640791/compile-errors-upgrading-atl-project-from-vs2010-to-vs2013

## 今後

これをベースに、TOPPERS/ASP のWindowsシミュレータを何とかしたい。
