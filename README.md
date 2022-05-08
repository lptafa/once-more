# yeah, one more ray tracer

A Basic raytracer with WIP support for python bindings

---

## Run raytracer

```bash
$ ./run.sh
```

## Generate Python bindings

You need to make sure you have `pybind11` installed. You can do this through `pip install pybind11`.

```bash
$ ./gen_bindings.sh
$ python3
>>> import raytrace as rt
>>> rt.Vec3(1, 2, 3)
(1.000000, 2.000000, 3.000000)
```
---