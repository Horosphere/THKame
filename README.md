# Touhou Kamechinjiru 東方亀珍汁

A STG game about Anikis. Inspired by THP.

## Building

###### Dependencies
THKame uses [CMake](https://cmake.org/) to automate the process of linking
libraries. It is avaliable on (visibly) all platforms.
THKame depends on [SFML](https://github.com/SFML/SFML) and Boost 1.61.0.

###### Compilation
Make sure that you have the following environment variables set if your boost
installation is not native (CMake uses `find_package` to find boost):
```
BOOST_ROOT = <libboost>
BOOST_LIBRARYDIR = <libboost-libraries>
```
First, make a symbolic link at `bin/resources` which points to `resources`
folder. Or you can simply copy the `resources` folder into `bin/`. Then create
a subdirectory `build/` and execute:
```
cmake ..
	-DSFML_INCLUDE_DIR:STRING=<sfml-header-path>
	-DSFML_LIBRARY_DIR:STRING=<sfml-library-path>
```
`<sfml-header-path>` should be a directory with no ending `/` and the directory
should contain a `SFML` folder.

## Developing

Each time a new source file is introduced, please run `update.py` to add it to
`CMakeLists.txt`

The source files are formatted according to the following `astyle`
configuration:
```
--style=allman
--align-pointer=type	
--close-templates
--convert-tabs
--indent-preproc-block
--indent-preproc-define
--indent=tab=2
--pad-header
--unpad-paren
```
