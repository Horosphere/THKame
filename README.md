# Touhou Kamechinjiru 東方亀珍汁

A STG game with Japanese and American elements

## Building

###### Dependencies
THKame uses [CMake](https://cmake.org/) to automate the process of linking libraries. It is avaliable on (visibly)all platforms.
THKame depends on [SFML](https://github.com/SFML/SFML) and Boost 1.61.0.

###### Compilation
Make sure that you have the following environment variables set if your boost installation is not native (CMake uses `find_package` to find boost):
```
BOOST_ROOT = <libboost>
BOOST_LIBRARYDIR = <libboost-libraries>
```
First, make a symbolic link at `bin/resources` which points to `resources` folder. Or you can simply copy the `resources` folder into `bin/`. Then use the following command:
```
cmake CMakeLists.txt -DSFML_INCLUDE_DIR:STRING=<sfml-header-path>
                     -DSFML_LIBRARY_DIR:STRING=<sfml-library-path>
```
I highly suggest you make the above two commands into a script. `<sfml-header-path>` should be a directory with no ending `/` and the directory should contain a `SFML` folder.

If you are using GNU Makefiles as your generator, you can now execute `make` to produce the desired binary.

## Developing

Each time a new source file is introduced, please run `update.py` to add it to `CMakeLists.txt`

The source files are formatted according to the following `astyle` configuration:
```
--style=allman
--indent=tab
--indent-preproc-block
--pad-header
--unpad-paren
--align-pointer=type	
```
