# ngl:cluster

__`[description]`__

A cluster is used to regroup ngl:data

__`[edges]`__

- [concept](cluster/concept.md)
- [entity](cluster/entity.md)
- [foreign](ecosystem/foreign.md)

__`[example]`__

```
// program.ngl
ngl:cluster main // every descriptions will belong to the main cluster
ngc::int a = 5

ngl:cluster zeta // everything after will belong to the zeta cluster

ngl:cluster:main
{
    // everything here will belong to the main cluster
}

// zeta.ngl
ngl:cluster main
a = 8 // a is accessible in zeta.ngl, it belongs to main cluster
```