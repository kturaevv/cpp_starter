
### Simple project template

To build the template ensure first `vcpkg` is iniitalized:

```bash
# In case vcpkg shows git diffs
git config submodule.extern/vcpkg.ignore all
# Download all extern packages
git submodule update --init --recursive --depth 1
```

Now the project can be started. There are utility functions wrapped in `Justfile` to build
from terminal.
Following commands would suffice to start working with the project:

```bash
just init
just build
just test
just run
```
