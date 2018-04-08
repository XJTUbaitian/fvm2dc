## 简介

fvm2dc是基于OPS实现的二维结构化网格计算传热学程序。

## 安装

首先fvm2dc基于OPS，所以先需要安装OPS库。

其次，在fvm2dc中使用了adi算法。所以我们需要安装tridsolver。


## 开发者指南

因为cuda工具支持原因以及易用性考虑，推荐使用ubuntu操作系统，eclipse集成开发环境，intel parallel studio编译器套件进行。

### 安装ubuntu

到这里（http://mirrors.163.com/ubuntu-releases/16.04.4/） 下载ubuntu 16.04 LTS版本的iso（ubuntu-16.04.4-desktop-amd64.iso）。使用rufus （到 http://rufus.akeo.ie/ 下载）制作启动u盘，从u盘启动安装ubuntu，按照向导提示安装ubuntu。

访问mirrors.163.com按照 http://mirrors.163.com/.help/ubuntu.html 指示修改sources.list，记得把wily都换成xenial。然后使用root账户或者sudo执行

```shell
apt-get update
apt-get install build-essential lib32z1 lib32z1-dev lib32ncurses5 lib32ncurses5-dev
apt-get install vim gfortran python2.7
```

### 安装intel parallel studio

下载parallel_studio_xe_2015_update6.tgz和parasxe2015u6cluster.lic。使用root账户或者sudo执行如下命令进行安装
```shell
tar zvxf parallel_studio_xe_2015_update6.tgz
cd parallel_studio_xe_2015_update6
./install.sh
```

### 安装cuda

到cuda的官方站点

### 安装pgi compliers（可选）

### 安装git

我们要用到的OPS和tridsolver都是托管在github上的项目。包括我们自己的fvm2dc也是托管在github的项目，所以安装git版本管理工具。

```shell
apt-get install git
```

### 安装tridsolver

```shell
git clone git@github.com:mingtaoli/tridsolver.git
```

### 安装ops库

```shell
git clone git@github:mingtaoli/OPS.git
```

OPS有个分支feature/Tridiagonal，支持tridsolver。但是这个分支暂时没有合并到主分支。我们使用这个分支即可。

```shell
git checkout feature/Tridiagonal
```


### 安装eclipse

安装eclipse的intel CDT。

### 工作流程简介