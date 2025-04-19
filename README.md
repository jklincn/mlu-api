# MLU-API

Python bindings for Cambricon's libraries

## Development

### Build and Install

```
uv sync
```

### Test

```
uv run pytest
```

### How to generate compile_command.json

```
# Avoid missing header caused by temporary environment
uv pip install --no-build-isolation -e .
ln -s build/cp310-cp310-linux_x86_64/compile_commands.json .
```

## Publish

```
sudo apt install patchelf
uv build
uv run auditwheel repair dist/mlu_api-0.1.0-cp310-cp310-linux_x86_64.whl --plat manylinux_2_34_x86_64
uv publish wheelhouse/mlu_api-0.1.0-cp310-cp310-manylinux_2_34_x86_64.whl
```