# Touhou Kamichinjiru

A STG game with Japanese and American elements

## Building

###### Dependencies
THKame depends on [Urho3D](https://github.com/urho3d/Urho3D).

###### Make
First, set the following environment variable:
```
URHO3D_HOME=<Urho3D build directory>
```
The details for `URHO3D_HOME` can be found on Urho3D's website. Then, execute the following in the command line:
```
cmake CMakeLists.txt -DLIBDIR_URHO3D:STRING=<Urho3D source directory>
```
Now `make` can be executed to compile the application.

