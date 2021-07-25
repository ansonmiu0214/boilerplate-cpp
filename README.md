# C++ Boilerplate Repository

***Opinionated*** sample C++ project scaffolding with a few useful bells and whistles!

---

<p align="center">
<a href="#features">Features</a> |
<a href="#directory-layout">Directory Layout</a> |
<a href="#getting-started">Getting Started</a> |
<a href="#learn-more">Learn More</a>
</p>

---

## ✨ <a name="features"></a> Features

* ✅ CMake
* ✅ Docker
* ✅ GoogleTest
* ✅ Conan package manager
* ✅ VS Code
    * Header include paths
    * Launch configuration for debugging
    * Remote Docker container setup

## 🗺 <a name="directory-layout"></a> Directory Layout

File/Directory | Description
---|---
`.conan/conanfile.txt` | List dependencies to be installed via Conan package manager
`.devcontainer/devcontainer.json` | Config for VS Code to create development container
`.vscode/` | Configs for VS Code to set up include paths (for IntelliSense) and launch targets (for debugging)
`apps/` | Directory for **executables** created by this project
`include/myproject/` | Directory for the **header files** exposed by **libraries** created by this project (named `myproject`)
`src/` | Directory for implementation files and private headers used by **libraries** created by this project
`docker-compose.yml` | Config for starting development container
`Dockerfile` | Blueprint for development environment setup

## 💻 <a name="getting-started"></a> Getting Started

```bash
$ pwd
/path/to/boilerplate-cpp

# For VS Code users, open the repository in VS Code and select to
# reopen the folder in a container -- VS Code should auto-detect the
# `devcontainer.json` config.
$ docker-compose run dev bash

# Build and run tests
dev@dev:/workarea $ make

# Run the sample executable
dev@dev:/workarea $ ./build/bin/calculator add 12 34
Hello, world!
12 + 34 = 46
```

<details>
<summary>
⚠️ Note for VS Code users
</summary>

Instead of `docker-compose`, you can open the cloned repository in VS Code and you should be prompted to reopen the folder in a container.

</details>

## 🔎 <a name="learn-more"></a> Learn More

* [CMake](https://cmake.org/documentation/)
* [Conan package manager](https://docs.conan.io/en/latest/getting_started.html)
* [Docker](https://docs.docker.com/compose/gettingstarted/)
* [GoogleTest](https://github.com/google/googletest/blob/master/docs/primer.md)
* [VS Code Remote Containers](https://code.visualstudio.com/docs/remote/devcontainerjson-reference)