<div align="center">
  <a href="https://github.com/OpenCz/C_zsh/">
<img src="https://github.com/OpenCz/C_zsh/blob/main/assets/czsh-logo.png?raw=true" alt="Logo" height="180" style="border-radius: 10px">
</a>

<h3 align="center">C_zsh</h3>

[![License](https://img.shields.io/github/license/OpenCz/C_zsh?style=for-the-badge)](./LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/OpenCz/C_zsh/ci.yml?style=for-the-badge)](https://github.com/OpenCz/C_zsh/actions)

<p align="center">
    A Unix shell compatible with TCSH, written in C as part of the Epitech PSU project.
<br />
<a href="https://github.com/OpenCz/C_zsh"><strong>Explore the repository »</strong></a>
<br />
<br />
<a href="https://github.com/OpenCz/C_zsh">View Demo</a>
&middot;
<a href="https://github.com/OpenCz/C_zsh/issues/new?template=bug-report.yml">Report Bug</a>
&middot;
<a href="https://github.com/OpenCz/C_zsh/issues/new?template=feature-request.yml">Request Feature</a>
</p>
</div>

<details>
<summary>Table of Contents</summary>
<ol>
<li>
<a href="#about-the-project">About The Project</a>
<ul>
<li><a href="#built-with">Built With</a></li>
</ul>
</li>
<li>
<a href="#getting-started">Getting Started</a>
<ul>
<li><a href="#prerequisites">Prerequisites</a></li>
<li><a href="#installation">Installation</a></li>
</ul>
</li>
<li><a href="#usage">Usage</a></li>
<li><a href="#roadmap">Roadmap</a></li>
<li><a href="#contributing">Contributing</a></li>
<li><a href="#license">License</a></li>
<li><a href="#contact">Contact</a></li>
<li><a href="#acknowledgments">Acknowledgments</a></li>
</ol>
</details>

## About The Project

C_zsh (42sh) is a Unix shell written in C, designed to behave like TCSH. It implements an interactive REPL with a styled prompt, line editing, persistent history, pipelines, redirections, quoting, `$VAR` expansion, and a set of built-in commands (`cd`, `env`, `setenv`, `unsetenv`, `which`, `where`, `repeat`, `foreach`, `history`, `source`, and more).

### Built With

[![C][C-shield]][C-url]
[![Make][Make-shield]][Make-url]

## Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C compiler (gcc or clang) and GNU Make. Valgrind is recommended for memory-leak checks during development.

### Installation

#### Development mode (clone the repo, with local changes)
1. Clone the repository
```sh
git clone https://github.com/OpenCz/C_zsh.git
cd C_zsh
```
2. Build the project
```sh
make
```

#### Release mode (build and use the binary)
```sh
make          # build the ./42sh binary
./42sh        # start the interactive shell
```

## Usage

Launch the shell with `./42sh` for interactive use. See the [Project Architecture](./docs/ARCHITECTURE.md) and [Execution Flow](./docs/EXECUTION_FLOW.md) docs for details on the internals.

*For more advanced examples, please refer to the repository structure and adapt the code as needed.*

## Roadmap

See the [open issues](https://github.com/OpenCz/C_zsh/issues) for a full list of proposed features (and known issues).

## Contributing

Contributions are welcome and appreciated. Please review the contribution guide and follow the repository conventions when making changes.

See [CONTRIBUTING.md](./CONTRIBUTING.md) for setup instructions, commit conventions, and the PR process.

### Top contributors:

<a href="https://github.com/OpenCz/C_zsh/graphs/contributors">
<img src="https://contrib.rocks/image?repo=OpenCz/C_zsh" alt="contrib.rocks image" />
</a>

## License

Distributed under the MIT License. See [LICENSE](./LICENSE) for more information.

## Acknowledgments

* [tcsh manual](https://www.tcsh.org/) - Reference behavior for expansion order, builtins, and error messages
* [Markdown](https://www.markdownguide.org/) - The format used for documentation in this project

[C-shield]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[C-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[Make-shield]: https://img.shields.io/badge/Make-A42E2B?style=for-the-badge&logo=gnu&logoColor=white
[Make-url]: https://www.gnu.org/software/make/
[Markdown-shield]: https://img.shields.io/badge/Markdown-000000?style=for-the-badge&logo=markdown&logoColor=white
[Markdown-url]: https://www.markdownguide.org/