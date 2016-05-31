# Touhou Kamechinjiru 東方亀珍汁

A STG game with Japanese and American elements

## Building

###### Dependencies
THKame uses [CMake](https://cmake.org/) to automate the process of linking libraries. It is avaliable on (visibly)all platforms.
THKame depends on [Urho3D](https://github.com/urho3d/Urho3D).

###### Compilation
First, set the following environment variable:
```
URHO3D_HOME=<Urho3D build directory>
```
The details for `URHO3D_HOME` can be found on Urho3D's website. Then, execute the following in the command line:
```
cmake CMakeLists.txt -DLIBDIR_URHO3D:STRING=<Urho3D source directory>
```
I highly suggest you make the above two commands into a script.

If you are using GNU Makefiles as your generator, `make` can now be ran to produce the desired binary.

## Development

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
