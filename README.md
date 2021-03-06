# c-raytracer

A raytracer exercise in C (C 11)... just for fun.  
I only used the C standard library for this exercise.

Based on [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html).

## Build

```bash
make release # or debug if you want debug symbols in the bin
./raytracer
```

This repository includes my vscode configuration, if you want to play / debug the program by yourself.

## Visualisation

The output is a PPM file - to see the content, please to install a PPM viewer (like ImageMagick).  
If you don't want to use the *ppm* file, you can convert it using the `convert` tool from [imagemagick](https://imagemagick.org), for example
on png `convert output.ppm output.png`. 

#### GNU/Linux

```bash
# to display the output image using imagemagick
display output.ppm
```

### about macOS

#### default

macOS allows to watch *ppm* images using the default image viewer of macOS.  
You can try, using the command line: `open output.ppm`.

#### imagemagick / X11

If you want to use `display` from [imagemagick](https://imagemagick.org) for whatever reason:

```bash
# install X11 on macOS (and launch it)
brew cask install xquartz # you can use --appdir option to install xquartz in your userspace
# to communicate with xquartz, you will have to set the DISPLAY environment variable
export DISPLAY=:0
# install imagemagick
brew install imagemagick
# display the file
magick display output.ppm
```

If you want to have more explanation about the installation on macOS: [https://imagemagick.org/script/download.php#macosx](https://imagemagick.org/script/download.php#macosx).
