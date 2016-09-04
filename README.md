### Windows 系统下GCC开发Redbear Duo ###
> 本文主要记录在windows 系统下使用一个makefile模板利用GCC工具链编译开发Redbear Duo工程，Linux环境只要稍作修改也适用
### 准备：软件配置 ###

* 安装并配置make工具链。直接安装mingw，可以从网上下载[mingw-get-setup](https://sourceforge.net/projects/mingw/files/latest/download?source=files)进行在线安装，因为只需要make工具链，所以，只需要安装基本功能就行，如下图。

![image](http://qotone.qiniudn.com/md_imgmingw.PNG)

 由于，固件编译过程中需要用到CRC32校验工具，所以同时需要选择安装 **mingw-developer-toolkit**包，如下图所示：

![image](http://qotone.qiniudn.com/MinGW_install.PNG)

安装完成记下安装目录，比如：“D:\MinGW”，可以将这个目录中包含make.exe文件的目录添加进系统环境变量中，添加后可以在系统命令行中输入 `PATH` 打印系统环境变量，如下图。

![image](http://qotone.qiniudn.com/md_imgmake_tool_path.PNG)

也可以在系统命令行中输入“make -v”命令验证，当打印如图信息说明make工具配置好了。

![image](http://qotone.qiniudn.com/md_imgmake_tool_p.PNG)

* 安装GCC工具链。直接下载windows系统安装版，或者下载安装压缩包也行。注意，开发Coretex-M3的GCC工具链应选择arm-none-eabi-gcc版，将压缩包解压，并记下路径，如：“D：\GCC”，按照以上Make工具链的方法配置GCC工具链的系统环境变量，当然，对于系统中要安装多个版本GCC工具链时可以不设置GCC工具链的系统环境变量，可以在相应工程的makefile中定义GCC开发工具链地址。

* 下载[Redbear Duo 固件包](https://github.com/qotone/Duo)。将下载的固件包解压缩，如解压后的文件目录为：`D:/Duo`，该目录包含如下文件结构：
	* **0.2.10** ：这个文件夹是从Redbear Duo 的Arduino IDE 支持包中提取出来的，目前版本为*0.2.10*。里面是编译需要用到的库文件和头文件。
	* **bin**：这个文件夹包含需要用到的工具软件。
	* **project** ：这个文件就是需要编译的工程工程文件所在目录，里面包含用于存放工程源文件的`src`文件夹，编译工程的`makefile`，存放库文件的`lib`文件夹。
	* **readme.md**说明文档。

### 使用：简单工程编译 ###

打开固件包文件 `project` 目录中的 `makefile` 文件，将以上解压缩的GCC工具目录替换掉文档第31行的 `**ARM_GCC_PATH**` 关于GCC软件路径的相关定义，如下：

    # Define the compiler/tools prefix
	ARM_GCC_PATH = D:/GCC/bin
	GCC_PREFIX = $(ARM_GCC_PATH)/arm-none-eabi-

这个目录地址中必须包含 `arm-none-eabi-as.exe `，`arm-none-eabi-gcc.exe`等应用文件。 

在系统命令行工具（如：终端CMD）中进入固件包文件工程目录，如：`D:/workspace/Duo/project` ，工程文件夹中默认已经有一个点灯程序，直接在该目录下输入`make all`就开始编译这个点灯程序，编译过程如下图所示：

![image](http://qotone.qiniudn.com/md_img_redbear_gcc_make.PNG)

在`project`文件夹根目录下会编译生产一个 `Demo.bin` 文件，此时可以借助**dfu-util** 工具将这个固件烧写进入Duo，具体可以阅读本文最后的参考资料。首先，将Duo连接PC并使其进入**DFU Mode** ；然后，在 `project` 目录下输入： `dfu-util -d 0x2B04:0xD058 -a 0 -s 0x80c0000:leave -D Demo.bin` ，烧写完成，截图如下：

![image](http://qotone.qiniudn.com/md_img_redbear_app_download.PNG)

### 参考资料 ###

* [Redbear Duo 初体验](http://bbs.elecfans.com/jishu_932334_1_1.html)
* [ Develop in GCC Tool ,meet difficulties in Writing makefile
RedBear Duo
](http://discuss.redbear.cc/t/develop-in-gcc-tool-meet-difficulties-in-writing-makefile/750)
* [Stucked in red flash SOS
RedBear Duo](http://discuss.redbear.cc/t/stucked-in-red-flash-sos/712/5)