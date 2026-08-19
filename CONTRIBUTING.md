# Contributing

Thanks for considering a contribution. This project template is intended to be reusable across many languages and project types, so contributions should stay clear, focused, and easy to adapt.

## Table of Contents

- [Code of Conduct](#code-of-conduct)
- [Getting Started](#getting-started)
- [Project Structure](#project-structure)
- [Development Workflow](#development-workflow)
- [Commit Convention](#commit-convention)
- [Testing](#testing)
- [Submitting Changes](#submitting-changes)
- [Reporting Bugs / Requesting Features](#reporting-bugs--requesting-features)
- [Release Process](#release-process)
- [Style Guidelines](#style-guidelines)

## Code of Conduct

Be respectful, constructive, and patient. Disagreements about implementation are fine; personal attacks are not.

## Getting Started

### Prerequisites

- A working runtime or toolchain for the project you are scaffolding
- A package manager or build tool appropriate to the stack you choose
- A local development environment that can run tests or build checks

### Setup

```bash
git clone <repository-url>
cd <project-name>
# Install dependencies or set up the local environment for your stack
```

Verify your setup works with the appropriate build or test command for your project.

## Project Structure

| Path | Purpose |
|------|---------|
| `src/` or `app/` | Main implementation files |
| `tests/` | Automated tests and regression checks |
| `docs/` | Usage notes, architecture, or other documentation |
| `assets/` | Images, logos, and other static files |
| `scripts/` | Helper scripts or automation |

## Development Workflow

1. Fork the repo
2. Create a branch from `main`:
   ```bash
   git checkout -b feature/short-description
   # or
   git checkout -b fix/short-description
   ```
3. Make your changes, with tests where applicable
4. Run the test suite locally (see [Testing](#testing))
5. Push and open a Pull Request using the appropriate [PR template](.github/PULL_REQUEST_TEMPLATE/)

## Commit Convention

This project follows **[Conventional Commits](https://www.conventionalcommits.org/)** — it's required, since the release process (`release-config.json` / `.release-manifest.json`) depends on commit messages to determine versioning and changelog entries.

```
<type>(<scope>): <short description>

[optional body]
```

Common types: `feat`, `fix`, `docs`, `refactor`, `test`, `build`, `chore`.

## Testing

- Add or update tests when changing behavior.
- Run the project’s normal test or validation commands before opening a PR.
- If your change affects packaging, deployment, or user-facing behavior, verify it with the relevant checks.

## Submitting Changes

Open your PR using the template that matches your change:

| Change type        | Template                                              |
|---------------------|--------------------------------------------------------|
| New feature          | `?template=feature.md`                                |
| Bug fix               | `?template=hotfix.md`                                  |
| Release (maintainers) | `?template=release.md`                                 |

A PR is ready for review once every checkbox in its template is checked. Reviewers may ask for changes before merging — that's normal, not a rejection.

## Reporting Bugs / Requesting Features

Please use the issue templates instead of opening a blank issue when possible.

- **Bug report**: include reproduction steps, expected behavior, actual behavior, and environment details.
- **Feature request**: include goals, scope, and any constraints or dependencies.

## Release Process

*(Maintainers only — included for transparency.)*

1. Ensure all merged commits on `main` follow Conventional Commits
2. Confirm `release-config.json` / `.release-manifest.json` are up to date
3. Confirm the **CZSH** workflow is green on `stable`
4. Open a release PR using the `release.md` template
5. If a published release breaks downstream usage: publish a patch (`vX.Y.Z+1`) and yank the broken version on PyPI rather than force-pushing history

## Style Guidelines

- Keep changes focused and easy to review.
- Follow the existing style of the repository.
- Prefer clear naming, small commits, and concise documentation.
- Adapt the tooling and conventions to the stack you are using.

---

Questions that aren't a bug or feature request can go in [Discussions](https://github.com/your-name/your-repo/discussions) instead of an issue.