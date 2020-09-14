[![Build Status](https://travis-ci.com/x4kkk3r/IOMath.svg?branch=master)](https://travis-ci.com/x4kkk3r/IOMath)
[![License](https://img.shields.io/github/license/x4kkk3r/IOMath)]()
[![Latest Release](https://img.shields.io/github/v/release/x4kkk3r/IOMath?include_prereleases)]()
# IOMath

## About
IOMath is a ***fast header-only cross-platform*** math library. It's architecture is similar to [GLM](https://github.com/g-truc/glm).
### [**Latest release**](https://github.com/x4kkk3r/IOMath/releases/latest)

## Using
**Example**:
```c++
#include <IOMath/Vectors.hpp>
#include <IOMath/Matrices.hpp>
using namespace IOMath;

constexpr unsigned SCREEN_WIDTH = 1920;
constexpr unsigned SCREEN_HEIGHT = 1080;

int main(int, char**)
{
    Matrix4 modelMatrix = Matrix4::Identity();    
    Translate(transformationMatrix, Vector3(1.0f, 2.0f, 3.0f));
    Scale(transformationMatrix, Vector3(3.0f, 3.0f, 1.5f));
    Rotate(transformationMatrix, Vector3(1.0f, 0.0f, 0.0f), Radians(45.0f));

    Matrix4 viewMatrix = LookAtMatrix(Vector3(0.0f, 0.0f, 0.0f), Vector3(0.0f, 0.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f));

    Matrix4 projectionMatrix = PerspectiveMatrix(90.0f, static_cast<float>(SCREEN_WIDTH) / SCREEN_HEIGHT, 0.1f, 1000.0f);

    Vector2 screenPosition = Vector2(0.5f, -0.5f);
    Vector4 spacePosition = projectionMatrix * viewMatrix * modelMatrix * Vector4(screenPosition, 0.0f, 0.0f);

    return 0;
}
```

## Tests
To run test type followind in the command line:
```sh
cd tests/
cmake . -Wno-dev && cmake --build .
ctest --output-on-failure
```

## Dependecies
[Boost](https://github.com/boostorg/boost) (only for testing)

## License
IOMath is licensed under the [MIT license](LICENSE).