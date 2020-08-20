[![Build Status](https://travis-ci.com/x4kkk3r/IOMath.svg?branch=master)](https://travis-ci.com/x4kkk3r/IOMath)
[![License](https://img.shields.io/github/license/x4kkk3r/IOMath)]()
[![Latest Release](https://img.shields.io/github/v/release/x4kkk3r/IOMath?include_prereleases)]()
# IOMath

## About
IOMath is a ***fast header-only cross-platform*** math library.

## Installation
Type following in the command line:
```
git clone https://github.com/x4kkk3r/IOMath.git
```

## Using
**Example**:
```c++
#include <IOMath/Vectors.hpp>
#include <IOMath/Matrices.hpp>
using namespace IOMath;

int main(int, char**)
{
    Matrix4 transformationMatrix = Matrix4::Identity();
    
    Translate(transformationMatrix, Vector3(1.0f, 2.0f, 3.0f));
    Scale(transformationMatrix, Vector3(3.0f, 3.0f, 1.5f));
    Rotate(transformationMatrix, Vector3(1.0f, 0.0f, 0.0f), Radians(45.0f));

    Vector2 screenPosition = Vector2(0.5f, -0.5f);
    Vector4 spacePosition = transformationMatrix * Vector4(screenPosition, 0.0f, 0.0f);

    return 0;
}
```

## Tests
To run test type followind in the command line:
```bash
cd tests/
cmake CMakeLists.txt -Wno-dev && cmake --build .
ctest
```


## License
IOMath is licensed under the [MIT license](LICENSE).