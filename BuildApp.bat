REM Build Bat File
REM Precheck the Resource 
"C:\MRE_SDK\tools\ResEditor\CmdShell.exe" save  "C:\Users\mmb\dev\gptvxp\TelnetVXP.vcproj"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-gcc" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions -o "C:\Users\mmb\dev\gptvxp\arm\gccmain.o" -c "C:\MRE_SDK\lib\MRE30\src\gccmain.c"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-g++" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions           -fcheck-new -o "C:\Users\mmb\dev\gptvxp\arm\Console.o" -c "C:\Users\mmb\dev\gptvxp\Console.cpp"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-g++" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions           -fcheck-new           -fcheck-new -o "C:\Users\mmb\dev\gptvxp\arm\main.o" -c "C:\Users\mmb\dev\gptvxp\main.cpp"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-g++" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions           -fcheck-new           -fcheck-new           -fcheck-new -o "C:\Users\mmb\dev\gptvxp\arm\T2Input.o" -c "C:\Users\mmb\dev\gptvxp\T2Input.cpp"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-g++" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions           -fcheck-new           -fcheck-new           -fcheck-new           -fcheck-new -o "C:\Users\mmb\dev\gptvxp\arm\chatgpt.o" -c "C:\Users\mmb\dev\gptvxp\chatgpt.cpp"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Copmile c file 
"C:\SourceryLite\Bin\arm-none-eabi-g++" -c -g -fpic -mcpu=arm7tdmi-s -fvisibility=hidden -mthumb -mlittle-endian -O2 -D__MRE_COMPILER_GCC__ -fno-exceptions -fno-non-call-exceptions           -fcheck-new           -fcheck-new           -fcheck-new           -fcheck-new -o "C:\Users\mmb\dev\gptvxp\arm\Console_io.o" -c "C:\Users\mmb\dev\gptvxp\Console_io.cpp"      -D _MINIGUI_LIB_ -D _USE_MINIGUIENTRY -D _NOUNIX_ -D _FOR_WNC -D __MRE_SDK__ -D   __MRE_VENUS_NORMAL__  -D  __MMI_MAINLCD_240X320__ -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\MRE_SDK\include" -I "C:\MRE_SDK\include\service" -I "C:\Users\mmb\dev\gptvxp\include" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\ResID" -I "C:\Users\mmb\dev\gptvxp\src\app\widget" -I "C:\Users\mmb\dev\gptvxp\src\app\launcher" -I "C:\Users\mmb\dev\gptvxp\src\app\wallpaper" -I "C:\Users\mmb\dev\gptvxp\src\app\screen_lock" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\include\component" -I "C:\Users\mmb\dev\gptvxp\include\service" -I "C:\Users\mmb\dev\gptvxp\src\framework" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\base" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\mvc" -I "C:\Users\mmb\dev\gptvxp\src\framework\ui_core\pme" -I "C:\Users\mmb\dev\gptvxp\src\framework\mmi_core" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\vrt\interface" -I "C:\Users\mmb\dev\gptvxp\src\component" -I "C:\Users\mmb\dev\gptvxp\src\ui_engine\framework\xml" -I "C:\Users\mmb\dev\gptvxp"
REM Link app 
"C:\SourceryLite\Bin\arm-none-eabi-gcc" -o "C:\Users\mmb\dev\gptvxp\TelnetVXP.axf"  "C:\Users\mmb\dev\gptvxp\arm\gccmain.o"  "C:\Users\mmb\dev\gptvxp\arm\Console.o"  "C:\Users\mmb\dev\gptvxp\arm\main.o"  "C:\Users\mmb\dev\gptvxp\arm\T2Input.o"  "C:\Users\mmb\dev\gptvxp\arm\chatgpt.o"  "C:\Users\mmb\dev\gptvxp\arm\Console_io.o" -fpic -pie  -T "C:\MRE_SDK\lib\MRE30\armgcc_t\scat.ld" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\percommon.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\pertcp.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\persensor.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\persmsper.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\perbitstream.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\perfile.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\perhttp.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\perpro.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\persec.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\persysstorage.a" -l:"C:\MRE_SDK\lib\MRE30\armgcc_t\perudp.a"
REM Pack resource to app 
"C:\MRE_SDK\tools\ResEditor\CmdShell.exe" pack -silent -resolution 240x320 -o "C:\Users\mmb\dev\gptvxp\TelnetVXP.pkd" -e AXF "C:\Users\mmb\dev\gptvxp\TelnetVXP.vcproj" "C:\Users\mmb\dev\gptvxp\TelnetVXP.axf"
REM Add tag infromation 
"C:\MRE_SDK\tools\PackDigist.exe" "C:\Users\mmb\dev\gptvxp\TelnetVXP.vcproj" "GPT" "0.1.0" "gvl610" "3072" "NotSupportBg" "Not Support rotate" "GPT" "GPT" "GPT" "1234567890" "content" " TCP Sensor SMS(person) BitStream File HTTP ProMng Sec SysStorage UDP" "vxp" "GCC" "PKD" "UnCompress" "NoVPI" "Adaptable" "15728960" "UnSysMemAble" "" "-1" "UNPUSH" "-1" ""  "UnAutoStart"  "UnTransferImg" "NoIdleShortcut"  C:\Users\mmb\dev\gptvxp\arm C:\Users\mmb\dev\gptvxp\build.log
REM Rename
del gpt.vxp
ren TelnetVXP.vxp gpt.vxp
