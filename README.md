# MLU-API

Python bindings for Cambricon's libraries

## Build

```
uv build
```

## Test

```
uv venv
uv sync
uv pip install scikit-build-core pybind11
uv pip install --no-build-isolation -e .
uv run -- pytest
```

## How to generate compile_command.json

```
uv venv
uv pip install scikit-build-core pybind11
uv pip install --no-build-isolation -e .
ln -s build/cp310-cp310-linux_x86_64/compile_commands.json .
```