## 简介

fvm2dc是基于OPS实现的二维结构化网格计算传热学程序。

## 安装

首先fvm2dc基于OPS，所以先需要安装OPS库。

其次，在fvm2dc中使用了adi算法。所以我们需要安装tridsolver。


## 开发者指南

因为cuda工具支持原因以及易用性考虑，推荐使用ubuntu操作系统，eclipse集成开发环境，intel parallel studio编译器套件进行。

### 安装ubuntu

到这里（ http://mirrors.163.com/ubuntu-releases/16.04.4/ ） 下载ubuntu 16.04 LTS版本的iso（ ubuntu-16.04.4-desktop-amd64.iso ）。使用rufus （到 http://rufus.akeo.ie/ 下载）制作启动u盘，从u盘启动安装ubuntu，按照向导提示安装ubuntu。

访问mirrors.163.com按照 http://mirrors.163.com/.help/ubuntu.html 指示修改sources.list，记得把wily都换成xenial。然后使用root账户或者sudo执行

```shell
apt-get update
apt-get install build-essential lib32z1 lib32z1-dev lib32ncurses5 lib32ncurses5-dev
apt-get install vim gfortran python2.7
```
如果是虚拟机或者机子比较慢，推荐使用xfce，使用如下命令安装
```shell
apt-get install xubuntu-desktop
```
### 安装intel parallel studio

下载parallel_studio_xe_2015_update6.tgz和parasxe2015u6cluster.lic。使用root账户或者sudo执行如下命令进行安装
```shell
tar zvxf parallel_studio_xe_2015_update6.tgz
cd parallel_studio_xe_2015_update6
./install.sh
```
如果缺少相应的软件包，逐一安装了再安装parallel studio。

实际上intel parallel studio包含fortran编译器、c（c++）编译器、mkl数学库、intel mpi并行消息传递软件等。

### 安装cuda

到cuda的官方站点 ( https://developer.nvidia.com/cuda-downloads )下载，点选Linux->x86_64->Ubuntu->16.04->deb(network)，下载cuda-repo-ubuntu1604_9.1.85-1_amd64.deb，使用root账户或者sudo执行如下命令安装cuda。
```shell
dpkg -i cuda-repo-ubuntu1604_9.1.85-1_amd64.deb
apt-key adv --fetch-keys http://developer.download.nvidia.com/compute/cuda/repos/ubuntu1604/x86_64/7fa2af80.pub
apt-get update
apt-get install cuda
```

### 安装pgi compliers（可选）

目前支持cuda的fortran编译器只有pgi的fortran编译器。而且使用pgi的编译器我们可以使用openacc、opencl等。pgi编译器套集有社区版，免费。到 https://www.pgroup.com/ 下载pgilinux-2017-1710-x86_64.tar.gz。使用root账户或者sudo执行如下命令，按照向导提示一步一步安装完成。

```shell
mkdir pgi
mv pgilinux-2017-1710-x86_64.tar.gz pgi/
cd pgi/
tar zvxf pgilinux-2017-1710-x86_64.tar.gz
./install
```
在提示是否安装open mpi和cuda的时候，我们选择是。

### 安装git

我们要用到的OPS和tridsolver都是托管在github上的项目。包括我们自己的fvm2dc也是托管在github的项目，所以安装git版本管理工具。使用root账户或者sudo执行如下命令

```shell
apt-get install git
```
参考网上的git教程对该工具有个概貌的了解。

### 安装eclipse

eclipse是很好的跨平台集成开发环境。使用ubuntu源安装的eclipse有点旧。我们可以从eclipse的官方站点（ https://www.eclipse.org/downloads/ ）下载更新的版本。我们直接下载 Eclipse for Parallel Application Developers 这一版本，即eclipse-parallel-oxygen-2-linux-gtk-x86_64.tar.gz。通过如下命令把eclipse解压在/opt/下。

```shell
tar zvxf eclipse-parallel-oxygen-2-linux-gtk-x86_64.tar.gz -C /opt/
```
这样我们就可以使用/opt/eclipse/eclipse启动集成开发环境了。进一步我们可以把/opt/eclipse加到环境变量PATH，我们就可以直接使用eclipse启动集成开发环境。

安装eclipse的intel CDT。集成开发环境安装好后，并不能够直接支持intel 的编译器套集。我们可以运行eclipse，然后点Help->Install New Software...->Add->Local...，选择 /opt/intel/composer_xe_2015.6.233/eclipse_support/cdt8.0/eclipse/ ，点ok， 勾选要安装的组件，然后按照提示安装完成。

### 设置环境变量

将如下内容添加到~/.bashrc的尾部。注意用户名修改一下，相应的目录修改正确。
```shell
export PATH=/opt/eclipse:$PATH

source /opt/intel/parallel_studio_xe_2015/psxevars.sh intel64
export INTEL_DISABLE_ISIP=1
export MPI_INSTALL_PATH=/opt/intel/impi/5.0.3.049/intel64

export OPS_COMPILER=intel
export OPS_INSTALL_PATH=/home/username/localsoft/OPS/ops
export CUDA_INSTALL_PATH=/usr/local/cuda
export OPENCL_INSTALL_PATH=/usr/local/cuda
export HDF5_INSTALL_PATH=/home/username/localsoft/hdf5
export LD_LIBRARY_PATH=$HDF5_INSTALL_PATH/lib:$LD_LIBRARY_PATH

export PATH=/home/username/localsoft/OPS/translator/python/c:$PATH

export LD_LIBRARY_PATH=/home/username/localsoft/tridsolver/scalar/build/lib:$LD_LIBRARY_PATH
```
将username修改成自己的用户名。

### 安装tridsolver

首先通过如下代码获得tridsolver的源代码。

```shell
git clone git@github.com:mingtaoli/tridsolver.git
```

然后，阅读其README文件可知，tridsolver是分块三对角block和三对角scalar两个库的。我们使用scalar这个。按照README的说明使用如下命令安装

```shell
cd /path/to/tridsolver/scalar
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_FOR_CPU=ON -DBUILD_FOR_GPU=ON
make
make install
```
然后对tridsolver的例子进行学习和试运行。
```shell
cd /path/to/tridsolver/apps/adi
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_FOR_CPU=ON -DBUILD_FOR_GPU=ON
make
```
其中的/path/to/tridsolver改为自己系统上的tridsolver目录。

不过这里还有要注意的是，需要修改CMakeLists.txt，把LIBTRID_PATH设为正确的值。

如果系统没有cmake，使用如下命令安装cmake。
```shell
apt-get install cmake
```
### 安装hdf5

OPS要用到hdf5,所以我们需要安装hdf5。到hdf的官方站点 （url???） 下载hdf5-1.10.1.tar.gz，
```shell
tar zvxf hdf5-1.10.1.tar.gz
cd hdf5-1.10.1
./configure --prefix=/home/username/localsoft/hdf5 --enable-fortran --enable-parallel CPP=cpp CC=mpiicc FC=mpiifort CFLAGS=-fPIC FCFLAGS=-fPIC
make -j 4
make install
```

### 安装ops库

```shell
git clone git@github:mingtaoli/OPS.git
```

OPS有个分支feature/Tridiagonal，支持tridsolver。但是这个分支暂时没有合并到主分支。我们使用这个分支即可。

```shell
git checkout feature/Tridiagonal
```
通过如下命令编译ops库：
```shell
cd /path/to/OPS/ops/c/
make
```
在这之前，我们需要修改Makefile，把一些路径修改正确。而且还有，intel编译器使用的mpicc实际上是mpiicc，mpicxx实际上使用mpiicpc，作相应修改。完全不知道Makefile的请到网上查阅makefile相关知识。

### 安装clang-format
ops.py实际上会使用clang-format进行最后cpp文件的格式化，所以我们需要安装clang-format
```shell
apt-get install clang-format
```

### 工作流程简介

首先使用git clone我们的fvm2dc库。
```shell
mkdir -p ~/projects
cd ~/projects
git clone git@github:mingtaoli/fvm2dc.git
```
如果没有权限，请申请github账户，并与我联系。只读clone可使用
```shell
git clone https://github.com/mingtaoli/fvm2dc.git
```
然后在~/projects/fvm2dc目录下可以看到三个目录，
doc是文档目录
fvm2dc是原始工作目录（开发写代码在此目录）
fvm2d_ops是生成的ops代码目录。（用于集成开发环境编译调试）
我们进入fvm2dc目录，使用如下命令
```shell
make trans
```
会在fvm2dc_ops下生成一些文件。

使用eclipse打开project fvm2dc和fvm2dc_ops。

由于使用的路径不同，我们可能还需要在eclipse中点中项目，使用project->properties->c++builder->settings修改linker下的Libraries中的search directory，使用project->properties->c++general->paths and symbols修改include dirctories。

这样我们就可以在eclispe中fvm2dc下编辑代码，
在shell中使用make trans生成fvm2dc_ops的文件。针对fvm2dc_ops使用eclipse的菜单进行编译、调试等等。

